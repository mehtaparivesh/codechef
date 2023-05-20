#include <iostream>
#include <vector>
using namespace std;

int maxSquareSubmatrix(vector<vector<int>> &v)
{
    int ans = 1;
    vector<vector<int>> dp(v.size(), vector<int>(v[0].size(), 0));

    for (int i = v.size() - 1; i >= 0; i--)
    {

        for (int j = v[0].size() - 1; j >= 0; j--)
        {
            if (i == v.size() - 1 or j == v[0].size() - 1)
            {
                dp[i][j] = v[i][j];
                continue;
            }
            if (v[i][j] == 1)
            {
                dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
            }
            else
                dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    cout << maxSquareSubmatrix(v) << endl;
    return 0;
}


