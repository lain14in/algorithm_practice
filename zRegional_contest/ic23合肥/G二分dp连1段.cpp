//https://codeforces.com/gym/104857/problem/G
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7,INF=1e9;
const double eps=1e-9,pi=2*acos(0);
int n,m,k;
vector<int>pre,last;//pre[i]:1~i中0的个数，last[i]:1~i中最后一个0的位置
string s;
bool ck(int x){
    vector<int>dp(n+1),ndp(n+1);//dp[i][j]:前j个字符当中，选i个长度>=x的连1串需要的最少操作数
    for(int i=1;i<=k;++i){
        fill(ndp.begin(),ndp.end(),INF);
        for(int j=x;j<=n;++j){
            int p=i==1?1:last[j-x];//上一个连1段的最终位置
            if(p)ndp[j]=min(ndp[j-1],dp[p-1]+pre[j]-pre[j-x]);//当前作不作为第i个连1段
        }
        dp.swap(ndp);
    }
    return dp[n]<=m;
}
void solve(){
    cin>>n>>m>>k>>s;
    s=" "+s;
    pre.assign(n+1,0),last.assign(n+1,0);
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+(s[i]=='0');
        last[i]=s[i]=='0'?i:last[i-1];
    }
    int L=1,R=n,ans=-1;
    while(L<=R){
        int mid=(L+R)/2;
        if(ck(mid)){ans=mid;L=mid+1;}
        else R=mid-1;
    }
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