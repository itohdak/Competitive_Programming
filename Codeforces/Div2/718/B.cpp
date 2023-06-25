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
  int n, m; cin >> n >> m;
  vector<vector<int>> B(n, vector<int>(m));
  vector<pair<int, int>> A;
  rep(i, n) rep(j, m) {
    cin >> B[i][j];
    A.push_back({B[i][j], i});
  }
  sort(all(A));
  vector<set<int>> vst(n);
  rep(i, n) rep(j, m) vst[i].insert(j);
  vector<vector<int>> ans(n, vector<int>(m));
  rep(i, m) {
    auto [l, j] = A[i];
    ans[j][i] = l;
    vst[j].erase(i);
  }
  REP(i, m, n*m) {
    auto [l, j] = A[i];
    assert(vst[j].size());
    ans[j][*vst[j].begin()] = l;
    vst[j].erase(vst[j].begin());
  }
  rep(i, n) {
    rep(j, m) cout << ans[i][j] << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
