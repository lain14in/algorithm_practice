//https://ac.nowcoder.com/acm/contest/21289/A
//欧拉定理一般情况求逆，但是会超时，换别的单组数据可过
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=2e5+5,MOD=1e9+7;
const double eps=1e-6;
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll qpow(ll a,ll b,ll mod){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
ll phi(ll n){
    ll r=n;
    for(ll i=2;i*i<=n;++i){
        if(n%i)continue;
        r=r/i*(i-1);
        while(n%i==0)n/=i;
    }
    if(n>1)r=r/n*(n-1);
    return r;
}
void solve(){
    ll a,b;cin>>a>>b;
    if(gcd(a,b)!=1)cout<<-1<<'\n';
    else cout<<qpow(a,phi(b)-1,b)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}