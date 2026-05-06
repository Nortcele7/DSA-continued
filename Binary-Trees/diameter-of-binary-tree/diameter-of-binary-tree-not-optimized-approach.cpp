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

    int height(TreeNode* root)
    {

        int leftHeight, rightHeight;

        if(root==NULL)
        {
            return 0;
        }

        leftHeight = height(root->left);
        rightHeight = height(root->right);

        return max(leftHeight, rightHeight)+1;

    }

    int diameter(TreeNode* root)
    {
        int leftDiam, rightDiam, currDiam;

        if(root==NULL)
        {
            return 0;
        }

        leftDiam = diameter(root->left);
        rightDiam = diameter(root->right);

        currDiam = height(root->left)+height(root->right);

        int max1 = max(leftDiam, rightDiam);
        return max(max1, currDiam);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        return diameter(root);

    }
};