/*

 Nayan Chandra (Nayan_C)
 Dhaka University of Engineering & Technology,Gazipur(DUET)
 CSE-21,ID-214001

*/

const int N = 20;
int n;
int G[N][N];
vector<int> x(N);


void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0) return;

        if (G[x[k - 1]][x[k]] != 0)
         {
            int j;
            for (j = 1; j < k; j++)
            {
                if (x[j] == x[k]) break;
            }
            if (j == k && (k < n || (k == n && G[x[n]][x[1]] != 0))) return;
        }
    } while (true);
}


void Hamiltonian(int k) {
    do {
        NextValue(k);
        if (x[k] == 0) return;
        if (k == n)
        {

            for (int i = 1; i <= n; i++)
             {
                cout << x[i] << " ";
            }
            cout << x[1] << endl;

        } else
        {
            Hamiltonian(k + 1);
        }
    } while (true);
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> G[i][j];
        }
    }


    for (int i = 1; i <= n; i++) x[i] = 0;
    x[1] = 1;


    Hamiltonian(2);

    return 0;
}
