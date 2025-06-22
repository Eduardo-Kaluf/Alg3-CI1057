#include <stdlib.h>

#include "hashtable.h"



struct node *create_node(int k) {
    struct node *new_node;
    if(!(new_node = (struct node *)malloc(sizeof(struct node)))){
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

void insert_hashtable(struct hashtable *hash, int key);

int hashing1(int key);

int hashing2(int key);

int search_hashtable(struct hashtable *hash, int key);

void remove_hashtable(struct hashtable *hash, int key);

void print_hashtable(struct hashtable);