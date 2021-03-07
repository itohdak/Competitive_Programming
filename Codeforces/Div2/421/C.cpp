#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b; ll l, r; cin >> a >> b >> l >> r;
  l--;
  int x = (a <= b ? 1 : a-b);
  ll ql = l/(a+b), qr = r/(a+b);
  int rl = l%(a+b), rr = r%(a+b);
  if(rl<a-x) {
    if(qr-ql>=2) {
      cout << a+x << endk;
    } else if(qr-ql==1) {
      if(rr<=a-x)    cout << min(a-(rl-rr), a) << endk;
      else if(rr<=a) cout << rr+x << endk;
      else           cout << a+x << endk;
    } else {
      if(rr<=a) cout << rr-rl << endk;
      else      cout << a-rl << endk;
    }
  } else if(rl<a) {
    if(qr-ql>=3) {
      cout << a+x << endk;
    } else if(qr-ql==2) {
      if(rr<=a-x)     cout << 2*a-rl << endk;
      else if(rr<=rl) cout << a-rl+rr+x << endk;
      else            cout << a+x << endk;
    } else if(qr-ql==1) {
      if(rr<=a) cout << a-rl+rr << endk;
      else      cout << 2*a-rl << endk;
    } else {
      if(rr<=a) cout << rr-rl << endk;
      else      cout << a-rl << endk;
    }
  } else {
    if(qr-ql>=3) {
      cout << a+x << endk;
    } else if(qr-ql==2) {
      if(rr<=a-x)      cout << 1+a << endk;
      else if(rr<=a-1) cout << 1+rr+x << endk;
      else             cout << a+x << endk;
    } else if(qr-ql==1) {
      if(rr<=a) cout << 1+rr << endk;
      else      cout << 1+a  << endk;
    } else {
      cout << 1 << endk;
    }
  }
  return 0;
}
