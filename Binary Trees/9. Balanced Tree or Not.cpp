// A balanced tree is that in which the absolute difference between the left subtree and right subtree is less than equal to 1.

// METHOD:->1---------------------

class Solution {
private:
    int height(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        int lh=height(root->left);
        int rh=height(root->right);

        return 1+max(lh,rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int lh=height(root->left);
        int rh=height(root->right);

        int ans = abs(lh-rh);

        if(ans<=1&&isBalanced(root->left)&&isBalanced(root->right)) return true;
        return false;
    }
};

/*

Time Complexity: O(N2) where N is the number of nodes in the Binary Tree.This arises as we calculate the height of each node and to calculate the height for each node, we traverse the tree which is proportional to the number of nodes. Since this calculation is performed for each node in the tree, the complexity becomes: O(N x N) ~ O(N2).

Space Complexity : O(1) as no additional data structures or memory is allocated.O(H): Recursive Stack Space is used to calculate the height of the tree at each node which is proportional to the height of the tree.The recursive nature of the getHeight function, which incurs space on the call stack for each recursive call until it reaches the leaf nodes or the height of the tree.*/



// METHOD:->2--------------------------------

//in this we will add the conditions in the code of findinng height which will tell us if the tree is balanced or not.


class Solution {
    private:
    int  height (TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        int lh=height(root->left);
        int rh=height(root->right);

        if(abs(lh-rh)>1) return -1;
        if(lh==-1 || rh==-1) return -1;
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};

/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the postorder traversal.

Space Complexity : O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.
*/