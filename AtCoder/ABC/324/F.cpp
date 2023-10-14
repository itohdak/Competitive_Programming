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
  vector<tuple<int, int, int, int>> A(m);
  rep(i, m) {
    auto& [u, v, b, c] = A[i];
    cin >> u >> v >> b >> c;
    u--; v--;
  }
  sort(all(A));
  ld ok = 0, ng = 10101;
  auto test = [&](ld k) -> bool {
    vector<ld> dist(n, -longinf);
    dist[0] = 0;
    rep(i, m) {
      auto [u, v, b, c] = A[i];
      chmax(dist[v], dist[u]+(b-k*c));
    }
    return dist[n-1] >= 0;
  };
  rep(_, 100) {
    ld mid = (ok + ng) / 2;
    (test(mid) ? ok : ng) = mid;
  }
  cout << fixed << setprecision(10) << ok << endk;
  return 0;
}
