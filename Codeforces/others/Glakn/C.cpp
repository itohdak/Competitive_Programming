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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; ll l; cin >> n >> l;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  deque<ll> q; rep(i, n) q.push_back(A[i]);
  ld p0 = 0, p1 = l;
  ll v0 = 1, v1 = 1;
  ld ans = 0;
  while(!q.empty()) {
    ld t0 = (ld)(q.front()-p0)/v0;
    ld t1 = (ld)(p1-q.back())/v1;
    if(t0 <= t1) {
      p0 = q.front(); q.pop_front();
      v0++;
      p1 -= v1*t0;
      ans += t0;
    } else {
      p1 = q.back(); q.pop_back();
      v1++;
      p0 += v0*t1;
      ans += t1;
    }
  }
  ans += (p1-p0)/(v0+v1);
  cout << fixed << setprecision(15) << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
