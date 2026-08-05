/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        int res = 1;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* node_p, int& res)
    {
        if(node_p == nullptr)
        {
            return 0;
        }
        int leftSubTree = dfs(node_p->left, res);
        int rightSubTree = dfs(node_p->right, res);
        if(abs(leftSubTree - rightSubTree) > 1)
        {
            res = 0;
        }

        return 1+ max(leftSubTree, rightSubTree);
    }
};
