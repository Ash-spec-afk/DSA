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
    private:
        int countNodes(TreeNode* root){
            if(root == nullptr){
                return 0;
            }
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    
    private:
        bool isCompleteUtil(TreeNode* root, int index, int num_nodes){
            if(root == nullptr){
                return true;
            }

            if(index >= num_nodes){
                return false;
            }
            return isCompleteUtil(root->left, 2*index+1, num_nodes) && 
                    isCompleteUtil(root->right, 2*index+2, num_nodes);
        }
public:
    bool isCompleteTree(TreeNode* root) {
        int nodes = countNodes(root);
        if(isCompleteUtil(root, 0, nodes)){
            return true;
        }
        return false;
    }
};