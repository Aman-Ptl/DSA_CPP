#include <bits/stdc++.h>
using namespace std;

class Lower_tri_Matrix
{
private:
    int *A; // stores only lower triangular elements
    int n;  // dimension of the matrix

public:
    // constructor -> Allocated Memory
    Lower_tri_Matrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++) A[i] = 0; // initialize with 0
    }

    // destructor -> de-allocated Memory
    ~Lower_tri_Matrix()
    {
        delete[] A;
    }

    // Row-major mapping
    void SetRowMajor(int i, int j, int x)
    {
        if (i >= j) // valid only for lower triangular
        {
            int index = (i * (i + 1)) / 2 + j; // row-major formula
            A[index] = x;
        }
    }

    int GetRowMajor(int i, int j)
    {
        if (i >= j)
        {
            int index = (i * (i + 1)) / 2 + j;
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
                if (i >= j)
                {
                    int index = (i * (i + 1)) / 2 + j;
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
    Lower_tri_Matrix d(4);

    d.SetRowMajor(0, 0, 10);
    d.SetRowMajor(1, 0, 5);
    d.SetRowMajor(1, 1, 20);
    d.SetRowMajor(2, 0, 15);
    d.SetRowMajor(2, 1, 25);
    d.SetRowMajor(2, 2, 30);
    d.SetRowMajor(3, 0, 35);
    d.SetRowMajor(3, 1, 45);
    d.SetRowMajor(3, 2, 55);
    d.SetRowMajor(3, 3, 40);

    cout << "Lower Triangular Matrix (Row-Major):" << endl;
    d.display();

    cout << "\nElement at (2,2): " << d.GetRowMajor(2, 2) << endl; // should print 30
    cout << "Element at (1,3): " << d.GetRowMajor(1, 3) << endl;   // should print 0

    return 0;
}
