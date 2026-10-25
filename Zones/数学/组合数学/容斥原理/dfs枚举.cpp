//https://ac.nowcoder.com/acm/contest/22529/B
//dfs枚举实现
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=1e6+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
ll ans,a[21],L,R,k;
void dfs(int i,ll x,int s){
    ans+=s*(R/x-(L-1)/x);
    for(int j=i;j<k;++j)
        if(x<=R/a[j])
            dfs(j+1,x*a[j],-s);
}
void solve(){
    cin>>L>>R>>k;
    for(int i=0;i<k;++i)cin>>a[i];
    dfs(0,1,1);
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