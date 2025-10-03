#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);    
void delete_node(Node *&head);
void add_front(Node *&head, float val);
void add_tail(Node *&head, float val);
void insert_node();
void deleteList(Node *&head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        add_front(head, tmp_val); // replaced by function
    }
    output(head);
    // add a node in the tail
    add_tail(head,  6666);
    cout << "After adding 9999 at tail:\n";
    output(head);

    // deleting a node
    delete_node(head);
    output(head);

    // insert a node

    // delete the list
    deleteList(head);
    output(head);
    

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void delete_node(Node *&head) {
    if (!head) return;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    Node *current = head, *prev = head;
    for (int i = 0; i < (entry-1); i++) {
        if (i == 0) current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }
    if (current) {
        if (current == head) {  // delete the head
            head = head->next;
            delete current;
        } else {
            prev->next = current->next;
            delete current;
        }
    }
}

void add_front(Node *&head, float val){
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

void add_tail(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next) current = current->next;
    current->next = newNode;
}

void insert_node(){
    
}

void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
    head = nullptr;
}