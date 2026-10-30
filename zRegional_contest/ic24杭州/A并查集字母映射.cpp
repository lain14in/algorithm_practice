//https://codeforces.com/gym/105657/problem/A
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
int f[26];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    f[x]=y;
}
void solve(){
    string a,b,c;cin>>a>>b>>c;
    if(a.size()!=b.size()){cout<<"NO\n";return;}
    for(int i=0;i<26;++i)f[i]=i;
    for(int i=0;i<(int)a.size();++i)
        merge(a[i]-'a',b[i]-'a');
    if(a.size()!=c.size()){cout<<"YES\n";return;}
    for(int i=0;i<(int)a.size();++i){
        if(find(a[i]-'a')!=find(c[i]-'a')){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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