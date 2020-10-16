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

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  ll mx = 0;
  rep(i, N) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  rep(i, N) {
    B[i] = mx - A[i];
  }
  sort(all(B));
  set<ll> se;
  rep(i, N-1) se.insert(B[i+1] - B[i]);
  ll z = 0;
  rep(i, N-1) {
    if(z) z = gcd(z, B[i+1]);
    else z = gcd(B[i], B[i+1]);
  }
  ll y = 0;
  rep(i, N) {
    y += (B[i] + z - 1) / z;
  }
  cout << endl;
  cout << y << ' ' << z << endl;
  return 0;
}

