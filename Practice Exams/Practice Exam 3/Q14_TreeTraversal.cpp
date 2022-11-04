#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
bool isSameTree(TreeNode *p, TreeNode *q);

int main()
{
    TreeNode h(10);
    h.left = new TreeNode(30);
    h.right = new TreeNode(20);

    TreeNode j(10);
    j.left = new TreeNode(30);

    std::cout << isSameTree(&j, &h);

}
// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical
// and the nodes have the same value.
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if (p == nullptr || q == nullptr)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }

    bool left_side = isSameTree(p->left, q->left);
    if (!left_side)
    {
        return false;
    }

    bool right_side = isSameTree(p->right, q->right);
    if (!right_side)
    {
        return false;
    }

    return true;

    // TODO
}
// Given a binary tree, check whether it is a mirror of itself
// (ie, symmetric around its center).
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    // TODO
}
// Given a binary tree, implement level order traversal
void levelOrder(TreeNode *root)
{
    // TODO
}