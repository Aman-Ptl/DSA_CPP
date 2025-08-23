#include <bits/stdc++.h>
using namespace std;

class TriBandMatrix {
private:
    int *A;
    int n;

public:
    TriBandMatrix(int n) {
        this->n = n;
        A = new int[3 * n - 2]; // store lower, main, upper
        for (int i = 0; i < 3 * n - 2; i++) A[i] = 0;
    }

    ~TriBandMatrix() {
        delete[] A;
    }

    // Set value
    void set(int i, int j, int x) {
        if (i == j)               A[n - 1 + i] = x;      // main diag
        else if (i == j + 1)      A[i - 1] = x;          // lower diag
        else if (i + 1 == j)      A[2 * n - 1 + i] = x;  // upper diag
    }

    // Get value
    int get(int i, int j) {
        if (i == j)               return A[n - 1 + i];
        else if (i == j + 1)      return A[i - 1];
        else if (i + 1 == j)      return A[2 * n - 1 + i];
        else                      return 0;
    }

    // Display matrix
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriBandMatrix m(5);

    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(1, 0, 3);
    m.set(1, 1, 4);
    m.set(1, 2, 5);
    m.set(2, 1, 6);
    m.set(2, 2, 7);
    m.set(2, 3, 8);
    m.set(3, 2, 9);
    m.set(3, 3, 10);
    m.set(3, 4, 11);
    m.set(4, 3, 12);
    m.set(4, 4, 13);

    cout << "Tri-band Matrix:" << endl;
    m.display();

    return 0;
}
