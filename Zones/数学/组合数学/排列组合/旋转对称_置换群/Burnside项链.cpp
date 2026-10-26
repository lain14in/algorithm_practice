//https://vjudge.net/problem/CSES-2209
//Σ每种操作的等价方案数/操作数，每旋转k个位置，同一个环的珠子同色，有m种颜色，回到起点的步数就是环长，gcd(n,k)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
void solve(){
    int n,m;cin>>n>>m;
    ll ans=0;
    for(int i=0;i<n;++i){
        ans=(ans+qpow(m,__gcd(i,n)))%mod;
    }
    cout<<ans*qpow(n,mod-2)%mod;
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