#include <stack>
#include <queue>

using namespace std;
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }

    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int depth = 1;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (!curr->left && !curr->right)
                {
                    return depth;
                }

                if (curr->left)
                {
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            depth++;
        }
        return depth;
    }

    bool helper(TreeNode *root, long long minVal, long long maxVal)
    {
        if (!root)
        {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal)
        {
            return false;
        }

        return helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }

    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }

        if (!left || !right)
        {
            return false;
        }

        if (left->val != right->val)
        {
            return false;
        }

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        return isMirror(root->left, root->right);
    }
};