/*
Problem Statement: Given a Binary Tree, determine whether the given tree is symmetric or not. A Binary Tree would be Symmetric, when its mirror image is exactly the same as the original tree. If we were to draw a vertical line through the centre of the tree, the nodes on the left and right side would be mirror images of each other.

Algorithm / Intuition:-

A tree is said to be symmetric when its structure exhibits a mirroring pattern, meaning that the left and right subtrees of any node are identical or mirror images of each other. In other words, if you could draw a vertical line through the centre of the tree, the nodes on the left side should be symmetrically aligned with the nodes on the right side.


For a binary tree to be symmetric:

The root node and its two subtrees (left and right) must have the same value.
The left subtree of the root should be a mirror image of the right subtree.
This mirroring should be consistent throughout the entire tree, not just at the root level.
When recursively checking the left and right subtrees for symmetry in a binary tree, the traversals are mirrored. Specifically, the algorithm compares the left child of the left subtree with the right child of the right subtree and the right child of the left subtree with the left child of the right subtree.

*/



class Solution {
private:
    // Function to check if
    // two subtrees are symmetric
    bool isSymmetricUtil(Node* root1, Node* root2) {
        // Check if either subtree is NULL
        if (root1 == NULL || root2 == NULL) {
            // If one subtree is NULL, the other
            // must also be NULL for symmetry
            return root1 == root2;
        }
        // Check if the data in the current nodes is equal
        // and recursively check for symmetry in subtrees
        return (root1->data == root2->data)
            && isSymmetricUtil(root1->left, root2->right)
            && isSymmetricUtil(root1->right, root2->left);
    }

public:
    // Public function to check if the
    // entire binary tree is symmetric
    bool isSymmetric(Node* root) {
        // Check if the tree is empty
        if (!root) {
            // An empty tree is
            // considered symmetric
            return true;
        }
        // Call the utility function
        // to check symmetry of subtrees
        return isSymmetricUtil(root->left, root->right);
    }
};

/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the traversal and the function compares the nodes in a symmetric manner.

Space Complexity: O(1) as no additional data structures or memory is allocated.

O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.
The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.
*/