#ifndef BST_H 
#define BST_H

#include <stdlib.h>

struct root_t {
    struct node_t *root;
    struct node_t *nil;
};

struct node_t {
    int key;
    char color;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
};

struct root_t *create_rb(int k);

struct node_t *create_node(struct root_t *tree, struct node_t *parent_node, int k);

void left_rotate(struct root_t *tree, struct node_t *target);

struct node_t *bst_insert(struct root_t *tree, struct node_t *node, struct node_t *parent_node, int k);

void rb_insert(struct root_t *tree, int k);

void postorder(struct node_t* p, int indent);

void print_tree(struct root_t *tree, struct node_t *node, int counter);

#endif
