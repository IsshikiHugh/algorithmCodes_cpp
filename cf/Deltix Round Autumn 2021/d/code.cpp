#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define per(i,a,b) for(int i = (a);i >= (b);--i) 
#define mkp std::make_pair
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;
inline bool cmp(int x,int y){return x > y;}
/* -fsanitize=undefined  */
const int N = 1e3+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,a[2*N],fa[2*N],size[2*N],group[2*N],cnt;

void init(){
    rep(i,1,n) fa[i] = i;
    rep(i,1,n) size[i] = 1;
    return;
}

int getfa(int x){
    if(fa[x] == x) return x;
    else return fa[x] = getfa(fa[x]); 
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> n >> _;
    int u,v;
    init();
    while(_--){
        cin >> u >> v;
        fa[u] = getfa(u) , fa[v] = getfa(v);
        if(fa[u] == fa[v]){
            ++cnt;
        } else {
            size[ fa[u] ] += size[ fa[v] ]; 
            fa[ fa[v] ] = fa[u];
        }
        group[0] = 0;
        rep(i,1,n) if(fa[i] == i) group[ ++group[0] ] = size[i];
        std::sort(group+1,group+group[0]+1,cmp);
        if(group[0]-1 < cnt) cout << n-1 << "\n";
        else{
            rep(i,1,cnt) group[1] += group[i+1];
            cout << group[1]-1 << "\n";
        }
    }


    return 0;
}

