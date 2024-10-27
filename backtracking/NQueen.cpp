#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int x[100];

bool Place(int k, int i)
{

    for (int j = 1; j < k; j++)
    {

        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}


void NQueens(int k, int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
         {
            x[k] = i;
            if (k == n)
            {

                for (int j = 1; j <= n; j++)
                {
                    cout << x[j] << " ";      //here print all possiable combination
                                             // here print just column just have to add row sequentially
                                             // print like 3,1,4,2  its acutally (1,3),(2,1),(3,4),(4,2)
                }
                cout << endl;
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    NQueens(1, n);  // Start solving from the first row
    return 0;
}
