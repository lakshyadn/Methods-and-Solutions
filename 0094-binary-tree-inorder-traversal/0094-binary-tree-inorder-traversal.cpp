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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;

        while(curr != nullptr){
            if (curr -> left == nullptr){
                res.push_back(curr -> val);
                curr = curr -> right;
            }

            else{
                TreeNode* pred = curr -> left;
                while (pred -> right != nullptr && pred -> right != curr){
                    pred = pred -> right;
                }

                if (pred -> right == nullptr){
                    pred -> right = curr;
                    curr = curr -> left;
                }
                else{
                    pred -> right = nullptr;
                    res.push_back(curr -> val);
                    curr = curr -> right;
                }
            }

        }
        return res;
    }
};