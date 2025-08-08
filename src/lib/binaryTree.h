#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void free_tree_node(Tree *tree, TreeNode *node);

void push(Tree *tree, TreeNode *newNode);
TreeNode *pop(Tree *tree, TreeNode *node);
TreeNode *pop_min(Tree *tree, TreeNode **out_min);
TreeNode *pop_max(Tree *tree, TreeNode **out_max);
TreeNode *get_node(Tree *tree, ...);

int tree_height(TreeNode *node);

int tree_height(TreeNode *node);
void fill_levels(Tree *tree, TreeNode *node, int level, int pos, char **lines,
                 int width);
void print_tree(Tree *tree);
void print_node(Tree *tree, TreeNode *node);
