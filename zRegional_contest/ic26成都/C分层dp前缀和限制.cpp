//https://qoj.ac/contest/4600/problem/23594
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=105,S=5055,mod=998244353;
int f[N][N][S],pw[N];//f[len][r][s]从1~len中选出r个不同的数，且它们的和为s的方案数
void init(){
    pw[0]=1;
    for(int i=1;i<=100;++i)pw[i]=pw[i-1]*2%mod;//处理2的幂
    f[0][0][0]=1;
    for(int len=1;len<=100;++len){
        for(int r=0;r<=len;++r){
            int l=r*(r+1)/2;
            int h=r*(2*len-r+1)/2;
            for(int s=l;s<=h;++s){
                int v=f[len-1][r][s];
                if(r&&s>=len){
                    v+=f[len-1][r-1][s-len];
                    if(v>=mod)v-=mod;
                }
                f[len][r][s]=v;
            }
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    vector<pii>a(m);
    for(auto &[p,v]:a)cin>>p>>v;
    vector<int>dp(n),ndp(n);//dp[h]满足已经处理的所有限制，且当前最后一个元素为h的方案数。
    dp[0]=1;
    int last=1,old=0;
    for(auto [p,v]:a){
        if(v>p*(p-1)/2){
            cout<<0<<'\n';
            return;
        }
        int len=p-last,delta=v-old;
        fill(ndp.begin(),ndp.end(),0);
        for(int h=0;h<last;++h){
            if(!dp[h])continue;
            int s=delta-len*h;
            if(s<0||s>len*(len+1)/2)continue;
            for(int r=0;r<=len;++r){
                ndp[h+r]=(ndp[h+r]
                    +1LL*dp[h]*f[len][r][s])%mod;
            }
        }
        dp.swap(ndp);
        last=p;
        old=v;
    }
    int ans=0;
    for(int v:dp){
        ans+=v;
        if(ans>=mod)ans-=mod;
    }
    cout<<1LL*ans*pw[n-last]%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
将相邻前缀和限制之间的部分分段处理：若一段长 len、起始值为 h，这段总和就是 len*h 加上各次增量的贡献，而各步增加 1 的贡献依次为 len、len-1、…、1。先预处理 f[len][r][s]，
表示从 1~len 中选 r 个数、和为 s 的方案数；再用 dp[h] 记录满足之前限制且末尾值为 h 的方案数，
对下一段令 s=两次前缀和之差-len*h，通过 ndp[h+r]+=dp[h]*f[len][r][s] 转移。
最后汇总所有状态，再乘上最后一个限制之后自由选择增量的方案数 2^(n-last)。
*/