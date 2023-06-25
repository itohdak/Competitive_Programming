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
  string n; cin >> n;
  vector<int> prev(10, -inf);
  int ans = inf;
  rep(i, n.size()) {
    int m = n[i]-'0';
    if(m == 0) {
      chmin(ans, i-prev[0]-1+n.size()-i-1);
      chmin(ans, i-prev[5]-1+n.size()-i-1);
    } else if(m == 5) {
      chmin(ans, i-prev[2]-1+n.size()-i-1);
      chmin(ans, i-prev[7]-1+n.size()-i-1);
    }
    prev[m] = i;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
