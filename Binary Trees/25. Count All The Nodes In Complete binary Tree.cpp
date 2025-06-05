/*Problem Statement: Given a Complete Binary Tree, count and return the number of nodes in the given tree. A Complete Binary Tree is a binary tree in which all levels are completely filled, except possibly for the last level, and all nodes are as left as possible.*/

/*METHOD 1:- BRUTE FORCE*/


class Solution {
    private:
    void inorder(TreeNode* root,int &count){
        if(!root) return;
        count++;

        inorder(root->left,count);
        inorder(root->right,count);
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int count=0;
        inorder(root,count);
        return count;
    }
};
/*Complexity Analysis

Time Complexity: O(N) where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once.

Space Complexity : O(N) where N is the number of nodes in the binary tree. This is because the recursive stack uses an auxiliary space which can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes. In the average case or for a balanced tree, the maximum number of nodes that could be in the stack at any given time would be roughly the height of the tree hence O(log2N).
*/

/*METHOD 2:- OPTIMAL APPROACH 

Algorithm / Intuition
Given that the binary is a complete binary tree, we can exploit its properties to optimise the algorithm and achieve a better time complexity. In a complete binary tree, the last level may not be completely filled, but the nodes are positioned from left to right. This property allows us to determine the number of nodes using just the height. The relationship between the height of the binary tree (h) and the maximum number of nodes it can have, denoted by the formula: Maximum Number of Nodes: 2^h-1

If the last level of a binary tree is perfectly filled, known as a perfect binary tree, the count of nodes can be determined by the formula: 2h-1, where h is the height. To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.


If the left height equals right height, it indicates that the last level is completely filled.
If the left height does not equal right height, the last level is not completely filled.
In the case where left height and right height differ, we can employ a recursive approach. We recursively calculate the number of nodes in the left subtree and in the right subtree , and then return the total count as 1 + leftNodes + rightNodes. If the height of the left subtree is equal to the height of the right subtree, we can directly calculate using the 2h-1 formula.


*/

class Solution {
    private:
    int leftHeight(TreeNode* node){
        int cnt=0;
        while(node){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    int rightHeight(TreeNode* node){
        int cnt=0;
        while(node){
            cnt++;
            node=node->right;
        }
        return cnt;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh=leftHeight(root);
        int rh=rightHeight(root);

        if(lh==rh) return (1<<lh)-1;

        return 1+countNodes(root->left) + countNodes(root->right);
    }
};

/*Complexity Analysis

Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree.

The calculation of leftHeight and rightHeight takes O(log N) time.
In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).
Therefore, the total time complexity is O(log N * log N).
Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree.

The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.
Since the given tree is a complete binary tree, the height will always be log N.
Therefore, the space complexity is O(log N).*/
