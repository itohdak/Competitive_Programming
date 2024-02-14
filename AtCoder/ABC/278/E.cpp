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
  int H, W, n, h, w; cin >> H >> W >> n >> h >> w;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, H) rep(j, W) {
    cin >> A[i][j];
    A[i][j]--;
  }
  vector<int> cnt(n);
  int ans = 0;
  rep(i, H) rep(j, W) {
    if(cnt[A[i][j]]++ == 0) ans++;
  }
  rep(i, H-h+1) {
    auto c = cnt;
    int a = ans;
    rep(di, h) rep(dj, w) {
      if(--c[A[i+di][0+dj]] == 0) a--;
    }
    rep(j, W-w+1) {
      cout << a << ' ';
      rep(di, h) {
        if(--c[A[i+di][j+w]] == 0) a--;
        if(c[A[i+di][j]]++ == 0) a++;
      }
    }
    cout << endk;
  }
  return 0;
}
