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
  vector<pair<int, string>> v(n);
  rep(i, n) cin >> v[i].second >> v[i].first;
  sort(all(v));
  vector<string> ans;
  rep(i, n) {
    vector<string> tmp;
    if(ans.size() < v[i].first) {
      cout << -1 << endk;
      return 0;
    }
    rep(j, v[i].first) {
      tmp.push_back(ans.back());
      ans.pop_back();
    }
    ans.push_back(v[i].second);
    rep(j, v[i].first) {
      ans.push_back(tmp.back());
      tmp.pop_back();
    }
  }
  // cout << v << endk;
  // cout << ans << endk;
  map<string, int> mp;
  ll tmp = 1;
  rep(i, n) mp[ans[i]] = tmp++;
  rep(i, n) cout << v[i].second << ' ' << mp[v[i].second] << endk;
  return 0;
}
