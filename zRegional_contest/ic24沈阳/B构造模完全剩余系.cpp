#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    ll n,m;cin>>n>>m;
    if(__gcd(n,m)>1){cout<<"No\n";return;}
    cout<<"Yes\n";
    for(int i=1;i<=n;++i)cout<<m*i-1<<' ';
    cout<<'\n';
    for(int j=1;j<=m;++j)cout<<n*j-1<<' ';
    cout<<'\n';
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