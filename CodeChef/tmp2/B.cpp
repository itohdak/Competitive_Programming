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
  // RPDRDNG
  int n; cin >> n;
  vector<int> B(2*n); rep(i, 2*n) cin >> B[i];
  map<int, int> mp;
  rep(i, 2*n) mp[B[i]]++;
  vector<int> cnt(n);
  rep(i, n) {
    // [0, i+1)
    cnt[i/2]++;
    // [n-1-i, n)
    cnt[n-1-i+i/2]++;
  }
  // cout << cnt << endk;
  if(mp.size() != n) {
    cout << -1 << endk;
    return;
  }
  int i = 0;
  vector<int> ans(n);
  for(auto [v, c]: mp) {
    if(cnt[i] != c) {
      cout << -1 << endk;
      return;
    }
    ans[i++] = v;
  }
  rep(i, n) cout << ans[i] << ' '; cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
