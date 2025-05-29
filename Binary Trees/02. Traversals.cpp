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


 /*
DFS :- Preorder, Inorder , Post order
BFS :- Level order


DFS :- Explore a binary tree by going deeply as possible along each branch before backtracking.
It starts from the root and explore as deeply as possible along each branch, Visiting the nodes untill it reaches the leaf node. it then backtracks to the most recent unexplored node and continues.

BFS :- Explore the Binary Tree Level by Level , Visiting all nodes at a given level before processing to the next level
It starts from the root and visits all nodes at level 0 , then level 1 and so on... Nodes at levels are visited from left to right.alignas

Preorder :- Root , Left , Right
Inorder :- Left , Root , Right
Post Order :- Left , Right , Root
*/



