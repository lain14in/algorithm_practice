//https://vjudge.net/problem/CSES-2210
//正方形旋转4次90°，黑白2种底为2：0°每个格子自己算一个；90°与270°每2*2算一个；180°是对称即可。注意n*n的中心点算一个
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
void solve(){
    ll n;cin>>n;
    ll s=n*n;
    ll ans=(qpow(2,s)+2*qpow(2,(s+3)/4)+qpow(2,(s+1)/2))%mod*qpow(4,mod-2)%mod;
    cout<<ans;
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