#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"


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