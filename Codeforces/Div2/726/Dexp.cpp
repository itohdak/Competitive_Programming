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
void find_divisor(ll N, vector<ll>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
void solve() {
  ll n; cin >> n;
  vector<bool> memo(201, true);
  for(int i=1; i<=200; i++) {
    if(i == 1) memo[i] = false;
    else if(is_prime(i)) memo[i] = false;
    else {
      vector<ll> div;
      find_divisor(i, div);
      memo[i] = false;
      for(ll d: div) {
        if(d == 1 || d == i) continue;
        if(!memo[i-d]) memo[i] = true;
      }
    }
  }
  REP(i, 1, 201) cout << i << ' ' << memo[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
