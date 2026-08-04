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
    int ans = 0;
private:
    int getHeight(TreeNode* root){
        if(root==NULL) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        ans = max(left+right,ans);
        return max(left,right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);

        return ans;
    }
};
