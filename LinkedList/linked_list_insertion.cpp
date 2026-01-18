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
    Node* newNode= new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node* &head, int data){
    Node* newNode= new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newNode;   
}
void display(Node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
// Free all allocated memory
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
    display(head);

    deleteList(head);  // ✅ Prevent memory leak
    return 0;
}