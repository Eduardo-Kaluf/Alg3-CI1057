#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "rb.h"

#define PRETO 0
#define VERMELHO 1

struct root_t *create_rb(int k) {
    struct root_t *tree = malloc(sizeof(struct root_t));
    struct node_t *root = malloc(sizeof(struct node_t));
    struct node_t *nil = malloc(sizeof(struct node_t));

    root->key = k;
    root->color = PRETO;
    root->left = nil;
    root->right = nil;
    root->parent = nil;

    tree->root = root;

    nil->color = PRETO;
    nil->left = nil;
    nil->right = nil;
    nil->parent = nil;

    tree->nil = nil;

    return tree;
}

struct node_t *create_rb_node(struct root_t *tree, struct node_t *parent_node, int k) {
    if (tree == NULL)
        return NULL;
    
    struct node_t *node = malloc(sizeof(struct node_t));

    node->key = k;
    node->color = VERMELHO;
    node->left = tree->nil;
    node->right = tree->nil;
    node->parent = parent_node;

    return node;
}

struct node_t *rb_search(struct root_t *tree, struct node_t *node, int key) {
    if (tree == NULL)
        return NULL;
    
    if (node == tree->nil || key == node->key)
        return node;
    if (key < node->key)
        return rb_search(tree, node->left, key);
    else
        return rb_search(tree, node->right, key);
}

void rb_left_rotation(struct root_t *tree, struct node_t *target) {
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

void rb_right_rotation(struct root_t *tree, struct node_t *target) {
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
    if (tree == NULL)
        return;
    
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
    new->color = VERMELHO;

    rb_insert_fixup(tree, new);
}

void rb_insert_fixup(struct root_t *tree, struct node_t *new) {
    while (new->parent->color == VERMELHO) {
        if (new->parent == new->parent->parent->left) {
            struct node_t *aux = new->parent->parent->right;
            
            if (aux->color == VERMELHO) {
                new->parent->color = PRETO;
                aux->color = PRETO;
                new->parent->parent->color = VERMELHO;
                new = new->parent->parent;
            } 
            else {
                if (new == new->parent->right) {
                    new = new->parent;
                    rb_left_rotation(tree, new);
                }

                new->parent->color = PRETO;
                new->parent->parent->color = VERMELHO;
                rb_right_rotation(tree, new->parent->parent);
            }
        } 
        else {
            struct node_t *aux = new->parent->parent->left;
            
            if (aux->color == VERMELHO) {
                new->parent->color = PRETO;
                aux->color = PRETO;
                new->parent->parent->color = VERMELHO;
                new = new->parent->parent;
            } 
            else {
                if (new == new->parent->left) {
                    new = new->parent;
                    rb_right_rotation(tree, new);
                }

                new->parent->color = PRETO;
                new->parent->parent->color = VERMELHO;
                rb_left_rotation(tree, new->parent->parent);
            }
        }
    }

    tree->root->color = PRETO;
}

void rb_print(struct root_t *tree, struct node_t *node, int counter) {
    if (tree == NULL)
        return;

    if (node == tree->nil)
        return;

    rb_print(tree, node->left, counter + 1);
    printf("%d,%d,%d\n", node->key, counter, node->color);
    rb_print(tree, node->right, counter + 1);
}

struct node_t *find_max(struct root_t *tree, struct node_t *node) {
    if (node->right != tree->nil)
        return (find_max(tree, node->right));
    
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

void rb_delete(struct root_t *tree, struct node_t *removing) {
    if (tree == NULL)
        return;
    
    struct node_t *target;
    struct node_t *aux = removing;
    char aux_color = aux->color;

    if (removing == tree->nil)
        return;

    if (removing->left == tree->nil) {
        target = removing->right;
        rb_transplant(tree, removing, removing->right);
    }
    else if (removing->right == tree->nil) {
        target = removing->left;
        rb_transplant(tree, removing, removing->left);
    }
    else {
        aux = find_max(tree, removing->left);
        aux_color = aux->color;
        target = aux->left;

        if (aux->parent == removing)
            target->parent = aux;
        else {
            rb_transplant(tree, aux, aux->left);
            aux->left = removing->left;
            aux->left->parent = aux;
        }

        rb_transplant(tree, removing, aux);
        aux->right = removing->right;
        aux->right->parent = aux;
        aux->color = removing->color;
    }

    free(removing);

    if (aux_color == PRETO)
        rb_delete_fixup(tree, target);
}

void rb_delete_fixup(struct root_t *tree, struct node_t *target) {
    while (target != tree->root && target->color == PRETO) {
        if (target == target->parent->left) {
            struct node_t *aux = target->parent->right;

            if (aux->color == VERMELHO) {
                aux->color = PRETO;
                target->parent->color = VERMELHO;
                rb_left_rotation(tree, target->parent);
                aux = target->parent->right;
            }
            if (aux->left->color == PRETO && aux->right->color == PRETO) {
                aux->color = VERMELHO;
                target = target->parent;
            } 
            else {
                if (aux->right->color == PRETO) {
                    aux->left->color = PRETO;
                    aux->color = VERMELHO;
                    rb_right_rotation(tree, aux);
                    aux = target->parent->right;
                }
                
                aux->color = target->parent->color;
                target->parent->color = PRETO;
                aux->right->color = PRETO;
                rb_left_rotation(tree, target->parent);
                target = tree->root;
            }
        } 
        else {
            struct node_t *aux = target->parent->left;

            if (aux->color == VERMELHO) {
                aux->color = PRETO;
                target->parent->color = VERMELHO;
                rb_right_rotation(tree, target->parent);
                aux = target->parent->left;
            }
            if (aux->right->color == PRETO && aux->left->color == PRETO) {
                aux->color = VERMELHO;
                target = target->parent;
            } 
            else {
                if (aux->left->color == PRETO) {
                    aux->right->color = PRETO;
                    aux->color = VERMELHO;
                    rb_left_rotation(tree, aux);
                    aux = target->parent->left;
                }

                aux->color = target->parent->color;
                target->parent->color = PRETO;
                aux->left->color = PRETO;
                rb_right_rotation(tree, target->parent);
                target = tree->root;
            }
        }
    }

    target->color = PRETO;
}

void rb_destroy(struct root_t *tree) {
    if (tree == NULL)
        return;

    while (tree->root->left != tree->nil) {
        rb_delete(tree, find_max(tree, tree->root->left));
    }
    
    while (tree->root->right != tree->nil) {
        rb_delete(tree, find_max(tree, tree->root->right));
    }

    if (tree->root != tree->nil)
        free(tree->root);
    
    free(tree->nil);
    free(tree);
}