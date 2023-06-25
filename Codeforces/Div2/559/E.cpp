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

void solve() {
  int n; cin >> n;
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    if(A[i] != -1) A[i]--;
  }
  set<int> st;
  bool ok = true;
  rep(i, n) {
    st.erase(i);
    if(A[i] == -1) continue;
    if(st.size() && A[i] > *st.begin()) {
      ok = false;
      break;
    }
    st.insert(A[i]);
  }
  if(!ok) {
    cout << -1 << endk;
    return;
  }
  rep(i, n) if(A[i] == -1) A[i] = i+1;
  vector<vector<int>> G(n+1);
  rep(i, n) G[A[i]].push_back(i);
  vector<int> ans(n+1);
  int tmp = n+1;
  auto dfs = [&](auto dfs, int cur) -> void {
    ans[cur] = tmp--;
    for(int ne: G[cur]) dfs(dfs, ne);
  };
  dfs(dfs, n);
  rep(i, n) cout << ans[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
