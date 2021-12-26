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
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,m,a[2*N],minTop1ByFriends,maxTop2ByShops,top1ByFriends[2*N],top2ByShops[2*N];

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> m >> n;
        rep(j,1,m) rep(i,1,n) cin >> a[(i-1)*m + (j-1)];
        minTop1ByFriends = inf , maxTop2ByShops = 0;
        rep(i,1,n){
            top1ByFriends[i] = 0;
            rep(j,1,m){
                if(a[ (i-1)*m + (j-1) ] > top1ByFriends[i]) top1ByFriends[i] = a[ (i-1)*m + (j-1) ];
            }
        }
        rep(j,1,m){
            int tmpMax = j-1;
            rep(i,1,n){
                if(a[ (i-1)*m + (j-1) ] > a[tmpMax]) tmpMax = (i-1)*m + (j-1);
            }
            top2ByShops[j] = 0;
            rep(i,1,n){
                if((i-1)*m + (j-1) == tmpMax) continue;
                if(a[ (i-1)*m + (j-1) ] > top2ByShops[j]) top2ByShops[j] = a[ (i-1)*m + (j-1) ];
            }
        }
        minTop1ByFriends = inf;
        rep(i,1,n){
            minTop1ByFriends = std::min(minTop1ByFriends,top1ByFriends[i]);
        }
        maxTop2ByShops = 0;
        rep(j,1,m){
            maxTop2ByShops = std::max(maxTop2ByShops,top2ByShops[j]);
        }
        // cout << "debug::  " << minTop1ByFriends << "   " << maxTop2ByShops << "  \n";
        cout << std::min(minTop1ByFriends,maxTop2ByShops) << "\n";
    }


    return 0;
}

