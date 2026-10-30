//https://qoj.ac/contest/2609/problem/14726
//异或按前缀分组，低位全1/全0得最大最小值还原数组
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7,mask=(1<<30)-1;
const double eps=1e-9,pi=2*acos(0);
int n;
vector<int>ans;
int ask(int c){
    cout<<"? "<<c<<endl;
    int r;
    if(!(cin>>r)||r==-1)exit(0);
    return c^r;
}
void dfs(int x,int b,int t){//x传入某组极值,t=1最大,t=0最小,b为当前组低位位数
    if((int)ans.size()==n||b<0)return;
    int low=(1<<(b+1))-1;
    int c=(mask^x)&(mask^low);//查该组最大，高位取反，低位全0
    if(t)c|=low;//查最小
    int y=ask(c);
    if(x==y)return;
    ans.push_back(y);
    if((int)ans.size()==n)return;
    int k=b;
    while(!(((x^y)>>k)&1))--k;//找到x与y最高的不同位分组，x!=y保证能找到
    dfs(min(x,y),k-1,0);
    dfs(max(x,y),k-1,1);
}
void solve(){
    cin>>n;
    ans.clear();
    int x=ask(0);
    ans.push_back(x);
    dfs(x,29,1);
    cout<<"! ";
    for(int v:ans)cout<<v<<' ';
    cout<<endl;
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