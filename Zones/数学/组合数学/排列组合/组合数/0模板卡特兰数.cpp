//https://vjudge.net/problem/CSES-2064
//预处理组合数公式求卡特兰数O(m+log(mod))
//左右括号一正一负，前缀和要非负，翻转恰好负数的位置前的括号方向，不合法序列唯一确定而且左括号数量+1
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
ll fac[N],invfac[N];
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
void init(int n){
    fac[0]=1;
    for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
    invfac[n]=qpow(fac[n],mod-2);
    for(int i=n;i>=1;--i)invfac[i-1]=invfac[i]*i%mod;
}
void solve(){
    ll n;cin>>n;
    init(n);
    if((n&1)||!n){cout<<0;return;}
    n/=2;
    cout<<fac[2*n]*invfac[n]%mod*invfac[n+1]%mod;
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