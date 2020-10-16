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

void solve() {
  int a, b, c; cin >> a >> b >> c;
  ll ans = longinf;
  int ansi, ansj;
  for(ll i=1; i<=10000; i++) {
    for(ll j=1; j<=10000; j++) {
      if(i*j >= 100000) break;
      ll tmp = 0;
      tmp += abs(a-i);
      tmp += abs(b-i*j);
      ll b_ = i*j;
      tmp += min(abs(c-c/b_*b_), abs(c-(c/b_+1)*b_));
      if(tmp < ans) {
        ans = tmp;
        ansi = i;
        ansj = j;
      }
    }
    // cout << i << endl;
  }
  ll b_ = 1LL * ansi * ansj;
  cout << ans << endk;
  cout << ansi << ' ' << b_ << ' ' << (abs(c-c/b_*b_) < abs(c-(c/b_+1)*b_) ? c/b_*b_ : (c/b_+1)*b_) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
