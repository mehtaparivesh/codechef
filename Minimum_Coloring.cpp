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
void solve()
{

    ll n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    ll a = (x1 + y1 - 2) % 2, b = (x2 + y2 - 2) % 2;

    vector<vi> v(n, vi(m, 0));
    if (a != b)
    {

        loop(i, 0, n - 1)
        {
            loop(j, 0, m - 1)
            {
                if ((i + j) % 2 == (x1 + y1) % 2)
                {
                    v[i][j] = 1;
                }
                else if ((i + j) % 2 == (x2 + y2) % 2)
                {
                    v[i][j] = 2;
                }
            }
        }
    }
    else
    {

        loop(i, 0, n - 1)
        {
            loop(j, 0, m - 1)
            {
                if ((i + j) % 2 == (x1 + y1) % 2)
                {
                    v[i][j] = 1;
                }
                else
                {
                    v[i][j] = 3;
                }
            }
        }
    }
    v[x1 - 1][y1 - 1] = 1;
    v[x2 - 1][y2 - 1] = 2;
    loop(i, 0, n - 1)
    {
        loop(j, 0, m - 1)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    file_i_o();

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}