#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical
// and the nodes have the same value.
bool isSameTree(TreeNode *p, TreeNode *q)
{
    bool value_check = (p->val == q->val);
    if (p->val != q->val)
    {
        return false;
    }
    if (p->val)

    // TODO
}
// Given a binary tree, check whether it is a mirror of itself
// (ie, symmetric around its center).
bool isSymmetric(TreeNode *root)
{
    // TODO
}
// Given a binary tree, implement level order traversal
void levelOrder(TreeNode *root)
{
    // TODO
}