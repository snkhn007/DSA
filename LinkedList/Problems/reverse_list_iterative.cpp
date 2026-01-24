#include <iostream>
using namespace std;
// O(n)
// O(1)
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* rev(Node* head) {
    // Base case: empty list or single node list is already reversed
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* temp = head;      // Current node being processed
    Node* prev = nullptr;  // Will become the new head after reversal
    Node* front = nullptr; // Stores the next node before breaking the link

    while (temp != nullptr) {
        front = temp->next;  // Save next node
        temp->next = prev;   // Reverse the current node's pointer
        prev = temp;         // Move prev forward
        temp = front;        // Move temp forward
    }

    // prev now points to the new head of the reversed list
    return prev;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}

void display(const Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original list: ";
    display(head);

    head = rev(head);

    cout << "Reversed list: ";
    display(head);

    deleteList(head);
    return 0;
}
