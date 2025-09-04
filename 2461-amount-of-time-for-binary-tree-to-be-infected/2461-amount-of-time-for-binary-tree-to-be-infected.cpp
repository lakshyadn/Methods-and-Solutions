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
    TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodeToParent ){
        
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while (!q.empty()){
            
            TreeNode* front = q.front();
            q.pop();
            
            if (front -> val == target){
                res = front;
            }
            if (front -> left){
                nodeToParent[front -> left] = front;
                q.push(front->left);
            }
            if (front -> right){
                nodeToParent[front -> right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    int burntree(TreeNode* root,map<TreeNode*, TreeNode*> &nodeToParent ){
        
        int ans = 0;
        
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(root);
        visited[root] = true;
        
        while (!q.empty()){
            
            int flag = 0;
            int size = q.size();
            
            for (int i = 0; i < size; i++){
                
                TreeNode* front = q.front();
                q.pop();
                
                if (front -> left && visited[front -> left] != true){
                    visited[front->left] = true;
                    q.push(front-> left);
                    //flag to determine that there is a entry so we can incrase 1 sec into time;
                    flag = 1;
                }
                
                if (front -> right && visited[front -> right] != true){
                    visited[front->right] = true;
                    q.push(front-> right);
                    //flag to determine that there is a entry so we can incrase 1 sec into time;
                    flag = 1;
                }
                if (nodeToParent[front] && visited[nodeToParent[front]] != true){
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                    flag = 1;
                }
            }
            if (flag == 1 ){
                ans++;
            }
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetnode = createParentMapping(root, start , nodeToParent);
        
        int ans  = burntree(targetnode, nodeToParent);
        
        return ans;

    }
};