struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *prev = nullptr;
    bool isValidBST(TreeNode *root)
    {
        return inorder(root);
    }

    // left < mid < right
    bool inorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (!inorder(root->left))
        {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val)
        {
            return false;
        }
        prev = root;
        return inorder(root->right);
    }
};