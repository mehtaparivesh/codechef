#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
int N = 1e6;
vector<int> seive(N+1);

void preProcess(){
    seive[0] = 1;
    for(int i=1; i<=N; i++)
    seive[i] = i;
    
    for(int i=2; i<=N; i+=2)
    seive[i] = 2;
    
    for(int i=3; i*i<=N; i+=2){
        if(seive[i] == i){
            for(int j=i*i; j<=N; j+=i){
                if(seive[j] == j)
                seive[j] = i;
            }
        }
    }
}


unsigned long long power(unsigned long long a, unsigned long long n){
    if(n == 0)
    return 1;
    
    unsigned long long p = power(a, n/2) % MOD;
    p = (p * p) % MOD;
    
    if(n & 1)
    p = (p*a) % MOD;
    
    return p;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    a[0] = 0;
    for(int i=1; i<=n; i++)
    cin >> a[i];
    
    vector<bool> vis(n+1, false);
    vector<int> s;
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vis[i] = true;
            int cnt = 1;
            int next = a[i];
            while(next != i){
                vis[next] = true;
                cnt++;
                next = a[next];
                // cout << next << " " << cnt << endl;
            }
            s.push_back(cnt);
            // cout << cnt << endl;
        }
    }
    
    unsigned long long lcm = 1;
    unordered_map<int, int> max_fact;
    
    for(int i = 0; i<s.size(); i++){
        int num = s[i];
        // cout << num << endl;
        unordered_map<int , int> fact;
        while(num > 1){
            int factor = seive[num];
            fact[factor]++;
            num /= factor;
        }
        
        for(auto it:fact){
            max_fact[it.first] = max(max_fact[it.first], it.second);
        }
    }
    
    for(auto it: max_fact){
        lcm = (lcm * power(it.first, it.second)) % MOD;
        // cout << it.first << " " << it.second << endl;
    }
    
    cout << lcm;
}

int main() {
	// your code goes here
	preProcess();
	int t;
	cin >> t;
	while(t--){
	    solve();
	    cout << endl;
	}
	return 0;
}
