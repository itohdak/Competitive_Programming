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
  int n, m, k, q; cin >> n >> m >> k >> q;
  vector<int> who_holds(m, -1);
  vector<vector<int>> holds(n);
  vector<vector<int>> G(n);
  rep(i, k) {
    int a, b; cin >> a >> b;
    a--; b--;
    if(who_holds[b] == -1) {
      who_holds[b] = a;
      holds[a].push_back(b);
    } else {
      G[a].push_back(who_holds[b]);
    }
  }
  rep(_, q) {
    int x, y;
    cin >> x >> y;
  }
  cout << G << endk;
  return 0;
}
