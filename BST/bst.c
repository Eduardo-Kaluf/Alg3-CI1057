#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


#include <stdlib.h>

struct node_t *create_node(struct node_t *parent_node, int k) {
    struct node_t *node = malloc(sizeof(struct node_t));

    node->key = k;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent_node;

    return node;
}

struct node_t *binary(struct node_t *node, struct node_t *parent_node, int k) {
    if (node == NULL)
        return(create_node(parent_node, k));
    if (node->key > k)
        node->left = binary(node->left, node, k);
    else if (node->key < k)
        node->right = binary(node->right, node, k);
    
    return node;
}

void print_tree(struct node_t *node) {
    if (node == NULL)
        return;

    print_tree(node->left);
    printf("%d ", node->key);  
    print_tree(node->right);
}

struct node_t *find_max(struct node_t *node) {
    if (node->right)
        return (find_max(node->right));
    
    return node;
}

struct node_t *find_min(struct node_t *node) {
    if (node->left)
        return (find_min(node->left));
    
    return node;
}

// void rotate_left(struct node_t *root, struct node_t *node) {
//     struct node_t *pivot;
//     pivot = node->right;

//     node->right = pivot->left;

//     if (pivot->left != NULL)
//         pivot->left->parent = node;
    
//     pivot->parent = node->parent;

//     if (node->parent == NULL)
//         root = pivot;
//     else if (node == node->parent->left)
//         node->parent->left = pivot;
//     else
//         node->parent->right = pivot;
    
//     pivot->left = node;
//     node->parent = pivot;
// }

// void *rotate_right(struct node_t *node);

void postorder(struct node_t* p, int indent) {
    if (p != NULL) {
        if (p->right) {
            postorder(p->right, indent + 4);
        }
        
        if (indent) {
            for (int i = 0; i < indent; i++) {
                printf(" ");
            }
        }

        if (p->right) {
            printf(" /\\\n");
            for (int i = 0; i < indent; i++) {
                printf(" ");
            }
        }

        printf("%d\n", p->key);

        if (p->left) {
            for (int i = 0; i < indent; i++) {
                printf(" ");
            }
            printf(" \\\n");
            postorder(p->left, indent + 4);
        }
    }
}