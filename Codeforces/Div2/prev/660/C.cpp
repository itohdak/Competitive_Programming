#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int n; ll m; cin >> n >> m;
  vector<ll> P(n); rep(i, n) cin >> P[i];
  vector<ll> H(n); rep(i, n) cin >> H[i];
  vector<ll> Porig(n);
  copy(all(P), begin(Porig));
  vector<ll> happy(n);
  vector<vector<int>> G(n);
  rep(i, n-1) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  bool ok = true;
  auto dfs = [&](auto dfs, int cur, int par) -> void {
    ll sumHappy = 0;
    for(int ne: G[cur]) {
      if(ne != par) {
        dfs(dfs, ne, cur);
        sumHappy += happy[ne];
        P[cur] += P[ne];
      }
    }
    if((P[cur]+H[cur])%2 != 0) ok = false;
    if(P[cur]-H[cur] < 0 || P[cur]+H[cur] < 0) ok = false;
    happy[cur] = (H[cur]+P[cur])/2;
    if(happy[cur] < sumHappy) ok = false;
  };
  dfs(dfs, 0, -1);
  cout << (ok ? "YES" : "NO") << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
