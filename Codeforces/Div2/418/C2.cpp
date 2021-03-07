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
  string s; cin >> s;
  vector<vector<int>> ans(26, vector<int>(n+1, inf));
  rep(i, n+1) {
    if(i == 0) {
      rep(j, 26) ans[j][i] = 0;
      continue;
    }
    vector<int> cnt(26);
    rep(j, i) {
      assert(j < n);
      assert(s[j]-'a' < 26);
      cnt[s[j]-'a']++;
    }
    rep(j, n-i+1) {
      rep(k, 26) {
        assert(i < n+1);
        chmin(ans[k][i], i-cnt[k]);
      }
      assert(j < n);
      cnt[s[j]-'a']--;
      if(j+i < n) cnt[s[j+i]-'a']++;
    }
  }
  // cout << ans << endl;
  int q; cin >> q;
  rep(_, q) {
    int m; char c; cin >> m >> c;
    cout << upper_bound(all(ans[c-'a']), m) - begin(ans[c-'a']) - 1 << endk;
  }
  return 0;
}
