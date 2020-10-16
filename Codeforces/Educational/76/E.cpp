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

vector<vector<int> > C;

int main() {
  vector<int> K(3);
  int sum = 0;
  rep(i, 3) {
    cin >> K[i];
    sum += K[i];
  }
  vector<set<int> > A(3);
  rep(i, 3) rep(j, K[i]) {
    int a;
    cin >> a;
    a--;
    A[i].insert(a);
  }
  C = vector<vector<int> >(sum+1, vector<int>(3));
  REP(i, 1, sum+1) {
    rep(j, 3) {
      C[i][j] = C[i-1][j];
      if(!A[j].count(i-1)) C[i][j]++;
    }
  }
  // rep(i, sum+1) cout << C[i] << endl;
  vector<vector<int> > dp(sum+1, vector<int>(3));
  rep(i, sum+1) {
    if(i) {
      dp[i][0] = dp[i-1][0]+C[i][0]-C[i-1][0];
      dp[i][1] = min(dp[i][0],
                     dp[i-1][1]+C[i][1]-C[i-1][1]);
      dp[i][2] = min(dp[i][0],
                     min(dp[i][1],
                         dp[i-1][2]+C[i][2]-C[i-1][2]));
    } else {
      dp[i][0] = 0;
      dp[i][1] = 0;
      dp[i][2] = 0;
    }
  }
  cout << dp[sum][2] << endl;
  return 0;
}

