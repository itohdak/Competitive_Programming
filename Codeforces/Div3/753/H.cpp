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
  int n; cin >> n;
  map<int, vector<tuple<int, int, int>>> mp;
  vector<int> A(n), B(n);
  rep(i, n) {
    int a, b, m; cin >> a >> b >> m;
    int sum = a+b-m;
    int mn = (a-min(a, m))-(b-m+min(a,m));
    int mx = (a-m+min(b,m))-(b-min(b,m));
    mp[sum].push_back({mn, mx, i});
    A[i] = a, B[i] = b;
  }
  vector<pair<int, int>> ans(n);
  int cnt = 0;
  for(auto [sum, v]: mp) {
    vector<tuple<int, int, int>> C;
    for(auto [mn, mx, i]: v) {
      C.push_back({mn, -1, i}); // in
      C.push_back({mx+1, 1, i}); // out
    }
    set<int> st;
    sort(all(C));
    for(auto [p, t, i]: C) {
      if(t == -1) {
        st.insert(i);
      } else {
        if(st.count(i)) {
          cnt++;
          for(int j: st) {
            ans[j] = {A[j]-(sum+p-1)/2, B[j]-(sum-(p-1))/2};
          }
          st.clear();
        }
      }
    }
  }
  cout << cnt << endk;
  rep(i, n) cout << ans[i].first << ' ' << ans[i].second << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
