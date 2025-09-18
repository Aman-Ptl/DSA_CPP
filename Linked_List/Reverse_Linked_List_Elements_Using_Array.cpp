// Reverse_Linked_List_Elements_Using_Array.cpp

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

// Function to reverse elements using array
void ReverseElements(struct Node *p) {
    vector<int> arr;

    // Step 1: Copy elements to array
    while (p != NULL) {
        arr.push_back(p->data);
        p = p->next;
    }

    // Step 2: Reassign elements in reverse order
    p = first;
    int i = arr.size() - 1;
    while (p != NULL) {
        p->data = arr[i--];
        p = p->next;
    }
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    cout << "Original List: ";
    Display(first);

    ReverseElements(first);

    cout << "Reversed List (by elements): ";
    Display(first);

    return 0;
}
