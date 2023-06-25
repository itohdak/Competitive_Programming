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
  int n, m; cin >> n >> m;
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int rt = sqrt(m);
  unordered_set<int> high;
  rep(i, n) if((int)G[i].size() > rt) high.insert(i);
  vector<vector<int>> G_high(n);
  rep(i, n) {
    for(int j: G[i]) {
      if(high.count(j)) G_high[i].push_back(j);
    }
  }
  vector<int> cnt_high(n), cnt_low(n), sum(n);
  int q; cin >> q;
  rep(_, q) {
    int t, x;
    cin >> t >> x;
    x--;
    if(t == 1) {
      if(high.count(x)) {
        cnt_high[x]++;
      } else {
        for(int to: G[x]) cnt_low[to]++;
      }
    } else {
      int ans = 0;
      ans += cnt_low[x];
      for(int to: G_high[x]) ans += cnt_high[to];
      cout << ans - sum[x] << endk;
      sum[x] = ans;
    }
  }
  return 0;
}
