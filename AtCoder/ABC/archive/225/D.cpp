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
  int n, q; cin >> n >> q;
  vector<int> par(n, -1);
  vector<int> chi(n, -1);
  rep(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x, y; cin >> x >> y;
      x--; y--;
      par[y] = x;
      chi[x] = y;
    } else if(t == 2) {
      int x, y; cin >> x >> y;
      x--; y--;
      assert(par[y] == x);
      assert(chi[x] == y);
      par[y] = -1;
      chi[x] = -1;
    } else {
      int x; cin >> x;
      x--;
      int tmp = x;
      while(par[tmp] != -1) {
        tmp = par[tmp];
      }
      vector<int> ans;
      ans.push_back(tmp);
      while(chi[tmp] != -1) {
        tmp = chi[tmp];
        ans.push_back(tmp);
      }
      cout << ans.size() << ' ';
      for(int a: ans) cout << a+1 << ' ';
      cout << endk;
    }
  }
  return 0;
}
