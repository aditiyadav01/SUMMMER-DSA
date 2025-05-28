#include <iostream>

// a node in a binary tree
struct Node {
    int data;        //value of node(integer)
    Node* left;      //reference pointer to left child
    Node* right;      //reference pointer to right child
    Node(int val) {   // method to initiate node with value
        data = val;    // set valur of the node 
        left = right = NULL;  //initialise left and right pointer to null
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
}
