
// 3.  POSTORDER TRAVERSAL (LEFT + RIGHT + ROOT )

class Solution {
    void postorder(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
        {
            return ;
        }

        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);

    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // lnr
        vector<int> res;
        postorder(root,res);
        return res;
    }
};


// ITERATIVE USING 2 STACK 

class Solution {
   
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        if(root==nullptr) return postorder;

        stack<TreeNode*> st1,st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            
            if(root->left!=nullptr) {
                st1.push(root->left);
            }

            if(root->right!=nullptr) {
                st1.push(root->right);
            }
    
        }

        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};


//ITERATIVE USING 1 STACK


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> postorder;

        if(root==nullptr){
            return postorder;
        }

        TreeNode* curr= root;

        while(curr!=nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty()&&temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }else{
                    curr=temp;
                }
            }
        }
        return postorder;
    }
};

/*✅ Time Complexity:
O(n) – Every node is visited exactly once.

✅ Space Complexity:
Recursive: O(h) → due to function call stack (height of tree).

Iterative (2 stacks):

st1 and st2 may hold n elements together.

Space: O(2n) = O(n).

Iterative (1 stack):

Stack and result vector: up to n nodes.

Space: O(n).
*/

