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
  int N;
  cin >> N;
  vector<int> A(N), sum(N+1);
  map<int, int> mp;
  rep(i, N) {
    cin >> A[i];
    mp[A[i]]++;
    sum[i+1] = sum[i] + A[i];
  }
  // cout << sum << endl;
  // cout << mp << endl;
  ll ans = 0;
  set<int> se;
  rep(i, N+1) REP(j, i+2, N+1) {
    ll tmp = sum[j]-sum[i];
    if(!se.count(tmp) && mp.count(tmp)) {
      ans += mp[tmp];
      se.insert(tmp);
    }
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
