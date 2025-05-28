
//  LEVEL ORDER TRAVERSAL


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        if(root==nullptr){
            return  ans;
        }

        while(!q.empty()){
            int size=q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val); 
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                
            }

            ans.push_back(level);
        }
        return ans;
    }
};

/*
✅ Time Complexity:
O(n) – All nodes are visited once.

✅ Space Complexity:
O(n) – At most all nodes at the last level (≈ n/2) are in the queue at once.

So queue size can be up to O(n) in worst case.
*/

