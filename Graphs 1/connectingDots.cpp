#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node
{
    int first;
    int second;

    bool operator<(const Node &t) const
    {
        if (this->first != t.first)
            return (this->first < t.first);
        return this->second < t.second;
    }
};

bool solve(int cr, int cc, vector<vector<char>> &board, int &n, int &m, vector<vector<bool>> &visited, map<Node, int> &mp, int &cp)
{
    ++cp;
    visited[cr][cc] = true;
    Node temp;
    temp.first = cr;
    temp.second = cc;
    mp[temp] = cp;
    bool ans = false;
    for (int i = 0; i < 4; i++)
    {
        int x = cr + dx[i];
        int y = cc + dy[i];

        if (0 <= x and 0 <= y and x < n and y < n and board[x][y] == board[cr][cc])
        {
            Node temp2;
            temp2.first = x;
            temp2.second = y;
            if (visited[x][y] and abs(mp[temp2] - cp) >= 4)
                return true;
            else if (!visited[x][y])
                ans = ans or solve(x, y, board, n, m, visited, mp, cp);
        }
    }
    return ans;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                map<Node, int> mp;

                bool ans = solve(i, j, board, n, m, visited, mp, cp);
                if (ans)
                    return true;
                mp.clear();
            }
        }
    }
    return false;
}