#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
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
void solve() {
  ll n;
  cin >> n;
  int cnt = 0;
  while(n > 1) {
    map<ll, int> res;
    prime_factorization(n, res);
    if(!res.count(2)) {
      n = 1;
    } else if(res.size() == 1) {
      n--;
    } else if(res[2] == 1) {
      auto itr = ++res.begin();
      if(n != 2 * itr->first) n = 2 * itr->first;
      else n = 2;
    } else {
      n = 1 << res[2];
    }
    // cout << n << endl;
    cnt++;
  }
  cout << (cnt%2==0 ? "FastestFinger" : "Ashishgup") << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
