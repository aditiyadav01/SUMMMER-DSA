
// 2.  INORDER TRAVERSAL (LEFT + ROOT + RIGHT)

class Solution {
    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
        {
            return ;
        }

        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);

    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // lnr
        vector<int> res;
        inorder(root,res);
        return res;
    }
};

// ITERATIVE


class Solution {
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* node= root;
        stack<TreeNode*> st;

        while(true){
            if(node!=nullptr){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }
};

 /*

✅ Time Complexity:
O(n) – Each node is visited once.

✅ Space Complexity:
Recursive: O(h) → call stack, up to height of tree.

Iterative: O(n) → up to n nodes in the stack in worst case (left skewed).*/
