#pragma once

typedef struct TreeNode {
  struct TreeNode *father;
  struct ThreeNode *left;
  struct ThreeNode *right;
} TreeNode;
