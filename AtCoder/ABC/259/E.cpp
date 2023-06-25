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
  int n; cin >> n;
  vector<vector<pair<int, int>>> A(n);
  map<int, pair<int, int>> mp;
  rep(i, n) {
    int m; cin >> m;
    rep(j, m) {
      int p, e; cin >> p >> e;
      A[i].push_back({p, e});
      if(mp.count(p)) {
        if(e > mp[p].first) {
          mp[p] = {e, mp[p].first};
        } else if(e > mp[p].second) {
          mp[p] = {mp[p].first, e};
        }
      } else {
        mp[p] = {e, 0};
      }
    }
  }
  set<vector<pair<int, int>>> st;
  rep(i, n) {
    vector<pair<int, int>> tmp;
    rep(j, A[i].size()) {
      auto [p, e] = A[i][j];
      if(mp[p].first == e) {
        int c = mp[p].first - mp[p].second;
        if(c > 0) {
          tmp.push_back({p, c});
        }
      }
    }
    sort(all(tmp));
    st.insert(tmp);
  }
  // cout << st << endk;
  cout << st.size() << endk;
  return 0;
}
