#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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

void prime_factorization(ll N, map<ll, int>& res) {
  if(N == 1 || N == 0) return;
  ll n = N;
  ll i = 2;
  while(n >= i * i) {
    while(n % i == 0) {
      if(res.count(i)) res[i]++;
      else res[i] = 1;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
  }
  if(n != 1) res[n] = 1;
}

ll binary_pow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) {
      ans *= tmp;
      // ans %= mod;
    }
    N /= 2;
    tmp *= tmp;
    // tmp %= mod;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<ll, pair<int, int>> M;
  map<ll, int> cnt;
  rep(i, N) {
    cin >> A[i];
    map<ll, int> mp;
    prime_factorization(A[i], mp);
    for(auto m: mp) {
      ll p = m.first;
      int n = m.second;
      if(!M.count(p)) M[p] = make_pair(inf, inf);
      cnt[p]++;
      if(n < M[p].first) {
        M[p].second = M[p].first;
        M[p].first = n;
      } else if(n < M[p].second) {
        M[p].second = n;
      }
    }
  }
  ll ans = 1;
  for(auto& m: M) {
    ll p = m.first;
    if(cnt[p] <= N-2) {
      continue;
    } else if(cnt[p] == N-1) {
      ans *= binary_pow(p, m.second.first);
    } else {
      ans *= binary_pow(p, m.second.second);
    }
  }
  cout << ans << endl;
  return 0;
}
