Binary tree:- :
        Binary tree is a fundamental hierarchical data structure in computer science that comprises nodes arranged in a tree-like structure. It consists of nodes, where each node can have at most two children nodes, known as the left child and the right child.

Nodes:-
        Each node in a binary tree contains a piece of data, often referred to as the node’s value or key. This node also contains references and pointers to its left and right children so that we can traverse from one node to another in a hierarchical order.

Root Node: 
        is the topmost node of a binary tree from which all other nodes stem out. This serves as the entry point for traversing the tree structure.

Children Nodes:- 
        are the nodes directly connected to a parent node. In a binary tree, a parent node can have zero, one or two children nodes, each situated to the left or right of the parent node.

Leaf Nodes:-
         are the nodes that do not have any children. These nodes lie on the outermost ends of the tree branches and are the terminal points of the traversal.

Ancestors :- 
        in a Binary Tree are those nodes that lie on the path from a particular node to the root node. They are the nodes encountered while moving upwards from a specific node through its parent nodes until reaching the root of the tree.

Full Binary Tree:
        A Full Binary Tree, also known as a Strict Binary Tree, adheres to the structural property where every node has either zero or two children.

        No node of this tree has just a single child, all internal nodes have exactly two children or in the case of leaf nodes, no children.

Complete Binary Tree:
        A Complete Binary Tree is a specialised form of Binary Tree where all levels are filled completely except possibly the last level, which is filled from left to right.

        All levels of the tree, except possibly the last one, are fully filled. If the last level is not completely filled, it is filled from left to right, ensuring that nodes are positioned as far left as possible.

Perfect Binary Tree:
        A Perfect Binary tree is a type of Binary Tree where all leaf nodes are at the same level and the number of leaf nodes is maximised for that level.

        Every node in a perfect binary tree has either zero or two children. This means that every internal node (non-leaf node) has exactly two children and all leaf nodes are at the same level.

        All levels of this tree are fully filled with nodes including the last level. Perfect Binary Trees have a balanced structure that maximises the number of nodes for a given height, creating a dense structure where the number of nodes doubles as we move down each level of the tree.

        Properties of perfect binary trees make them efficient for certain operations like searching and sorting due to their balanced nature. However, achieving and maintaining perfect balance, especially when the number of nodes is not a power of two, might not be feasible in many practical applications.

Balanced Binary Tree:
        A Balanced Binary tree is a type of Binary Tree where the heights of the two subtrees of any node differ by at most one. This property ensures that the tree remains relatively well-balanced, preventing the tree from becoming highly skewed or degenerate.
        In a balanced binary tree, the height of the tree should be log2N at maximum, where N is the number of nodes. This ensures that the tree does not become heavily skewed or imbalanced. The distribution of nodes of both the left and right subtrees remains relatively even throughout the tree.

Degenerate Tree:
        A Degenerate Tree is a Binary Tree where the nodes are arranged in a single path leaning to the right or left. The tree resembles a linked list in its structure where each node points to the next node in a linear fashion.


