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
  vector<pair<int, int>> P(n), Q(m);
  rep(i, n) cin >> P[i].first >> P[i].second;
  rep(i, m) cin >> Q[i].first >> Q[i].second;
  vector<vector<pair<int, int>>> G(n+m);
  set<int> cand;
  rep(i, n) rep(j, m) {
    set<int> st;
    st.insert(P[i].first);
    st.insert(P[i].second);
    int cnt = st.count(Q[j].first) + st.count(Q[j].second);
    if(cnt == 0 || cnt == 2) continue;
    int match = (st.count(Q[j].first) ? Q[j].first : Q[j].second);
    G[i].push_back({n+j, match});
    G[n+j].push_back({i, match});
    cand.insert(match);
  }
  if(cand.size() == 0) {
    assert(false);
  } else if(cand.size() == 1) {
    cout << *cand.begin() << endk;
  } else {
    bool ok1 = true, ok2 = true;
    rep(i, n) {
      if(G[i].empty()) continue;
      set<int> cand2;
      for(auto [j, v]: G[i]) cand2.insert(v);
      if(cand2.size() > 1) ok1 = false;
    }
    rep(i, m) {
      if(G[n+i].empty()) continue;
      set<int> cand2;
      for(auto [j, v]: G[n+i]) cand2.insert(v);
      if(cand2.size() > 1) ok2 = false;
    }
    if(ok1 && ok2) cout << 0 << endk;
    else cout << -1 << endk;
  }
  return 0;
}
