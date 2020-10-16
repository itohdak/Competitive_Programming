#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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
  int N;
  string S;
  cin >> N >> S;
  vector<string> T(2);
  T[0] = S.substr(0, N);
  T[1] = S.substr(N, N);
  reverse(all(T[1]));
  vector<map<pair<string, string>, ll>> mp(2);
  rep(n, 2) {
    rep(i, 1<<N) {
      vector<string> s(2);
      rep(j, N) {
        s[(i>>j)&1] += T[n][j];
      }
      mp[n][make_pair(s[0], s[1])]++;
    }
  }
  // cout << mp[0] << endl << mp[1] << endl;
  ll ans = 0;
  for(auto m: mp[0]) {
    ans += m.second * mp[1][m.first];
  }
  cout << ans << endl;
  return 0;
}
