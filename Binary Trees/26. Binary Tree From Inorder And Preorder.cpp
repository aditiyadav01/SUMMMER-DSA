/*Problem Statement: Given the Preorder and Inorder traversal of a Binary Tree, construct the Unique Binary Tree represented by them.*/


class Solution {
public:
    // Function to build a binary tree
    // from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        // Create a map to store indices
        // of elements in the inorder traversal
        map<int, int> inMap;
        
        // Populate the map with indices
        // of elements in the inorder traversal
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        
        // Call the private helper function
        // to recursively build the tree
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        
        return root;
    }

private:
    // Recursive helper function to build the tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
                // Base case: If the start indices 
                // exceed the end indices, return NULL
                if(preStart > preEnd || inStart > inEnd){
                    return NULL;
                }
                
                // Create a new TreeNode with value
                // at the current preorder index
                TreeNode* root = new TreeNode(preorder[preStart]);
                
                // Find the index of the current root
                // value in the inorder traversal
                int inRoot = inMap[root->val];
                
                // Calculate the number of
                // elements in the left subtree
                int numsLeft = inRoot - inStart;
                
                // Recursively build the left subtree
                root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, 
                                inorder, inStart, inRoot - 1, inMap);
                
                // Recursively build the right subtree
                root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, 
                                inorder, inRoot + 1, inEnd, inMap);
                
                // Return the current root node
                return root;
            }
};

/*Complexity Analysis

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This is because each node of the Binary Tree is visited once.

Space Complexity: O(N) where N is the number of nodes in the Binary Tree. The inorder hashmap to store the inorder array for fast lookup takes up space proportional to the input nodes. An auxiliary stack space ~ O(H) where H is the height of the Binary Tree is used. This is the stack space used to build the tree recursively. In the case of a skewed tree, the height of the tree will be H ~ N hence the worst case auxiliary space is O(N).
*/