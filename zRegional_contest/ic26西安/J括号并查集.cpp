//https://qoj.ac/contest/4580/problem/20060
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int p[N],pos[N];
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return 0;
    p[x]=y;
    return 1;
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        p[i]=i;
        pos[i]=0;
    }
    for(int i=1;i<=2*n;++i){
        int x;cin>>x;
        int k=(i+1)/2;
        if(!pos[x])pos[x]=k;
        else merge(pos[x],k);
    }
    string s;
    for(int i=1;i<=n;++i)s+="()";
    for(int i=1;i<n;++i){
        if(merge(i,i+1)){
            s[2*i-1]='(';
            s[2*i]=')';
        }
    }
    cout<<s<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
代码先构造 ()()…()，把位置 2i-1、2i 看作第 i 组。
读取数组时，用并查集合并相同数字所在的组。读完后，每个集合对应图中的一个环。
然后依次检查相邻组 i、i+1：
- 已经在同一个环中：不修改。
- 属于不同环：合并集合，同时把位置 2i、2i+1 的 )( 改成 ()，使两个环合成一个环。
这种修改始终保持括号串合法；遍历结束后所有组连通，便得到包含全部位置的一个环。
*/