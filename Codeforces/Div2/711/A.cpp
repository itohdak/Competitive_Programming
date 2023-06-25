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
bool calc(ll n) {
  ll sum = 0;
  ll m = n;
  while(m) {
    sum += m%10;
    m /= 10;
  }
  vector<ll> div;
  find_divisor(sum, div);
  for(ll d: div) {
    if(d == 1) continue;
    if(n % d == 0) {
      cout << n << endk;
      return true;
    }
  }
  return false;
}
void solve() {
  ll n; cin >> n;
  while(!calc(n)) {
    n++;
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
