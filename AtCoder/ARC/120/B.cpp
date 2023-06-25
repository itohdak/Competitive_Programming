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
// const ll mod = 1e9+7;
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<vector<int>> cnt(h+w-1, vector<int>(2));
  rep(i, h) rep(j, w) {
    if(S[i][j] == 'R') {
      cnt[i+j][0]++;
    } else if(S[i][j] == 'B') {
      cnt[i+j][1]++;
    }
  }
  ll ans = 1;
  rep(i, h+w-1) {
    if(cnt[i][0] && cnt[i][1]) ans *= 0;
    else if(!cnt[i][0] && !cnt[i][1]) (ans *= 2) %= mod;
    else ans *= 1;
  }
  cout << ans << endk;
  return 0;
}
