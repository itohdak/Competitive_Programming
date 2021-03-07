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
  map<int, string> mp;
  rep(i, n) {
    string s; cin >> s;
    int m = s.size();
    int k; cin >> k;
    int p;
    int prev = -1;
    int begin;
    rep(j, k) {
      cin >> p;
      p--;
      if(prev != -1 && p-prev < m) {
        begin = m-(p-prev);
      } else {
        begin = 0;
      }
      if(mp[p+begin] < s.substr(begin)) {
        mp[p+begin] = s.substr(begin);
      }
      prev = p;
    }
  }
  // cout << mp << endk;
  string ans = "";
  for(auto& [p, str]: mp) {
    if(p > ans.size()) ans += string(p-ans.size(), 'a');
    if(ans.size()-p < str.size()) {
      ans += str.substr(ans.size()-p);
    }
    assert(ans.size() <= 2000005);
  }
  cout << ans << endk;
  return 0;
}
