//https://ac.nowcoder.com/acm/contest/21289/B
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=3e6+5,mod=1e9+7;
const double eps=1e-6;
ll inv[N]={1,1};
void solve(){
    ll n,p;cin>>n>>p;
    cout<<"1\n";
    for(int i=2;i<=n;++i){
        inv[i]=(p-p/i)*inv[p%i]%p;
        cout<<inv[i]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}