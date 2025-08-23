#include <bits/stdc++.h>
using namespace std;

class TriDiagonalMatrix
{
private:
    int *A; // stores 3 diagonals
    int n;  // dimension

public:
    // Constructor
    TriDiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[3 * n - 2];
        for (int i = 0; i < 3 * n - 2; i++)
            A[i] = 0;
    }

    // Destructor
    ~TriDiagonalMatrix()
    {
        delete[] A;
    }

    // Set value at (i,j)
    void set(int i, int j, int x)
    {
        if (i == j) // main diagonal
        {
            A[n - 1 + i] = x;
        }
        else if (i == j + 1) // lower diagonal
        {
            A[i - 1] = x;
        }
        else if (i + 1 == j) // upper diagonal
        {
            A[2 * n - 1 + i] = x;
        }
    }

    // Get value at (i,j)
    int get(int i, int j)
    {
        if (i == j) // main diagonal
        {
            return A[n - 1 + i];
        }
        else if (i == j + 1) // lower diagonal
        {
            return A[i - 1];
        }
        else if (i + 1 == j) // upper diagonal
        {
            return A[2 * n - 1 + i];
        }
        else
            return 0;
    }

    // Display matrix
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    TriDiagonalMatrix t(4);

    // Setting values (main, upper, lower diagonals only)
    t.set(0, 0, 1);
    t.set(0, 1, 2);
    t.set(1, 0, 3);
    t.set(1, 1, 4);
    t.set(1, 2, 5);
    t.set(2, 1, 6);
    t.set(2, 2, 7);
    t.set(2, 3, 8);
    t.set(3, 2, 9);
    t.set(3, 3, 10);

    cout << "Tridiagonal Matrix:" << endl;
    t.display();

    return 0;
}
