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
    int maxDepth(TreeNode* root) 
    {
        return f_dfs(root);
    }
private:
    int f_dfs(TreeNode* node_p)
    {
        if(node_p == nullptr)
        {
            return 0;
        }
        return 1+max(f_dfs(node_p->left), f_dfs(node_p->right));
    }
};
