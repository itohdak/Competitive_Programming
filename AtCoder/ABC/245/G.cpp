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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, k, l; cin >> n >> m >> k >> l;
  vector<int> A(n);
  rep(i, n) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> B(l);
  rep(i, l) {
    cin >> B[i];
    B[i]--;
  }
  vector<tuple<int, int, ll>> C(m);
  vector<vector<edge>> G(n);
  for(auto& [u, v, c]: C) {
    cin >> u >> v >> c;
    u--; v--;
    G[u].push_back({v, c});
    G[v].push_back({u, c});
  }

  vector<ll> dist1(n, longinf), dist2(n, longinf);
  vector<int> col1(n, -1), col2(n, -1);
  vector<int> cnt(n, 0);

  // dijkstra
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> q;
  rep(i, l) {
    q.push({0, B[i], A[B[i]]});
  }
  while(q.size()) {
    auto [d, cur, col] = q.top(); q.pop();
    if(cnt[cur] == 0) {
      dist1[cur] = d;
      col1[cur] = col;
    } else if(cnt[cur] == 1 && col != col1[cur]) {
      dist2[cur] = d;
      col2[cur] = col;
    } else {
      continue;
    }
    cnt[cur]++;
    for(auto [ne, cost]: G[cur]) {
      q.push({d + cost, ne, col});
    }
  }

  // cout << dist1 << col1 << endk;
  // cout << dist2 << col2 << endk;
  rep(i, n) {
    if(col1[i] == A[i]) {
      cout << (dist2[i] == longinf ? -1 : dist2[i]) << ' ';
    } else {
      cout << (dist1[i] == longinf ? -1 : dist1[i]) << ' ';
    }
  }
  cout << endk;
  return 0;
}
