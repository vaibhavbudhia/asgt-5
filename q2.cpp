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

    void countAndDelete(int key) {
        int count = 0;
        Node* curr = head;
        Node* prev = NULL;

        while (curr) {
            if (curr->data == key) {
                count++;
                if (prev == NULL) {
                    head = curr->next;
                    delete curr;
                    curr = head;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        cout << "Occurrences of " << key << " deleted: " << count << endl;
    }

    void display() {
        Node* p = head;
        while (p) { cout << p->data << " "; p = p->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1); l.insertEnd(2); l.insertEnd(2); l.insertEnd(3); l.insertEnd(2);

    cout << "Original List: "; l.display();

    int key;
    cout << "Enter element to delete: ";
    cin >> key;
    l.countAndDelete(key);

    cout << "Updated List: "; l.display();
}