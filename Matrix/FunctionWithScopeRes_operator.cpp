#include <bits/stdc++.h>
using namespace std;

class Diagonal
{
private:
    int *A; // stores only diagonal elements
    int n;  // dimension of the matrix

public:
    // constructor
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
        for (int i = 0; i < n; i++) A[i] = 0; // initialize with 0
    }

    // destructor
    ~Diagonal()
    {
        delete[] A;
    }

    // function to set diagonal element
    void Diagonal::setElement(int i, int j, int x)
    {
        if (i == j && i < n) // only diagonal positions
        {
            A[i] = x;
        }
    }

    // function to get element at (i,j)
    int Diagonal::get(int i, int j)
    {
        if (i == j && i < n)
        {
            return A[i];
        }
        return 0;
    }

    // function to display full matrix
    void Diagonal::display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << A[i] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Diagonal d(4);

    d.setElement(0, 0, 10);
    d.setElement(1, 1, 20);
    d.setElement(2, 2, 30);
    d.setElement(3, 3, 40);

    cout << "Diagonal Matrix:" << endl;
    d.display();

    cout << "\nElement at (2,2): " << d.get(2, 2) << endl; // should print 30
    cout << "Element at (1,3): " << d.get(1, 3) << endl;   // should print 0

    return 0;
}
