#include <stdlib.h>

#include "hashtable.h"



struct node *create_node(int k) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(!new_node){
        return NULL;
    }

    new_node->key = k;
    new_node->valid = TRUE;

    return new_node;
}

void destroy_node(struct node *node) {
    if(node){
        free(node);
    }
}



struct hashtable *create_hashtable(int size){
    struct hashtable *new_hash = (struct hashtable *)malloc(sizeof(struct hashtable));
    if(!new_hash){
        return NULL;
    }
    new_hash->size = size;

    new_hash->h1 = (struct node **)calloc(size, sizeof(struct node *));
    new_hash->h2 = (struct node **)calloc(size, sizeof(struct node *));

    for(int i = 0; i < size; i++){
        new_hash->h1[i] = NULL;
        new_hash->h2[i] = NULL;
    }

    return new_hash;

}

void destroy_hashtable(struct hashtable *hash);

void insert_hashtable(struct hashtable *hash, int key) {

}

int hashing1(int key);

int hashing2(int key);

int search_hashtable(struct hashtable *hash, int key);

void remove_hashtable(struct hashtable *hash, int key);

void print_hashtable(struct hashtable);