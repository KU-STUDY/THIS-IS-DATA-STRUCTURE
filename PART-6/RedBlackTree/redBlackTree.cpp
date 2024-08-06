#include <iostream>

using namespace std;

enum Color {
    RED, BLACK
};

typedef struct node {
    int data;
    node *parent;
    node *right, *left;
    Color color;
}Node;

static Node* NIL;


class RBT {
    private:
        Node* root;
    public:
        void leftRotate(Node* node);
        void rightRotate(Node* node);
        void insertNode(int data) {
            Node* node = new Node();
            node->data = data;
        
            insertion(&root, node);
            node->color = RED;
            node->left = NIL;
            node->right = NIL;
            
            if(node->parent == nullptr) reconstruct(node, false);
            else {
                reconstruct(node, node->parent->left == node);
            }
        }
        void print() {
            printTree(root, "", true);
        }
        void printTree(Node* node, string indent, bool last);
        void insertion(Node** root, Node* node);
        void reconstruct(Node* node, bool left);
        void deletion(Node* child, Node* parent);
};
void RBT::printTree(Node* node, string indent, bool last) {
    if(node != NIL) {
        cout << indent;

        string color = node->color == RED ? "RED" : "BLACk";
        cout << node->data << "(" << color << ")" << "\n";
        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}
void RBT::insertion(Node** root, Node* node) {
    if(*root == nullptr) *root = node;
    
    if((*root)->data < node->data) {
        if((*root)->right == NIL) {
            (*root)->right = node;
            node->parent = (*root);
        }
        else insertion(&(*root)->right, node);
    }
    else if((*root)->data > node->data) {
        if((*root)->left == NIL) {
            (*root)->left = node;
            node->parent = (*root);
        }
        else insertion(&(*root)->left, node);
    }
}

void RBT::leftRotate(Node* node) {
    
    if(node == NIL || node->right == NIL) return;

    Node* temp = node->right;
    node->right = node->right->left;
    node->right->parent = node;

    temp->left = node;
    temp->parent = node->parent;

    if(node->parent != nullptr) {
        if(node->parent->left == node) node->parent->left = temp;
        else node->parent->right = temp;
    }

    node->parent = temp;
    if(root == node)
        root = temp;
}

void RBT::rightRotate(Node* node) {

    if(node == NIL || node->right == NIL) return;

    Node* temp = node->left;
    node->left = node->left->right;
    node->left->parent = node;

    temp->right = node;
    temp->parent = node->parent;

    if(node->parent != nullptr) {
        if(node->parent->left == node) node->parent->left = temp;
        else node->parent->right = temp;
    }

    node->parent = temp;
    if(root == node)
        root = temp;
}

void RBT::reconstruct(Node* node, bool Isleft)
{
    Node* parent = node->parent;
    while(parent != nullptr && parent->color == RED){
        
        Node* grandParent = parent->parent;
        bool IsleftParent = grandParent->left == parent;
        Node* uncle = IsleftParent ? grandParent->right : grandParent->left;

        if(uncle != nullptr && uncle->color == RED) {
            parent->color = BLACK;
            uncle->color = BLACK;
            grandParent->color = RED;

            node = grandParent;
            parent = grandParent->parent;

            if(parent != nullptr) Isleft = parent->left == node;
        }
        else {
            if((IsleftParent == true && Isleft == false) || (IsleftParent == false && Isleft == true)) {
                IsleftParent ? leftRotate(parent) : rightRotate(parent);
                parent = node;
                Isleft = !Isleft;
            }
            parent->color = BLACK;
            grandParent->color = RED;
            Isleft ? rightRotate(grandParent) : leftRotate(grandParent);
            break;
        }
    }
    root->color = BLACK;
}

void RBT::deletion(Node* child, Node* parent){
    while(parent != nullptr) {
        bool left = parent->left == child;
        Node* sibling = left ? parent->right : parent->left;

        if(parent->color == RED) {
            // [case 1]부모 노드가 레드이고, 형제, 조카 노드들이 블랙인 경우
            if(sibling->left->color == BLACK && sibling->right->color == BLACK) {
                //부모, 형제 노드 색상 교환한다.
                sibling->color = RED;
                parent->color = BLACK;
                break;
            }
        }
        else if(sibling->left->color == BLACK && sibling->right->color == BLACK) {
            // [case 4] 부모, 형제, 조카 노드가 모두 블랙인 경우
            if(sibling->color == BLACK) {
                //형제 노드의 색상 레드로 바꿔주기
                sibling->color = RED;
                child = parent;
                parent = parent->parent;
                continue;
            }

            // [case 5] 형제 노드가 레드이고, 부모, 조카 노드들이 블랙인 경우
            else {
                parent->color = RED;
                sibling->color = BLACK;
                if(left) {
                    leftRotate(parent);
                    sibling = parent->right;   
                }
                else{
                    rightRotate(parent);
                    sibling = parent->left;
                }
                continue;
            }
        }

        // [case 3] 형제 노드가 블랙이고 가까이 있는 조카 노드가 레드, 멀리 있는 조카 노드가 블랙인 경우 
        if (sibling->color == BLACK && ((left && sibling->left->color == RED && sibling->right->color == BLACK)
            || (!left && sibling->left->color == BLACK && sibling->right->color == RED))) {
                if(left) {
                    rightRotate(sibling);
                    parent->right->color = BLACK;
                    parent->right->right->color = RED;
                    sibling = parent->right;
                }
                else {
                    leftRotate(sibling);
                    parent->left->color = BLACK;
                    parent->left->left->color = RED;
                    sibling = parent->left;
                }
            }
        // [case 2] 형제 노드가 블랙이고, 조카 노드가 레드인 경우 
        if (sibling->color == BLACK && ((left && sibling->right->color == RED) || (!left && sibling->left->color == RED))) {
            left ? leftRotate(parent) : rightRotate(parent);
            Color temp = parent->color;
            parent->color = sibling->color;
            sibling->color = temp;
            left ? sibling->right->color = BLACK : sibling->left->color = RED;
            break;
        }
    
    }
}

int main() {
    RBT *rbt = new RBT();
    rbt->insertNode(2);
    rbt->insertNode(3);
    rbt->insertNode(4);
    rbt->print();
}