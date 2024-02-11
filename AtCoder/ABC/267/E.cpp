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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<set<int>> G(n);
  rep(i, m) {
    int u, v; cin >> u >> v;
    u--; v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  vector<ll> init(n);
  rep(i, n) {
    for(int ne: G[i]) {
      init[i] += A[ne];
    }
  }
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  rep(i, n) {
    q.push({init[i], i});
  }
  vector<ll> C = init;
  vector<bool> done(n);
  ll ans = 0;
  while(q.size()) {
    auto [cost, cur] = q.top(); q.pop();
    if(done[cur]) continue;
    if(C[cur] < cost) continue;
    chmax(ans, cost);
    ll tmp = 0;
    for(int ne: G[cur]) {
      tmp += A[ne];
      G[ne].erase(cur);
      C[ne] -= A[cur];
      q.push({C[ne], ne});
    }
    G[cur] = set<int>();
    assert(cost == tmp);
    done[cur] = true;
  }
  cout << ans << endk;
  return 0;
}
