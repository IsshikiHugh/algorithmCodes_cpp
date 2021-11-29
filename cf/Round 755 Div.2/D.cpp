#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define mkp std::make_pair
typedef long long ll;
typedef unsigned long long ull;
using std::cin;
using std::cout;
using std::string;
inline bool cmp(int x, int y) { return x < y; }
/* -fsanitize=undefined  */
const int N = 1e7 + 9;
const int inf = 1e9 + 9;
const double eps = 1e-7;
int _, n;
ll tot, res, L, R, K, l, r, mid;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while (_--){
        cin >> n;
        cout << "? " << 1 << " " << n << "\n";
        cout.flush();
        cin >> tot;

        // do L
        l = 1 , r = n;
        while(l <= r){
            mid = (l+r) >> 1;
            cout << "? " << mid << " " << n << "\n";
            cout .flush();
            cin >> res;
            if(res < tot) r = mid - 1;
            else l = mid + 1;
        }
        L = r;
        // std::cerr << "L OK = " << L << "\n";

        if(L == n-3){
            K = L+2 , R = L+3;
            cout << "! " << L << " " << K << " " << R << "\n";
            cout .flush();
            continue;
        }

        cout << "? " << L+1 << " " << n << "\n";
        cout.flush();
        cin >> res;
        K = L + tot - res + 1;
        // std::cerr << "K OK = " << K << "\n";

        tot -= (K-L)*(K-L-1)/2;
        res = std::sqrt(2*tot);
        R = K + res;

        // std::cerr << "R OK = " << R << "\n";

        cout << "! " << L << " " << K << " " << R << "\n";
        cout .flush();
    }

    return 0;
}
