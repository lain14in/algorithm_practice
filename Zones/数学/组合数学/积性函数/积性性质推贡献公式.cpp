//https://ac.nowcoder.com/acm/contest/22769/F
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-9;
int spf[N];
vector<int>p;
ll invfac[25];
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
    for(int i=2;i<N;++i){
        if(!spf[i]){
            spf[i]=i;
            p.push_back(i);
        }
        for(int pj:p){
            if((ll)i*pj>=N)break;
            spf[i*pj]=pj;
            if(i%pj==0)break;
        }
    }
    ll fac=1;
    for(int i=1;i<=20;++i)fac=fac*i%mod;
    invfac[20]=qpow(fac,mod-2);
    for(int i=20;i>=1;--i){
        invfac[i-1]=invfac[i]*i%mod;
    }
}
ll cal(int r,int e){
    ll res=r+2*e;
    for(int i=1;i<e;++i)
        res=res*(r+i)%mod;
    return res*invfac[e]%mod;
}
void solve(){
    int r,n;cin>>r>>n;
    ll ans=1;
    while(n>1){
        int x=spf[n],e=0;
        while(n%x==0){
            n/=x;
            ++e;
        }
        ans=ans*cal(r,e)%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}