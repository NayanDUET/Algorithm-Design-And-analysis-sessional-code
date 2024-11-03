/*

 Nayan Chandra (Nayan_C)
 Dhaka University of Engineering & Technology,Gazipur(DUET)
 CSE-21,ID-214001

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
int G[N][N];
vector<int> x(N);


void NextValue(int k)
{
    do {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
         return;
        }

        int j;
        for (j = 1; j <= n; j++)
        {
            if (G[k][j] == 1 && x[k] == x[j]) break;
        }

        if (j == n + 1)
        {
         return;
        }
    } while (true);
}


void mColoring(int k)
 {
    do {
        NextValue(k);
        if (x[k] == 0) return;
        if (k == n) {
            for (int i = 1; i <= n; i++)
            {
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }
        else
         {
            mColoring(k + 1);
        }
    } while (true);
}

int main()
{
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of colors: ";
    cin >> m;

   cout<<"mariex inter:"<<endl;
    for (int i = 1; i <= n; i++)
     {
        for (int j = 1; j <= n; j++)
         {
            cin >> G[i][j];
        }
    }

    // sobgulaer color by default 0 mane akhono kono color kora hoi ni
    for (int i = 1; i <= n; i++) x[i] = 0;

    // first node thake suru
    mColoring(1);

    return 0;
}
