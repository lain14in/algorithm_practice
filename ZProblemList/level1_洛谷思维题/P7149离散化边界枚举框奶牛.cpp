#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=2505;
int s[N][N];//s[i][j]表示x排名<=i且y排名<=j的奶牛数
int query(int l,int r,int d,int u){//统计[x=l..r,y=d..u]内的奶牛数
    return s[r][u]-s[l-1][u]-s[r][d-1]+s[l-1][d-1];
}
void solve(){
    int n;cin>>n;
    vector<pii>a(n); //a[i]牛原来坐标
    vector<int>ys(n),y(n+1);//ys用来给原始y坐标排序，y[i]保存第i头牛的y排名
    for(int i=0;i<n;++i){
        cin>>a[i].first>>a[i].second;
        ys[i]=a[i].second;
    }
    sort(a.begin(),a.end());//按x排序
    sort(ys.begin(),ys.end());//原始的y排序（不分编号，方便后续给点找y的对应排名）
    for(int i=1;i<=n;++i)
        y[i]=lower_bound(ys.begin(),ys.end(),a[i-1].second)-ys.begin()+1;//找第i头牛的y排第几
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(y[i]==j);//离散化坐标(i,y[i]),格子有牛就是j==y[i]
    ll ans=1;//空集
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            int lo=min(y[i],y[j]),hi=max(y[i],y[j]);
            int down=query(i,j,1,lo);
            int up=query(i,j,hi,n);
            ans+=1LL*down*up;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
/*
边界枚举，为了不会有重复，双指针定左右边界，然后上下边界方法数相乘。
核心：
每个非空子集都有唯一的最小外接矩形。所以把矩形的四条边都贴到子集的最外侧，就能让同一个子集只被统计一次。
证明：
对任意非空子集 \(S\)，记它的最小、最大横坐标为 \(x_{\min},x_{\max}\)，最小、最大纵坐标为 \(y_{\min},y_{\max}\)。
任何框住 \(S\) 的矩形都必须包含
\[
[x_{\min},x_{\max}]\times[y_{\min},y_{\max}],
\]
而这个矩形本身就框住了 \(S\)，所以它是**唯一的最小外接矩形**。
如果原来的栅栏恰好框住 \(S\)，把四条边向内收紧到这四个极值，既不会丢掉 \(S\) 中的牛，也不会框进新牛。
收紧后的四条边完全由 \(S\) 决定，所以只枚举这种贴边的矩形，每个可行子集就恰好被数一次。

这题数的是不同的奶牛子集，所以先把每个可行的非空子集对应到它唯一的**最小外接矩形**，这样就不会重复计数。由于所有 \(x\) 坐标不同，
可以枚举最左和最右的两头牛来固定左右边界。为了框住这两头牛，下边界要贴在不高于两牛中较低者的位置，上边界要贴在不低于较高者的位置，
两边各有多少种选法，乘起来就是这对左右边界的贡献。代码先按 \(x\) 排序、将 \(y\) 离散化，再用二维前缀和快速查询左右边界之间的上下候选数，
枚举所有点对累加，允许左右是同一头牛来统计单牛子集，最后算上空集。时间复杂度为 \(O(n^2)\)。
*/