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

pii helper(vector<vi> &g, vi &values, ll i)
{

    if (g[i].size() == 0)
        return {values[i], 0};
    vector<pii> t;
    for (auto it : g[i])
    {
        if (i == it)
            continue;
        t.push_back(helper(g, values, it));
    }

    ll sum = 0;
    ll gc = values[i];
    loop(i, 0, t.size() - 1)
    {
        sum += t[i].ff;
        gc = __gcd(gc, t[i].ff);
    }
    ll ans = sum;
    loop(i, 0, t.size() - 1)
    {
        ans = max(ans, sum + t[i].ss - t[i].ff);
    }
    return {gc, ans};
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
        vi values(n + 1);
        loop(i, 1, n) cin >> values[i];

        vector<vi> g(n + 1);
        loop(i, 0, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            g[u].pb(v);
        }
        auto p = helper(g, values, 1);
        cout << p.ff << " " << p.ss << endl;
    }
    return 0;
}

// import sys


// class Node:
//     def init(self, val):
//         self.val = val
//         self.gcd = val
//         self.sumOfGcdChildren = 0

//     def str(self):
//         return f" {self.gcd} {self.sumOfGcdChildren} {self.val}"


// # gcd function
// def __gcd(a, b):
//     if b == 0:
//         return a
//     return __gcd(b, a % b)

// ans=0
// def run():
//     n = int(input())
//     nodeval = list(map(int, input().split()))
//     nodes={}
//     for i in range(1,n+1):
//         nodes[i] = Node(nodeval[i-1])
//     graph = {}
//     for i in range(1,n+1):
//         graph[i] = []
//     for i in range(n-1):
//         a, b = map(int, input().split())
//         graph[a].append(b)
//         graph[b].append(a)
//     def dfs(curr, parent):
//         sumofgcd = 0
//         for child in graph[curr]:
//             if child != parent:
//                 dfs(child, curr)
//                 nodes[curr].gcd = __gcd(nodes[curr].gcd, nodes[child].gcd) 
//                 sumofgcd += nodes[child].gcd
//         nodes[curr].sumOfGcdChildren = sumofgcd
//     dfs(1, -1)
//     global ans
//     ans=0
//     def dfs2(curr,parent,sum):
//         sum+=nodes[curr].sumOfGcdChildren
//         global ans
//         ans=max(ans,sum)
//         for child in graph[curr]:
//             if child != parent:
//                 dfs2(child,curr,sum-nodes[child].gcd)
//     dfs2(1,-1,0)
//     print(ans)
    

// sys.setrecursionlimit(10**6)
// test=int(input())
// for i in range(test):
//     run()