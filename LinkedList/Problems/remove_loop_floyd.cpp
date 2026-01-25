#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

/*
    removeLoop(head)
    ----------------
    Detects and removes a loop (cycle) from a singly linked list using
    Floyd's Tortoise and Hare algorithm.

    Algorithm:
    1) Use two pointers (slow and fast) to detect if a loop exists.
       - slow moves 1 step at a time
       - fast moves 2 steps at a time
       - If they ever meet, a loop is present.

    2) If no loop is found, simply return.

    3) To remove the loop:
       - Reset slow to head.
       - Case A: If slow == fast, the loop starts at head.
                Traverse fast until fast->next == head,
                then set fast->next = nullptr.

       - Case B: Otherwise, move slow and fast one step at a time
                until slow->next == fast->next.
                fast will then point to the last node in the loop.
                Set fast->next = nullptr.

    Time Complexity:  O(n)
    Space Complexity: O(1)
*/
void removeLoop(Node* head) {
    // Base case: empty list or single-node list cannot have a loop
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd's cycle detection
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         
        fast = fast->next->next;   

        if (slow == fast) {
            // Loop detected
            break;
        }
    }

    // Step 2: If no loop exists, exit
    if (fast == nullptr || fast->next == nullptr) {
        return; // no loop
    }

    // Step 3: Find the start of the loop and remove it
    slow = head;

    // Case A: Loop starts at the head
    if (slow == fast) {
        while (fast->next != head) {
            fast = fast->next;
        }
        fast->next = nullptr;
        return;
    }

    // Case B: Loop starts somewhere after head
    // Move slow and fast until their next pointers meet
    // slow->next and fast->next will be the start of the loop
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    // fast now points to the last node in the loop
    fast->next = nullptr; // break the loop
}

void insertAtFront(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void createLoop(Node* head, int value) {
    if (head == nullptr) return;

    Node* loopNode = nullptr;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == value) {
            loopNode = temp;
        }
        if (temp->next == nullptr) break;
        temp = temp->next;
    }

    if (loopNode != nullptr) {
        temp->next = loopNode;
        cout << "Loop created at node with value: " << value << endl;
    } else {
        cout << "Value not found. Loop not created." << endl;
    }
}

/*
    WARNING: Do NOT call this function if a loop exists
*/
void display(const Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/*
    Deletes all nodes in the list
    WARNING: Unsafe if a loop exists
*/
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Build the list: 8 -> 9 -> 10 -> 11 -> 12 -> 13
    insertAtFront(head, 10);
    insertAtFront(head, 9);
    insertAtFront(head, 8);
    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);

    display(head);   // Safe here (no loop yet)

    // Create a loop: last node (13) -> node with value 9
    createLoop(head, 9);

    // Remove the loop
    removeLoop(head);

    display(head);   // Safe again (loop removed)

    // Free allocated memory
    deleteList(head);

    return 0;
}
