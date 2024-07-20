#include <iostream>
#include <stack>

using namespace std;

struct Node {
    char value;
    Node *left, *right;
};

class ExpressionTree {
    private:
        Node* root;
    
    public:
        ExpressionTree() {root=nullptr;}
        ~ExpressionTree() {}
        
        void MakeExpTree(string exp);

        int calculate() {
            return _calculate(root);
        }
        int _calculate(Node * node);
        void print() {
            postOrder(root);
        }
        void postOrder(Node * node) {
            if(node != nullptr) {
                postOrder(node->left);
                postOrder(node->right);
                cout << node->value << '\n';
            }
        }
};

int ExpressionTree::_calculate(Node *node){
    int op1, op2;

    if(node->left == nullptr && node->right == nullptr) return (node->value) - '0';

    op1 = _calculate(node->left);
    op2 = _calculate(node->right);

    switch (node->value)
    {
    case '+':
        return op1 + op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '-':
        return op1 - op2;
    default:
        break;
    }
    return 0;
}


void ExpressionTree::MakeExpTree(string exp) {
    stack <Node*> s;
    for(auto c : exp) {
        if(isdigit(c)) {
            Node* node = new Node();
            node->value = c;
            s.push(node);
        }
        else {
            Node* node = new Node();
            node->value = c;
            Node* rightNode = s.top(); s.pop();
            Node* leftNode = s.top(); s.pop();
            node->right = rightNode;
            node->left = leftNode;

            s.push(node);
        }
    }

    if(!s.empty()) root = s.top();
}

int main(void) {
    ExpressionTree *Exp = new ExpressionTree();
    Exp -> MakeExpTree("12+7*");
    Exp -> print();
    cout << '\n' << Exp->calculate() << '\n';
}
