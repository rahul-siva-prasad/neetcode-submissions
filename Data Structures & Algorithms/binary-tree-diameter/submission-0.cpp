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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int res=0;
        f_dfs(root, res);
        return res;
    }

private:
    int f_dfs(TreeNode* node_p, int& res)
    {
        if(node_p == nullptr)
        {
            return 0;
        }
        int leftSubTreeHeight  = f_dfs(node_p->left, res);
        int rightSubTreeHeight = f_dfs(node_p->right, res);
        res = max(res, leftSubTreeHeight + rightSubTreeHeight);
        return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    }
};
