/*
Problem Statement:
 Given a Binary Tree, convert it to a Linked List where the linked list nodes follow the same order as the pre-order traversal of the binary tree.

Use the right pointer of the Binary Tree as the ‘next’ pointer for the linked list and set the left pointer to null. Do this in place and do not create extra nodes.
*/

// METHOD 1: BRUTE FORCE:-


class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
       if(root==NULL){
           return;
       }

       flatten(root->right);
       
       flatten(root->left);
       root->right = prev;

       root->left = NULL;

       prev = root;
    }
};

/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. Each node of the binary node is visited exactly once. At each node, constant-time operations are performed. Hence the time complexity is O(N).

Space Complexity : O(log2N)where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).
*/


//METHOD : 2 



class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        stack<TreeNode*> st;
        st.push(root);  
        
        while (!st.empty()) {  
            TreeNode* cur = st.top(); 
            st.pop();  

            if (cur->right != NULL) {
                st.push(cur->right); 
            }
            
            if (cur->left != NULL) {
                st.push(cur->left); 
            }

            if (!st.empty()) {
                cur->right = st.top();  
            }
            
            cur->left = NULL;  
        }
    }
};

/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. Each node of the binary node is visited exactly once. At each node, constant-time operations are performed. Hence the time complexity is O(N).

Space Complexity : O(log2N) where N is the number of nodes in the Binary Tree. There are no additional data structures or space used but the auxiliary stack space is used during recursion. Since the recursion depth can be at most equal to the height to the Binary Tree, the space complexity is O(H) where H is the height of the Binary Tree. In the ideal case, H = log2N and in the worst case H = N (skewed tree).
*/


//METHOD 3:-


class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) 
            if (curr->left) {
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                pre->right = curr->right;

                curr->right = curr->left;

                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};

/*
Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.

The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.
Space Complexity: O(1) The space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.

Morris Traversal does not use any additional data structures like stacks or recursion, making it an in-place algorithm.
The only space utilised is for a few auxiliary variables, such as pointers to current and in-order predecessor nodes.
*/