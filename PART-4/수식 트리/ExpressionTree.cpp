#include <iostream>

using namespace std;

struct Node {
    char value;
    Node *left, *right;
};

class ExpressionTree {
    private: 
        Node* root;

    public:
        ExpressionTree() {
            root = new Node();
        }
        void addTree(char* expression, Node** rootNode);
        void printByPostOrder(Node* rootNode);
        double evaluate(Node* rootNode);
        Node* getRoot();
        Node** getRoot2() {
            return &root;
        }
};

Node* ExpressionTree::getRoot() {
    return root;
}

void ExpressionTree::addTree(char* expression, Node** rootNode) {
    Node *node = new Node();

    int len = strlen(expression);
    char token = expression[len-1];
    expression[len-1] = '\0';
    node->value = token;

    switch(token) {
        // 연산자 인 경우
        case '+': case '-': case '*': case '/':
            addTree(expression, &(*rootNode)->right);
            addTree(expression, &(*rootNode)->left);
        default:
            *rootNode = node;
            break;
    }
    
}

void ExpressionTree::printByPostOrder(Node* rootNode) {
    if (rootNode != nullptr) {
        printByPostOrder(rootNode->left);
        printByPostOrder(rootNode->right);
        cout << rootNode->value << "\n";
    }
}

double ExpressionTree::evaluate(Node* rootNode) {
    
    double left = 0;
    double right = 0;
    double result = 0;

    switch(rootNode->value) {
        case '+': case '-': case '*': case '/':
            left = evaluate(root->left);
            right = evaluate(root->right);

            if (rootNode->value == '+') result = left + right;
            else if(rootNode->value == '-') result = left - right;
            else if(rootNode->value == '*') result = left * right;
            else if(rootNode->value == '/') result = left / right;

            break;

        default:
            string temp;
            temp.push_back(rootNode->value);
            result = stod(temp);
            break;
    }

    return result;
}

int main(void) {

    char PostfixExpression[100];
    cout << "수식을 입력하세요 : ";
    cin >> PostfixExpression;

    ExpressionTree tree = ExpressionTree();
    tree.addTree(PostfixExpression, tree.getRoot2());

    cout << "PostOrder ... \n";
    tree.printByPostOrder(tree.getRoot());

    double result = tree.evaluate(tree.getRoot());
    cout << result;
    
}