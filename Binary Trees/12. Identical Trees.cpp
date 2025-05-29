// we have to check whether the two trees are same or not


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr){
            // if( both null that means equal so it return true but if
            // anyone of them is not null than it  will give false because it is not equal)
            return p==q; 
        }

        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);

        return (p->val==q->val&&left&&right);
    }
};

/*
Time Complexity: O(N+M) where N is the number of nodes in the first Binary Tree and M is the number of nodes in the second Binary Tree. This complexity arises from visiting each node of the two binary nodes during their comparison.

Space Complexity: O(1) as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive Stack Auxiliary Space : The recursion stack space is determined by the maximum depth of the recursion, which is the height of the binary tree denoted as H. In the balanced case it is log2N and in the worst case (its N).*/