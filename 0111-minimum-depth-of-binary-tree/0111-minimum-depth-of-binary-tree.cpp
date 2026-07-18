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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int ldepth = minDepth(root->left);
        int rdepth = minDepth(root->right);

        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        if(root->left == nullptr){
            return (rdepth+1);
        }
        if(root->right == nullptr){
            return (ldepth + 1);
        }
        return min(ldepth , rdepth) + 1;
    }
};