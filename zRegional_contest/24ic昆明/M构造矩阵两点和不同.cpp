//https://codeforces.com/gym/105588/problem/M
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;

void solve(){
    cout<<"YES\n";
    int n,m;cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int s=0,cnt=0;s<=n+m-2;++s){
        int l=max(0,s-(m-1)),r=min(n-1,s);
        for(int i=l;i<=r;++i){
            int j=s-i;
            a[i][j]=++cnt;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}