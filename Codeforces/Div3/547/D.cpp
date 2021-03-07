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
  string s, t; cin >> s >> t;
  vector<vector<int>> cntS(27), cntT(27);
  rep(i, n) {
    if(s[i] == '?') cntS[26].push_back(i);
    else cntS[s[i]-'a'].push_back(i);
    if(t[i] == '?') cntT[26].push_back(i);
    else cntT[t[i]-'a'].push_back(i);
  }
  vector<pair<int, int>> ans;
  rep(i, 26) {
    int mn = min(cntS[i].size(), cntT[i].size());
    rep(j, mn) {
      ans.push_back({cntS[i].back(), cntT[i].back()});
      cntS[i].pop_back();
      cntT[i].pop_back();
    }
  }
  rep(i, 26) {
    if(cntS[i].size() == 0 && cntT[i].size()) {
      int mn = min(cntT[i].size(), cntS[26].size());
      rep(j, mn) {
        ans.push_back({cntS[26].back(), cntT[i].back()});
        cntT[i].pop_back();
        cntS[26].pop_back();
      }
    } else if(cntT[i].size() == 0 && cntS[i].size()) {
      int mn = min(cntS[i].size(), cntT[26].size());
      rep(j, mn) {
        ans.push_back({cntS[i].back(), cntT[26].back()});
        cntS[i].pop_back();
        cntT[26].pop_back();
      }
    }
  }
  int mn = min(cntS[26].size(), cntT[26].size());
  rep(i, mn) {
    ans.push_back({cntS[26].back(), cntT[26].back()});
    cntS[26].pop_back();
    cntT[26].pop_back();
  }
  cout << ans.size() << endk;
  for(auto ele: ans) cout << ele.first+1 << ' ' << ele.second+1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
