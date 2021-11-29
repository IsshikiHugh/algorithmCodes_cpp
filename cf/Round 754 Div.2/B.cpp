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
int _,n,a[2*N],cnt_1,cnt_0,cnt_x;
string str;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cnt_1 = a[0] = 0;
        cin >> n >> str;
        n = str.length();
        rep(i,1,n) cnt_1 += str[i-1] - '0';
        cnt_0 = n - cnt_1;
        rep(i,1,n){
            if(str[i-1] == '1' && i <= cnt_0){
                a[ ++a[0] ] = i;
            } else if(str[i-1] == '0' && i > cnt_0){
                a[ ++a[0] ] = i;
            }
        }
        if(a[0] != 0) cout << "1\n";
        cout << a[0] << " ";
        rep(i,1,a[0]) cout << a[i] << " ";
        cout << "\n";
    }


    return 0;
}

