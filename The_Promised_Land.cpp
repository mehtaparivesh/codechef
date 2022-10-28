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

int main(int argc, char const *argv[])
{
    file_i_o();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll x, y, s;
        cin >> x >> y >> s;

        vi horizontal;
        horizontal.push_back(0);
        for (int i = 0; i < x; i++)
        {
            ll q;
            cin >> q;
            horizontal.push_back(q);
        }

        horizontal.push_back(n + 1);

        ll hs = 0;
        sort(horizontal.begin(), horizontal.end());
        for (int i = 1; i < horizontal.size(); i++)
        {
            hs += (horizontal[i] - horizontal[i - 1] - 1) / s;
        }

        vi vertical = {0};

        for (int i = 0; i < y; i++)
        {
            ll q;
            cin >> q;
            vertical.push_back(q);
        }

        vertical.push_back(m + 1);
        sort(vertical.begin(), vertical.end());

        ll ans = 0;
        for (int i = 1; i < vertical.size(); i++)
        {

            ll bb = (vertical[i] - vertical[i - 1] - 1) / s;
            ans += bb * hs;
        }
        cout << ans << endl;
    }

    return 0;
}