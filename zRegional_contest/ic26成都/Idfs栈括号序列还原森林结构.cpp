//https://qoj.ac/contest/4600/problem/23600
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
void cat(){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1);
    for(int i=0,u,v;i<m;++i){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>a(n+1),fa(n+1),st;
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(a[i])continue;
        st.push_back(i);
        while(!st.empty()){
            int u=st.back();st.pop_back();
            if(u<0){++cnt;continue;}
            a[u]=++cnt;
            st.push_back(-u);
            for(int v:g[u]){
                if(v==fa[u])continue;
                fa[v]=u;
                st.push_back(v);
            }
        }
    }
    for(int i=1;i<=n;++i)cout<<a[i]<<' ';
    cout<<'\n';
}
void dog(){
    int n;cin>>n;
    vector<int>pos(2*n+1),st;
    vector<pii>ans;
    for(int i=1,b;i<=n;++i){
        cin>>b;
        pos[b]=i;
    }
    for(int i=1;i<=2*n;++i){
        if(pos[i]){
            int u=pos[i];
            if(!st.empty())ans.push_back({st.back(),u});
            st.push_back(u);
        }else st.pop_back();
    }
    cout<<ans.size()<<'\n';
    for(auto [u,v]:ans)cout<<u<<' '<<v<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    int T;
    cin>>T;
    while(T--){
        if(s=="cat")cat();
        else dog();
    }
    return 0;
}
/*
I dfs括号序列+栈，
要恢复森林，本质上只需恢复每个非根节点的父亲，DFS 的进入、退出过程，正好能描述父子关系。
括号的嵌套关系记录了树的结构：B、C 的括号都直接包含在 A 的括号中，所以它们的父亲是 A，刚好n个点，可以编号2n。
dfs+栈 来描述结构、反推还原
*/