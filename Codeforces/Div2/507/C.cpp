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
  int n; ll t; cin >> n >> t;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<int> X(n);
  rep(i, n) {
    cin >> X[i];
    X[i]--;
  }
  rep(i, n) {
    if(X[i] < i) {
      cout << "No" << endk;
      return 0;
    }
    if(i+1 < n && X[i] > X[i+1]) {
      cout << "No" << endk;
      return 0;
    }
  }
  vector<int> flag(n);
  rep(i, n) {
    if(X[i] > i) {
      flag[i]++;
      flag[X[i]]--;
    }
  }
  rep(i, n) if(i) flag[i] += flag[i-1];
  vector<ll> B(n);
  rep(i, n) {
    if(flag[i]) {
      assert(i != n-1);
      chmax(B[i], A[i+1]+t);
    } else {
      chmax(B[i], A[i]+t);
    }
    if(i) chmax(B[i], B[i-1]+1);
  }
  bool ok = true;
  rep(i, n) {
    if(X[i]+1 < n && B[X[i]] >= A[X[i]+1]+t) ok = false;
  }
  if(!ok) cout << "No" << endk;
  else {
    cout << "Yes" << endk;
    rep(i, n) cout << B[i] << ' ';
    cout << endk;
  }
  return 0;
}
