//https://ac.nowcoder.com/acm/contest/21289/F
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-6;
ll qpow(ll a,ll b,ll m){
    ll r=1;
    while(b){
        if(b&1)r=r*a%m;
        a=a*a%m;
        b>>=1;
    }
    return r;
}
ll phi(ll x){//求欧拉函数
    ll r=x;
    for(ll i=2;i*i<=x;++i){
        if(x%i==0){
            r=r/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)r=r/x*(x-1);
    return r;
}
void solve(){
    string b,n;cin>>b>>n;
    ll c;cin>>c;
    if(c==1){cout<<1;return;}
    ll base=0,rem=0,val=0,f=phi(c);
    for(char ch:b)
        base=(10*base+ch-'0')%c;
    for(char ch:n){
        rem=(10*rem+ch-'0')%f;//加乘可以阶段性先取模（展开就能推导）
        val=min(10*val+ch-'0',f+1);//判断是否超过phi，从大往小了读，phi比较小所以可以安全判断
    }
    ll e;
    if(val<=f)e=val-1;//真实指数
    else e=(rem-1+f)%f+f;//欧拉定理简化指数
    ll ans=(base-1+c)%c*qpow(base,e,c)%c;
    if(ans==0)ans=c;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}