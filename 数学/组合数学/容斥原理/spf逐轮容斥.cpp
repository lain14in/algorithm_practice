//https://ac.nowcoder.com/acm/contest/22529/E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=5e5+5,mod=1e9+7;
const double eps=1e-9;
int spf[N],cnt[N];
bool vis[N];
void init(){
    for(int i=2;i<N;++i){
        if(spf[i])continue;
        for(int j=i;j<N;j+=i)
            if(!spf[j])spf[j]=i;
    }
}
vector<pair<int,int>>get(int x){
    vector<pair<int,int>>v;
    v.push_back({1,1});
    while(x>1){
        int p=spf[x];
        while(x%p==0)x/=p;
        int sz=v.size();
        for(int i=0;i<sz;++i)
            v.push_back({v[i].first*p,-v[i].second});
    }
    return v;
}
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    init();
    ll ans=0;
    while(q--){
        int id;cin>>id;
        auto v=get(a[id]);
        if(!vis[id]){
            for(auto [d,s]:v)ans+=(ll)s*cnt[d];
            for(auto [d,s]:v)++cnt[d];
        }else{
            for(auto [d,s]:v)--cnt[d];
            for(auto [d,s]:v)ans-=(ll)s*cnt[d];
        }
        vis[id]^=1;
        cout<<ans<<'\n';
    }
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