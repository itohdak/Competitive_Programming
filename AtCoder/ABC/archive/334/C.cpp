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
  int n, k; cin >> n >> k;
  vector<int> A(k); rep(i, k) cin >> A[i];
  if(k&1) {
    vector<ll> L, R;
    L.push_back(0);
    for(int i=0; i+1<k; i+=2) {
      L.push_back(A[i+1]-A[i]+L.back());
    }
    R.push_back(0);
    for(int i=k-1; i-1>=0; i-=2) {
      R.push_back(A[i]-A[i-1]+R.back());
    }
    reverse(all(R));
    ll ans = longinf;
    rep(i, L.size()) {
      chmin(ans, L[i]+R[i]);
    }
    cout << ans << endk;
  } else {
    ll ans = 0;
    for(int i=0; i<k; i+=2) {
      ans += A[i+1]-A[i];
    }
    cout << ans << endk;
  }
  return 0;
}
