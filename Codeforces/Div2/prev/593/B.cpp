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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

ll binary_pow(ll a, ll b) {
  ll ans = 1;
  ll tmp = a;
  while(b > 0) {
    if(b % 2 == 1) {
      ans *= tmp;
      ans %= mod;
    }
    b /= 2;
    tmp *= tmp;
    tmp %= mod;
  }
  return ans;
}

int main() {
  ll N, M;
  cin >> N >> M;
  // pow((pow(2, M) - 1), N)
  ll ans = binary_pow(2, M);
  ll ans2 = binary_pow((ans+mod-1)%mod, N);
  cout << ans2 << endl;
  return 0;
}

