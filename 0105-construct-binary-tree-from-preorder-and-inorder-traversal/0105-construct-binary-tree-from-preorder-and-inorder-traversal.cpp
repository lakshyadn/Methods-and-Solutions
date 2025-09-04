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

    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int &preindex, int inindex,int    inorderend, int n){
        
        if (preindex >= n || inindex > inorderend){
            return NULL;
        }
        
        int element = preorder[preindex ];
        TreeNode* temp = new TreeNode(element);
        int pos = findPosition(inorder, element, n);
        preindex++;
        temp -> left = solve(inorder, preorder, preindex, inindex, pos -1, n);
        temp -> right = solve(inorder, preorder, preindex, pos + 1, inorderend, n);
        
        return temp;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex =0;
        int inindex = 0;
        int n = inorder.size();
        TreeNode* ans = solve(inorder, preorder, preindex, inindex, n-1, n);
    
        return ans;
    }
};