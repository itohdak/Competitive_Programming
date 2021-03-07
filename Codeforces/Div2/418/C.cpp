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
  vector<vector<int>> cnt(26);
  rep(i, n) cnt[s[i]-'a'].push_back(i);
  map<pair<int, char>, int> ans;
  for(int m=1; m<=n; m++) {
    for(char c='a'; c<='z'; c++) {
      auto bsearch = [&](int begin) {
        auto test = [&](int mid) {
          int end = begin + mid;
          if(end > n) return false;
          int cnt2 = upper_bound(all(cnt[c-'a']), end-1) - lower_bound(all(cnt[c-'a']), begin);
          return mid - cnt2 <= m;
        };
        int ok = 0, ng = n+1;
        while(ng-ok>1) {
          int mid = (ok+ng)/2;
          (test(mid) ? ok : ng) = mid;
        }
        return ok;
      };
      int a = 0;
      rep(j, n) chmax(a, bsearch(j));
      // cout << a << endk;
      ans[{m, c}] = a;
    }
  }
  cout << ans << endk;
  int q; cin >> q;
  rep(i, q) {
    int m; cin >> m;
    char c; cin >> c;
    cout << ans[{m, c}] << endk;
  }
  return 0;
}
