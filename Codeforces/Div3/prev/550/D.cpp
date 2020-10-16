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
  map<int, vector<int>> cnt;
  rep(i, n) cnt[A[i]].push_back(i);
  int mx = -1; int mxi = 0;
  for(auto ele: cnt) {
    if(mx < (int)ele.second.size()) {
      mx = ele.second.size();
      mxi = ele.first;
    }
  }
  cout << n - mx << endk;
  vector<tuple<int, int, int>> ans;
  for(int i=cnt[mxi][0]-1; i>=0; i--) {
    if(A[i+1] > A[i]) ans.push_back({1, i, i+1});
    else ans.push_back({2, i, i+1});
    A[i] = mxi;
  }
  cnt[mxi].push_back(n);
  rep(i, cnt[mxi].size()-1) {
    for(int j=cnt[mxi][i]+1; j<cnt[mxi][i+1]; j++) {
      if(A[j] > A[j-1]) ans.push_back({2, j, j-1});
      else ans.push_back({1, j, j-1});
      A[j] = mxi;
    }
  }
  assert(ans.size() == n-mx);
  for(auto [t, i, j]: ans) cout << t << ' ' << i+1 << ' ' << j+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
