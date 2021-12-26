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
int _,n,a[2*N],less[2*N],equal[2*N],stack[2*N],top;
ll ans;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> n;
        rep(i,1,n) cin >> a[i];
        std::sort(a+1,a+n+1,cmp);
        rep(i,0,n+10) less[i] = equal[i] = stack[i] = 0;
        top = 5;
        int p = 1;
        rep(i,0,n){
            if(i > 0) less[i] += equal[i-1] + less[i-1];
            while(p <= n && a[p] < i) ++less[i],++p;
            while(p <= n && a[p] == i) ++equal[i],++p;
            // cout << less[i] << " ; ";
        }
        // cout << "\n";
        bool unable = false;
        ans = 0;
        rep(i,0,n){
            if(unable){
                cout << "-1 ";
            } else if(less[i] < i){
                unable = true;
                cout << "-1 ";
            } else {
                if(i == 0) ans = equal[0];
                else {
                    // cout << "debug :: " << ans << " " << equal[i-1] << " " << equal[i] << " ";
                    if(i > 1){
                        if(equal[i-2] > 1) stack[++top] = i-2;
                    }
                    ans -= equal[i-1];
                    ans += equal[i];
                    if(equal[i-1] == 0){
                        --equal[ stack[top] ];
                        ans += i-1 - stack[top];
                        if(equal[ stack[top] ] <= 1) --top;
                    }
                }
                cout << ans << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}

