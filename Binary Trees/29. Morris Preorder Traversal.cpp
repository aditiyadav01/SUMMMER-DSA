/*
Problem Statement:
Given a Binary Tree, implement Morris Preorder Traversal and return the array containing its preorder sequence.

Morris Preorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure. The algorithm should efficiently visit each node in the binary tree in preorder sequence, printing or processing the node values as it traverses, without using a stack or recursion.


 Intuition:-

A prerequisite to this problem is Morris Inorder Traversal of Binary Tree. We extend Morris Inorder Traversal to Preorder Morris Traversal and modify the algorithm to print the current node’s value before moving to the left child when the right child of the inorder predecessor is null.

This change ensures that the nodes are processed in the desired order for Preorder Traversal. The basic structure of Morris Traversal remains intact, but the printing step is adjusted, resulting in a Preorder Traversal that is still in-place and has a constant space complexity.


In Morris Inorder Traversal, we are traversing the tree in the way: Left, Root, Right. In Morris Preorder traversal we want to traverse the tree in the way: Root, Left, Right. Therefore, the following code changes are required:

1. When the current node has a left child:

In Morris Inorder Traversal, a new thread is created by establishing a temporary link between the current node and its in-order predecessor. In Morris Preorder Traversal, we want to print the root before visiting the left child. Therefore, after setting the thread (establishing the link), we print the current node's value before moving it to its left child.


2. When the current node has no left child:

This case remains unchanged from Morris Inorder Traversal. If the current node has no left child, there is nothing to visit on the left side. In both Inorder and Preorder traversals, we want to print the current node's value and move to the right child. Therefore, there is no code modification needed for this scenario.
*/


class Solution {
public:
    vector<int> getPreorder(TreeNode* root) {
        vector<int> preorder;
        
        TreeNode* cur = root;
        while (cur != NULL) {
            // If the current node
            // has no left child
            if (cur->left == NULL) {
                // Add the value of the
                // current node to the preorder vector
                preorder.push_back(cur->val);
                
                // Move to the right child
                cur = cur->right;
            } else {
                // If the current node has a left child
                // Create a pointer to traverse to the
                // rightmost node in the left subtree
                TreeNode* prev = cur->left;
                
                // Traverse to the rightmost node in the
                // left subtree or until we find a node 
                // whose right child is not yet processed
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the right child of the
                // rightmost node is NULL
                if (prev->right == NULL) {
                    // Set the right child of the
                    // rightmost node to the current node
                    prev->right = cur;
                    
                    // Move to the left child
                    cur = cur->left;
                } else {
                    // If the right child of the
                    // rightmost node is not NULL
                    // Reset the right child to NULL
                    prev->right = NULL;
                    
                    // Add the value of the
                    // current node to the preorder vector
                    preorder.push_back(cur->val);
                    
                    // Move to the right child
                    cur = cur->right;
                }
            }
        }
        
        return preorder;
    }
};

/*Complexity Analysis

Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.

The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.
Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.

Morris Traversal does not use any additional data structures like stacks or recursion, making it an in-place algorithm.
The only space utilised is for a few auxiliary variables, such as pointers to current and in-order predecessor nodes.*/