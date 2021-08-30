#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

bool DFS(int sx, int sy, vector<vector<char>> &board, string &s, vector<vector<bool>> &visited, int &m, int &n, int pos)
{

    if (s[pos] != board[sx][sy])
        return false;
    if (s.size() - 1 == pos)
        return true;

    bool ans = false;

    for (int i = 0; i < 8 and ans == false; i++)
    {
        if (sx + dx[i] < 0 or sx + dx[i] >= m or sy + dy[i] < 0 or sy + dy[i] >= n)
        {
            continue;
        }
        if (visited[sx + dx[i]][sy + dy[i]])
        {
            continue;
        }
        visited[sx + dx[i]][sy + dy[i]] = true;
        ans = ans or DFS(sx + dx[i], sy + dy[i], board, s, visited, m, n, pos + 1);
        visited[sx + dx[i]][sy + dy[i]] = false;
    }
    return ans;
}

bool hasPath(vector<vector<char>> &board, int m, int n)
{

    string s = "CODINGNINJA";

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = true;
            if (DFS(i, j, board, s, visited, m, n, 0) == true)
            {
                return true;
            }
            visited[i][j] = false;
        }
    }
    return false;
}