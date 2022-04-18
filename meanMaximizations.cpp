#include <bits/stdc++.h>
using namespace std;
#define all(cont) cont.begin(), cont.end()
#define ll long long
void solve()
{
    int n;
    cin >> n;
    vector<int> ndkfndkfndnjkfdfdfdf(n);
    for (int i = 0; i < n; i++)
        cin >> ndkfndkfndnjkfdfdfdf[i];
    sort(ndkfndkfndnjkfdfdfdf.rbegin(), ndkfndkfndnjkfdfdfdf.rend());
    int a = *ndkfndkfndnjkfdfdfdf.begin();
    int sm = accumulate(all(ndkfndkfndnjkfdfdfdf), 0LL);
    double kdfkdjfnkdnjkfndjknfdjfdnjfjkjii = double(sm - a) / (n - 1);
    kdfkdjfnkdnjkfndjknfdjfdnjfjkjii += a;
    cout << setprecision(12) << fixed;
    cout << kdfkdjfnkdnjkfndjknfdjfdnjfjkjii << '\n';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}