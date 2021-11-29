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
int _,n,a[2*N],st,ed,ans;
char ch;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> n;
        rep(i,1,n){
            cin >> ch;
            a[i] = ch - 'a' + 1;
        }
        st = 1 , ed = n;
        while(a[st] != 1 && st <= n) ++st;
        while(a[ed] != 1 && ed > st) --ed;
        ans = 10;
        rep(i,ed+1,ed+10) a[i] = 3;
        rep(i,st,ed){
            if(a[i] == 1){
                if(a[i+1] == 1){ // aa
                    ans = 2;
                    break;
                } else if(a[i+2] == 1){ // axa
                    ans = std::min(ans,3);
                    continue;
                } else if(a[i+3] == 1 && a[i+1] != a[i+2]){ // axya
                    ans = std::min(ans,4);
                    continue;
                } else if(a[i+3] == 1 && a[i+4] == a[i+5] && a[i+4] != 1 && a[i+6] == 1 && a[i+1] != a[i+4]){ // axxayya
                    ans = std::min(ans,7);   
                    continue;
                }
            }
        }
        if(ans == 10) ans = -1; 
        cout << ans << "\n";
    }    


    return 0;
}

