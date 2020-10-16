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

void solve() {
  ll A, K;
  cin >> A >> K;
  vector<ll> ans;
  ans.push_back(A);
  while(true) {
    set<int> se;
    ll tmp = A;
    while(tmp > 0) {
      se.insert(tmp%10);
      tmp /= 10;
    }
    if(*se.begin() == 0) break;
    A += *se.begin() * *(--se.end());
    ans.push_back(A);
  }
  cout << ans[min(K-1, (ll)ans.size()-1)] << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
