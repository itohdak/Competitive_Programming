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
  int n; cin >> n;
  vector<string> S(n), T(n);
  vector<string> ALL;
  rep(i, n) {
    cin >> S[i] >> T[i];
    ALL.push_back(S[i]);
    ALL.push_back(T[i]);
  }
  sort(all(ALL));
  ALL.erase(unique(all(ALL)), end(ALL));
  auto id = [&](string s) {
    return lower_bound(all(ALL), s) - begin(ALL);
  };
  int m = ALL.size();
  vector<vector<int>> par(m);
  dsu uf(m);
  rep(i, n) {
    par[id(T[i])].push_back(id(S[i]));
    uf.merge(id(S[i]), id(T[i]));
  }
  map<int, int> cntE, cntV;
  rep(i, n) {
    cntE[uf.leader(id(S[i]))]++;
  }
  rep(i, m) {
    cntV[uf.leader(i)]++;
  }
  bool ok = true;
  for(auto [k, _]: cntE) {
    if(cntE[k] >= cntV[k]) {
      ok = false;
    }
  }
  rep(i, m) {
    if(par[i].size() > 1) ok = false;
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
