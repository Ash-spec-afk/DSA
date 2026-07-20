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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr || x == y){
            return false;
        }

        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int len = q.size();

            bool xfound = false;
            bool yfound = false;

            for(int i=0; i<len; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->val == x){
                    xfound = true;
                }
                if(curr->val == y){
                    yfound = true;
                }

                if(curr->left && curr->right){
                    int left = curr->left->val;
                    int right = curr->right->val;

                    if((left == x && right == y )||(left == y && right == x)){
                        return false;
                    }
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(xfound && yfound){
                return true;
            }
            if(xfound || yfound){
                return false;
            }
        }
        return false;
    }
};