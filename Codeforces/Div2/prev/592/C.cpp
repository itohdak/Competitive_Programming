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
  ll n, p, w, d;
  cin >> n >> p >> w >> d;
  // x * w + y * d == p
  // x + y + z = n
  // 0 <= x, y, z
  // 0 <= x + y <= n
  // 0 <= y <= n - x
  // x * w <= x * w + y * d == p <= x * (w - d) + n * d
  // ceil((p - n * d) / (w - d)) <= x <= floor(p / w)
  ll ib = max(0LL, (p-n*d+(w-d)-1)/(w-d));
  ll ie = min(min(n, p/w)+1, ib+d+1);
  REPL(i, ib, ie) {
    ll x, y, z;
    x = i;
    y = (p - x * w) / d;
    if(y * d != p - x * w || y < 0) continue;
    z = n - x - y;
    if(z < 0) continue;
    cout << x << ' ' << y << ' ' << z << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}

