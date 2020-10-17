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
  int N, K;
  cin >> N >> K;
  vector<string> S(N);
  rep(i, N) cin >> S[i];
  sort(all(S));
  int ans = 0;
  for(int i=0; i<N; i+=K) {
    string T = S[i];
    int valid = T.size();
    REP(j, i, i+K) {
      int tmp = 0;
      while(tmp < min(valid, (int)S[j].size())) {
	if(T[tmp] == S[j][tmp]) tmp++;
	else break;
      }
      valid = tmp;
    }
    ans += valid;
  }
  cout << "Case #" << i << ": ";
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(i, T) solve(i+1);
  return 0;
}

