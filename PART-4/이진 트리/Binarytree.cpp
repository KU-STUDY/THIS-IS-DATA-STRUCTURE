#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
};

class BinaryTree {
    private:
        Node* root;
    
    public:
        BinaryTree() { root = nullptr; }
        ~BinaryTree() {}
        void addNode(int value);
        void removeNode(int value);
        bool searchNode(int value);

        void print() {
            inOrder(root);
        }
        void inOrder(Node *current) {
            if(current != nullptr) {
                inOrder(current->left);
                cout << current -> value << "\n";
                inOrder(current->right);
            }
        }
        void postOrder(Node *current) {
            if (current != nullptr) {
                postOrder(current->left);
                postOrder(current->right);
                cout << current -> value << "\n";
            }
        }
        void preOrder(Node *current) {
            if (current != nullptr) {
                cout << current -> value << "\n";
                preOrder(current->left);
                preOrder(current->right);
            }
        }
};

bool BinaryTree::searchNode(int number) {
    if(root == nullptr) {
        return false;
    }

    else {
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()) {
            Node *tmp = q.front();
            q.pop();

            if(tmp->value == number) {
                return true;
            }

            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);
        }
    }
    return false;
}

void BinaryTree::removeNode(int index) {
    if(root == nullptr) {
        cout << "해당 index를 가진 노드가 존재하지 않습니다.\n";
        return;
    }
    else {
        queue<Node **> q;
        q.push(&root);

        int tmpIndex = 0;
        while(!q.empty()) {
            Node **tmp = q.front();
            q.pop(); 
            tmpIndex++;

            if (tmpIndex < index) {
                if((*tmp)->left != nullptr) q.push(&(*tmp)->left);
                if((*tmp)->right != nullptr) q.push(&(*tmp)->right);
            }
            else if (tmpIndex == index) {
                if((*tmp)->left == nullptr && (*tmp)->right == nullptr) {
                    (*tmp) = nullptr;
                }
                break;
            }
            else {
                break;
            }
        }
    }
}
void BinaryTree::addNode(int value) {
    Node *node = new Node();
    node->value = value;

    if(root == nullptr) {
        root = node;
    }
    else {
        queue<Node *> q;
        q.push(root);

        while(!q.empty()) {
            Node *tmp = q.front();
            q.pop();
        
            if(tmp->left == nullptr) {
                tmp->left = node;
                break;
            }
            q.push(tmp->left);

            if(tmp->right == nullptr) {
                tmp->right = node;
                break;
            }
            q.push(tmp->right);
        }
    }
}

int main(void) {

    BinaryTree *BT = new BinaryTree();
    BT -> addNode(1);
    BT -> addNode(2);
    BT -> addNode(3);
    BT -> addNode(4);
    BT -> addNode(5);

    BT -> removeNode(5);
    BT -> print();

}
