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
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, int> > A(N);
  rep(i, N) { cin >> A[i].first; A[i].second = i; }
  sort(all(A));
  vector<pair<int, ll> > B(N);
  rep(i, N) B[i].first = A[i].second;
  vector<int> C(N);
  vector<ll> dp(N+1, longinf);
  vector<pair<int, int> > memo(N+1, make_pair(-1, 0));
  dp[0] = 0;
  memo[0].second = 0;
  rep(i, N+1) {
    REP(j, 3, 6) {
      if(i+j > N) break;
      if(dp[i] + (A[i+j-1].first - A[i].first) < dp[i+j]) {
        dp[i+j] = dp[i] + (A[i+j-1].first - A[i].first);
        memo[i+j].first = i;
        memo[i+j].second = memo[i].second + 1;
      }
    }
  }
  cout << dp[N] << ' ' << memo[N].second << endl;
  vector<int> ans(N+1);
  int tmp = N;
  // cout << A << endl;
  // cout << dp << endl;
  // cout << memo << endl;
  while(tmp > 0) {
    REP(i, memo[tmp].first+1, tmp+1) ans[i] = memo[tmp].second;
    tmp = memo[tmp].first;
  }
  REP(i, 1, N+1) B[i-1].second = ans[i];
  sort(all(B));
  rep(i, N) cout << B[i].second << ' '; cout << endl;
  return 0;
}

