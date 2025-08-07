#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#include "./utils/char.h"
#include "./utils/float.h"
#include "./utils/int.h"

typedef enum {
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_CHAR,
} DataType;

typedef struct TreeNode {
  struct TreeNode *father;
  struct TreeNode *left;
  struct TreeNode *right;
  void *value;
} TreeNode;

typedef struct Tree {
  TreeNode *root;
  size_t len;
  DataType type;

  bool (*greather)(void *, void *);
  bool (*cmp)(void *, void *);
  void (*to_string)(void *, char *);
  void (*free)(void *free);
  void *(*make)(va_list);
} Tree;

void *make_value(Tree *tree, ...);

Tree *initTree(DataType type);
TreeNode *initNode(Tree *tree, ...);

void free_tree(Tree *tree, bool free_struct);

void push(Tree *tree, TreeNode *newNode);
TreeNode *pop(Tree *tree, TreeNode *node);

TreeNode *get_node(Tree *tree, ...);

void print_tree(Tree *tree);
char *three_toString(Tree *tree);
void print_node(Tree *tree, TreeNode *node);
