//https://codeforces.com/contest/2283/problem/D
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
int n;
bool ck(int k,int w,vector<vector<int>>&g){
    vector<int>b(n+1);//b[u]:删除w之后，u所属连通块编号，初始0
    vector<int>st;//栈模拟dfs
    int cnt=0;
    for(int s:g[w]){
        ++cnt;
        b[s]=cnt;
        st.push_back(s);
        while(!st.empty()){
            int u=st.back();st.pop_back();
            for(int v:g[u]){
                if(v==w||b[v])continue;
                b[v]=cnt;
                st.push_back(v);
            }
        }
    }
    for(int i=1;i<=n;++i){
        int j=k-i;
        if(i<j&&j<=n&&b[i]!=b[j])return 1;//配对合法且跨块，路径必经过w，它能变灰
    }
    return 0;//有配对的路径都不经过w，它保持白色
}
void solve(){
    cin>>n;
    vector<vector<int>>g(n+1);
    for(int i=0;i<n-1;++i){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n%2==0){
        cout<<n+1<<'\n';
        return;
    }
    int a[3]={n,(n+1)/2,1};
    for(int i=0;i<3;++i){
        if(ck(n+i,a[i],g)){
            cout<<n+i<<'\n';
            return;
        }
    }
    cout<<n<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
考查**配对规律分析＋树上路径性质＋DFS求连通块**。先只考虑优先级更高的黑点数量：偶数 `n` 选 `k=n+1` 能让所有点变黑；
奇数 `n` 则只有 `n、n+1、n+2` 三个候选能达到最多的 `n-1` 个黑点，接下来只需判断唯一非黑点能否变灰。
利用“删掉一个点后，配对端点分属不同连通块，其原路径就必经过该点”的性质，代码用栈模拟 DFS 标记连通块，
再枚举编号和为 `k` 的配对，找到跨块配对就选择该 `k`；若三个候选都不能产生灰点，任选一个即可，总复杂度为 `O(n)`。
*/