#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

/*funcoes privadas*/

void particao_mediana (struct order_node v[], int esq, int dir, int *pos_pivo){
    int i, j;
    struct order_node aux, pivo;

    //procura a mediana entre inicio, meio e fim
    int meio = (esq + dir) / 2;
    struct order_node a = v[esq];
    struct order_node b = v[meio];
    struct order_node c = v[dir];
    int medianaIndice; 
    if (a.key < b.key) {
        if (b.key < c.key) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a.key < c.key) {
                //a < c && c <= b
                medianaIndice = dir;
            } else {
                //c <= a && a < b
                medianaIndice = esq;
            }
        }
    } else {
        if (c.key < b.key) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c.key < a.key) {
                //b <= c && c < a
                medianaIndice = dir;
            } else {
                //b <= a && a <= c
                medianaIndice = esq;
            }
        }
    }
    aux = v[medianaIndice];
    v[medianaIndice] = v[dir];
    v[dir] = v[medianaIndice];

    pivo = v[dir];
    i = esq;
    j = dir;
    while(i < j){
        while((v[i].key <= pivo.key) && (i < dir)){
            i++;
    
        }
        while(v[j].key > pivo.key){
            j--;
    
        }
        if(i < j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }

    v[esq] = v[j];
    v[j] = pivo;
    *pos_pivo = j;
}

/* com pivo aleatorio */
void quicksort (struct order_node v[], int esq, int dir){
    int pos_pivo;

    if(esq < dir){
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
    if (node)
        free(node);
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

int search_hashtable(struct hashtable *hash, int key){

    int hk1 = hashing1(key);
    if(hash->h1[hk1] == NULL){
        return -1;
    }
    if((hash->h1[hk1]->key == key) && (hash->h1[hk1]->valid == TRUE)){
        return hk1;
    } else {
        int hk2 = hashing2(key);
        if(hash->h2[hk2]) {
            return hk2;
        }
        return -1;
    }
}

void remove_hashtable(struct hashtable *hash, int key) {

    if (hash->h2[hashing2(key)] != NULL)
        destroy_node(hash->h2[hashing2(key)]);
    else if (hash->h1[hashing1(key)] != NULL) {
        hash->h1[hashing1(key)]->key = -1;
        hash->h1[hashing1(key)]->key = FALSE;
    }
}

void print_hashtable(struct hashtable *hash) {

    struct order_node sorted_array[22];

    for (int i = 0; i < hash->size; i++) {
        sorted_array[i].key = -1;
        sorted_array[i].key = -1;
        sorted_array[i].key = -1;
    }

}