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

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return g * (x / g) * (y / g);
}
void solve() {
  int a, b, q;
  cin >> a >> b >> q;
  ll c = lcm(a, b);
  vector<int> cnt(c+1);
  rep(i, c+1) if(i) {
    cnt[i] = cnt[i-1];
    if(i % a % b != i % b % a) cnt[i]++;
  }
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    l--;
    ll ansl, ansr;
    ansl = (l/c)*cnt[c]+cnt[l%c];
    ansr = (r/c)*cnt[c]+cnt[r%c];
    cout << ansr - ansl << ' ';
  }
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
