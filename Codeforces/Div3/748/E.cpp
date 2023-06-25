#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, k; cin >> n >> k;
  vector<set<int>> G(n);
  rep(i, n-1) {
    int u,  v; cin >> u >> v;
    u--; v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  queue<int> q;
  vector<bool> done(n), put(n);
  rep(i, n) {
    if(G[i].size() <= 1 && !put[i]) {
      q.push(i);
      put[i] = true;
    }
  }
  int cnt = 0;
  rep(i, k) {
    if(cnt == n) break;
    queue<int> next;
    while(q.size()) {
      int cur = q.front(); q.pop();
      if(done[cur]) continue;
      done[cur] = true;
      cnt++;
      assert(G[cur].size() <= 1);
      for(int ne: G[cur]) {
        G[ne].erase(cur);
        if(G[ne].size() <= 1 && !put[ne]) {
          next.push(ne);
          put[ne] = true;
        }
      }
      G[cur].clear();
    }
    q = next;
  }
  cout << n-accumulate(all(done), 0) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
