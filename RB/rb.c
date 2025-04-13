#include <stdio.h>
#include <stdlib.h>
#include "rb.h"


#include <stdlib.h>

struct root_t *create_rb(int k) {
    struct root_t *tree = malloc(sizeof(struct node_t));
    struct node_t *root = malloc(sizeof(struct node_t));
    struct node_t *nil = malloc(sizeof(struct node_t));

    root->key = k;
    root->color = 0;
    root->left = nil;
    root->right = nil;
    root->parent = nil;

    tree->root = root;

    nil->color = 0;
    tree->nil = nil;

    return tree;
}


struct node_t *create_node(struct root_t *tree, struct node_t *parent_node, int k) {
    struct node_t *node = malloc(sizeof(struct node_t));

    node->key = k;
    node->color = 0;
    node->left = tree->nil;
    node->right = tree->nil;
    node->parent = parent_node;

    return node;
}

void left_rotate(struct root_t *tree, struct node_t *target) {
    struct node_t *aux = target->right;
    target->right = aux->left;

    if (aux->left != tree->nil)
        aux->left->parent = target;

    aux->parent = target->parent;

    if (target->parent == tree->nil)
        tree->root = aux;
    else if (target == target->parent->left)
        target->parent->left = aux;
    else
        target->parent->right = aux;

    aux->left = target;
    target->parent = aux;
}

void right_rotate(struct root_t *tree, struct node_t *target) {
    struct node_t *aux = target->left;
    target->left = aux->right;

    if (aux->right != tree->nil)
        aux->right->parent = target;

    aux->parent = target->parent;

    if (target->parent == tree->nil)
        tree->root = aux;
    else if (target == target->parent->right)
        target->parent->right = aux;
    else
        target->parent->left = aux;

    aux->right = target;
    target->parent = aux;
}

struct node_t *bst_insert(struct root_t *tree, struct node_t *node, struct node_t *parent_node, int k) {
    if (node == tree->nil)
        return(create_node(tree, parent_node, k));
    if (node->key > k) {
        struct node_t *inserted = bst_insert(tree, node->left, node, k);
        node->left = inserted;
        return inserted;
    }
    else if (node->key < k) {
        struct node_t *inserted = bst_insert(tree, node->right, node, k);
        node->right = inserted;
        return inserted;
    }
    
    return node;
}

void rb_insert(struct root_t *tree, int k) {
    struct node_t *new = bst_insert(tree, tree->root, tree->nil, k);
    
    new->color = 1;

    // while (new->parent->color == 1) {
    //     if (new->parent == new->parent->parent->left) {
    //         struct node_t *aux = new->parent->parent->right;
            
    //         if (aux->color == 1) {
    //             new->parent->color = 0;
    //             aux->color = 0;
    //             new->parent->parent->color = 1;
    //             new = new->parent->parent;
    //         } 
    //         else {
    //             if (new == new->parent->right) {
    //                 new = new->parent;
    //                 left_rotate(tree, new);
    //             }

    //             new->parent->color = 0;
    //             new->parent->parent->color = 1;
    //             right_rotate(tree, new->parent->parent);
    //         }
    //     } 
    //     else {
    //         struct node_t *aux = new->parent->parent->left;
    //         if (aux->color == 1) {
    //             new->parent->color = 0;
    //             aux->color = 0;
    //             new->parent->parent->color = 1;
    //             new = new->parent->parent;
    //         } 
    //         else {
    //             if (new == new->parent->left) {
    //                 new = new->parent;
    //                 right_rotate(tree, new);
    //             }

    //             new->parent->color = 0;
    //             new->parent->parent->color = 1;
    //             left_rotate(tree, new->parent->parent);
    //         }
    //     }
    // }

    // tree->root->color = 0;
}

void print_tree(struct root_t *tree, struct node_t *node, int counter) {
    if (node == tree->nil)
        return;

    print_tree(tree, node->left, counter + 1);
    printf("%d,%d,%c\n", node->key, counter, node->color);
    print_tree(tree, node->right, counter + 1);
}

// struct node_t *find_max(struct node_t *node) {
//     if (node->right)
//         return (find_max(node->right));
    
//     return node;
// }

// struct node_t *find_min(struct node_t *node) {
//     if (node->left)
//         return (find_min(node->left));
    
//     return node;
// }


// // void *rotate_right(struct node_t *node);