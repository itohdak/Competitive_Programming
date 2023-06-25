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

void solve() {
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  if(n == 1) {
    if(1 < A[0]) {
      cout << 0 << ' ' << 0 << endk;
    } else {
      cout << 1 << ' ' << 0 << endk;
    }
  } else {
    int mx = -1;
    int ans_l = 0, ans_r = 0;
    vector<vector<int>> pos(5);
    rep(i, n) pos[A[i]+2].push_back(i);
    pos[2].push_back(n);
    rep(i, n) {
      int r = *lower_bound(all(pos[2]), i);
      vector<int> cnt(5);
      int mx_minus = 0;
      rep(j, 5) {
        cnt[j] = upper_bound(all(pos[j]), r-1) - lower_bound(all(pos[j]), i);
        if(j < 2 && cnt[j] > 0) {
          int tmp = *(--upper_bound(all(pos[j]), r-1));
          chmax(mx_minus, tmp);
        }
      }
      assert(cnt[2] == 0);
      if((cnt[0]+cnt[1])%2) {
        r = mx_minus;
        rep(j, 5) {
          cnt[j] = upper_bound(all(pos[j]), r-1) - lower_bound(all(pos[j]), i);
        }
      }
      assert((cnt[0]+cnt[1])%2 == 0);
      int cnt2 = cnt[0]+cnt[4];
      if(mx < cnt2) {
        ans_l = i, ans_r = n-r;
        mx = cnt2;
      }
    }
    cout << ans_l << ' ' << ans_r << endl;
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
