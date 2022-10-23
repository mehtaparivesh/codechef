#include <bits/stdc++.h>
#define lli long long int
#define mod 2098244353
using namespace std;




int main() {
//ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    int n,i,j,k,p,t,a,b,c,d,e,f,g,ans;
    bool flag;
 string s1;
    cin>>t;
    while(t--){
	cin>>s1  ;
n=s1.length();	
vector <vector <int> > v1(n,vector <int>(26,0));

vector <int> hashes;
for(i=0;i<n;i++){
    for(j=0;j<26;j++){
    if(i>0)
    v1[i][j]=v1[i-1][j];
    }
if(s1[i]=='#') hashes.push_back(i)  ; else v1[i][s1[i]-'a']++;
}

ans=0;
k=hashes.size();
for(i=1;i<k-1;i++){
a=hashes[i-1]; b=hashes[i]; c=hashes[i+1];
d=0;e=0;f=0;g=0;

for(j=0;j<26;j++){
d=max(d,v1[a][j]);    
e=max(e, v1[b][j]-v1[a][j]);
f=max(f,v1[c][j]-v1[b][j]) ;
g=max(g,v1[n-1][j]-v1[c][j]);
}

if(d>0 && e>0 && f>0 && g>0)
ans=max(ans, d+e+f+g+3);    

    
}




cout<<ans<<"\n";
}
    return 0;
}