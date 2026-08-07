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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({p,q});

        while(!stk.empty())
        {
            pair<TreeNode*, TreeNode*> treeNode = stk.top();
            stk.pop();
            if(!treeNode.first && !treeNode.second)
            {
                continue;
            }
            if(!treeNode.first || !treeNode.second || treeNode.first->val != treeNode.second->val)
            {
                return false;
            }
            stk.push({treeNode.first->left, treeNode.second->left});
            stk.push({treeNode.first->right, treeNode.second->right});
        }
        return true;
    }
};
