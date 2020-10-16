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
  int n, m; ll k; cin >> n >> m >> k;
  int mx = 4*n*m-2*n-2*m;
  if(k > mx) {
    cout << "NO" << endk;
    return;
  }
  cout << "YES" << endk;
  vector<pair<int, string>> ans;
  int cnt = 0;
  if(n-1) ans.push_back({n-1, "D"}); cnt += n-1;
  if(n-1) ans.push_back({n-1, "U"}); cnt += n-1;
  rep(i, m-1) {
    ans.push_back({1, "R"});     cnt += 1;
    if(n-1) ans.push_back({n-1, "DLR"}); cnt += (n-1)*3;
    if(n-1) ans.push_back({n-1, "U"});   cnt += n-1;
  }
  if(m-1) ans.push_back({m-1, "L"}); cnt += m-1;
  assert(cnt == mx);
  assert(ans.size() <= 3000);
  vector<pair<int, string>> ans2;
  int i = 0;
  while(k) {
    if(ans[i].first * (int)ans[i].second.size() >= k) {
      if(k / (int)ans[i].second.size()) ans2.push_back({k / (int)ans[i].second.size(), ans[i].second});
      if(k % (int)ans[i].second.size()) ans2.push_back({1, ans[i].second.substr(0, k % (int)ans[i].second.size())});
      break;
    } else {
      ans2.push_back(ans[i]);
      k -= ans[i].first * (int)ans[i].second.size();
    }
    i++;
  }
  assert(ans2.size() <= 3000);
  cout << ans2.size() << endk;
  for(auto ele: ans2) cout << ele.first << ' ' << ele.second << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
