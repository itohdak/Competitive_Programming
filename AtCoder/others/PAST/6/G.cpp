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

using P = pair<ll, int>;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  vector<vector<pair<int, ll>>> G(n);
  rep(i, m) {
    int a, b; ll c; cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  vector<ll> X(q);
  rep(i, q) cin >> X[i];
  priority_queue<P, vector<P>, greater<P>> E;
  vector<bool> done(n);
  set<int> st;
  vector<P> tmp;
  auto add_edge = [&](int i) {
    st.insert(i);
    if(done[i]) return;
    for(auto [ne, cost]: G[i]) {
      if(done[ne]) continue;
      tmp.push_back({cost, ne});
    }
    done[i] = true;
  };
  {
    add_edge(0);
    for(auto ele: tmp) E.push(ele);
    tmp.clear();
  }
  rep(i, q) {
    while(E.size() && E.top().first <= X[i]) {
      auto [_, ne] = E.top();
      E.pop();
      add_edge(ne);
    }
    for(auto ele: tmp) E.push(ele);
    tmp.clear();
    cout << st.size() << endk;
  }
  return 0;
}
