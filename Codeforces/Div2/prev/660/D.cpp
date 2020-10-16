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

vector<vector<int>> G;
vector<int> Tpl;

/* topological sort */
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}
// rep(i, N) dfs(i);
// reverse(all(Tpl));

void solve() {
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(n);
  rep(i, n) {
    cin >> B[i];
    if(B[i]!=-1) B[i]--;
  }
  vis = vector<bool>(n);
  G = vector<vector<int>>(n);
  rep(i, n) {
    if(B[i]!=-1) G[i].push_back(B[i]);
  }
  rep(i, n) dfs(i);
  reverse(all(Tpl));
  ll ans = 0;
  vector<int> hold;
  vector<int> v;
  rep(i, n) {
    if(A[Tpl[i]]<0) {
      hold.push_back(Tpl[i]);
    } else {
      v.push_back(Tpl[i]);
      ans += A[Tpl[i]];
      if(B[Tpl[i]]!=-1) A[B[Tpl[i]]] += A[Tpl[i]];
    }
  }
  reverse(all(hold));
  for(int i: hold) {
    v.push_back(i);
    ans += A[i];
    if(B[i]!=-1) A[B[i]] += A[i];
  }
  cout << ans << "\n";
  rep(i, n) cout << v[i]+1 << ' ';
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
