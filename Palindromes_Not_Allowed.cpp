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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        map<char, ll> f;
        for (auto c : s)
        {
            f[c]++;
        }
        priority_queue<pair<ll, char>> pq;
        for (auto [k, v] : f)
        {

            pq.push({v, k});
        }
        bool flag = true;

        string ans = "";
        while (pq.size() >= 3)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            auto c = pq.top();
            pq.pop();

            ans += a.ss;
            a.ff--;

            ans += b.ss;
            b.ff--;
            ans += c.ss;
            c.ff--;

            if (a.ff)
                pq.push(a);
            if (b.ff)
                pq.push(b);
            if (c.ff)
                pq.push(c);
        }

        if (pq.size() == 1)
        {
            auto a = pq.top();
            if (a.ff > 1)
            {
                flag = false;
            }
            else
                ans += a.ss;
        }
        else if (pq.size() == 2)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();

            if (a.ff > 1 or b.ff > 1)
                flag = false;
            else
            {
                ans += a.ss;
                ans += b.ss;
            }
        }
        if (flag)
            cout << "YES" << endl
                 << ans << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}