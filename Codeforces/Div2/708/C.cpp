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
  ll n; int k; cin >> n >> k;
  if((n-(k-2))%2==0) {
    ll rem = (n-(k-2));
    cout << rem/2 << ' ' << rem/2 << ' ';
    rep(i, k-2) cout << 1 << ' ';
    cout << endk;
  } else {
    ll rem = (n-(k-3));
    assert(rem % 2 == 0);
    if(rem % 4 == 0) {
      cout << rem/4*2 << ' ' << rem/4 << ' ' << rem/4 << ' ';
    } else if(rem % 4 == 2) {
      cout << 2 << ' ' << rem/2-1 << ' ' << rem/2-1 << ' ';
    } else {
      assert(false);
    }
    rep(i, k-3) cout << 1 << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
