//https://www.luogu.com.cn/problem/P1446
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
ll sr,sb,sg,n,m,P;
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%P;
        a=a*a%P;
        b>>=1;
    }
    return r;
}
ll cal(vector<ll>&c){
    ll dp[21][21]={{1}},ndp[21][21],tot=0;
    for(ll w:c){
        memset(ndp,0,sizeof(ndp));
        for(ll r=0;r<=sr;++r){
            for(ll b=0;b<=sb;++b){
                if(!dp[r][b])continue;
                if(r+w<=sr)ndp[r+w][b]=(ndp[r+w][b]+dp[r][b])%P;
                if(b+w<=sb)ndp[r][b+w]=(ndp[r][b+w]+dp[r][b])%P;
                if(tot-r-b+w<=sg)ndp[r][b]=(ndp[r][b]+dp[r][b])%P;
            }
        }
        memcpy(dp,ndp,sizeof(dp));
        tot+=w;
    }
    return dp[sr][sb];
}
void solve(){
    cin>>sr>>sb>>sg>>m>>P;
    n=sr+sb+sg;
    vector<ll>id(n,1);
    ll ans=cal(id);
    for(int t=0;t<m;++t){
        vector<ll>p(n+1),vis(n+1),c;
        for(int i=1;i<=n;++i)cin>>p[i];
        for(int i=1;i<=n;++i){
            if(vis[i])continue;
            int x=i,len=0;
            while(!vis[x]){
                vis[x]=1;
                ++len;
                x=p[x];
            }
            c.push_back(len);
        }
        ans=(ans+cal(c))%P;
    }
    ans=ans*qpow(m+1,P-2)%P;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}
/*
用Burnside引理：把“经过允许洗牌能互相得到”的染色看成同一类，答案等于所有群元素下“不变染色数”的平均值。
对某个具体置换，先拆成若干置换环；一个染色想在这个置换下保持不变，同一环里的所有位置必须同色，
所以每个环相当于一个不可拆分、大小等于环长的块，只能整体染红/蓝/绿。
于是用 `dp[r][b]` 统计处理若干环后用了多少红、多少蓝，绿色由已处理总数减去红蓝得到；
每个环做三种转移。恒等置换就是 `n` 个长度 1 的环。
把恒等置换和题目给出的 `m` 个置换的固定染色数全部相加，
最后乘上 `(m+1)` 在模 `P` 下的逆元即可。
*/