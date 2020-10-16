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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  ll ans = 0;
  for(int mx=0; mx<=30; mx++) {
    ll tmp = 0;
    ll mn = 0;
    rep(i, n) {
      tmp += (A[i] > mx ? -inf : A[i]);
      mn = min(tmp, mn);
      ans = max(tmp-mn-mx, ans);
    }
  }
  cout << ans << endl;
  return 0;
}
