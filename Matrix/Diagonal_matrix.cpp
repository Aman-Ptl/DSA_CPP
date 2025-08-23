#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int A[10]; // stores only diagonal elements
    int n;     // dimension of the matrix
};

// function to set diagonal element
void setElement(struct Matrix *m, int i, int j, int x) {
    if (i == j) {
        m->A[i] = x;
    }
}

// function to get element at (i,j)
int get(Matrix m, int i, int j) {
    if (i == j) {
        return m.A[i];
    } else {
        return 0;
    }
}

// function to display full matrix
void display(struct Matrix m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            if (i == j) {
                cout << m.A[i] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    struct Matrix m;
    m.n = 4;

    setElement(&m, 0, 0, 10);
    setElement(&m, 1, 1, 20);
    setElement(&m, 2, 2, 30);
    setElement(&m, 3, 3, 40);

    cout << "Diagonal Matrix:" << endl;
    display(m);

    cout << "\nElement at (2,2): " << get(m, 2, 2) << endl; // should print 30
    cout << "Element at (1,3): " << get(m, 1, 3) << endl; // should print 0

    return 0;
}
