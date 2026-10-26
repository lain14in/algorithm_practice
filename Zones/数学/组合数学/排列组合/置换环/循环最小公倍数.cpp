//https://vjudge.net/problem/CSES-3398
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
using pii=pair<int,int>;
const int N=2e5+5,mod=1e9+7;
const double eps=1e-9,pi=2*acos(0);
int f[N];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    f[x]=y;
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)f[i]=i;
    for(int i=1;i<=n;++i){
        int p;cin>>p;
        merge(i,p);
    }
    vector<int>cnt(n+1),mx(n+1);
    for(int i=1;i<=n;++i)++cnt[find(i)];//置换环的长度数量（连通块元素数量）
    for(int i=1;i<=n;++i){
        int x=cnt[i];
        if(x<=1)continue;
        for(int j=2;j*j<=x;++j){
            if(x%j)continue;
            int c=0;
            while(x%j==0)x/=j,++c;
            mx[j]=max(mx[j],c);//更新质数j的最大指数
        }
        if(x>1)mx[x]=max(mx[x],1);//处理剩下的质数x
    }
    ll ans=1;
    for(int i=2;i<=n;++i)
        for(int j=0;j<mx[i];++j)//不是质数其实就是0，直接跳过的
            ans=ans*i%mod;//i出现mx[i]次
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