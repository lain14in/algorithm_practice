//https://ac.nowcoder.com/acm/contest/21791/G
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=998244353;
const double eps=1e-6,pi=2*acos(0);
ll fac[N+1],invfac[N+1];
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=N;++i)fac[i]=fac[i-1]*i%mod;
    invfac[N]=qpow(fac[N],mod-2);
    for(int i=N;i>=1;--i)invfac[i-1]=invfac[i]*i%mod;
}
ll C(ll n,ll m){
    if(m>n||n<0)return 0;
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void solve(){
    init();
    ll n,m;cin>>n>>m;
    if(n==2){cout<<0<<'\n';return;}
    ll ans=C(m,n-1)*(n-2)%mod*qpow(2,n-3)%mod;
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