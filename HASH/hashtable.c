#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

#include <stdio.h>

void particao_mediana(struct order_node v[],
                             int        esq,
                             int        dir,
                             int       *pos_pivo)
{
    int meio = (esq + dir) / 2;

    int mediana = esq;        

    if ((v[esq].key <= v[meio].key && v[meio].key <= v[dir].key) ||
        (v[dir].key <= v[meio].key && v[meio].key <= v[esq].key))
        mediana = meio;
    else if ((v[esq].key <= v[dir].key && v[dir].key <= v[meio].key) ||
             (v[meio].key <= v[dir].key && v[dir].key <= v[esq].key))
        mediana = dir;

    struct order_node aux        = v[mediana];
    v[mediana]            = v[dir];
    v[dir]                = aux;
    struct order_node pivot = v[dir];

    int i = esq;
    for (int j = esq; j < dir; ++j) {
        if (v[j].key <= pivot.key) {
            aux   = v[i];
            v[i]  = v[j];
            v[j]  = aux;
            ++i;
        }
    }

    aux   = v[i];
    v[i]  = v[dir];
    v[dir]= aux;

    *pos_pivo = i;
}

void quicksort(struct order_node v[], int esq, int dir)
{
    if (esq < dir) {
        int pos_pivo;
        particao_mediana(v, esq, dir, &pos_pivo);
        quicksort(v, esq, pos_pivo - 1);
        quicksort(v, pos_pivo + 1, dir);
    }
}

/*funcoes publicas*/
struct node *create_node(int k) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    if (!new_node)
        return NULL;

    new_node->key = k;
    new_node->valid = TRUE;

    return new_node;
}

void destroy_node(struct node *node) {
    if (node){
        free(node);
    }

}

struct hashtable *create_hashtable(int size){
    struct hashtable *new_hash = (struct hashtable *) malloc(sizeof(struct hashtable));

    if (!new_hash)
        return NULL;

    new_hash->size = size;

    new_hash->h1 = (struct node **)calloc(size, sizeof(struct node *));
    new_hash->h2 = (struct node **)calloc(size, sizeof(struct node *));

    for (int i = 0; i < size; i++) {
        new_hash->h1[i] = NULL;
        new_hash->h2[i] = NULL;
    }

    return new_hash;

}

void destroy_hashtable(struct hashtable *hash) {
    if (hash) {
        for (int i = 0; i < hash->size; i++){
            if(hash->h1[i])
                destroy_node(hash->h1[i]);
            if(hash->h2[i])
                destroy_node(hash->h2[i]);
        }

        free(hash->h1);
        free(hash->h2);
        free(hash);
    }
}

void insert_hashtable(struct hashtable *hash, int key) {
    int hk1 = hashing1(key);

    if (hash->h1[hk1] == NULL)
        hash->h1[hk1] = create_node(key);
    else if (hash->h1[hk1]->valid == FALSE) {
        hash->h1[hk1]->key = key;
        hash->h1[hk1]->valid = TRUE;
    }
    else if (key != hash->h1[hk1]->key) {
        int hk2 = hashing2(hash->h1[hk1]->key);
        hash->h2[hk2] = create_node(hash->h1[hk1]->key);
        hash->h1[hk1]->key = key;
    }
}

int hashing1(int key) {
    return key % SIZE;
}

int hashing2(int key) {
    return (int)(SIZE * (key * 0.9 - (int)(key * 0.9)));
}

int search_hashtable(struct hashtable *hash, int key) {
    int hk1 = hashing1(key);

    if(hash->h1[hk1] == NULL)
        return -1;

    if((hash->h1[hk1]->key == key) && (hash->h1[hk1]->valid == TRUE))
        return hk1;

    int hk2 = hashing2(key);

    if(hash->h2[hk2])
        return hk2;

    return -1;
}

void remove_hashtable(struct hashtable *hash, int key) {
    int hk1 = hashing1(key);
    int hk2 = hashing2(key);

    if ((hash->h2[hk2] != NULL) && (hash->h2[hk2]->key == key)){
        destroy_node(hash->h2[hk2]);
        hash->h2[hk2] = NULL;
    } else if ((hash->h1[hk1] != NULL) && (hash->h1[hk1]->key == key)) {
        hash->h1[hk1]->key = -1;
        hash->h1[hk1]->valid = FALSE;
    }
}

void print_hashtable(struct hashtable *hash) {
    struct order_node sorted_array[22];
    int n = 0;

    for (int i = 0; i < hash->size; i++) {
        if (hash->h1[i] != NULL && hash->h1[i]->valid) {
            sorted_array[n].key = hash->h1[i]->key;
            strcpy(sorted_array[n].table, "T1");
            sorted_array[n].index = i;
            n += 1;
        }

        if (hash->h2[i] != NULL) {
            sorted_array[n].key = hash->h2[i]->key;
            strcpy(sorted_array[n].table, "T2");
            sorted_array[n].index = i;
            n += 1;
        }
    }

    quicksort(sorted_array, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d,%s,%d\n", sorted_array[i].key, sorted_array[i].table, sorted_array[i].index);
}