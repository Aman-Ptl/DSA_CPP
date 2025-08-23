#include <bits/stdc++.h>
using namespace std;

class Upper_tri_Matrix
{
private:
    int *A; // stores only upper triangular elements
    int n;  // dimension of the matrix

public:
    // constructor -> allocate memory
    Upper_tri_Matrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++) A[i] = 0; // initialize with 0
    }

    // destructor -> deallocate memory
    ~Upper_tri_Matrix()
    {
        delete[] A;
    }

    // Row-major mapping (set value)
    void SetRowMajor(int i, int j, int x)
    {
        if (i <= j) // only upper triangular
        {
            int index = (i * (2 * n - i + 1)) / 2 + (j - i);
            A[index] = x;
        }
    }

    // Row-major mapping (get value)
    int GetRowMajor(int i, int j)
    {
        if (i <= j)
        {
            int index = (i * (2 * n - i + 1)) / 2 + (j - i);
            return A[index];
        }
        return 0;
    }

    // function to display full matrix
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i <= j)
                {
                    int index = (i * (2 * n - i + 1)) / 2 + (j - i);
                    cout << A[index] << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Upper_tri_Matrix u(4);

    u.SetRowMajor(0, 0, 10);
    u.SetRowMajor(0, 1, 20);
    u.SetRowMajor(0, 2, 30);
    u.SetRowMajor(0, 3, 40);
    u.SetRowMajor(1, 1, 50);
    u.SetRowMajor(1, 2, 60);
    u.SetRowMajor(1, 3, 70);
    u.SetRowMajor(2, 2, 80);
    u.SetRowMajor(2, 3, 90);
    u.SetRowMajor(3, 3, 100);

    cout << "Upper Triangular Matrix (Row-Major):" << endl;
    u.display();

    cout << "\nElement at (0,2): " << u.GetRowMajor(0, 2) << endl; // should print 30
    cout << "Element at (3,1): " << u.GetRowMajor(3, 1) << endl;   // should print 0

    return 0;
}
