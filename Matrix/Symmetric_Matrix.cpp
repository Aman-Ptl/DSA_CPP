#include <bits/stdc++.h>
using namespace std;

class SymmetricMatrix
{
private:
    int *A; // stores only lower triangular part
    int n;  // dimension of the matrix

public:
    // constructor -> allocate memory
    SymmetricMatrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++) A[i] = 0; // initialize with 0
    }

    // destructor -> deallocate memory
    ~SymmetricMatrix()
    {
        delete[] A;
    }

    // Set value
    void set(int i, int j, int x)
    {
        if (i >= j) // store in lower triangular
        {
            int index = (i * (i + 1)) / 2 + j;
            A[index] = x;
        }
        else // use symmetry: A[i][j] = A[j][i]
        {
            int index = (j * (j + 1)) / 2 + i;
            A[index] = x;
        }
    }

    // Get value
    int get(int i, int j)
    {
        if (i >= j) // lower triangular
        {
            int index = (i * (i + 1)) / 2 + j;
            return A[index];
        }
        else // upper triangular -> mirror
        {
            int index = (j * (j + 1)) / 2 + i;
            return A[index];
        }
    }

    // Display full matrix
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
    SymmetricMatrix s(4);

    // Setting lower triangular values (rest will be auto-filled by symmetry)
    s.set(0, 0, 1);
    s.set(1, 0, 2);
    s.set(1, 1, 3);
    s.set(2, 0, 4);
    s.set(2, 1, 5);
    s.set(2, 2, 6);
    s.set(3, 0, 7);
    s.set(3, 1, 8);
    s.set(3, 2, 9);
    s.set(3, 3, 10);

    cout << "Symmetric Matrix:" << endl;
    s.display();

    cout << "\nElement at (2,1): " << s.get(2, 1) << endl; // should print 5
    cout << "Element at (1,2): " << s.get(1, 2) << endl;   // should also print 5 (symmetric)

    return 0;
}
