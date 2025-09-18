// Reverse_Linked_List_by_Reversing_Links.cpp

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

// Function to reverse linked list by changing links
void ReverseLinks(struct Node *p) {
    struct Node *q = NULL, *r = NULL;

    while (p != NULL) {
        r = q;        // move r one step behind q
        q = p;        // move q one step behind p
        p = p->next;  // move p to next
        q->next = r;  // reverse the link
    }
    first = q;        // update head pointer
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    cout << "Original List: ";
    Display(first);

    ReverseLinks(first);

    cout << "Reversed List (by links): ";
    Display(first);

    return 0;
}
