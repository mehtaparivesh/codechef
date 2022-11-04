#include<bits/stdc++.h>
#include<string>

using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int tc = 1; tc <= t; tc++){
        ll n;
        cin>>n;

        string s;
        cin>>s;

        if(n % 2 == 1){
            cout<<"nO\n";
        }else{
            ll ones = 0 , zeroes = 0;
            for(int i = 0; i < n; i++){
                ones += (s[i] == '1');
                zeroes += (s[i] == '0');
            }

            ll req = (ones - zeroes) / 2 , cur = 0 , l = 1 , r = 1;
            for(int i = 0; i < n; i++){
                cur += (s[i] == '1');
                cur -= (s[i] == '0');

                if(cur == req){
                    r = i + 1;
                    break;
                }
            }
            cout<<"YeS\n";
            cout<<l<<" "<<r<<"\n";
        }
    }   
    return 0;
}