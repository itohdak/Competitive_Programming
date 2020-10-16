#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
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

map<ll, int> res;
void prime_factorization(ll N) {
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
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> ans(N);
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  map<int, int> mp;
  rep(i, 11) mp[primes[i]] = i;
  vector<int> cnt(11);
  rep(i, N) {
    cin >> A[i];
    res = map<ll, int>();
    prime_factorization(A[i]);
    ans[i] = mp[res.begin()->first];
    cnt[ans[i]]++;
  }
  map<int, int> mp2;
  int i = 0;
  for(auto m: mp) {
    if(cnt[m.second]) {
      mp2[m.second] = i;
      i++;
    }
  }
  cout << mp2.size() << endl;
  rep(i, N) cout << mp2[ans[i]]+1 << ' ';
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
