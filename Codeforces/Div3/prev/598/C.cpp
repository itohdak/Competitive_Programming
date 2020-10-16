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
  int N, M, D;
  cin >> N >> M >> D;
  vector<int> C(M);
  rep(i, M) cin >> C[i];
  vector<int> A(N+1);
  int tmp = N;
  rrep(i, M) {
    rep(j, C[i]) {
      A[tmp] = i+1;
      tmp--;
    }
  }
  tmp++;
  ll tmp2 = 0;
  bool ok = false;
  rep(i, M) {
    if(tmp2+D > N) {
      ok = true;
      break;
    } else if(A[tmp2+D] == 0) {
      rep(j, C[i]) A[tmp+j] = 0;
      rep(j, C[i]) A[tmp2+D+j] = i+1;
      tmp += C[i];
      tmp2 += D + C[i] - 1;
    } else {
      ok = true;
      break;
    }
  }
  if(ok) {
    cout << "YES" << endl;
    REP(i, 1, N+1) cout << A[i] << ' ';
    cout << endl;
  } else {
    if(tmp2+D > N) {
      cout << "YES" << endl;
      REP(i, 1, N+1) cout << A[i] << ' ';
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

