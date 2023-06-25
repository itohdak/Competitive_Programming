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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  vector<ll> D;
  vector<ll> div;
  rep(i, n) {
    div.clear();
    find_divisor(A[i], div);
    for(auto d: div) D.push_back(d);
    div.clear();
    find_divisor(B[i], div);
    for(auto d: div) D.push_back(d);
  }
  sort(all(D));
  D.erase(unique(all(D)), end(D));
  ll ans = 1;
  for(auto d1: D) {
    for(auto d2: D) {
      bool ok = true;
      rep(i, n) {
        if((A[i]%d1==0 && B[i]%d2==0) || (B[i]%d1==0 && A[i]%d2==0)) continue;
        ok = false;
        break;
      }
      if(ok) chmax(ans, d1*d2);
    }
  }
  ll gcd_all = A[0];
  rep(i, n) gcd_all = __gcd(__gcd(gcd_all, A[i]), B[i]);
  cout << ans / gcd_all << endk;
  return 0;
}
