#include <iostream>
#include <stack>
using namespace std;
// O(n)
// O(n)

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void rev(Node* head){
    Node* temp = head;
    stack <int>st;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;        
    }
    while(head != nullptr){
        head->data = st.top();
        st.pop();
        head = head-> next;
    }
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

    // Build list: 10 -> 1 -> 2 -> 3 -> 4 -> 5
    insertAtStart(head, 5);
    insertAtStart(head, 4);
    insertAtStart(head, 3);
    insertAtStart(head, 2);
    insertAtStart(head, 1);
    insertAtStart(head, 10);

    cout << "Original list: ";
    display(head);

    rev(head);

    cout << "Reversed list (using stack - data only): ";
    display(head);

    freeSpace(head);
    return 0;
}