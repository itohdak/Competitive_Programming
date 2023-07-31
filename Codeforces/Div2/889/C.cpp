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
  auto mx = max_element(all(A));
  auto mn = min_element(all(A));
  if(*mx == 0 && *mn == 0) {
    cout << 0 << endk;
  } else {
    bool rev = false;
    if(*mx <= 0) {
      rev = true;
      rep(i, n) A[i] = -A[i];
      reverse(all(A));
      mx = max_element(all(A));
    }
    int p = mx-begin(A);
    vector<pair<int, int>> ans;
    while(A[p] < 20) {
      ans.push_back({p, p});
      A[p] += A[p];
    }
    rep(i, n) {
      if(i == 0) {
	while(A[i] < 20) {
	  ans.push_back({i, p});
	  A[i] += A[p];
	}
      } else {
	while(A[i] < A[i-1]) {
	  ans.push_back({i, i-1});
	  A[i] += A[i-1];
	}
      }
    }
    // assert(ans.size() <= 50);
    cout << ans.size() << endk;
    for(auto [i, j]: ans) {
      if(rev) {
	cout << n-i << ' ' << n-j << endk;
      } else {
	cout << i+1 << ' ' << j+1 << endk;
      }
    }
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
