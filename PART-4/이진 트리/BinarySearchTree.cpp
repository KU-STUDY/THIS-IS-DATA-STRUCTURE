#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
};

class BinarySearchTree {
    public:
        void addNode(int value);
        void show() {
            inOrder(root);
        }

        Node* remove(Node *node, int value);
        void removeNode(int value) {
            remove(root, value);
        }
        void inOrder(Node *current);
        void postOrder(Node *current);
        void preOrder(Node *current);

        bool search(Node *node, int value);

        bool searchNode(int value) {
            return search(root, value);
        }
        Node* searchMaxNode(Node *node) {
            if (node == nullptr) 
                return nullptr;
            while(node->right != nullptr)
                node = node -> right;
            return node;
        }
    
    private:
        Node *root;
};

bool BinarySearchTree::search(Node *node, int value) {

    if(node == nullptr) return false;

    while(node != nullptr) {
        if(node->value < value) {
            node = node -> right;
        }
        else if(node->value > value) {
            node = node -> left;
        }
        else if(node->value == value) {
            return true;
        }
    }
    return false;
}

Node *BinarySearchTree::remove(Node *node, int value) {
    if(node == nullptr) return node;

    else if (node -> value > value) {
        node -> left = remove(node -> left, value);
    } else if (node-> value < value) {
        node -> right = remove(node -> right, value);
    } else {
        Node *ptr = node;
        if(node -> right == nullptr && node -> left == nullptr) {
            delete node;
            node = nullptr;
        } else if (node -> right == nullptr) {
            node = node -> left;
            delete ptr;
        } else if (node -> left == nullptr) {
            node = node -> right;
            delete ptr;
        } else {
            ptr = searchMaxNode(node -> left);
            node -> value = ptr -> value;
            node -> left = remove(node->left, ptr->value);
        }
    }
    return node;
}

void BinarySearchTree::preOrder(Node *current) {
    if(current != nullptr) {
        cout << current -> value << "\n";
        preOrder(current -> left);
        preOrder(current -> right);
    }
}
void BinarySearchTree::postOrder(Node *current) {
    if(current != nullptr) {
        postOrder(current ->left);
        postOrder(current ->right);
        cout << current -> value << "\n";
    }
}
void BinarySearchTree::inOrder(Node *current) {
    if(current != nullptr) {
        inOrder(current -> left);
        cout << current -> value << "\n";
        inOrder(current -> right);
    }
}



void BinarySearchTree::addNode(int value) {
    Node *node = new Node();
    node->value = value;

    if(root == nullptr) {
        root = node;
    }
    else {
        Node *ptr = root;
        Node *tail = root;

        while(ptr != nullptr) {
            tail = ptr;
            if(node -> value < ptr -> value) {
                ptr = ptr -> left;
            } else {
                ptr = ptr -> right;
            }
        }
        if (node -> value < tail -> value)
            tail -> left = node;
        else
            tail -> right = node;
    }
}

int main(void) {
    BinarySearchTree *BST = new BinarySearchTree();
    BST -> addNode(1);
    BST -> addNode(3);
    BST -> addNode(5);
    BST -> show();

    cout << BST -> searchNode(5) << '\n';
    cout << BST -> searchNode(6) << '\n';

    BST -> removeNode(3);
    BST -> show();

    cout << "\n";
}