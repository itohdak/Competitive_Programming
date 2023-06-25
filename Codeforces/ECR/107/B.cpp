#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

bool is_prime(const unsigned n) {
  switch(n) {
  case 0:
  case 1: return false;
  case 2:
  case 3: return true;
  }
  if(n % 2 == 0) return false;
  if(n % 3 == 0) return false;
  if(n % 6 != 1 && n % 6 != 5) return false;
  for(unsigned i=5; i*i<=n; i+=6) {
    if(n % i     == 0) return false;
    if(n % (i+2) == 0) return false;
  }
  return true;
}
vector<vector<ll>> base(10);
void solve() {
  int a, b, c; cin >> a >> b >> c;
  ll gcd = base[c][0];
  ll x = gcd * base[a-c+1][1];
  ll y = gcd * base[b-c+1][2];
  // cout << x << ' ' << y << ' ' << __gcd(x, y) << endl;
  assert((int)log10(x)+1 == a && (int)log10(y)+1 == b && (int)log10(__gcd(x, y))+1 == c);
  cout << x << ' ' << y << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll pw = 1;
  base[1].push_back(1);
  rep(i, 10) {
    if(i == 0) continue;
    ll tmp = pw;
    while(true) {
      if(is_prime(tmp)) {
        base[i].push_back(tmp);
        if(base[i].size() == 3) break;
      }
      tmp++;
    }
    pw *= 10;
  }
  // cout << base << endk;
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
