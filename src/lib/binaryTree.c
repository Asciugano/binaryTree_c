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

int tree_height(TreeNode *node) {
  if (!node)
    return 0;
  int left = tree_height(node->left);
  int right = tree_height(node->right);
  return (left > right ? left : right) + 1;
}

void fill_levels(Tree *tree, TreeNode *node, int level, int pos, char **lines,
                 int spacing) {
  if (!node)
    return;

  char buffer[32];
  tree->to_string(node->value, buffer);
  int len = (int)strlen(buffer);

  int idx = pos - len / 2;
  if (idx < 0)
    idx = 0;
  if (idx + len > strlen(lines[level])) // meglio usare width, passalo se serve
    len = (int)strlen(lines[level]) - idx;

  for (int i = 0; i < len; i++) {
    lines[level][idx + i] = buffer[i];
  }

  int next_spacing = spacing / 2;
  if (next_spacing < 2)
    next_spacing = 2;

  if (node->left) {
    if (pos - 1 >= 0)
      lines[level + 1][pos - 1] = '/';
    fill_levels(tree, node->left, level + 2, pos - next_spacing, lines,
                next_spacing);
  }

  if (node->right) {
    if (pos + 1 < (int)strlen(lines[level]))
      lines[level + 1][pos + 1] = '\\';
    fill_levels(tree, node->right, level + 2, pos + next_spacing, lines,
                next_spacing);
  }
}

void print_tree(Tree *tree) {
  if (!tree || !tree->root || tree->len == 0) {
    printf("[empty]\n");
    return;
  }

  int height = tree_height(tree->root);
  int width = (1 << height) * 3;
  int lines_count = height * 2 - 1;

  char **lines = malloc(sizeof(char *) * lines_count);
  for (int i = 0; i < lines_count; i++) {
    lines[i] = calloc(width + 1, sizeof(char));
    memset(lines[i], ' ', width);
    lines[i][width] = '\0';
  }

  fill_levels(tree, tree->root, 0, width / 2, lines, width / 4);

  for (int i = 0; i < lines_count; i++) {
    printf("%s\n", lines[i]);
    free(lines[i]);
  }
  free(lines);
}
