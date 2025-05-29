
/*
Base Case: When the current node is null which indicates the end of a path or a lead node, we return the maximum path sum as 0.

Recursive Function:

Calculate the maximum path sum for the left and right subtrees by making recursive calls to the left and right child of the current node.
Calculate the maximum path sum when the current node serves as the turning point: Maximum Path Sum when Current Node is Turning Point = Maximum Path Sum of Left Subtree + Maximum Path Sum of Right Subtree + Current Value of Node
Update the overall maximum path sum (maxi) by considering the sum of the current node and the left and right subtree sums.
Return the maximum sum considering only one branch (either left or right) along with the value of the current node as the maximum sum up until this node.



*/



class Solution {
    private:
    int findMaxPath(TreeNode* root,int &maxi){
        if(root==nullptr) return 0;

        int leftMaxPath=max(0,findMaxPath(root->left,maxi));
        int rightMaxPath=max(0,findMaxPath(root->right,maxi));

        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);

        return max(leftMaxPath, rightMaxPath) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;

        findMaxPath(root,maxi);
        return maxi;

    }
};

/*

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the recursive traversal.

Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.

*/