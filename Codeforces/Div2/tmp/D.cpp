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
  int n, m, p; cin >> n >> m >> p;
  vector<string> S(n);
  vector<int> cnt(m);
  rep(i, n) {
    cin >> S[i];
    rep(j, m) {
      cnt[j] += S[i][j] == '1';
    }
  }
  vector<int> half;
  rep(j, m) if(cnt[j] >= (n+1)/2) half.push_back(j);
  assert(half.size() <= 30);
  vector<int> T(n);
  rep(i, n) {
    rep(j, half.size()) {
      if(S[i][half[j]] == '1') T[i] ^= 1<<j;
    }
  }
  // cout << T << endk;
  vector<int> cnt2(1<<half.size());
  rep(i, n) {
    for(int j=T[i]+1; (--j)&=T[i]; ) {
      cnt2[j]++;
    }
  }
  int mx = 0;
  int mxi = 0;
  rep(i, 1<<half.size()) {
    if(cnt2[i] >= (n+1)/2 && __builtin_popcount(i) > mx) {
      mx = __builtin_popcount(i);
      mxi = i;
    }
  }
  // cout << mx << ' ' << mxi << endk;
  string ret(m, '0');
  rep(i, 30) if((mxi>>i)&1) ret[half[i]] = '1';
  cout << ret << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
