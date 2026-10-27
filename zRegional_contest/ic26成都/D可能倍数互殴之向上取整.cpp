//https://qoj.ac/contest/4600/problem/23595
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    ll ha,hb,a,b;cin>>a>>b>>ha>>hb;
    ll t=(hb+a-1)/a;//a打死b需要的最少次数
    if((i128)(t+3)*b<ha)cout<<"YES\n";//最后一轮打4下，多出3倍攻击，a不能被b打死
    else cout<<"NO\n";
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