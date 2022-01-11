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
int _,n,a[2*N],cnt,k;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cnt = 0;
        cin >> n >> k;
        rep(i,1,n){
            char ch;
            cin >> ch;
            a[i] = ch - 'a' + 1;
        }
        std::sort(a+1,a+n+1);
        rep(i,1,n-1){
            if(a[i] == a[i+1]){
                ++cnt;
                ++i;
            }
        }
        n -= cnt * 2;
        int t = (cnt/k);
        cnt -= t*k;
        n += cnt * 2;
        int ans = 2*t;
        if(n >= k) ans += 1;

        
        cout << ans << "\n";
    }


    return 0;
}

