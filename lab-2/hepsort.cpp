//Nayan Chandra (CSE-21,ID-214001)
#include <bits/stdc++.h>
using namespace std;

void heapiFy(vector<int>& vec, int n, int i)
 {
    int lar = i;
    int le = 2 * i + 1;
    int ri = 2 * i + 2;
    if (le < n && vec[le] > vec[lar])
    {
        lar = le;
    }
    if (ri < n && vec[ri] > vec[lar])
    {
        lar = ri;
    }
    if (lar != i)
    {
        swap(vec[i], vec[lar]);
        heapiFy(vec, n, lar);
    }
}
void heapSorT(vector<int>& vec)
{
    int n = vec.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapiFy(vec, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(vec[0], vec[i]);
        heapiFy(vec, i, 0);
    }
}

int main()
 {
    int n = 1000000;
    vector<int> vec(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);
    for (int i = 0; i < n; i++)
        vec[i] = dis(gen);



    for (int i = 0; i < n; i++)
        vec[i] = n - i;


    ofstream decFileIn("dec.txt");
    for (int num : vec) {
        decFileIn << num << " ";
    }
    decFileIn.close();

    ifstream decFileOut("dec.txt");
    for (int& it : vec) {
        decFileOut >> it;
    }
    decFileOut.close();

    heapSorT(vec);

 return 0;
}
