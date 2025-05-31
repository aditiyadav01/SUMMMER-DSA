/*
Problem Statement: Given a Binary Tree, return the Vertical Order Traversal of it starting from the Leftmost level to the Rightmost level. If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.



Algorithm / Intuition

We assign vertical (x) and level (y) coordinates to each node in a binary tree, where x indicates horizontal position (column) and y indicates depth (level).

We use a nested map structure:
map<x, map<y, multiset<node values>>>
This groups nodes by their vertical and level coordinates, storing values in sorted order using a multiset.

A BFS traversal is performed with a queue that holds nodes along with their (x, y) coordinates. Starting with the root at (0, 0), we enqueue:

Left child as (x-1, y+1)

Right child as (x+1, y+1)

During traversal, we insert each node's value into the map at its (x, y) position.

Finally, we build the result by iterating through the map: for each vertical x, collect and sort values from all levels y to form a column. These columns are added to the final 2D result, representing the vertical order traversal.




*/


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int x=p.second.first;
            int y=p.second.second;

            nodes[x][y].insert(temp->val);

            if(temp->left){
                q.push({temp->left,{x-1,y+1}});
            }
            if(temp->right){
                q.push({temp->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                //vector.insert(position,start_iterator, end_iterator);
                col.insert(col.end(),q.second.begin(),q.second.end()); 

            }

            ans.push_back(col);
        }

        return ans;


    }
};

/*
Time Complexity: O(N * log2N * log2N * log2N) where N represents the number of nodes in the Binary Tree.

Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).
Space Complexity: O(N + N/2) where N represents the number of nodes in the Binary Tree.

The map for storing nodes based on their vertical and level information occupies an additional space complexity of O(N) as it stores all N nodes of the Binary Tree.
The queue for breadth first traversal occupies a space proportional to the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree.
*/