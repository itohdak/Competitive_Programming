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

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<char> C(4); rep(i, 4) cin >> C[i];
  vector<ll> fib(n);
  fib[0] = fib[1] = 1;
  REP(i, 2, n) (fib[i] = fib[i-1] + fib[i-2]) %= mod;
  if(n == 2) cout << 1 << endk;
  else if(C[1] == 'B') {
    if(C[3] == 'B') cout << 1 << endk; // AB(B)B
    else if(C[2] == 'A') cout << modpow(2, n-3) << endk; // AB(*)B
    else cout << fib[n-2] << endk;
  }
  else {
    if(C[0] == 'A') cout << 1 << endk; // A(A)AB
    else if(C[2] == 'B') cout << modpow(2, n-3) << endk; // A(*)AB
    else cout << fib[n-2] << endk;
  }
  return 0;
}
