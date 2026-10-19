//https://ac.nowcoder.com/acm/contest/21289/H
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-6;
int k;
vector<ll>ai,mi;
ll mul(ll a,ll b,ll m){
    a=(a%m+m)%m;
    ll r=0;
    while(b){
        if(b&1)r=(r+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return r;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll excrt(){
    ll x,y;
    ll m1=mi[1],a1=ai[1];
    ll ans=a1%m1;
    for(int i=2;i<=k;++i){
        ll m2=mi[i],a2=ai[i];
        ll a=m1,b=m2,c=(a2-a1%m2+m2)%m2;
        ll d=exgcd(a,b,x,y);
        if(c%d)return -1;
        x=mul(x,c/d,b/d);
        ans=a1+x*m1;
        m1=m2/d*m1;
        ans=(ans%m1+m1)%m1;
        a1=ans;
    }
    return ans;
}
void solve(){
    ll n,m;cin>>n>>m>>k;
    ai.resize(k+1),mi.resize(k+1);
    for(int i=1;i<=k;++i){
        cin>>mi[i];
        ai[i]=(mi[i]-(i-1)%mi[i])%mi[i];//初始列J=-(i-1)（mod mi[i])
    }
    if(k>m){cout<<"NO";return;}
    ll L=1;
    for(int i=1;i<=k;++i){//求mi最小公倍数
        i128 t=(i128)(L/__gcd(L,mi[i]))*mi[i];
        if(t>n){cout<<"NO";return;}
        L=(ll)t;
    }
    ll J=excrt();
    if(J==-1){cout<<"NO";return;}
    if(J==0)J=L;
    if(J+k-1>m){cout<<"NO";return;}
    for(int i=1;i<=k;++i){//周期性，只用检查这一处
        if(__gcd(L,J+i-1)!=mi[i]){cout<<"NO";return;}
    }
    cout<<"YES";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}