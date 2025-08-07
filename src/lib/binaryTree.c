#include "./binaryTree.h"

void *make_value(Tree *tree, ...) {
  va_list args;
  va_start(args, tree);
  void *result = tree->make(args);
  va_end(args);

  return result;
}

TreeNode *initNode(Tree *tree, ...) {
  va_list args;
  va_start(args, tree);
  void *value = tree->make(args);
  va_end(args);

  TreeNode *node = calloc(1, sizeof(TreeNode));
  node->father = NULL;
  node->left = NULL;
  node->right = NULL;
  node->value = value;

  return node;
}

Tree *initTree(DataType type) {
  Tree *tree = malloc(sizeof(Tree));
  if (!tree)
    return NULL;

  tree->root = NULL;
  tree->len = 0;
  tree->type = type;

  switch (type) {
  case TYPE_INT:
    tree->cmp = compare_int;
    tree->to_string = int_toString;
    tree->free = free_int;
    tree->make = (void *(*)(va_list))make_int;
    tree->greather = greather_int;
    break;
  case TYPE_FLOAT:
    tree->cmp = compare_float;
    tree->to_string = float_toString;
    tree->free = free_float;
    tree->make = (void *(*)(va_list))make_float;
    tree->greather = greather_float;
    break;
  case TYPE_CHAR:
    tree->cmp = compare_char;
    tree->to_string = char_toString;
    tree->free = free_char;
    tree->make = (void *(*)(va_list))make_char;
    tree->greather = greather_char;
    break;
  default:
    tree->cmp = NULL;
    tree->to_string = NULL;
    tree->free = NULL;
    tree->greather = NULL;
    break;
  }

  return tree;
}

void push(Tree *tree, TreeNode *newNode) {
  if (!tree || !newNode)
    return;

  if (!tree->root) {
    tree->root = newNode;
    tree->len++;
    return;
  }

  TreeNode *curr = tree->root;
  while (curr) {
    if (tree->cmp(newNode->value, curr->value)) {
      // no duplicates
      return;
    } else if (tree->greather(newNode->value, curr->value)) {
      if (!curr->right) {
        curr->right = newNode;
        newNode->father = curr;
        tree->len++;
        return;
      } else {
        curr = curr->right;
      }
    } else {
      if (!curr->left) {
        curr->left = newNode;
        newNode->father = curr;
        tree->len++;
        return;
      } else {
        curr = curr->left;
      }
    }
  }
}

TreeNode *pop(Tree *tree, TreeNode *node) { return NULL; }
