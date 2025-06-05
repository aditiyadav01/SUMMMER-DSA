/*Problem Statement: 
Given a Binary Tree, design an algorithm to serialise and deserialise it. There is no restriction on how the serialisation and deserialization takes place. But it needs to be ensured that the serialised binary tree can be deserialized to the original tree structure. Serialisation is the process of translating a data structure or object state into a format that can be stored or transmitted (for example, across a computer network) and reconstructed later. The opposite operation, that is, extracting a data structure from stored information, is deserialization.
*/


/*
Serialisation:
Step 1: Check if the tree is empty: If the root is null, return an empty string.

Step 2: Initialise an empty string: This string will store the serialised binary tree.

Step 3: Use a queue for level-order traversal: Initialise a queue and enqueue the root.


Step 4: Within the level-order traversal loop:

Dequeue a node from the queue.
If the node is null, append "#" to the string.
If the node is not null, append its data value along with a ‘,’ (comma) to the string. This comma acts as a delimiter that separates the different node values in the string. Enqueue its left and right children.

Step 5: Return the final string containing the serialised representation of the tree.

Deserialization:
Step 1:Check if the serialised data is empty: If it is, return null.

Step 2: Tokenize the serialised data: Use a stringstream to tokenize the input string using the comma as a delimiter.

Step 3: Read the root value: Read the first token and create the root node with this value.

Step 4: Use a queue for level-order traversal: Initialise a queue and enqueue the root.


Step 5: Within the level-order traversal loop:

Dequeue a node from the queue.
Read the value for the left child from the stringstream.
If it is "#", set the left child to null. If it's not "#", create a new node with the value and set it as the left child.
Read the next value in the stringstream for the right child.
If it is "#", set the right child to null. If it's not "#", create a new node with the value and set it as the right child.
Enqueue the left and right children into the queue for further traversal.

Step 6: Return the reconstructed root: The final result is the root of the reconstructed tree.
*/


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            if (curNode == nullptr) {
                s += "#,";
            } else {
                s += to_string(curNode->val) + ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

/*Complexity Analysis

Time Complexity: O(N)

serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.
deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.
Space Complexity: O(N)

serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.
deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.
*/