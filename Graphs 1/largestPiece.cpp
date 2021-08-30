#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int solve(int cr, int cc, vector<vector<int>> &cake, int n, vector<vector<bool>> &visited)
{

    visited[cr][cc] = true;

    int ans = 1;
    for (int i = 0; i < 4; i++)
    {
        int x = cr + dx[i];
        int y = cc + dy[i];
        if (0 <= x and x < n and 0 <= y and y < n and !visited[x][y] and cake[x][y] == 1)
        {
            ans += solve(x, y, cake, n, visited);
        }
    }
    return ans;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    // Write your code here

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] and cake[i][j] == 1)
            {
                ans = max(ans, solve(i, j, cake, n, visited));
                // cout << i << j << " " << ans << endl;
            }
        }
    }
    return ans;
}