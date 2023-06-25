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
  int t; cin >> t;
  while(t--) {
    vector<ll> A(3); rep(i, 3) cin >> A[i];
    sort(all(A));
    ll ans = longinf;
    if((A[1]-A[0])%3==0) {
      chmin(ans, A[1]);
    }
    if((A[2]-A[0])%3==0) {
      chmin(ans, A[2]);
    }
    if((A[2]-A[1])%3==0) {
      ll n = (A[2]-A[0])/3;
      ll m = (A[0]>=n ? 0LL : (A[0]-n+1)/2);
      if(A[1] >= m) {
        ll a = A[0]+2*m, b = A[1]-m, c = A[2]-m;
        chmin(ans, m+c);
      }
    }
    cout << (ans == longinf ? -1 : ans) << endk;
  }
  return 0;
}
