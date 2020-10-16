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
  ll N;
  cin >> N;
  vector<ll> ans;
  ll pw = 1;
  while(N >= pw) {
    ans.push_back(pw);
    N -= pw;
    pw *= 2;
  }
  if(N) {
    ans.push_back(N);
    sort(all(ans));
  }
  cout << ans.size()-1 << endl;
  rep(i, ans.size()) if(i) cout << ans[i]-ans[i-1] << ' ';
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
