#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        q.push(root);

        std::vector<std::vector<int>> ans;
        if (root == nullptr)
            return ans;
        while (!q.empty())
        {
            std::vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }
            ans.push_back(level);
        }

        return ans;
    }
};