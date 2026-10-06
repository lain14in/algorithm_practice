//https://codeforces.com/problemset/problem/2223/B
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pll=pair<ll,ll>;
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
bool cmp(pll a,pll b){
    return a.first*b.second<a.second*b.first;
}
void solve(){
    ll n;cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    if(n==1){cout<<"0\n";return;}
    vector<pll>v;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ll x=min(b[i],b[j]),y=max(b[i],b[j]);
            v.push_back({y,x});
        }
    }
    sort(v.begin(),v.end(),cmp);
    ll ans=0,c=n*(n-1)/2;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(a[i]>a[j]){
                pll x={a[i],a[j]};
                ll t=lower_bound(v.begin(),v.end(),x,cmp)-v.begin();
                ans+=c+t;
            }else{
                pll x={a[j],a[i]};
                ll t=upper_bound(v.begin(),v.end(),x,cmp)-v.begin();
                ans+=c-t;
            }
        }
    }
    ans=ans%mod*qpow(n*(n-1)%mod,mod-2)%mod;
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
期望的线性，所以可以固定两点看ai*bi和aj*bj的逆序排列，预处理排序然后分类讨论
for(每对位置 i<j){
    if(a[i]>a[j])
        成功数 = 所有b对都至少成功一次 + b比值<a[i]/a[j]的数量;
    else if(a[i]<=a[j])
        成功数 = b比值>a[j]/a[i]的数量;
}
*/