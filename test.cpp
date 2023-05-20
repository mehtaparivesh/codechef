#include <iostream>
using namespace std;
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
    int n;
    cin >> n;
    cout << n << endl;
    return 0;
}
