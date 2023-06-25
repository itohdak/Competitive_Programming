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

void solve() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }
  int M;
  cin >> M;
  vector<ll> P(M);
  vector<int> S(M);
  vector<ll> B(N+1);
  rep(i, M) {
    cin >> P[i] >> S[i];
    B[S[i]] = max(P[i], B[S[i]]);
  }
  RREP(i, N-1, 1) B[i] = max(B[i], B[i+1]);
  int pos = 0;
  int ans = 0;
  bool ok = true;
  while(pos < N) {
    ++ans;
    int npos = pos;
    ll mx = 0;
    while(npos < N) {
      mx = max(mx, A[npos]);
      if(mx > B[npos-pos+1]) break;
      ++npos;
    }
    if(pos == npos) {
      ok = false;
      break;
    }
    pos = npos;
  }
  if(!ok) ans = -1;
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

