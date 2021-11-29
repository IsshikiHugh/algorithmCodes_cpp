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
const int N = 1e7+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,a[200],b[200];


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> n;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) cin >> b[i];
        std::sort(a+1,a+n+1,cmp);
        std::sort(b+1,b+n+1,cmp);
        bool flag = true;
        rep(i,1,n){
            if(a[i] == b[i]) continue;
            if(b[i] - a[i] == 1) continue;
            flag = false;
            break;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }    


    return 0;
}

