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
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  ll ans = 0;
  vector<ll> cnt(B+C+1);
  for(int i=A+B; i<=B+C; i++) {
    cnt[i] = min(i-A, C) - max(i-B, B) + 1;
  }
  rrep(i, B+C) cnt[i] += cnt[i+1];
  for(int z=C; z<=D; z++) {
    if(z+1 > B+C) break;
    ans += cnt[z+1];
  }
  cout << ans << endl;
  return 0;
}
