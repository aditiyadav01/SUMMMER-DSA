
// in this we first have to traverse from left to right then right to left and we have done this like level order traversal and the only difference is that we have to take a boolean to check whether to push them from right to left or left to right.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool left2right=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> level(size);

            for(int i=0;i<size;i++)
            {
                TreeNode* node= q.front();
                q.pop();
                int index;

                if(left2right){
                    index=i;
                }
                else{
                    index=size-1-i;
                }
                level[index]=node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            left2right=!left2right;
            ans.push_back(level);
        }
        
        return ans;

    }
};
/*
Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.
*/