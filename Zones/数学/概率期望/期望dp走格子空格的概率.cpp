//https://vjudge.net/problem/CSES-1726
//概率题先明确状态和事件，期望题先考虑能否拆成多个贡献
//对每个机器人用概率DP求出走k步后到各格子的概率，
//再利用独立性将所有机器人“不在某格”的概率相乘，得到该格为空的概率，由期望的线性，最后对所有格子求和就是期望。
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
int dx[]={1,-1,0,0},dy[]={0,0,1,-1},cnt[8][8];//dx/dy模拟走格子 cnt每格合法可走方向数
long double dp[8][8],ndp[8][8],p[8][8];//dp当前机器人该格概率 ndp下一步dp概率 p已处理机器人都不在该格的概率
bool in(int x,int y){
    return x>=0&&x<8&&y>=0&&y<8;
}
void solve(){
    int k;cin>>k;
    for(int x=0;x<8;++x)
        for(int y=0;y<8;++y){
            p[x][y]=1;//未处理，初始化1
            for(int d=0;d<4;++d)
                if(in(x+dx[d],y+dy[d]))++cnt[x][y];
        }
    for(int sx=0;sx<8;++sx)//枚举处理64个机器人
        for(int sy=0;sy<8;++sy){
            memset(dp,0,sizeof(dp));
            dp[sx][sy]=1;//最初一定在此
            for(int i=1;i<=k;++i){//走k步
                memset(ndp,0,sizeof(ndp));
                for(int x=0;x<8;++x)
                    for(int y=0;y<8;++y)
                        for(int d=0;d<4;++d){
                            int nx=x+dx[d],ny=y+dy[d];
                            if(in(nx,ny))ndp[nx][ny]+=dp[x][y]/cnt[x][y];//当前位置概率平均分配给邻居
                        }
                memcpy(dp,ndp,sizeof(dp));
            }
            for(int x=0;x<8;++x)
                for(int y=0;y<8;++y)
                    p[x][y]*=1-dp[x][y];//当前机器人最终不在(x,y)的概率
        }
    long double ans=0;
    for(int x=0;x<8;++x)
        for(int y=0;y<8;++y)
            ans+=p[x][y];//p[x][y]当前格子为空的概率。利用期望线性求和
    cout<<fixed<<setprecision(6)<<ans;
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