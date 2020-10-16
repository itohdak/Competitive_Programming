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
  int a, b, c; cin >> a >> b >> c;
  vector<tuple<int, int, int>> A;
  rep(i, 2) rep(j, 2) rep(k, 2) {
    if(!i && !j && !k) continue;
    A.push_back({i, j, k});
  }
  int mx = 0;
  rep(i, 1<<7) {
    int cnt = 0;
    int tmpa = a, tmpb = b, tmpc = c;
    rep(j, 7) {
      if((i>>j)&1 && get<0>(A[j]) <= tmpa && get<1>(A[j]) <= tmpb && get<2>(A[j]) <= tmpc) {
        cnt++;
        tmpa -= get<0>(A[j]);
        tmpb -= get<1>(A[j]);
        tmpc -= get<2>(A[j]);
      }
    }
    chmax(mx, cnt);
  }
  cout << mx << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
