#ifndef BST_H 
#define BST_H

#include <stdlib.h>

struct node_t {
    int key;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
};

struct node_t *create_node(struct node_t *parent_node, int key);

struct node_t *binary(struct node_t *node, struct node_t *parent_node, int k);

void print_tree(struct node_t *node);

struct node_t *find_max(struct node_t *node);

struct node_t *find_min(struct node_t *node);

void rotate_left(struct node_t *root, struct node_t *node);

void rotate_right(struct node_t *root, struct node_t *node);

void postorder(struct node_t* p, int indent);

#endif
