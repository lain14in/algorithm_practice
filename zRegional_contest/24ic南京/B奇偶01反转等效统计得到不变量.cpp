//https://codeforces.com/gym/105484/problem/B
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e6+5,mod=1e9+7;
void solve(){
    string s,t;cin>>s;
    for(int i=0,j=0;i<(int)s.size();++i){
        t+=s[i];
        while(t.size()>=2&&t[j]==t[j-1])t.pop_back(),t.pop_back(),j-=2;
    }
    int c0=0,c1=0,c2=0,ans=INT_MAX;
    for(int i=0;i<(int)t.size();++i){
        if(!(i&1)&&t[i]!='2')t[i]^=1;
        if(t[i]=='0')++c0;
        else if(t[i]=='1')++c1;
        else ++c2;
    }
    for(int i=0;i<=c2;++i)
        ans=min(ans,abs(2*i+c0-c1-c2));
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
1，先优化一下，去除00/11连续段，剩下的全是携带2的01交叉的串
2，（核心点）找1/0的相邻相同的，相当于把偶数位全部0/1翻转，找01交叉不同的数量，
   对于交叉数量的抵消，0、1数量是同时-1的，所以0、1总数之差不变，统计差值即可
3，由于2可以变为0/1，直接设变出i个0，那就是2的数量-i个1，0和1的总数做差取绝对值，然后遍历一遍求max即可
*/