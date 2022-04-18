#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
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
        string s;
        cin >> s;
        ll ans = 0;
        ll o = 0, z = 0;
        ll c0 = 0, c1 = 0;
        loop(i, 0, s.size() - 1)
        {
            c0 += s[i] == '0';
            c1 += s[i] == '1';
            if (s[i] == '0')
            {
                z++;
            }
            else
            {
                o++;
            }
            if (z and o > z)
            {
                ans++;
                z = 0;
                o = 0;
            }
        }

        if (o > z)
            ans++;

        if (c0 == 0)
        {
            cout << c1 << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}