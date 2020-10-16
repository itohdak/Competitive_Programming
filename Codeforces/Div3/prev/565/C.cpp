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
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, int> cnt;
  cnt[4] = 0, cnt[8] = 0, cnt[15] = 0, cnt[16] = 0, cnt[23] = 0, cnt[42] = 0;
  int ans = 0;
  rep(i, n) {
    if(A[i] == 4) {
      cnt[4]++;
    } else if(A[i] == 8 && cnt[4]) {
      cnt[4]--; cnt[8]++;
    } else if(A[i] == 15 && cnt[8]) {
      cnt[8]--; cnt[15]++;
    } else if(A[i] == 16 && cnt[15]) {
      cnt[15]--; cnt[16]++;
    } else if(A[i] == 23 && cnt[16]) {
      cnt[16]--; cnt[23]++;
    } else if(A[i] == 42 && cnt[23]) {
      cnt[23]--; cnt[42]++;
    } else {
      ans++;
    }
  }
  ans += cnt[4];
  ans += cnt[8] * 2;
  ans += cnt[15] * 3;
  ans += cnt[16] * 4;
  ans += cnt[23] * 5;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
