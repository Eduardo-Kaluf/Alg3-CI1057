#ifndef HASHTABLE_H
#define HASHTABLE_H

#define SIZE 11
#define TRUE 1 
#define FALSE 0


struct node {
    char valid;
    int key;
};

struct hashtable {
    int size;
    struct node **h1; //vector of first hashtable
    struct node **h2; //vector of second hashtable
};

struct order_node {
    int key;
    char table[3];
    int index;
};


struct node *create_node(int k);

void destroy_node(struct node *node);

struct hashtable *create_hashtable(int size);

void destroy_hashtable(struct hashtable *hash);

void insert_hashtable(struct hashtable *hash, int key);

int hashing1(int key);

int hashing2(int key);

int search_hashtable(struct hashtable *hash, int key);

void remove_hashtable(struct hashtable *hash, int key);

void print_hashtable(struct hashtable);


#endif
