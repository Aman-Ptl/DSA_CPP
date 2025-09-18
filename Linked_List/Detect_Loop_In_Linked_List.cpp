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

// Function to check if linked list has a loop (Floyd’s Algorithm)
bool isLoop(struct Node *f) {
    struct Node *p, *q;
    p = q = f;

    while (p && q && q->next) {
        p = p->next;          // move one step
        q = q->next->next;    // move two steps
        if (p == q)           // they meet → loop detected
            return true;
    }
    return false;
}

// Function to display (only safe if no loop)
void Display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    cout << "Loop Present? " << (isLoop(first) ? "Yes" : "No") << endl;

    // Manually creating a loop for testing
    first->next->next->next->next->next = first->next; // 50 → 20

    cout << "After creating loop: " << (isLoop(first) ? "Yes" : "No") << endl;

    return 0;
}
