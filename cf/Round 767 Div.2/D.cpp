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
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n;
int a[2*N];
string str;

struct node{
    int len;
    char ch[5];
    bool is = false;
    void DO(string str){
        len = str.length(); 
        rep(i,1,len) ch[i] = str[i-1];
        if(len == 1) is = true;
        else if(len == 2 && ch[1] == ch[2]) is = true;
        else if(len == 3 && ch[1] == ch[3]) is = true; 
        else is = false;
    }
    string pre(){
        string res = "";
        rep(i,1,len) res += ch[i];
        return res;
    }
    string suf(){
        string res = "";
        per(i,len,1) res += ch[i];
        return res;
    }
}s[2*N];

inline bool cmp(node x,node y){
    return x.len < y.len;
}

void solve(){
    bool flag = false;
    cin >> n;
    rep(i,1,n){
        cin >> str;
        s[i].DO(str);
    }

    rep(i,1,n) if(s[i].is) flag = true;
    if(flag){
        cout << "YES\n";
        return;
    }

    set<string> preSet;
    preSet.clear();
    rep(i,1,n){
        str = s[i].pre();
        preSet.insert(str);
        str = s[i].suf();
        if(preSet.find(str) != preSet.end()) flag = true;
        if(flag) break;
        if(s[i].len == 3){
            str = "";
            str.push_back(s[i].ch[3]);
            str.push_back(s[i].ch[2]);
            if(preSet.find(str) != preSet.end()) flag = true;
        }
        if(flag) break;
           if(s[i].len == 2){
            string tmp = str;
            rep(i,'a','z'){
                char chh = i;
                tmp = str;
                tmp.push_back(chh);
                if(preSet.find(tmp) != preSet.end()) flag = true;
                if(flag) break;
            }
        }
        if(flag) break;
    }

    if(flag){
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
        return;
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
