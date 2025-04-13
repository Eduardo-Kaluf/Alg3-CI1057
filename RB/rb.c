#include <stdio.h>
#include <stdlib.h>
#include "rb.h"


#include <stdlib.h>

struct root_t *create_rb(int k) {
    struct root_t *tree = malloc(sizeof(struct root_t));
    struct node_t *root = malloc(sizeof(struct node_t));
    struct node_t *nil = malloc(sizeof(struct node_t));

    root->key = k;
    root->color = 0;
    root->left = nil;
    root->right = nil;
    root->parent = nil;

    tree->root = root;

    nil->color = 0;
    nil->left = nil;
    nil->right = nil;
    nil->parent = nil;
    tree->nil = nil;

    return tree;
}


struct node_t *create_node(struct root_t *tree, struct node_t *parent_node, int k) {
    struct node_t *node = malloc(sizeof(struct node_t));

    node->key = k;
    node->color = 1;
    node->left = tree->nil;
    node->right = tree->nil;
    node->parent = parent_node;

    return node;
}

struct node_t *rb_search(struct root_t *tree, struct node_t *node, int key) {
    if (node == tree->nil || key == node->key)
        return node;
    if (key < node->key)
        return rb_search(tree, node->left, key);
    else
        return rb_search(tree, node->right, key);
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

void rb_insert(struct root_t *tree, struct node_t *new) {
    struct node_t *aux = tree->nil;
    struct node_t *target = tree->root;

    while (target != tree->nil) {
        aux = target;
        if (new->key < target->key)
            target = target->left;
        else
            target = target->right;
    }

    new->parent = aux;

    if (aux == tree->nil)
        tree->root = new;
    else if (new->key < aux->key)
        aux->left = new;
    else
        aux->right = new;
    
    new->left = tree->nil;
    new->right = tree->nil;
    new->color = 1;

    rb_insert_fixup(tree, new);
}

void rb_insert_fixup(struct root_t *tree, struct node_t *new) {
    while (new->parent->color == 1) {
        if (new->parent == new->parent->parent->left) {
            struct node_t *aux = new->parent->parent->right;
            
            if (aux->color == 1) {
                new->parent->color = 0;
                aux->color = 0;
                new->parent->parent->color = 1;
                new = new->parent->parent;
            } 
            else {
                if (new == new->parent->right) {
                    new = new->parent;
                    left_rotate(tree, new);
                }

                new->parent->color = 0;
                new->parent->parent->color = 1;
                right_rotate(tree, new->parent->parent);
            }
        } 
        else {
            struct node_t *aux = new->parent->parent->left;
            if (aux->color == 1) {
                new->parent->color = 0;
                aux->color = 0;
                new->parent->parent->color = 1;
                new = new->parent->parent;
            } 
            else {
                if (new == new->parent->left) {
                    new = new->parent;
                    right_rotate(tree, new);
                }

                new->parent->color = 0;
                new->parent->parent->color = 1;
                left_rotate(tree, new->parent->parent);
            }
        }
    }

    tree->root->color = 0;
}

void print_tree(struct root_t *tree, struct node_t *node, int counter) {

    if (node == tree->nil)
        return;

    print_tree(tree, node->left, counter + 1);
    printf("%d,%d,%d\n", node->key, counter, node->color);
    print_tree(tree, node->right, counter + 1);
}

struct node_t *find_min(struct root_t *tree, struct node_t *node) {
    if (node->left != tree->nil)
        return (find_min(tree, node->left));
    
    return node;
}

void rb_transplant(struct root_t *tree, struct node_t *removing, struct node_t *new_sub_root) {
    if (removing->parent == tree->nil)
        tree->root = new_sub_root;
    else if (removing == removing->parent->left)
        removing->parent->left = new_sub_root;
    else 
        removing->parent->right = new_sub_root;
    
    new_sub_root->parent = removing->parent;
}

void rb_delete_fixup(struct root_t *tree, struct node_t *removing) {
    struct node_t *aux;

    while (removing != tree->root && removing->color == 0) {
        if (removing == removing->parent->left) {
            aux = removing->parent->right;

            if (aux->color == 1) {
                aux->color = 0;
                removing->parent->color = 1;
                left_rotate(tree, removing->parent);
                aux = removing->parent->right;
            }

            if (aux->left->color == 0 && aux->right->color == 0) {
                aux->color = 1;
                removing = removing->parent;
            }

            else if (aux->right->color == 0) {
                aux->left->color = 0;
                aux->color = 1;
                right_rotate(tree, aux);
                aux = removing->parent->right;
            }
            else {
                aux->color = removing->parent->color;
                removing->parent->color = 0;
                aux->right->color = 0;
                left_rotate(tree, removing->parent);
                removing = tree->root;
            }

        }
        else {
            aux = removing->parent->left;

            if (aux->color == 1) {
                aux->color = 0;
                removing->parent->color = 1;
                right_rotate(tree, removing->parent);
                aux = removing->parent->left;
            }

            if (aux->right->color == 0 && aux->left->color == 0) {
                aux->color = 1;
                removing = removing->parent;
            }

            else if (aux->left->color == 0) {
                aux->right->color = 0;
                aux->color = 1;
                left_rotate(tree, aux);
                aux = removing->parent->left;
            }

            else {
                aux->color = removing->parent->color;
                removing->parent->color = 0;
                aux->left->color = 0;
                right_rotate(tree, removing->parent);
                removing = tree->root;
            }
        }
    }

    tree->root->color = 0;
}


void rb_delete(struct root_t *tree, struct node_t *removing) {
    struct node_t *target;
    struct node_t *aux = removing;
    char aux_color = aux->color;

    if (removing->left == tree->nil) {
        target = removing->right;
        rb_transplant(tree, removing, removing->right);
    }
    else if (removing->right == tree->nil) {
        target = removing->left;
        rb_transplant(tree, removing, removing->left);
    }
    else {
        aux = find_min(tree, removing->right);
        aux_color = aux->color;
        target = aux->right;
        if (aux->parent == removing)
            target->parent = aux;
        else {
            rb_transplant(tree, aux, aux->right);
            aux->right = removing->right;
            aux->right->parent = aux;
        }
        rb_transplant(tree, removing, aux);
        aux->left = removing->left;
        aux->left->parent = aux;
        aux->color = removing->color;
    }
    
    if (aux_color == 0)
        rb_delete_fixup(tree, target);
}
