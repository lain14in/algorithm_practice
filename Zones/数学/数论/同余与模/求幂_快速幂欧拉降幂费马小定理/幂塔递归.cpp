//https://ac.nowcoder.com/acm/contest/21289/G
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e5+5,mod=1e9+7;
const double eps=1e-6;
ll w[N];
vector<ll>f;
ll phi(ll x){
    ll ans=x;
    for(ll i=2;i*i<=x;++i){
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ans=ans/x*(x-1);
    return ans;
}
ll qpow(ll a,ll b,ll m){
    ll r=1;
    while(b){
        if(b&1)r=r*a%m;
        a=a*a%m;
        b>>=1;
    }
    return r;
}
ll cap(int l,int r,ll lim){//判断幂塔是否达到界限，返回min(区间幂塔的真实值,lim)
    if(lim==1||w[l]==1)return 1;
    if(l==r)return min(w[l],lim);
    ll v=1,need=0;//找最小的need，使w[l]^need>=lim
    while(v<lim){
        v=min(v*w[l],lim);
        ++need;
    }
    ll e=cap(l+1,r,need);//只需知道后面的指数是否达到need
    if(e==need)return lim;
    v=1;//e<need，真实结果小于lim，可以直接计算
    while(e--)v*=w[l];
    return v;
}
ll cal(int l,int r,int pos){//求区间幂塔对f[pos]的余数
    ll m=f[pos];
    if(m==1)return 0;
    if(w[l]==1)return 1;
    if(l==r)return w[l]%m;
    ll next=f[pos+1];//phi(m)
    ll e=cal(l+1,r,pos+1);//后面幂塔对phi(m)的余数
    if(cap(l+1,r,next)==next)
        e+=next;//真实指数足够大，要加phi(m)
    return qpow(w[l],e,m);
}
void solve(){
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    f.clear();
    f.push_back(m);
    while(f.back()!=1)f.push_back(phi(f.back()));
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<cal(l,r,0)<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}