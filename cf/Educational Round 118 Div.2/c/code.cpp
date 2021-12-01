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
const int N = 100+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n;
ll a[2*N],delta[2*N],h,last,ans;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> n >> h;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n-1) delta[i] = a[i+1] - a[i];
        std::sort(delta+1,delta+n,cmp);
        last = 0 , delta[0] = 0 , ans = -1;
        rep(i,1,n-1){
            int nn = n - i + 1;
            if((delta[i]-delta[i-1]) * nn + last < h){
                last += (delta[i]-delta[i-1]) * nn;
                continue;
            }
            h -= last;
            ans = (h-1)/nn + 1 + delta[i-1];
            break;
        }
        if(ans == -1) ans = delta[n-1] + ( h - last );
        cout << ans << "\n";
    }    
    return 0;
}

