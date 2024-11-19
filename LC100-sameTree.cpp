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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr ^ q == nullptr)
        {
            return false;
        }
        while (p != nullptr)
        {
            if (q == nullptr)
            {
                return false;
            }
            if (p->left != nullptr)
            {
                if (q->left == nullptr)
                {
                    return false;
                }
                TreeNode *rightMost = p->left;
                TreeNode *rightQ = q->left;
                while (rightMost->right != nullptr)
                {
                    rightMost = rightMost->right;
                    if (rightQ->right == nullptr)
                    {
                        return false;
                    }
                    rightQ = rightQ->right;
                }
                if (rightQ->right != nullptr)
                {
                    return false;
                }
                rightMost->right = p;
                rightQ->right = q;
                TreeNode *temp = p;
                TreeNode *tempQ = q;
                p = p->left;
                q = q->left;
                temp->left = nullptr;
                tempQ->left = nullptr;
                // Parents do not need to refer to the new child
                // Cause next round it starts from the child
            }
            else
            {
                if (q->left != nullptr)
                {
                    return false;
                }
                if (p->val != q->val)
                {
                    return false;
                }
                p = p->right;
                q = q->right;
            }
        }
        if (q != nullptr)
        {
            return false;
        }

        return true;
    }
};