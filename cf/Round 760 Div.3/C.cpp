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
int _,n;
ll a[2*N],tmp;

ll gcd(ll x,ll y){
    if(!y) return x;
    else return gcd(y,x%y);
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        bool flag = true;
        cin >> n;
        rep(i,1,n) cin >> a[i];
        tmp = a[1];
        rep(i,3,n){
            if(i % 2 == 0) continue;
            tmp = gcd(tmp,a[i]);
        }
        rep(i,2,n){
            if(i % 2 == 1) continue;
            if(a[i] % tmp == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << tmp << "\n";
            continue;
        }

        flag = true;
        tmp = a[2];
        rep(i,4,n){
            if(i % 2 == 1) continue;
            tmp = gcd(tmp,a[i]);
        }
        rep(i,1,n){
            if(i % 2 == 0) continue;
            if(a[i] % tmp == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << tmp << "\n";
        } else {
            cout << "0\n";
        }
    }


    return 0;
}

