#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll A[55][55];
int n;
void solve() {
  ll k; cin >> k;
  vector<pair<int, int>> ans;
  int m = 2*n-2;
  int x = n-1, y = n-1;
  while(!(x==0 && y==0)) {
    ans.push_back({x, y});
    if(A[x][y]>0) {
      if((k>>(m-1))&1) {
        y--;
      } else {
        x--;
      }
    } else {
      if((k>>(m-1))&1) {
        x--;
      } else {
        y--;
      }
    }
    m--;
  }
  ans.push_back({x, y});
  reverse(all(ans));
  assert(ans.size() == 2*n-1);
  rep(i, 2*n-1) cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  rep(i, n) rep(j, n) {
    if(i%2) A[i][j] = 1LL<<(i+j);
  }
  // output Axy
  rep(i, n) {
    rep(j, n) cout << A[i][j] << ' ';
    cout << endl;
  }
  // query
  int q; cin >> q;
  while(q--) solve();
  return 0;
}
