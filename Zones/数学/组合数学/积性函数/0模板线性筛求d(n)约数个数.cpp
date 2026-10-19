//https://ac.nowcoder.com/acm/contest/22769/A
//求约数个数d(n)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const int N=1e7+5,mod=1e9+7;
const double eps=1e-9;
int d[N],p[N],e[N];
void euler_sieve_d(){
    d[1]=1;
    int cnt=0;
    for(int i=2;i<N;++i){
        if(!d[i]){
            p[cnt++]=i;
            d[i]=2;
            e[i]=1;
        }
        for(int j=0;j<cnt;++j){
            if((ll)i*p[j]>N)break;
            if(i%p[j]==0){
                e[i*p[j]]=e[i]+1;
                d[i*p[j]]=d[i]/(e[i]+1)*(e[i*p[j]]+1);
                break;
            }
            e[i*p[j]]=1;
            d[i*p[j]]=d[i]*2;
        }
    }
}
void solve(){
    int q;cin>>q;
    cout<<d[q]<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    euler_sieve_d();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}