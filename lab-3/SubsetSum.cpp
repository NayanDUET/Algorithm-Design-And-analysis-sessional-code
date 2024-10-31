#include <iostream>
#include <vector>
using namespace std;

vector<int> x;
vector<int> w;
int m;


void SumOfSub(int s, int k, int r)
{

    x[k] = 1;
    if (s + w[k] == m) {


        for (int i = 1; i <= k; i++) {
            if (x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << endl;
    }

    else if (s + w[k] + w[k + 1] <= m) {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }


    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m)) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    w.resize(n + 1);
    x.resize(n + 1, 0);
    cout << "Enter the elements in non-decreasing order: ";
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    cout << "Enter the target sum (m): ";
    cin >> m;

    int total_sum = 0;
    for (int i = 1; i <= n; i++) {
        total_sum += w[i];
    }

    cout << "Subsets that sum to " << m << ":" << endl;
    SumOfSub(0, 1, total_sum);
    return 0;
}
