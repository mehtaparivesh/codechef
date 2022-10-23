#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb emplace_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp map
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll power(long long x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(unsigned long long n,
                     int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll blues;

ll helper(ll i, ll reds, vi &red, vi &blue, vi &dp)
{
    if (i == 0)
        return accumulate(blue.begin(), blue.end(), 0ll);
    ll ans = max(helper(i - 1, reds - red[i], red, blue, dp), helper(i - 1, reds, red, blue, dp) + blue[i]);
    return dp[reds] = max(dp[reds], ans);
}
int main(int argc, char const *argv[])
{
    file_i_o();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi dp(20005, -1);
        vi red(n), blue(n);
        for (auto &it : red)
            cin >> it;
        for (auto &it : blue)
            cin >> it;
        // ll reds = accumulate(red.begin(), red.end(), 0ll);
        // blues = accumulate(blue.begin(), blue.end(), 0ll);
        // dp[0] = 0;
        // helper(n - 1, reds, red, blue, dp);
        // ll ans = INT_MAX;
        // loop(i, 0, dp.size() - 1)
        // {
        //     if (dp[i] != -1)
        //         ans = min(ans, dp[i]);
        // }
        // cout << ans << endl;
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 20004; j >= 0; j--)
            {
                ll val = -1;
                if (dp[j] != -1)
                {
                    val = dp[j] + blue[i];
                }
                if (j - red[i] >= 0 and dp[j - red[i]] != -1)
                {
                    val = max(val, dp[j - red[i]]);
                }

                dp[j] = val;
            }
        }
        ll ans = 0;
        loop(i, 0, 20004)
        {
            if (dp[i] != -1)
                ans = max(ans, min(dp[i], i * 1ll));
        }
        cout << ans << endl;
    }
    return 0;
}