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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> pos(n);
  rep(i, n) pos[i].push_back(-1);
  rep(i, n) pos[A[i]-1].push_back(i);
  rep(i, n) pos[i].push_back(n);
  vector<int> maxdist(n);
  rep(i, n) {
    int prev = pos[i][0];
    rep(j, pos[i].size()) {
      chmax(maxdist[i], pos[i][j] - prev);
      prev = pos[i][j];
    }
  }
  // cout << maxdist << endl;
  vector<vector<int>> B(n+1);
  rep(i, n) if(maxdist[i] != n+1) B[maxdist[i]].push_back(i);
  set<int> st;
  rep(i, n+1) {
    if(i) {
      for(int j: B[i]) st.insert(j);
      if(st.empty()) cout << -1 << ' ';
      else cout << *st.begin()+1 << ' ';
    }
  }
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
