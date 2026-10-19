//https://ac.nowcoder.com/acm/contest/21289/D
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-6;
int n;
vector<ll>ai,mi;
ll mul(ll a,ll b,ll m){//安全模乘a*b%m
    ll r=0;
    while(b>0){
        if(b&1)r=(r+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return r;
}
ll exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll excrt(){
    ll x,y;
    ll m1=mi[1],a1=ai[1];
    ll ans=a1%m1;
    for(int i=2;i<=n;++i){
        ll a2=ai[i],m2=mi[i];
        ll a=m1,b=m2,c=(a2-a1%m2+m2)%m2;
        ll d=exgcd(a,b,x,y);
        if(c%d!=0)return -1;
        x=mul(x,c/d,b/d);
        ans=a1+x*m1;
        m1=m2/d*m1;
        ans=(ans%m1+m1)%m1;
        a1=ans;
    }
    return ans;
}
void solve(){
    cin>>n;
    ai.resize(n+1),mi.resize(n+1);
    for(int i=1;i<=n;++i)cin>>mi[i]>>ai[i];
    cout<<excrt();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}