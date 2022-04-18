#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")
// BOOST END */

#define gc getchar_unlocked
#define ll long long int
#define br printf("\n")
#define fo(i, n) for(i=0;i<n;i++)
#define fox(i, a,b) for(i=a;i<=b;i++)
#define reps(i, a,b) for(int i=a;i<=b;i++)
#define repe(i, a,b) for(int i=a;i>=b;i--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define F first
#define S second
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
template <typename T>
void inpV (vector<T> &vec, int end)
{
    vec.resize(end);
    for (int i = 0; i < end; i += 1)
    {
        cin >> vec[i];
    }
}

/* ========== YOUR CODE HERE ========= */
ll isprime(ll n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)return 0;
    }
    return 1;
}

void primeFactors(ll n, map<ll, ll> &hp)
{
    while (n % 2 == 0)
    {
        hp[2] += 1;
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            hp[i] += 1;
            n = n / i;
        }
    }
    if (n > 2)
        hp[n] += 1;
}


ll llis(vector<ll>& a)
{
    ll n = a.size();
    vector<ll> arr;
    for (ll i = 0; i < n; i++)
    {
        auto lb = upper_bound(arr.begin(), arr.end(), a[i]);
        if (lb != arr.end())
        {
            *lb = min(*lb, a[i]);
        }
        else
        {
            arr.push_back(a[i]);
        }
    }
    return arr.size();
}

auto solve()
{
    ll n, m; cin >> n >> m;
    vll a(n, 0), b(m, 0);
    inpV(a, n); inpV(b, m);
    ll mx1 = 1, mx2 = 1;
    mx1 = llis(a); mx2 = llis(b);
    cout << mx1 + mx2 << endl;
    return "";
}

int main()
{
    FAST_IO;
    ll tcs = 1;
    cin >> tcs;
    while (tcs--)
    {
        cout << solve();
    }
    return 0;
}