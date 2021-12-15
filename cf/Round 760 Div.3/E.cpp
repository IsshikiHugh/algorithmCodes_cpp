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
int _,n,a[2*N],b[2*N],c[2*N],ans[2*N];
ll sum,tmp;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        bool flag = true;
        sum = tmp = 0;
        cin >> n;
        rep(i,0,n+1) a[i] = b[i] = c[i] = ans[i] = 0;
        rep(i,1,n) cin >> a[i];

        if(n == 1){
            cout << "YES\n" << a[1] << "\n";
            continue;
        }

        rep(i,1,n){
            sum += a[i];

            if(i == 1) b[i] = a[n-1] + a[1] - 2*a[n];
            else if(i == 2) b[i] = a[n] + a[2] - 2*a[1];
            else b[i] = a[i] + a[i-2] - 2*a[i-1];
        }

        // cout << "b:";
        // rep(i,1,n) cout << b[i]/n << " ";
        // cout << "\n";

        rep(i,1,n){
            if(b[i] % n == 0){
                b[i] /= n;
            } else {
                flag = false;
                break;
            }
        }


        if((2*sum) % (n*n+n) == 0) sum *= 2 , sum /= (n*n+n);
        else flag = false;

        if(!flag){
            cout << "NO\n";
            continue;
        }

        c[1] = 0;
        rep(i,2,n) c[i] = c[i-1] + b[i];
        rep(i,2,n) tmp += c[i];
        sum += tmp;

        if(sum % n != 0){
            cout << "NO\n";
            continue;
        } else {
            ans[1] = sum / n;
        }
        rep(i,2,n) ans[i] = ans[i-1] - b[i];
        rep(i,1,n)
            if(ans[i] <= 0) flag = false;
        
        if(!flag){
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
            rep(i,1,n) cout << ans[i] << " ";
        }
        cout << "\n";
    }    


    return 0;
}

