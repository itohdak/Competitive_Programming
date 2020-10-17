#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll solve() {
  ll n, k, w; cin >> n >> k >> w;
  vector<ll> L(n); rep(i, k) cin >> L[i];
  ll lparam[4]; rep(i, 4) cin >> lparam[i];
  vector<ll> H(n); rep(i, k) cin >> H[i];
  ll hparam[4]; rep(i, 4) cin >> hparam[i];
  REP(i, k, n) {
    ll a, b, c, d;
    a = lparam[0], b = lparam[1], c = lparam[2], d = lparam[3];
    L[i] = (a*L[i-2]%d+b*L[i-1]%d+c)%d+1;
    a = hparam[0], b = hparam[1], c = hparam[2], d = hparam[3];
    H[i] = (a*H[i-2]%d+b*H[i-1]%d+c)%d+1;
  }
  ll ans = 1;
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": " << solve() << endk;
  }
  return 0;
}
