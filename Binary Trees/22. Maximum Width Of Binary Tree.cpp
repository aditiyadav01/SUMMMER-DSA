/*
Problem Statement: Given a Binary Tree, return its maximum width. The maximum width of a Binary Tree is the maximum diameter among all its levels. The width or diameter of a level is the number of nodes between the leftmost and rightmost nodes.

Intuition:-

To determine the maximum width of a tree, an effective strategy would be to assign and identify indexes for the leftmost and rightmost nodes at each level. Using these indexes, we can calculate the width for each level by subtracting the index of the leftmost node from that of the rightmost node.


Start by assigning an index to the root node as 0. For each level, the left child gets an index equal to 2 * parent index, and the right child gets an index equal to 2 * parent index + 1. Using a level order traversal, we use the leftmost and rightmost nodes at each level and using their indices, get the width at that level. Keep track of the maximum width encountered during the traversal. Whenever a wider level is found, update the maximum width.

*/


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        long long  ans=0;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            int mini=q.front().second;
            int size=q.size();
            long long  first,last;
            for(int i=0;i<size;i++){
                long long  curr_idx= q.front().second - mini;
                TreeNode* node=q.front().first;
                q.pop();

                if(i==0) first = curr_idx;
                if(i==size-1) last=curr_idx;
                if(node->left){
                    q.push({node->left,curr_idx*2+1});
                }
                if(node->right){
                    q.push({node->right,curr_idx*2+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};

/*Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N).
*/