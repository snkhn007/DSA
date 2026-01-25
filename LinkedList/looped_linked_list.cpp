#include <iostream>
using namespace std;

class Node{
public:
    Node (int data){
        this->data = data;
        this->next = nullptr;
    }
    int data;
    Node* next;
};

void insertAtFront(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newNode;   
}

// Creates a loop: tail -> node with given value
void createLoop(Node* head, int value){
    if(head == nullptr) return;

    Node* loopNode = nullptr;
    Node* temp = head;

    // Find the node where loop should start
    while(temp != nullptr){
        if(temp->data == value){
            loopNode = temp;
        }
        if(temp->next == nullptr) break; // temp becomes last node
        temp = temp->next;
    }

    // Connect last node to loopNode
    if(loopNode != nullptr){
        temp->next = loopNode;
        cout << "Loop created at node with value: " << value << endl;
    } else {
        cout << "Value not found. Loop not created." << endl;
    }
}

// Normal display (DO NOT use if loop exists)
void display(const Node *head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Free all allocated memory (unsafe if loop exists)
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    Node* head = nullptr;

    insertAtFront(head,10);
    insertAtFront(head,9);
    insertAtFront(head,8);
    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);

    display(head);   // Safe here (no loop yet)

    // Create a loop: last node (13) -> node with value 9
    createLoop(head, 9);

    //Do NOT call display(head) now — infinite loop!

    return 0;
}
