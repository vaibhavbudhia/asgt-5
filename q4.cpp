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

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* p = head;
        while (p) { cout << p->data << " "; p = p->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1); l.insertEnd(2); l.insertEnd(3); l.insertEnd(4);

    cout << "Original List: "; l.display();
    l.reverse();
    cout << "Reversed List: "; l.display();
}