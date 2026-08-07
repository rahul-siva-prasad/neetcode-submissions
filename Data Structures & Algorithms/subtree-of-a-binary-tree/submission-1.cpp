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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!subRoot)
        {
            return true;
        }

        if(!root)
        {
            return false;
        }

        if(f_isSameTree(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }

private:
    bool f_isSameTree(TreeNode* node1_p, TreeNode* node2_p)
    {
        if(!node1_p && !node2_p)
        {
            return true;
        }
        if(node1_p && node2_p && node1_p->val == node2_p->val)
        {
            return f_isSameTree(node1_p->left, node2_p->left) && f_isSameTree(node1_p->right, node2_p->right);
        }
        return false;
    }
};
