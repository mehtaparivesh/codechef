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

ld dis(ld x1, ld y1, ld x2, ld y2)
{

    return (ld)sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
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
        vector<pair<ld, ld>> v(n);
        for (auto &it : v)
        {
            cin >> it.ff;
            cin >> it.ss;
        }
        ll ans = 0;
        map<ld, ll> m;
        loop(i, 0, n - 1)
        {
            loop(j, i + 1, n - 1)
            {
                auto x1 = v[i].ff, y1 = v[i].ss;
                auto x2 = v[j].ff, y2 = v[j].ss;

                ld slope = (ld)((ld)y2 - (ld)y1) / (ld)((ld)x2 - (ld)x1);

                ll totalPoints = j - i - 1; 
                ll toAdd = totalPoints - m[slope];
                ans += toAdd;
                m[slope]++;
            }
            m.clear();
        }

        cout << ans << endl;
    }
    return 0;
}
