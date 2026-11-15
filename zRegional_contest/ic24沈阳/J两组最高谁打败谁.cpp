#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    map<int,string>a,b;
    int mx1=0,mx2=0;
    for(int i=1;i<=4;++i){
        string s;cin>>s;
        int x;cin>>x;
        a[x]=s;
        mx1=max(mx1,x);
    }
    for(int i=5;i<=8;++i){
        string s;cin>>s;
        int x;cin>>x;
        b[x]=s;
        mx2=max(mx2,x);
    }
    if(mx1>mx2)cout<<a[mx1]<<" beats "<<b[mx2];
    else cout<<b[mx2]<<" beats "<<a[mx1];
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