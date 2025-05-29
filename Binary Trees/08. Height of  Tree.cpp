// we can find the height/depth of binary tree by recursion or level order traversal.

//in recursion the auxillary space in worst case is 0(n) and normally o(height). 
//in level order traversal qe have to use queue which uses a o(n) space .

// in mostly recursion is used .

// code:-

// 1. RECURSSIVE:-> ---------------------------------------

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);

        return 1+max(lh,rh);
    }
};
/*
✅ Time Complexity: O(n)
Each node is visited exactly once, so time is linear in the number of nodes.

✅ Space Complexity:
Best/Average Case (Balanced Tree): O(log n) (height of the tree)

Worst Case (Skewed Tree): O(n) (tree is a linked list)


*/



// 2. LEVEL ORDER TRAVERSAL:->---------------------------


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at current level
            level++; // Increment level for each new level

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return level;
    }
};

/*
✅ Time Complexity: O(n)
Again, every node is visited exactly once during traversal.

✅ Space Complexity: O(n)
At most, the queue will contain all nodes at a single level, which in the worst case (for a complete binary tree) is about n/2 nodes.

So, queue size is O(n) in the worst case.
*/