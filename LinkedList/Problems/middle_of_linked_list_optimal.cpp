#include <iostream>
using namespace std;

// Finds middle of linked list using slow-fast pointer technique
// Time: O(n), Space: O(1)

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
Node* middleElement(Node* head){
    if(head == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

    // For even 
    // 10,1,2,3,4,5
    insertAtStart(head, 10);

    display(head);
    Node* midRes = middleElement(head);
    if(midRes) cout<<"Middle element: "<<midRes->data<<endl;

    freeSpace(head);
    return 0;
}
