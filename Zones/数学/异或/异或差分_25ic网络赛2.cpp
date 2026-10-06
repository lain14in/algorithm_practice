//https://qoj.ac/contest/2524/problem/14318
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=998244353;
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
    ll n,m;cin>>n>>m;
    ll x=(qpow(2,m)-1+mod)%mod;
    ll ans=qpow(x,n-1);
    if(!(n&1)){
        ll t=qpow(x,n/2);
        if((n/2)&1)ans=(ans-t+mod)%mod;
        else ans=(ans+t)%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
先对相邻两项做异或差分，这样“相邻元素不能相等”就变成了“每个差分值都不能为 0”。
然后把原序列全部用第一个元素和这些差分值表示。
若长度是奇数，总异或为 0 只会把第一个元素唯一确定，所以其余差分都可以自由选；
若长度是偶数，第一个元素会被抵消掉，变成一半位置上的差分值异或必须为 0，
此时再统计“若干个非零数异或为 0”的方案数，最后用快速幂计算即可。
*/