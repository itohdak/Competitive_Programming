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
  ll h, n; cin >> h >> n;
  vector<ll> D(n), sum(n+1);
  rep(i, n) {
    cin >> D[i];
    D[i] = -D[i];
    sum[i+1] = sum[i] + D[i];
  }
  rep(i, n+1) {
    if(sum[i] >= h) {
      cout << i << endk;
      return;
    }
  }
  if(sum[n] <= 0) {
    cout << -1 << endk;
    return;
  }
  ll mx = *max_element(all(sum));
  ll times = (h-mx+sum[n]-1)/sum[n];
  ll tmp = times * sum[n];
  rep(i, n+1) {
    if(tmp + sum[i] >= h) {
      cout << n * times + i << endk;
      return;
    }
  }
  assert(false);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
