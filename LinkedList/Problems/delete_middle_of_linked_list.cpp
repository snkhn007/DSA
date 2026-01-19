#include <iostream>
using namespace std;
// Program to delete middle element of a singly linked list
// Time: O(n), Space: O(1)
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
void insertAtStart(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void display(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* delMiddle(Node* head){
    // empty list
    if (head == nullptr){
        return head;
    }
    // only one element in list
    if(head -> next == nullptr){
        delete head;
        return  nullptr;
    }
    // more than one element in list
    // Using slow-fast pointer technique to find middle
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    while(fast != nullptr && fast->next != nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

void freeSpace(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main(){
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
    head = delMiddle(head);
    display(head);
    freeSpace(head);
    return 0;

}