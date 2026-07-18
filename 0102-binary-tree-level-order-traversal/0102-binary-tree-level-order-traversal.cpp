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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        queue<TreeNode* > q;
        vector<vector<int>> res;

        q.push(root);
        int curr_level = 0;

        while(!q.empty()){

            int len = q.size();
            res.push_back({});

            for(int i=0; i<len; i++){
                TreeNode* curr = q.front();
                q.pop();

                res[curr_level].push_back(curr->val);

                if(curr->left != nullptr){
                    q.push(curr->left);
                    }
                if(curr->right != nullptr){
                    q.push(curr->right);
                    }
                }
            curr_level++;
        }
        return res;
    }
};