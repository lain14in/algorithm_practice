//https://vjudge.net/problem/CSES-2187
//剩余位置卡特兰数思想，选左括号数，删去不合法序列数，翻转选择左括号数量确定
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
ll C(ll n,ll m){
    if(m>n||n<0)return 0;
    return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    if((n&1)||!n){cout<<0;return;}
    int sum=0;
    for(char c:s){
        if(c=='(')++sum;
        else --sum;
        if(sum<0){cout<<0;return;}
    }
    int len=n-s.size();//剩余要选的位置
    if(sum>len){cout<<0;return;}//右括号不够抵消左括号
    int u=(len-sum)/2;//剩余位置要选的左括号数量
    init(len);
    cout<<(C(len,u)-C(len,u-1)+mod)%mod;
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