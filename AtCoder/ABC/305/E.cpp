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
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  priority_queue<pair<int, int>> Q;
  vector<bool> V(n);
  vector<int> H(n, -inf);
  rep(i, k) {
    int p, h; cin >> p >> h;
    p--;
    H[p] = h;
    Q.push({h, p});
  }
  while(Q.size()) {
    auto [h, p] = Q.top(); Q.pop();
    if(V[p]) continue;
    if(H[p] > h) continue;
    V[p] = true;
    if(H[p]) {
      for(int nx: G[p]) {
	if(H[nx] < H[p]-1) {
	  H[nx] = H[p]-1;
	  Q.push({H[nx], nx});
	}
      }
    }
  }
  cout << accumulate(all(V), 0) << endk;
  rep(i, n) {
    if(V[i]) {
      cout << i+1 << ' ';
    }
  }
  cout << endk;
  return 0;
}
