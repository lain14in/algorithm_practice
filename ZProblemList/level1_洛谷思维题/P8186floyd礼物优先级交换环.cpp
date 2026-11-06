#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);

void solve(){
    int n;cin>>n;
    vector<vector<int>>a(n+1,vector<int>(n+1));
    vector<vector<int>>f(n+1,vector<int>(n+1));
    for(int i=1;i<=n;++i){
        int t=1;
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            if(t)f[i][a[i][j]]=1;
            if(a[i][j]==i)t=0;//优先级低于当前拿的礼物
        }
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i){
            if(!f[i][k])continue;//跳过i不能到k的
            for(int j=1;j<=n;++j)
                f[i][j]|=f[k][j];//i能到k,k能到j,则i能到j
        }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){//优先级高到低
            int v=a[i][j];
            if(f[v][i]){//v可以回到i,能形成交换环
                cout<<v<<'\n';
                break;
            }
            if(v==i)break;//不能比自己手里的礼物优先级更低
        }
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
/*
把“奶牛`i`愿意拿礼物`j`”看成有向边`i→j`，关键是重新分配实际上由若干个交换环组成：
若`i`想拿`j`的礼物，就需要从`j`沿着其他奶牛愿意的交换关系回到`i`，才能保证所有参与者都有礼物且不会变差。
因此，先把每行愿望单中自己及排在自己前面的礼物连边，用Floyd求出任意两点之间的可达性，
再按每头奶牛的喜好顺序，找到第一个能回到自己的礼物编号并输出；时间复杂度为\(O(n^3)\)。
*/