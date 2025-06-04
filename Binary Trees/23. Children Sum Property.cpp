/*  TWO TYPES OF QUESTION

1.  Root Equals Sum of Children:-
    You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.

    Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.


    Example 1:

    Input: root = [10,4,6]
    Output: true
    Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
    10 is equal to 4 + 6, so we return true.

*/
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;

        int sum=0;

        if(root->left){
            sum+=root->left->val;
        }
        if(root->right){
            sum+=root->right->val;
        }

        return (sum==root->val)&&checkTree(root->left)&&checkTree(root->right);
    }
};



// 2. SECOND TYPE:-


/*
Problem Statement: Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. The Children Sum Property in a binary tree states that for every node, the sum of its children's values (if they exist) should be equal to the node's value. If a child is missing, it is considered as having a value of 0.

Note:

The node values can be increased by any positive integer any number of times, but decrementing any node value is not allowed.
A value for a NULL node can be assumed as 0.
We cannot change the structure of the given binary tree.
*/

/*Agorithm/Intuition:-
The constraint is that we cannot decrease the value of any node, only increase it. Also, the structure of the binary tree cannot be changed. If we follow a bottom-up approach and try to adjust parent values based on children, we may reach a situation where the sum of children exceeds the parent's value, requiring us to decrease the parent's value, which is not allowed.


With just a bottom-up approach, we cannot guarantee that the Children Sum Property will be satisfied at each level. It might work for some cases but not for all. There's no clear strategy to ensure that the property holds true for the entire tree. A key insight here is that there's no restriction on how much we can increase the value of each node. Hence, we have the flexibility to adjust the values as needed to ensure that the Children Sum Property holds true at every node in the tree.


This means that if the sum of the values of a node's children is less than the node's value, we can simply increase the values of the children (and potentially the grandchildren and so on) until the property is satisfied. Using recursive calls, we traverse the binary tree, addressing each node and its children iteratively. At each step, we calculate the sum of the children's values and compare it with the parent node's value.
*/

  
class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root) {
        // Base case: If the current node
        // is NULL, return and do nothing.
        if (root == NULL) {
            return;
        }

        // Calculate the sum of the values of
        // the left and right children, if they exist.
        int child = 0;
        if (root->left) {
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }

        // Compare the sum of children with
        // the current node's value and update
        if (child >= root->val) {
            root->val = child;
        } else {
            // If the sum is smaller, update the
            // child with the current node's value.
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }

        // Recursively call the function
        // on the left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the
        // values of the left and right
        // children, if they exist.
        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }

        // If either left or right child
        // exists, update the current node's
        // value with the total sum.
        if (root->left or root->right) {
            root->val = tot;
        }
    }
};

/*Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because the algorithm traverses each node exactly once, performing constant-time operations at each node.

Space Complexity: O(N) where N is the number of nodes in the Binary Tree.

In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum height of the tree, resulting in a space complexity of O(N).
In the optimal case of a balanced tree, the auxiliary space would take up space proportional to O(log2N).*/