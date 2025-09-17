#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertEnd(int x) {
        Node* t = new Node{x, NULL};
        if (!head) { head = t; return; }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = t;
    }

    void findMiddle() {
        if (!head) { cout << "List empty\n"; return; }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    void display() {
        Node* p = head;
        while (p) { cout << p->data << " "; p = p->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(10); l.insertEnd(20); l.insertEnd(30);
    l.insertEnd(40); l.insertEnd(50);

    cout << "List: "; l.display();
    l.findMiddle();
}