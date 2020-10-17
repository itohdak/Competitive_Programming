#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
// template<class t, class u>
// ostream& operator<<(ostream& os, const pair<t, u>& p) {
//   return os << "{" << p.first << ", " << p.second << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
//   os << "{";
//   rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
//   return os << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const set<t>& se) {
//   os << "{";
//   auto itr = se.begin();
//   rep(i, se.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
// template<class t, class u>
// ostream& operator<<(ostream& os, const map<t, u>& mp) {
//   os << "{";
//   auto itr = mp.begin();
//   rep(i, mp.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve(int i) {
  int N, K, P;
  cin >> N >> K >> P;
  vector<vector<int> > A(N, vector<int>(K)), sum(N, vector<int>(K+1));
  rep(i, N) {
    rep(j, K) {
      cin >> A[i][j];
      sum[i][j+1] = sum[i][j] + A[i][j];
    }
  }
  // cout << sum << endl;
  vector<vector<int> > dp(N+1, vector<int>(P+1));
  rep(i, N) {
    rep(j, P+1) {
      rep(k, K+1) {
	if(j+k<P+1) dp[i+1][j] = max(dp[i+1][j], dp[i][j+k]+sum[i][k]);
      }
    }
  }
  // cout << dp << endl;
  cout << "Case #" << i << ": ";
  cout << dp[N][0] << endl;
}
int main() {
  int T;
  cin >> T;
  rep(i, T) solve(i+1);
  return 0;
}

