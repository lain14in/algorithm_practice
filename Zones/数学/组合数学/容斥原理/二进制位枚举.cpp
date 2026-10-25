//https://ac.nowcoder.com/acm/contest/22529/B
//二进制位枚举实现
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    ll L,R,k;cin>>L>>R>>k;
    ll ans=0;
    vector<ll>a(k);
    for(int i=0;i<k;++i)cin>>a[i];
    for(int s=0;s<(1<<k);++s){
        ll x=1;
        bool ok=1;
        for(int i=0;i<k;++i){
            if((s>>i)&1){
                if(x>R/a[i]){
                    ok=0;
                    break;
                }
                x*=a[i];
            }
        }
        if(!ok)continue;
        ll cnt=R/x-(L-1)/x;
        if(__builtin_popcount(s)&1)ans-=cnt;
        else ans+=cnt;
    }
    cout<<ans;
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