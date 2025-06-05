/* SAME:- LEETCODE 2385 :- Amount of Time for Binary Tree to Be Infected
Problem Statement:
Given a binary tree and a target node, the tree burns in the following way:
At time 0, the target node catches fire.
Every second, the fire spreads to the adjacent nodes: left child, right child, and parent.
Your task is to determine the minimum time required to burn the entire binary tree.
 */

 template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T val) {
        data = val;
        left = right = nullptr;
    }
};

// Step 1: Map parent pointers and locate the target node
BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>* root, 
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mpp, int start) {

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    BinaryTreeNode<int>* res = nullptr;

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); q.pop();

        if (node->data == start) res = node;

        if (node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }

        if (node->right) {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }

    return res;
}

// Step 2: BFS to find maximum distance from target (simulate burning)
int findMaxDistance(map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mpp, 
    BinaryTreeNode<int>* target) {

    queue<BinaryTreeNode<int>*> q;
    q.push(target);

    map<BinaryTreeNode<int>*, int> vis;
    vis[target] = 1;

    int maxi = 0;

    while (!q.empty()) {
        int sz = q.size();
        int fl = 0; // flag to check if fire spreads this second

        for (int i = 0; i < sz; i++) {
            auto node = q.front(); q.pop();

            if (node->left && !vis[node->left]) {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }

            if (node->right && !vis[node->right]) {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }

            if (mpp[node] && !vis[mpp[node]]) {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }

        if (fl == 1) maxi++;
    }

    return maxi;
}

// Main function
int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp;
    BinaryTreeNode<int>* target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

/*
Time Complexity
The code consists of two main traversals of the binary tree:

1. bfsToMapParents():
We do a BFS traversal of the entire tree to:

Map each node to its parent.

Find the node from where fire starts.

✅ This takes O(n) time, where n is the number of nodes.

2. findMaxDistance():
Another BFS traversal starting from the target node.

We may end up visiting every node once, to simulate the fire spreading.

✅ This also takes O(n) time.

✅ Total Time Complexity:O(n)

✅ Space Complexity
We use space for:

1. mpp (parent map):
Stores each node’s parent.

✅ O(n)

2. vis (visited map):
Keeps track of visited (burned) nodes.

✅ O(n)

3. queue for BFS:
In worst case, it can hold up to n/2 nodes (last level of binary tree).

✅ O(n)

✅ Total Space Complexity:O(n)

*/