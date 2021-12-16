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
int _,n,a[2*N],stack[2*N],top,cnt,lim;
std::set<int> st;
bool flag[2*N];

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        bool ans = true;
        top = 0;
        cin >> n;
        rep(i,1,n) flag[i] = false;
        lim = 0;
        rep(i,1,n) cin >> a[i];
        std::sort(a+1,a+n+1,cmp);
        per(i,n,1){
            if(a[i] <= n){
                lim = i;
                break;
            }
            stack[++top] = (a[i]-1)/2;
        }
        per(i,lim,1){
            if(a[i] != a[i+1]) flag[a[i]] = true;
            else stack[++top] = (a[i]-1)/2;
        }
        cnt = top;
        // cout << "debug bein::\n";
        // rep(i,1,top) cout << stack[i] << " ";
        // cout << "\ndebug end::\n";
        rep(i,1,n){
            if(!flag[i]){
                if(stack[top] >= i) --top;
                else {
                    ans = false;
                    break;
                }
                continue;
            } else continue;
        }
        if(ans) cout << cnt << "\n";
        else cout << "-1\n";
    }

    return 0;
}

