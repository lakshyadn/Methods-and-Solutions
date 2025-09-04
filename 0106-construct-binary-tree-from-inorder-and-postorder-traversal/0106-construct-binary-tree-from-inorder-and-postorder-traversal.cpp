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
    int findPosition(vector<int> &inorder, int element, int n){
        
        for (int i = 0; i< n; i++){
            if (inorder[i]== element){
                return i;
            }
        }
        return -1; 
    }

    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &postindex, int inindex, int inorderend, int n){
        
        if (postindex < 0 || inindex >  inorderend){
            return NULL;
        }
        
        int element = postorder[postindex];
        TreeNode* temp = new TreeNode(element);
        int pos = findPosition(inorder, element, n);
        postindex--;
        temp -> right = solve(inorder, postorder, postindex, pos + 1, inorderend, n);
        temp -> left = solve(inorder, postorder, postindex, inindex, pos -1, n);
        
        return temp;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postindex = n -1;
        int inindex = 0;
        
        TreeNode* ans = solve(inorder, postorder, postindex, inindex, n-1, n);
    
        return ans;
    }
};