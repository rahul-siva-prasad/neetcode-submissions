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
        stack<pair<TreeNode*,int>> stk;
        stk.push({root,1});
        int maxDepth = 0;

        while(! stk.empty())
        {
            pair<TreeNode*,int> stkTop = stk.top();
            stk.pop();
            TreeNode* node_p = stkTop.first;
            int currDepth = stkTop.second;

            if(node_p != nullptr)
            {
                maxDepth = max(maxDepth, currDepth);
                stk.push({node_p->left, currDepth+1});
                stk.push({node_p->right, currDepth+1});
            }
        }
        return maxDepth;
    }
};
