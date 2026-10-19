//https://ac.nowcoder.com/acm/contest/22769/B
//质数直接快速幂，合数用线性筛里面前面的最小质数来计算
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e7+3e6+5,mod=1e9+7;
const double eps=1e-9;
int f[N];
vector<int>p;
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
void euler(int n){
    f[1]=1;
    for(int i=2;i<=n;++i){
        if(!f[i]){
            f[i]=qpow(i,n);
            p.push_back(i);
        }
        for(int pj:p){
            if((ll)i*pj>n)break;
            f[i*pj]=(ll)f[i]*f[pj]%mod;
            if(i%pj==0)break;
        }
    }
}
void solve(){
    int n;cin>>n;
    euler(n);
    ll ans=0;
    for(int i=1;i<=n;++i)ans^=f[i];
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