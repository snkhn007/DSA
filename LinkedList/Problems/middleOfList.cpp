#include <iostream>
using namespace std;
// O(n) + O(n) = O(2n)
// Time Complexity: O(n)

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// O(n)->
int count(Node* head){
    int count = 0;
    while(head != nullptr){
        count++;
        head = head -> next;
    }
    return count;
}
// O(n)->
Node* middleElement(Node* head){
    if(head == nullptr) return nullptr;
    int ind = 1;
    int pos = (count(head)/2)+1;
    while(ind < pos){
        head = head->next;
        ind++;
    }
    return head;
}

void insertAtStart(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void display(const Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void freeSpace(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main() {
    Node* head = nullptr;

    // 1,2,3,4,5
    insertAtStart(head, 5);
    insertAtStart(head, 4);
    insertAtStart(head, 3);
    insertAtStart(head, 2);
    insertAtStart(head, 1);

    // // For even 
    // // 10,1,2,3,4,5
    // insertAtStart(head, 10);

    display(head);
    Node* midRes = middleElement(head);
    if(midRes) cout<<"Middle element: "<<midRes->data<<endl;

    freeSpace(head);
    return 0;
}
