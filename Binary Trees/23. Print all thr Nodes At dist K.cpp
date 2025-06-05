/*Problem :-
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
ex:-
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

✅ Intuition:-
We can't solve this by just going down the tree from the target node — we also need to go up (to the parent) which requires knowing each node’s parent. Here's the high-level strategy:

🧠 Steps / Intuition

1. Mark Parent Nodes (1st BFS):

Do a level order traversal to store the parent of every node in a map.

This is necessary because binary trees don't have a built-in reference to their parent.

2. BFS from Target (2nd BFS):

From the target node, explore all neighbors (left child, right child, and parent).

Use BFS to go k levels from the target.

Use a visited map to avoid cycles.

3. Collect Result:

After reaching level k, all the nodes in the queue are at that distance.

*/

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* target) {
    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* current = queue.front(); queue.pop();

        if (current->left) {
            parent_track[current->left] = current;
            queue.push(current->left);
        }

        if (current->right) {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track;  // node -> parent
    markParents(root, parent_track, target);          // step 1

    unordered_map<TreeNode*, bool> visited;           // step 2
    queue<TreeNode*> queue;
    queue.push(target);
    visited[target] = true;
    int current_level = 0;

    while (!queue.empty()) {
        int size = queue.size();
        if (current_level++ == k) break;

        for (int i = 0; i < size; i++) {
            TreeNode* current = queue.front(); queue.pop();

            // Go left
            if (current->left && !visited[current->left]) {
                queue.push(current->left);
                visited[current->left] = true;
            }

            // Go right
            if (current->right && !visited[current->right]) {
                queue.push(current->right);
                visited[current->right] = true;
            }

            // Go up (parent)
            if (parent_track[current] && !visited[parent_track[current]]) {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    // Collect results
    vector<int> result;
    while (!queue.empty()) {
        TreeNode* current = queue.front(); queue.pop();
        result.push_back(current->val);
    }

    return result;
}

/*
✅ Time Complexity (TC)
1. markParents() (BFS to track parents):
Visits every node once.

✅ O(n) where n = number of nodes in the tree.

2. distanceK() (Second BFS from target):
In the worst case, it may visit all nodes up to distance k.

But still, each node is visited once.

✅ O(n)

🔹 So overall:
🕒 Time Complexity = O(n)

✅ Space Complexity (SC)
We use extra space for:

parent_track map → stores parent of each node:
✅ O(n)

visited map → to avoid revisiting:
✅ O(n)

Queue for BFS → in the worst case holds ~n/2 nodes (last level of tree):
✅ O(n)

🔹 So overall:
💾 Space Complexity = O(n)
*/