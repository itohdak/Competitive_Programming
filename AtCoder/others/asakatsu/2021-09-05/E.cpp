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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int mni = min_element(all(A)) - begin(A), mxi = max_element(all(A)) - begin(A);
  ll mn = A[mni], mx = A[mxi];
  if(mn >= 0) {
    vector<pair<int, int>> ans;
    cout << n-1 << endk;
    rep(i, n-1) {
      cout << i+1 << ' ' << i+2 << endk;
      A[i+1] += A[i];
    }
  } else if(mx <= 0) {
    cout << n-1 << endk;
    rrep(i, n-1) {
      cout << i+2 << ' ' << i+1 << endk;
      A[i] += A[i+1];
    }
  } else if(abs(mn) > mx) {
    cout << 2*n-2 << endk;
    rep(i, n) {
      if(i == mni) continue;
      cout << mni+1 << ' ' << i+1 << endk;
      A[i] += A[mni];
    }
    rrep(i, n-1) {
      cout << i+2 << ' ' << i+1 << endk;
      A[i] += A[i+1];
    }
  } else {
    cout << 2*n-2 << endk;
    rep(i, n) {
      if(i == mxi) continue;
      cout << mxi+1 << ' ' << i+1 << endk;
      A[i] += A[mxi];
    }
    rep(i, n-1) {
      cout << i+1 << ' ' << i+2 << endk;
      A[i+1] += A[i];
    }
  }
  // cout << A << endk;
  return 0;
}
