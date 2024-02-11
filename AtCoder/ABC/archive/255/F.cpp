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
  int n; cin >> n;
  vector<int> P(n); rep(i, n) cin >> P[i];
  vector<int> I(n); rep(i, n) cin >> I[i];
  rep(i, n) {
    P[i]--;
    I[i]--;
  }
  if(P[0] != 0) {
    cout << -1 << endk;
    return 0;
  }
  vector<int> pos1(n), pos2(n);
  rep(i, n) {
    pos1[P[i]] = i;
    pos2[I[i]] = i;
  }
  vector<pair<int, int>> C(n, {-1, -1});
  auto dfs = [&](auto dfs, int l1, int r1, int l2, int r2) -> bool {
    assert(r1-l1 == r2-l2);
    if(r1 == l1) return true;
    int root = P[l1];
    int next_pos = pos2[root];
    if(next_pos < l2 || next_pos >= r2) return false;
    if(next_pos-l2 > 0 && l1+1 < r1) C[root].first = P[l1+1];
    if(l1+1+(next_pos-l2) < r1) C[root].second = P[l1+1+(next_pos-l2)];
    bool ok = true;
    ok &= dfs(dfs, l1+1, l1+1+(next_pos-l2), l2, next_pos);
    ok &= dfs(dfs, l1+1+(next_pos-l2), r1, next_pos+1, r2);
    return ok;
  };
  bool ok = dfs(dfs, 0, n, 0, n);
  if(!ok) cout << -1 << endk;
  else rep(i, n) cout << C[i].first+1 << ' ' << C[i].second+1 << endk;
  return 0;
}
