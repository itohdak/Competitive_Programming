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
  int n; cin >> n;
  vector<ll> B(n); rep(i, n) cin >> B[i];
  if(n == 1 || n == 2) {
    cout << 0 << endk;
    return;
  }
  int ans = inf;
  for(int d1=-1; d1<=1; d1++) {
    for(int d2=-1; d2<=1; d2++) {
      ll b0 = B[0] + d1;
      ll b1 = B[1] + d2;
      ll d = b1 - b0;
      bool ok = true;
      int cnt = (d1 != 0) + (d2 != 0);
      for(int i=2; i<n; i++) {
        if(b0+d*i < B[i]-1 || B[i]+1 < b0+d*i) ok = false;
        else if(b0+d*i != B[i]) cnt++;
      }
      if(ok) chmin(ans, cnt);
    }
  }
  cout << (ans == inf ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
