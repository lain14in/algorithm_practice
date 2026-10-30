//https://qoj.ac/contest/2609/problem/14724
//贪心取尽可能覆盖多的点，然后log_2(cnt)。按区间右端点排序，每次没有覆盖就++cnt加一个选点选当前右端点
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
bool cmp(pair<int,int>a,pair<int,int>b){return a.second<b.second;}
void solve(){
    int n,q;cin>>n>>q;
    vector<pair<int,int>>a(q);
    for(int i=0;i<q;++i)cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end(),cmp);
    int r=0,cnt=0;
    for(int i=0;i<q;++i){//贪心找最小的选点数量
        if(a[i].first>r){//没有被下一个区间覆盖就选右端点
            ++cnt;
            r=a[i].second;
        }
    }
    int ans=0;
    while(cnt){//每次选中间的点,2^ans>cnt的最小ans
        cnt>>=1;
        ++ans;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}