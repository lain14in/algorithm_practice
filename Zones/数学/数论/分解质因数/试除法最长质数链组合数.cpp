//https://ac.nowcoder.com/acm/contest/21094/E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e7+9;
const double eps=1e-6,pi=2*acos(0);
ll fac[30]={1};
void init(){for(int i=1;i<30;++i)fac[i]=i*fac[i-1];}
void solve(){
    ll x;cin>>x;
    vector<ll>e;
    for(int i=2;i*i<=x;++i){
        if(x%i)continue;
        ll c=0;
        while(x%i==0)x/=i,++c;
        e.push_back(c);
    }
    if(x>1)e.push_back(1);
    ll m=0;
    for(ll ee:e)m+=ee;
    cout<<m<<' ';
    ll ans=fac[m];
    for(ll ee:e)ans/=fac[ee];
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    init();
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}