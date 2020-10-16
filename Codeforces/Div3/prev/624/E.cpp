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
  int n, d; cin >> n >> d;
  vector<int> cnt(n, 1);
  int l = 1, r = n-1;
  ll sum = n*(n-1)/2;
  while(sum > d) {
    if(l >= r) break;
    if(sum-d > r-l) {
      sum -= r-l;
      cnt[r]--;
      cnt[l]++;
      r--;
      if(cnt[l] == (ll)pow(2, l)) l++;
    } else {
      cnt[r]--;
      cnt[r-(sum-d)]++;
      sum = d;
    }
  }
  if(sum == d) {
    cout << "YES" << endk;
    assert(accumulate(all(cnt), 0) == n);
    vector<int> ans(n);
    vector<vector<int>> mem(n);
    int id = 0;
    rep(i, n) rep(j, cnt[i]) mem[i].push_back(id++);
    // cout << cnt << endk;
    // cout << mem << endk;
    rep(i, n) if(i) {
      int j = 0;
      int cnt = 0;
      for(int id: mem[i]) {
        ans[id] = mem[i-1][j];
        cnt++;
        if(cnt == 2) {
          j++;
          cnt = 0;
        }
      }
    }
    rep(i, n) if(i) cout << ans[i]+1 << ' ';
    cout << endk;
  } else {
    cout << "NO" << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
