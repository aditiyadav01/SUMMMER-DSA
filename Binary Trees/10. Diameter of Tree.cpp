// maximum distance between any two node is called diameter


class Solution {
private:
    int height(TreeNode* root,int& d) {
        if(root==nullptr){
            return 0;
        }

        int lh=height(root->left,d);
        int rh=height(root->right,d);

        d=max(d,lh+rh);

        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;

        height(root,diameter);

        return diameter;
    }
};

/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.
*/