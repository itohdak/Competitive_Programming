#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n);
  vector<int> B(n), C(n), cntB(2), cntC(2);
  rep(i, n) {
    cin >> A[i] >> B[i] >> C[i];
    cntB[B[i]]++;
    cntC[C[i]]++;
  }
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if(cntB[0] != cntC[0]) {
    cout << -1 << endl;
    return;
  }
  ll ans = 0;
  function<vector<int>(int, int)> dfs = [&](int tmp, int par) {
    if(par != -1) A[tmp] = min(A[tmp], A[par]);
    vector<int> cnt(2);
    if(B[tmp] != C[tmp]) cnt[B[tmp]]++;
    for(int ne: G[tmp]) {
      if(ne != par) {
        auto res = dfs(ne, tmp);
        rep(i, 2) cnt[i] += res[i];
      }
    }
    // cout << tmp+1 << ' ' << cnt << endl;
    int mn = min(cnt[0], cnt[1]);
    ans += 2 * mn * A[tmp];
    cnt[0] -= mn;
    cnt[1] -= mn;
    // cout << tmp+1 << ' ' << cnt << endl;
    return cnt;
  };
  dfs(0, -1);
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
