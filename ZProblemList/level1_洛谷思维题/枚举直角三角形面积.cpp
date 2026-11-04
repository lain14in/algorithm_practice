using namespace std;
#include<bits/stdc++.h>
using ll=long long;
using db=double;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
void calc(map<int,vector<pii>>&g,vector<ll>&d){
    for(auto &[key,v]:g){
        sort(v.begin(),v.end());
        int k=v.size();
        ll sum=0,pre=0;
        for(auto [x,id]:v)sum+=x;
        for(int i=0;i<k;++i){
            ll x=v[i].first;
            int id=v[i].second;
            ll L=x*i-pre;
            ll R=sum-pre-(k-i)*x;
            d[id]=(L+R)%mod;
            pre+=x;
        }
    }
}
void solve(){
    int n;cin>>n;
    map<int,vector<pii>>gx,gy;
    vector<ll>h(n+1),v(n+1);
    for(int i=1;i<=n;++i){
        int x,y;cin>>x>>y;
        gx[x].push_back({y,i});
        gy[y].push_back({x,i});
    }
    calc(gx,v);calc(gy,h);
    ll ans=0;
    for(int i=1;i<=n;++i)ans=(ans+h[i]*v[i])%mod;
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
/*
枚举每个点作为直角顶点，它到同一行所有点的水平距离之和为 `h[i]`，到同一列所有点的竖直距离之和为 `v[i]`，
每条横边都能与每条竖边搭配，所以该点贡献的面积两倍之和为 `h[i]*v[i]`。代码按横、纵坐标分别分组，组内排序，
利用前缀和计算每个点到组内其他点的距离之和，最后累加所有点的 `h[i]*v[i]` 并取模，时间复杂度为 `O(n log n)`。
*/