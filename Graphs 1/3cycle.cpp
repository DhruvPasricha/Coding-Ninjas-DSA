#include <iostream>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    int **adjMatrix = new int *[n];

    for (int i = 0; i < n; i++)
    {
        adjMatrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = false;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = adjMatrix[v][u] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (adjMatrix[i][j] and adjMatrix[j][k] and adjMatrix[k][i])
                    ans++;

    cout << ans << endl;
}