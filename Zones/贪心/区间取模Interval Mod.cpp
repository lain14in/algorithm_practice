//https://codeforces.com/problemset/problem/2215/A
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;

void solve(){
    ll n,k,p,q,s=0;cin>>n>>k>>p>>q;
    vector<ll>b(n+1),c(n+1),d(n+1);
    for(ll i=1,a;i<=n;++i){
        cin>>a;
        b[i]=a%p;
        c[i]=a%q%p;
        d[i]=min(b[i],c[i]);
        s+=d[i];
    }
    ll ans=4e18,x=0,y=0,z=0;
    for(int i=1;i<=n;++i){
        x+=b[i];
        y+=c[i];
        z+=d[i];
        if(i>k){
            x-=b[i-k];
            y-=c[i-k];
            z-=d[i-k];
        }
        if(i>=k)ans=min(ans,s-z+min(x,y));
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