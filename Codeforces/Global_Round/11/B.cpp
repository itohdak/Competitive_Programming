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
  vector<int> seg;
  int cnt2 = 0, cnt1 = 0;
  int l = 0, r = 0;
  while(l < n) {
    while(l < n && s[l] == 'L') l++;
    if(r == 0 && l == n) {
      cnt2 += l-r-1;
      cnt1 += 1;
    } else if(r == 0 || l == n) {
      cnt2 += l-r;
    } else {
      seg.push_back(l-r);
    }
    if(l == n) break;
    r = l;
    while(r < n && s[r] == 'W') r++;
    ans += 2*(r-l)-1;
    l = r;
  }
  sort(all(seg));
  rep(i, seg.size()) {
    if(k >= seg[i]) {
      ans += 2*seg[i]+1;
      k -= seg[i];
    } else {
      ans += 2*k;
      k = 0;
      break;
    }
  }
  if(k && cnt2) {
    int tmp = min(cnt2, k);
    ans += 2*tmp;
    k -= tmp;
  }
  if(k && cnt1) {
    int tmp = min(cnt1, k);
    ans += tmp;
    k -= tmp;
  }
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
