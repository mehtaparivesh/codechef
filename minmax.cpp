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
#define logarr(v, a, b)              \
    for (int z = (a); z <= (b); z++) \
        cout << (v[z]) << " ";       \
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
ll numberOfComparisons = 0;
pii getMinMaxRec(vi &v, int low, int high)
{

    pii ans, left, right;
    if (low == high)
    {
        ans.ss = v[low];
        ans.ff = v[low];
        return ans;
    }

    if (high == low + 1)
    {
        ++numberOfComparisons;
        if (v[low] > v[high])
        {
            ans.ss = v[low];
            ans.ff = v[high];
        }
        else
        {
            ans.ss = v[high];
            ans.ff = v[low];
        }
        return ans;
    }

    ll mid = (low + high) / 2;
    left = getMinMaxRec(v, low, mid);
    right = getMinMaxRec(v, mid + 1, high);
    (++ ++numberOfComparisons);
    if (left.ff < right.ff)
        ans.ff = left.ff;
    else
        ans.ff = right.ff;

    if (left.ss > right.ss)
        ans.ss = left.ss;
    else
        ans.ss = right.ss;

    return ans;
}

pii getMinMax(vi &v, int n)
{
    pii ans;
    int i;

    if (n % 2 == 0)
    {
        if (v[0] > v[1])
        {
            ans = {v[1], v[0]};
        }
        else
        {
            ans = {v[0], v[1]};
        }

        i = 2;
    }

    else
    {
        ans = {v[0], v[0]};

        i = 1;
    }

    while (i < n - 1)
    {
        if (v[i] > v[i + 1])
        {
            if (v[i] > ans.ss)
                ans.ss = v[i];

            if (v[i + 1] < ans.ff)
                ans.ff = v[i + 1];
        }
        else
        {
            if (v[i + 1] > ans.ss)
                ans.ss = v[i + 1];

            if (v[i] < ans.ff)
                ans.ff = v[i];
        }

        i += 2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    file_i_o();

    ll n;
    cin >> n;
    vi v(n);
    for (auto &it : v)
        cin >> it;
    numberOfComparisons = 0;
    pii ans = getMinMaxRec(v, 0, v.size() - 1);
    cout << ans.ff << " " << ans.ss << endl;
    cout << numberOfComparisons << endl;
    return 0;
}