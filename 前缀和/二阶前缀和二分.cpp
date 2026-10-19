//https://atcoder.jp/contests/abc480/tasks/abc480_d
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9;
ll n,q;
vector<ll>s(n+1),ss(n+1);
ll f(ll x){
    ll l=0,r=n;
    while(l<=r){
        ll m=(l+r)/2;
        if(m*(m+1)/2<=x)l=m+1;
        else r=m-1;
    }
    ll cnt=x-r*(r+1)/2;
    return ss[r]+s[cnt];
}
void solve(){
    cin>>n>>q;
    s.assign(n+1,0),ss.assign(n+1,0);
    for(int i=1;i<=n;++i){
        ll x;cin>>x;
        s[i]=s[i-1]+x;
        ss[i]=ss[i-1]+s[i];
    }
    while(q--){
        ll L,R;cin>>L>>R;
        cout<<f(R)-f(L-1)<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}