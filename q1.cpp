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

    ~LinkedList() { while (head) deleteBegin(); }

    void insertBegin(int x) {
        Node* t = new Node;
        t->data = x;
        t->next = head;
        head = t;
    }

    void insertEnd(int x) {
        Node* t = new Node;
        t->data = x;
        t->next = NULL;
        if (!head) { head = t; return; }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = t;
    }

    void insertAfter(int key, int x) {
        Node* p = head;
        while (p && p->data != key) p = p->next;
        if (!p) { cout << "Key not found\n"; return; }
        Node* t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }

    void deleteBegin() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head=NULL; return; }
        Node* p=head;
        while (p->next->next) p=p->next;
        delete p->next; p->next=NULL;
    }

    void deleteKey(int key) {
        if (!head) return;
        if (head->data==key) { deleteBegin(); return; }
        Node* p=head;
        while (p->next && p->next->data!=key) p=p->next;
        if (!p->next) { cout<<"Key not found\n"; return; }
        Node* t=p->next;
        p->next=t->next;
        delete t;
    }

    void search(int key) {
        Node* p=head; int pos=0;
        while (p) {
            if (p->data==key) { cout<<"Found at position "<<pos<<"\n"; return;}
            p=p->next; pos++;
        }
        cout<<"Not found\n";
    }

    void display() {
        Node* p=head;
        while (p) { cout<<p->data<<" "; p=p->next; }
        cout<<endl;
    }
};

int main() {
    LinkedList list;
    list.insertBegin(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertAfter(20, 25);

    cout << "List after insertions: ";
    list.display();

    list.deleteBegin();
    cout << "After deleting from beginning: ";
    list.display();

    list.deleteEnd();
    cout << "After deleting from end: ";
    list.display();

    list.deleteKey(25);
    cout << "After deleting key 25: ";
    list.display();

    list.search(20);
    list.search(100);

    return 0;
}