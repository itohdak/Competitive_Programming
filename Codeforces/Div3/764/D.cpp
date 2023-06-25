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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

// i-i of them: typo?
void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> cnt(26);
  for(char c: s) cnt[c-'a']++;
  int two = 0, one = 0;
  rep(i, 26) {
    two += cnt[i]/2;
    one += cnt[i]%2;
  }
  // auto bsearch = [&]() {
  //   auto test = [&](int m) {
  //     int need_two = m/2*k;
  //     if(two < need_two) return false;
  //     int rem_two = two - need_two;
  //     int need_one = m%2*k;
  //     return rem_two*2+one >= need_one;
  //   };
  //   int ok = 0, ng = n+1;
  //   while(ng-ok>1) {
  //     int mid = (ok+ng)/2;
  //     (test(mid) ? ok : ng) = mid;
  //   }
  //   return ok;
  // };
  int ans = 0;
  ans += two / k * 2;
  one += two % k * 2;
  if(one >= k) ans++;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
