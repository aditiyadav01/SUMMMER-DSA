/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


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

 /*2. 

✅ Time Complexity:
O(n) – Each node is visited once.

✅ Space Complexity:
Recursive: O(h) → call stack, up to height of tree.

Iterative: O(n) → up to n nodes in the stack in worst case (left skewed).*/




// 2.  POSTORDER TRAVERSAL (LEFT + RIGHT + ROOT )

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


//  LEVEL ORDER TRAVERSAL


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        if(root==nullptr){
            return  ans;
        }

        while(!q.empty()){
            int size=q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val); 
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                
            }

            ans.push_back(level);
        }
        return ans;
    }
};

/*
✅ Time Complexity:
O(n) – All nodes are visited once.

✅ Space Complexity:
O(n) – At most all nodes at the last level (≈ n/2) are in the queue at once.

So queue size can be up to O(n) in worst case.
*/



// ALL TRAVERSALS IN ONE ( PREORDER, POSTORDER, INORDER)


vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}

/*
✅ Time Complexity:
O(3n)

Each node is:

Pushed and popped from the stack

Recorded in pre, in, and post (total 3 operations)

So total = 3n operations

✅ Space Complexity:
O(4n):

Stack stores up to n nodes (worst case) ⇒ O(n)

3 vectors (pre, in, post), each of size n ⇒ O(3n)

So total = O(n + 3n) = O(4n)


*/


