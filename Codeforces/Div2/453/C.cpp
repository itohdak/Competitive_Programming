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
  int h; cin >> h;
  vector<int> A(h+1); rep(i, h+1) cin >> A[i];
  int n = accumulate(all(A), 0);
  vector<int> ans(n);
  int l = 0;
  rep(i, h+1) {
    rep(j, A[i]) ans[l+j] = l-1;
    l += A[i];
  }
  l = 0;
  rep(i, h+1) {
    if(i && A[i] > 1 && A[i-1] > 1) {
      cout << "ambiguous" << endk;
      rep(j, n) cout << ans[j]+1 << ' '; cout << endk;
      assert(ans[l] == l-1);
      ans[l]--;
      rep(j, n) cout << ans[j]+1 << ' '; cout << endk;
      return 0;
    }
    l += A[i];
  }
  cout << "perfect" << endk;
  return 0;
}
