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

void solve() {
  int N;
  ll K;
  cin >> N >> K;
  string S;
  cin >> S;
  int cnt = 0;
  rep(i, N) {
    if(S[i] == '0') {
      if(K >= i-cnt) {
        char tmp = S[cnt];
        S[cnt] = '0';
        S[i] = tmp;
        K -= i-cnt;
        cnt++;
      } else {
        char tmp = S[i-K];
        S[i-K] = '0';
        S[i] = tmp;
        break;
      }
    }
  }
  cout << S << endl;
}

int main() {
  int Q;
  cin >> Q;
  rep(q, Q) solve();
  return 0;
}

