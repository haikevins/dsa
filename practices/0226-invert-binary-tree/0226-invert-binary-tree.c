/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return NULL;
    }

    // Swap the left and right children
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert the left and right subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}