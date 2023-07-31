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
  vector<int> cnt(2);
  rep(i, n) {
    if(A[i] > 0) cnt[1]++;
    else cnt[0]++;
  }
  bool rev = false;
  if(cnt[0] > cnt[1]) {
    rev = true;
    rep(i, n) A[i] = -A[i];
    reverse(all(A));
  }
  int mx = -1, mxi = -1;
  rep(i, n) {
    if(abs(A[i]) > mx) {
      mx = abs(A[i]);
      mxi = i;
    } else if(abs(A[i]) == mx) {
      if(A[i] >= 0) {
	mxi = i;
      }
    }
  }
  vector<pair<int, int>> ans;
  if(A[mxi] < 0) {
    int mx2 = -1, mxi2 = -1;
    rep(i, n) {
      if(A[i] <= 0) continue;
      if(A[i] > mx2) {
	mx2 = A[i];
	mxi2 = i;
      }
    }
    while(A[mxi2] < abs(A[mxi])) {
      ans.push_back({mxi2, mxi2});
      A[mxi2] += A[mxi2];
    }
    mx = A[mxi2];
    mxi = mxi2;
  }
  rep(i, n) {
    if(i == 0) {
      if(A[i] < 0) {
	ans.push_back({i, mxi});
	A[i] += A[mxi];
      }
      ans.push_back({i, mxi});
      A[i] += A[mxi];
    } else {
      while(A[i] < A[i-1]) {
	ans.push_back({i, i-1});
	A[i] += A[i-1];
      }
    }
  }
  // assert(ans.size() <= 31);
  cout << ans.size() << endk;
  for(auto [i, j]: ans) {
    if(rev) cout << n-i << ' ' << n-j << endk;
    else cout << i+1 << ' ' << j+1 << endk;
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
