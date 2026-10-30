//https://codeforces.com/gym/104821/problem/I
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
void solve(){
    ll n;int m;cin>>n>>m;
    vector<pair<ll,ll>>a(m+1);
    a[0]={0,0};
    for(int i=1;i<=m;++i)cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());//按操作次数排序
    bool ok=1;
    for(int i=1;i<=m;++i){
        ll d=a[i].first-a[i-1].first;//两条记录之间的操作次数
        ll x=a[i-1].second,y=a[i].second;
        if(y!=x+d&&y>=d){
            ok=0;
            break;
        }
    }
    cout<<(ok?"Yes":"No")<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}