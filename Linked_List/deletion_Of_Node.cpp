#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

// Function to create linked list from array
void create(int A[], int n) {
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to display linked list
void Display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to delete a node at given position (1-based index)
void Delete(int pos) {
    struct Node *p, *q;
    if (pos == 1) {
        p = first;
        first = first->next;
        delete p;
    } else {
        p = first;
        q = NULL;
        for (int i = 0; i < pos - 1 && p; i++) {
            q = p;
            p = p->next;
        }
        if (p) {
            q->next = p->next;
            delete p;
        }
    }
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    cout << "Original List: ";
    Display(first);

    Delete(3); // deleting node at position 3 (30)

    cout << "After deleting node at position 3: ";
    Display(first);

    Delete(1); // deleting first node (10)

    cout << "After deleting first node: ";
    Display(first);

    return 0;
}
