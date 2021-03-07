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

  constexpr ll MAX = 1000000;
  vector<ll> sum(MAX+1);
  for(int i=1; i<=MAX; i++) {
    if(i == 1) continue;
    for(int j=i*2; j<=MAX; j+=i) {
      (sum[j] += i) %= mod;
    }
  }

  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> cnt(MAX+1);
  rep(i, n) {
    vector<ll> div;
    find_divisor(A[i], div);
    for(ll d: div) {
      if(d != 1) cnt[d]++;
    }
  }

  vector<ll> ans(MAX+1);
  for(ll i=MAX; i>=2; i--) {
    ans[i] = cnt[i] * modpow(2, cnt[i]-1) % mod;
    for(int j=2; i*j<=MAX; j++) {
      (ans[i] += mod - ans[i*j]) %= mod;
    }
  }
  ll ANS = 0;
  for(int i=2; i<=MAX; i++) {
    (ANS += ans[i] * i) %= mod;
  }
  cout << ANS << endk;
  return 0;
}
