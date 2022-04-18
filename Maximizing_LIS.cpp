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

ll lengthOfLIS(vi &nums, vi &pre)
{
    if (!nums.size())
        return 0;
    vi t;
    int ans = 0;
    loop(i, 0, nums.size() - 1)
    {

        if (!t.size() or t.back() < nums[i])
        {
            t.push_back(nums[i]);
        }
        else
        {
            int ind = lower_bound(t.begin(), t.end(), nums[i]) - t.begin();
            t[ind] = nums[i];
        }

        pre[i] = t.size();
    }

    return t.size();
}

ll lengthOfLIS2(vi &nums, vi &pre)
{
    if (!nums.size())
        return 0;
    vi t;
    int ans = 0;
    looprev(i, nums.size() - 1, 0)
    {

        if (!t.size() or t.back() < nums[i])
        {
            t.push_back(nums[i]);
        }
        else
        {
            int ind = lower_bound(t.begin(), t.end(), nums[i]) - t.begin();
            t[ind] = nums[i];
        }

        pre[i] = t.size();
    }

    return t.size();
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
        vi v(n);
        for (auto &it : v)
            cin >> it;

        vi pre(n), suff(n);
        ll lis = lengthOfLIS(v, pre);
        loop(i, 0, n - 1) v[i] *= -1;
        lengthOfLIS2(v, suff);
        ll ans = lis;
        loop(i, 0, n - 2)
        {
            ans = max(ans, pre[i] + suff[i + 1]);
        }

        ans = max({ans, pre[0], suff[0]});

        cout << ans << endl;
    }
    return 0;
}