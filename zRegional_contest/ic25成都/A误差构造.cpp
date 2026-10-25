//https://codeforces.com/gym/106161/problem/A
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using db=double;
const int N=2e5+5,mod=998244353;
void solve(){
    int n;cin>>n;
    ll s=0;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i])b[i]=(10*a[i]-5)*100;
        else b[i]=0;
        s+=b[i];
    }
    s=100000-s;
    for(int i=1;i<=n&&s>0;++i){
        int x;
        if(a[i]==0)x=499;
        else if(a[i]==100)x=500;
        else x=999;
        if(s>=x){
            b[i]+=x;
            s-=x;
        }else{
            b[i]+=s;
            s=0;
        }
    }
    if(s!=0){cout<<"No\n";return;}
    else cout<<"Yes\n";
    for(int i=1;i<=n;++i)cout<<b[i]<<' ';
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
误差分析、构造
*/