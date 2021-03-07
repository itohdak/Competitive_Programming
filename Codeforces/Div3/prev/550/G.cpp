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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> inc, dec;
  rep(i, n) {
    bool ok1, ok2;
    if(inc.empty()) ok1 = true;
    else if(A[inc.back()] < A[i]) ok1 = true;
    else ok1 = false;
    if(dec.empty()) ok2 = true;
    else if(A[dec.back()] > A[i]) ok2 = true;
    else ok2 = false;
    if(ok1 && ok2) {
      if(i == n-1) inc.push_back(i);
      else if(A[i+1] > A[i]) inc.push_back(i);
      else dec.push_back(i);
    } else if(ok1) {
      inc.push_back(i);
    } else if(ok2) {
      dec.push_back(i);
    } else {
      cout << "NO" << endk;
      return 0;
    }
  }
  cout << "YES" << endk;
  vector<int> ans(n, 1);
  for(int i: inc) ans[i] = 0;
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
