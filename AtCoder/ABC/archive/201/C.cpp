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

#define MAX_N 55
ll C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i;
    C[i][i] = 1;
    C[0][i] = 1;
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}
ll comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  string s; cin >> s;
  vector<int> cnt(3);
  rep(i, s.size()) {
    if(s[i] == 'o') cnt[0]++;
    else if(s[i] == 'x') cnt[1]++;
    else cnt[2]++;
  }
  auto calc = [&](int c) {
    if(c == 1) return 1;
    else if(c == 2) return 14;
    else if(c == 3) return 36;
    else if(c == 4) return 24;
    else return 0;
  };
  ll ans = 0;
  for(int i=0; i<=cnt[2]; i++) {
    ans += comb(cnt[2], i) * calc(cnt[0]+i);
  }
  cout << ans << endk;
  return 0;
}
