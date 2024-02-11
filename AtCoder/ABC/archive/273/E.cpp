#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int q; cin >> q;
  map<int, int> pos;
  vector<int> par(q);
  vector<int> val(q);
  int cur = -1;
  rep(i, q) {
    string cmd; cin >> cmd;
    if(cmd == "ADD") {
      int x; cin >> x;
      par[i] = cur;
      val[i] = x;
      cur = i;
    } else if(cmd == "DELETE") {
      if(cur >= 0) {
        cur = par[cur];
      }
    } else if(cmd == "SAVE") {
      int y; cin >> y;
      y--;
      pos[y] = cur;
    } else {
      int z; cin >> z;
      z--;
      cur = (pos.count(z) ? pos[z] : -1);
    }
    cout << (cur == -1 ? -1 : val[cur]) << ' ';
  }
  cout << endk;
  return 0;
}
