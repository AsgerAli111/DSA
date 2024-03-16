#include<iostream>
#include<cstdlib>

struct bstNode* rootNode = nullptr; // Global declaration of root node

struct bstNode {
    int data;
    struct bstNode* left;
    struct bstNode* right;
};

struct bstNode* createNewNode(int data) { // Function that creates a new node with data
    struct bstNode* temp = (struct bstNode*)malloc(sizeof(struct bstNode));
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

struct bstNode* insertNode(struct bstNode* root, int data) { // Function that inserts a node at the appropriate position
    if (root == nullptr) {
        root = createNewNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

bool search(struct bstNode* node, int data) {
    if (node == nullptr) {
        return false;
    }
    else if (node->data == data) {
        return true;
    }
    else if (data <= node->data) {
        return search(node->left, data);
    }
    else {
        return search(node->right, data);
    }
}

int main() {
    rootNode = nullptr; // Initially, the root node is null, meaning the tree is empty
    rootNode = insertNode(rootNode, 20);
    rootNode = insertNode(rootNode, 15);
    rootNode = insertNode(rootNode, 22);
    rootNode = insertNode(rootNode, 26);
    rootNode = insertNode(rootNode, 23);
    rootNode = insertNode(rootNode, 28);
    rootNode = insertNode(rootNode, 26);

    std::cout << search(rootNode, 27);

    return 0;
}
