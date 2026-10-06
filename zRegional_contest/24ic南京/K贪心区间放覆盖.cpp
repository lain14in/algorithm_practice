//https://codeforces.com/gym/105484/problem/K
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
void solve(){
    int n,m,k,w,cnt=0;cin>>n>>m>>k>>w;
    vector<int>a(n+1),b(m+2),l(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)cin>>b[i];
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.begin()+m+1);
    b[m+1]=w+1;
    for(int i=1,j=0;j<=m;++j){
        int lcnt=cnt;
        while(i<=n&&a[i]<b[j+1]){
            l[cnt++]=a[i];
            while(i<=n&&a[i]<b[j+1]&&a[i]<=l[cnt-1]+k-1)++i;
        }
        if(cnt==lcnt)continue;
        if(l[cnt-1]+k-1>=b[j+1]){
            l[cnt-1]=b[j+1]-k;
            for(int t=cnt-1;t>lcnt&&l[t-1]+k-1>=l[t];--t)
                l[t-1]=l[t]-k;
            if(l[lcnt]<=b[j]){
                cout<<"-1\n";
                return;
            }
        }
    }
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;++i)cout<<l[i]<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
黑点为端点，分段贪心，先尽可能往右放一轮，最右边那个如果超了就往左摞动，
和左边的交叉了也往左摞动，每次左摞尽量少摞，最左边的超了那就不成立输出-1
*/