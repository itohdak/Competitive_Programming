#include <bits/stdc++.h>
// #include <print.hpp>
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
  vector<vector<int>> cnt(2); // 1, >=2
  vector<pair<int, int>> ans;
  vector<int> target(n);
  int tmp = n-1;
  rrep(i, n) {
    if(A[i] == 0) {
      continue;
    } else if(A[i] == 1) {
      ans.push_back({tmp, i});
      target[i] = tmp;
      tmp--;
      cnt[0].push_back(i);
    } else if(A[i] == 2) {
      if(cnt[0].size() == 0) {
        cout << -1 << endk;
        return;
      }
      int p = cnt[0].back();
      cnt[0].pop_back();
      ans.push_back({target[p], i});
      target[i] = target[p];
      cnt[1].push_back(i);
    } else {
      if(cnt[1].size()) {
        int p = cnt[1].back();
        cnt[1].pop_back();
        ans.push_back({tmp, i});
        ans.push_back({tmp, p});
      } else if(cnt[0].size()) {
        int p = cnt[0].back();
        cnt[0].pop_back();
        ans.push_back({tmp, i});
        ans.push_back({tmp, p});
      } else {
        cout << -1 << endk;
        return;
      }
      target[i] = tmp;
      tmp--;
      cnt[1].push_back(i);
    }
  }
  if(tmp < -1) {
    cout << -1 << endk;
    return;
  }
  cout << ans.size() << endk;
  for(auto ele: ans) {
    cout << ele.first+1 << ' ' << ele.second+1 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
