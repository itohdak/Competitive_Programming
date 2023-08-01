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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, d, h; cin >> n >> d >> h;
  vector<int> Y(n);
  ld s = (ld)1 * d * h / 2;
  rep(i, n) cin >> Y[i];
  ld sum = 0;
  rep(i, n) {
    if(i == n-1) {
      sum += 1;
    } else {
      if(Y[i+1] >= Y[i]+h) {
	sum += 1;
      } else {
	ld tmp = (ld)1 * (Y[i+1]-Y[i]-h) / h;
	sum += 1 - tmp * tmp;
      }
    }
  }
  cout << fixed << setprecision(10) << s * sum << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
