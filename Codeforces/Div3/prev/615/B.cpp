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
  vector<vector<int>> v(1001);
  rep(i, n) {
    int x, y; cin >> x >> y;
    v[x].push_back(y);
  }
  rep(i, 1001) sort(all(v[i]));
  string ans;
  int tmpy = 0;
  int prevx = 0;
  rep(i, 1001) {
    if(v[i].size() == 0) continue;
    if(v[i].front() < tmpy) {
      cout << "NO" << endk;
      return;
    }
    ans += string(i-prevx, 'R');
    ans += string(v[i].back()-tmpy, 'U');
    tmpy = v[i].back();
    prevx = i;
  }
  cout << "YES" << endk;
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
