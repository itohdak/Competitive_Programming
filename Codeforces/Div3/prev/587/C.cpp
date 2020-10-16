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
  vector<ll> X(6), Y(6);
  rep(i, 6) cin >> X[i] >> Y[i];
  ll a = (X[1]-X[0]) * (Y[1]-Y[0]);
  REP(i, 2, 6) {
    X[i] = min(X[1], max(X[0], X[i]));
    Y[i] = min(Y[1], max(Y[0], Y[i]));
  }
  ll b;
  {
    ll xmax = max(X[2], X[4]);
    ll xmin = min(X[3], X[5]);
    ll ymax = max(Y[2], Y[4]);
    ll ymin = min(Y[3], Y[5]);
    b = (X[3]-X[2]) * (Y[3]-Y[2]) + (X[5]-X[4]) * (Y[5]-Y[4]) - max(0LL, xmin - xmax) * max(0LL, ymin - ymax);
  }
  if(a == b) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}

