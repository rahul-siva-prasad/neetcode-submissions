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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return nullptr;
        }

        queue<TreeNode*> que_p;
        que_p.push(root);
        while(!que_p.empty())
        {
            TreeNode* node_p = que_p.front();
            que_p.pop();
            swap(node_p->left, node_p->right);
            if(node_p->left)
            {
                que_p.push(node_p->left);
            }
            if(node_p->right)
            {
                que_p.push(node_p->right);
            }
        }
        return root;
        
    }
};
