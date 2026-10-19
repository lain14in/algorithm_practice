//https://codeforces.com/problemset/problem/991/E
//dfs枚举每一位置的出现次数计数，算组合数
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=20,mod=1e9+7;
const double eps=1e-6,pi=2*acos(0);
ll fac[N+1],ans,cnt[N],c[N];
void init(){
    fac[0]=1;
    for(int i=1;i<=N;++i)fac[i]=fac[i-1]*i;
}
void dfs(ll d){//统计数字d从0~9的选取个数
    if(d==10){
        ll L=0,res;
        for(int i=0;i<=9;++i)L+=c[i];
        res=fac[L];
        for(int i=0;i<=9;++i)res/=fac[c[i]];
        ans+=res;
        if(c[0]){
            res=fac[L-1];
            --c[0];
            for(int i=0;i<=9;++i)res/=fac[c[i]];
            ++c[0];
            ans-=res;
        }
        return;
    }
    if(cnt[d]==0){
        c[d]=0;
        dfs(d+1);
        return;
    }
    for(int i=1;i<=cnt[d];++i){
        c[d]=i;
        dfs(d+1);
    }
}
void solve(){
    init();
    string s;cin>>s;
    for(char ch:s)++cnt[ch-'0'];
    dfs(0);
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