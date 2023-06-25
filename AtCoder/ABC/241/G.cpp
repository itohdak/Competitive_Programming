#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  vector<int> W(m), L(m);
  vector<vector<int>> res(n, vector<int>(n));
  rep(i, m) {
    cin >> W[i] >> L[i];
    W[i]--; L[i]--;
    res[W[i]][L[i]] = 1;
    res[L[i]][W[i]] = -1;
  }

  map<pair<int, int>, int> id;
  int tmp = 0;
  rep(i, n) REP(j, i+1, n) {
    id[{i, j}] = tmp++;
  }

  int sum = n*(n-1)/2;
  int s = sum+n;
  int t = sum+n+1;
  vector<int> ans;

  rep(i, n) {
    vector<vector<int>> tmp = res;
    vector<int> win_cnt(n);
    rep(j, n) rep(k, n) {
      if(j == k) continue;
      if(j == i && tmp[j][k] == 0) {
        tmp[j][k] = 1;
        tmp[k][j] = -1;
      }
      if(tmp[j][k] == 1) win_cnt[j]++;
    }

    bool ok = true;
    int win = win_cnt[i];
    // rep(j, n) {
    //   if(j == i) continue;
    //   if(win_cnt[j] >= win) ok = false;
    // }
    if(!ok || win == 0) continue;

    mf_graph<int> G(n*(n-1)/2+n+2);
    rep(j, sum) {
      G.add_edge(s, j, 1);
    }
    rep(j, n) {
      G.add_edge(sum+j, t, win-(j!=i));
    }
    rep(j, n) rep(k, n) {
      if(j == k) continue;
      if(tmp[j][k] >= 0) {
        assert(id.count({min(j, k), max(j, k)}));
        G.add_edge(id[{min(j, k), max(j, k)}], sum+j, 1);
      }
    }

    if(G.flow(s, t) >= sum) ans.push_back(i);
  }
  for(int a: ans) cout << a+1 << ' '; cout << endk;
  return 0;
}
