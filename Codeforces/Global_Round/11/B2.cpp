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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int ans = 0;
  int cnt = 0;
  int l = 0;
  while(l < n && s[l] == 'L') l++;
  if(l == n) {
    cout << max(0, min(n, k) * 2 - 1) << endk;
    return;
  }
  cnt += l;
  int r = n-1;
  while(r >= 0 && s[r] == 'L') r--;
  cnt += n-1-r;
  r++;
  int prev = l;
  vector<int> seg;
  while(l < r) {
    while(l < r && s[l] == 'W') l++;
    if(l-prev) ans += (l-prev) * 2 - 1;
    prev = l;
    while(l < r && s[l] == 'L') l++;
    if(l-prev) seg.push_back(l-prev);
    prev = l;
  }
  sort(all(seg));
  for(int i: seg) {
    if(i <= k) {
      ans += i * 2 + 1;
      k -= i;
    } else {
      ans += k * 2;
      k = 0;
    }
  }
  ans += min(k, cnt) * 2;
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
