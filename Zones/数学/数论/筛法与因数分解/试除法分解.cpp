//https://ac.nowcoder.com/acm/contest/21094/D
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e7+9;
const double eps=1e-6,pi=2*acos(0);
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a;
        a=a*a;
        b>>=1;
    }
    return r;
}
void solve(){
    ll k,n=1;cin>>k;
    vector<ll>p,e;
    for(int i=0,pp,ee;i<k;++i){
        cin>>pp>>ee;
        n*=qpow(pp,ee);
    }
    --n;
    for(ll i=2;i*i<=n;++i){
        if(n%i)continue;
        ll cnte=0;
        while(n%i==0)n/=i,++cnte;
        p.push_back(i),e.push_back(cnte);
    }
    if(n>1)p.push_back(n),e.push_back(1);
    for(ll i=(ll)p.size()-1;i>=0;--i)cout<<p[i]<<' '<<e[i]<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}