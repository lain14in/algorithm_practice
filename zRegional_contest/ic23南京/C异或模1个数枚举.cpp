//https://codeforces.com/gym/104821/problem/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-6,pi=2*acos(0);

void solve(){
    ll p,m;cin>>p>>m;
    ll ans=m/p;
    for(ll k=m/p;k<m/p+2;++k){
        ll g=(p-1)^(k*p+1);
        if(g<=m)++ans;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}