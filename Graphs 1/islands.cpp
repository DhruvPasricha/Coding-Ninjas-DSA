#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int sv, int n, int **edges, bool *visited)
{

    visited[sv] = 1;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 and !visited[i])
        {
            DFS(i, n, edges, visited);
        }
    }
}

int main()
{
    // Write your code here

    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // Code Here
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i, n, edges, visited);
            ans++;
        }
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++)
    {
        delete edges[i];
    }

    delete[] edges, visited;

    return 0;
}