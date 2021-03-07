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
  vector<ll> D(n); rep(i, n) cin >> D[i];
  int l = 0, r = n-1;
  ll sum1 = 0, sum3 = 0;
  ll ans = 0;
  while(l <= r) {
    while(l <= r && sum1 < sum3) {
      sum1 += D[l++];
    }
    if(sum1 == sum3) {
      chmax(ans, sum1);
      sum1 += D[l++];
    }
    if(l > r) break;
    while(l <= r && sum1 > sum3) {
      sum3 += D[r--];
    }
    if(sum1 == sum3) {
      chmax(ans, sum1);
      sum3 += D[r--];
    }
    if(l > r) break;
  }
  cout << ans << endk;
  return 0;
}
