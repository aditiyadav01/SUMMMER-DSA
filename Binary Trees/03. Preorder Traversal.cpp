// 1. PREORDER TRAVERSAL (ROOT + LEFT + RIGHT)

class Solution {
    void preorder(TreeNode* root,vector<int>& ans)
    {
        if(root==nullptr)
        {
            return;
        }

        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};



//ITERATIVE 

class Solution {
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root==nullptr) return preorder;

        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val); 

            if(root->right!=nullptr) {
                st.push(root->right);
            }
            if(root->left!=nullptr) {
                st.push(root->left);
            }
    
        }
        return preorder;
    }
};

/*✅ Time Complexity:
O(n) – Each node is visited once.

✅ Space Complexity:
Recursive: O(h) → worst-case O(n) if skewed tree (due to call stack).

Iterative: O(n) → in the worst case, all nodes can be in the stack (like in a skewed tree).
*/

