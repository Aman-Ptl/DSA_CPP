// Concatenation_of_Two_Linked_Lists.cpp

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Function to create a linked list from an array
void createFirst(int A[], int n) {
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

void createSecond(int B[], int m) {
    struct Node *t, *last;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < m; i++) {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to display a linked list
void Display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to concatenate two linked lists
void Concat(struct Node *p, struct Node *q) {
    third = p;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = q;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {60, 70, 80, 90, 100};

    createFirst(A, 5);
    createSecond(B, 5);

    cout << "First Linked List: ";
    Display(first);

    cout << "Second Linked List: ";
    Display(second);

    Concat(first, second);

    cout << "Concatenated Linked List: ";
    Display(third);

    return 0;
}
