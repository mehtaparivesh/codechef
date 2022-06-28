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
ll calc(ll i, ll j, ll s)
{
    ll a = i, b = s * j, g = j;
    return __gcd(a, b) == g;
}
bool check(ll n, ll s, ll tc)
{
    for (ll i = 1; i * i <= n; i++)
        for (ll j = 1; j * j <= n; j++)
            if (i * i + j * j == n and (calc(i, j, s) or calc(j, i, s)))
            {
                return true;
            }
    return false;
}
int main(int argc, char const *argv[])
{
    file_i_o();
    ll t;
    cin >> t;
    unordered_map<ll, ll> m;
    for (int i = 1; i <= sqrt(1e10 + 1); i++)
    {
        m[i * i]++;
    }
    while (t--)
    {
        ll n;

        cin >> n;
        if (n % 2)
            cout << 0 << endl;
        else
        {
            ll ans = 0;
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    ll f1 = i;
                    ll f2 = n / i;

                    if (m.find(f1 - 1) != m.end() and check(f2, sqrt(f1 - 1), n))
                    {
                        // cout << f1 << " " << f2 << " ";
                        ans++;
                    }
                    if (f1 != f2 and m.find(f2 - 1) != m.end() and check(f1, sqrt(f2 - 1), n))
                    {
                        // cout << f2 << " " << f1 << " ";
                        ans++;
                    }
                    // cout << endl;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}