//https://codeforces.com/gym/104869/problem/E
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=105,mod=1e9+7;
int d[N][N][2];
void solve(){
    int x,y,p,q;cin>>x>>y>>p>>q;
    memset(d,-1,sizeof(d));
    queue<array<int,3>>qe;
    qe.push({x,y,0});
    d[x][y][0]=0;
    while(!qe.empty()){
        auto [a,b,s]=qe.front();qe.pop();
        if(a==0&&s==1){
            cout<<d[a][b][s]<<'\n';
            return;
        }
        if(s){
            for(int i=0;i<=min(p,x-a);++i){
                for(int j=0;j<=min(p-i,y-b);++j){
                    if((x-i-a>0)&&(x-i-a+q<y-j-b))continue;
                    if(d[a+i][b+j][0]!=-1)continue;
                    d[a+i][b+j][0]=d[a][b][1]+1;
                    qe.push({a+i,b+j,0});
                }
            }
        }else{
            for(int i=0;i<=min(p,a);++i){
                for(int j=0;j<=min(p-i,b);++j){
                    if((a-i>0)&&(a-i+q<b-j))continue;
                    if(d[a-i][b-j][1]!=-1)continue;
                    d[a-i][b-j][1]=d[a][b][0]+1;
                    qe.push({a-i,b-j,1});
                }
            }
        }
    }
    cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}
/*
状态来回变化+求最少操作次数->状态图+bfs
有一个局面
每次可以做若干操作
操作后进入新局面
允许来回（状态有单调性）
问最少几步到达目标
状态总数不大
*/