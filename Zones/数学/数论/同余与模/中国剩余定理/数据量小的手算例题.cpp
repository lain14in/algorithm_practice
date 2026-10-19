//https://ac.nowcoder.com/acm/contest/21289/E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-6;

void solve(){
    ll p,e,i,d;cin>>p>>e>>i>>d;
    ll x=5544*p+14421*e+1288*i,m=21252;
    ll ans=(x-d+m)%m;
    if(ans==0)cout<<m<<'\n';
    else cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}