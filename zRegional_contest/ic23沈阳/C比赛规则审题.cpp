//https://codeforces.com/gym/104869/problem/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128_t;
const int N=1e6+5,mod=1e9+7;

void solve(){
    int x,y,c=0;cin>>x>>y;
    while(x<3){
        if(x==2||y==2)c+=2;
        else c+=1;
        ++x;
    }
    cout<<c;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}