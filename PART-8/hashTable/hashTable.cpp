#include <iostream>
#include <string>
#include <vector>

/*
* Hash table with seperate chaining
*/
using namespace std;

const int bucketSize = 100;

typedef struct node {
    int key;
    string value;
    node* next;
}Node;

typedef struct bucket {
    Node* node;
}Bucket;

class Hashtable {
    private:
        Bucket* bucket[bucketSize];

        Node* createNode(string value) {
            Node* newNode;
            newNode = (Node*)malloc(sizeof(Node));
            newNode->key = hashCode(value);
            newNode->value = value;
            newNode->next = nullptr;

            return newNode;
        }
    public:
        Hashtable() {
            for(int i = 0; i < bucketSize; i++) {
                bucket[i] = (Bucket*)malloc(sizeof(Bucket));
            }
        }


        int hashCode(string value) {
            int h = 0;
            int length = value.length();
            for(int i=0; i<length; i++) {
                h = 31 * h + value[i];
            }
            h = h & INT_MAX;
            h = h % bucketSize;
            return h;
        }

        int put(string value) {
            Node* newNode = createNode(value);
            if(bucket[newNode->key]->node == nullptr) {
                bucket[newNode->key]->node = newNode;
                bucket[newNode->key]->node->next = nullptr;
            } 
            else {
                Node* current = bucket[newNode->key]->node;
                while(current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
                current->next->next = nullptr;
            }
            return newNode->key;
        }

        void print() {
            cout << "해시 테이블" << "\n";
            for(int i=0; i<bucketSize; i++) {
                Node* current = bucket[i]->node;
                while(current != nullptr) {
                    cout << '(' << current->key << ',' << current->value << ')';
                    if(current->next == nullptr) {
                        cout << "\n";
                        break;
                    }
                    cout << "->" << ' '; 
                    current = current->next;
                }
            }
        }

        void deleteNode(int key) {
            if(bucket[key]->node == nullptr) return;

            Node* current = bucket[key]->node;
            while(current != nullptr) {
                Node* temp = current;
                Node* next = temp->next;
                
                free(temp);
                current = next;
            }
            bucket[key] ->node = nullptr;
        }

        vector<string> getNode(int key) {
            vector<string> v;
            if(bucket[key]->node == nullptr) {
                return v;
            }

            Node *current = bucket[key]->node;
            while(current != nullptr) {
                v.push_back(current->value);
                current = current->next;
            }
            return v;
        }

        char* getrandomString(char* str, size_t size) {
            const char charset[] = "abcdefghijklmnopqrstuvwxyzA";
            if (size)
            {
                --size;
                for (size_t n = 0; n < size; n++)
                {
                    int key = rand() % (int)(sizeof charset - 1);
                    str[n] = charset[key];
                }
                str[size] = '\0';
            }
            return str;
        }
 };

 int main() {
    Hashtable hashtable;
    for(int i=0; i<bucketSize; i++)
    {
        char randbuff[65] = {0,};
        hashtable.put(hashtable.getrandomString(randbuff, 10));
    }

    hashtable.print();
    hashtable.deleteNode(12);
    hashtable.deleteNode(36);
    hashtable.print();

    vector <string> v = hashtable.getNode(15);
    for(auto t : v) {
        cout << t << "\n";
    }
 }