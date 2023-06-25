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
  vector<ll> S(n); rep(i, n) cin >> S[i];
  vector<ll> A(3);
  rep(j, 3) {
    ll cum = 0;
    for(int i=j; i+1<n; i+=3) {
      cum += S[i+1]-S[i];
      chmax(A[j], -cum);
    }
  }
  if(A[0]+A[1]+A[2] > S[0]) {
    cout << "No" << endk;
  } else {
    vector<ll> ans(n+2);
    ans[0] = S[0]-A[1]-A[2];
    ans[1] = A[1];
    ans[2] = A[2];
    for(int i=3; i<n+2; i++) {
      ans[i] = S[i-2]-ans[i-1]-ans[i-2];
    }
    cout << "Yes" << endk;
    rep(i, n+2) cout << ans[i] << ' '; cout << endk;
  }
  return 0;
}
