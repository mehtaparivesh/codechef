#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    queue<vector<int>> q;
    q.push({a, b, 0});
    int ans = -1;
    while (q.size())
    {

        int i = q.front()[0];
        int j = q.front()[1];
        int steps = q.front()[2];
        q.pop();
        if (i >= n or i < 0 or j >= m or j < 0 or vis[i][j] or v[i][j] == 0)
            continue;
        vis[i][j] = true;

        if (i == c and j == d)
        {
            ans = steps;
            break;
        }
        q.push({i + 1, j, steps + 1});
        q.push({i - 1, j, steps + 1});
        q.push({i, j + 1, steps + 1});
        q.push({i, j - 1, steps + 1});
    }
    cout << ans << endl;
    return 0;
}
