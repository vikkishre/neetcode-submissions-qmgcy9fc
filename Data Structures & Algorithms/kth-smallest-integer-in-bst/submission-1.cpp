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
    vector<int> inorder_vector;
    void In_order(TreeNode* root)
    {
        if(root==NULL)
            return;
        In_order(root->left);
        inorder_vector.push_back(root->val);
        In_order(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        In_order(root);
        return inorder_vector[k-1];
    }
};
