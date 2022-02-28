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
using std::cin;using std::cout;using std::pair;
using std::string;using std::set;using std::queue;using std::vector;using std::map;
using std::sort;
inline ll max(ll x,ll y){return x > y ? x : y;}
inline ll min(ll x,ll y){return x < y ? x : y;}
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;

bool judge(ll lim, vector<int> &a, ll k){
    for(auto it = a.begin()+1;it != a.end();++it){
        if(*it < lim){
            k -= lim - *it;
        }
        if(k < 0) return false;
    }
    return true;
}

void solve(){
    int n;
    ll k,aMin,aMax;
    cin >> n >> k;
    vector<int> a(n+1);
    rep(i,1,n){
        cin >> a[i];
    }
    aMin = aMax = a[1];
    rep(i,2,n){
        aMin = aMin <= a[i] ? aMin : a[i];
        aMax = aMax >= a[i] ? aMax : a[i];
    }
    ll l,r,mid;
    l = aMin, r = aMax + k;
    while(l <= r){
        mid = (l + r) >> 1;
        // std::cerr << l << " " << r << " " << mid << "\n";
        if(judge(mid, a, k)){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << "\n";

}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    int _ = 1;
    // cin >> _;
    while(_--) solve();
    return 0;
}
