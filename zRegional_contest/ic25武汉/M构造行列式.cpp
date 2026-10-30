//https://qoj.ac/contest/2609/problem/14731
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j)cout<<a[i]<<' ';
            else cout<<(a[i]+1)%MOD<<' ';
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}