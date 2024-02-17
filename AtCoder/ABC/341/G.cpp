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
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> cum(n+1);
  rep(i, n) cum[i+1] = cum[i] + A[i];
  vector<ld> ans(n);
  vector<int> B;
  rrep(i, n+1) {
    int x0 = i;
    ll y0 = cum[i];
    while(B.size() > 1) {
      int sz = B.size();
      int x1 = B[sz-1], x2 = B[sz-2];
      ll y1 = cum[x1], y2 = cum[x2];
      ld d1 = (ld)(y1-y0)/(x1-x0);
      ld d2 = (ld)(y2-y0)/(x2-x0);
      if(d2 >= d1) {
        B.pop_back();
      } else {
        break;
      }
    }
    if(i < n) {
      int sz = B.size();
      int x = B[sz-1];
      ll y = cum[x];
      ld d = (ld)(y-y0)/(x-x0);
      ans[i] = d;
    }
    B.push_back(i);
  }
  cout << fixed << setprecision(10);
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
