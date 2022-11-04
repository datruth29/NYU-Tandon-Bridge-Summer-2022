#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
bool isSameTree(TreeNode *p, TreeNode *q);
bool isSymmetric(TreeNode* root);
bool _isSymmetric(TreeNode* left, TreeNode* right);
void levelOrder(TreeNode* root);

int main()
{

    TreeNode j(10);
    j.left = new TreeNode(20);
    j.right = new TreeNode(30);

    TreeNode i(10);
    i.left = new TreeNode(30);
    i.right = new TreeNode(20);

    TreeNode h(10);
    h.left = &j;
	h.right = &i;
    

    std::cout << isSameTree(&j, &h) << '\n';
    std::cout << isSymmetric(&h) << '\n';
    levelOrder(&h);

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
    if (root->left == nullptr || root->right == nullptr)
    {
        return false;
    }

    return _isSymmetric(root->left, root->right);

}

bool _isSymmetric(TreeNode* left, TreeNode* right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }

    if (left == nullptr || right == nullptr)
    {
        return false;
    }

    if (left->val != right->val)
    {
        return false;
    }

	return _isSymmetric(left->left, right->right)
        && _isSymmetric(left->right, right->left);

}
// Given a binary tree, implement level order traversal
void levelOrder(TreeNode *root)
{
    std::queue<TreeNode*> tree_queue;
    std::queue<TreeNode*> level_queue;

    tree_queue.push(root);

    while (!tree_queue.empty())
    {
        tree_queue.swap(level_queue);
        while (!level_queue.empty())
        {
			TreeNode* node = level_queue.front();
			level_queue.pop();

            if (node->left != nullptr)
                tree_queue.push(node->left);
            if (node->right!= nullptr)
                tree_queue.push(node->right);
			
			std::cout << node->val << ' ';
        }
        std::cout << '\n';

    }
}