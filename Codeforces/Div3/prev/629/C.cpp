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

void solve() {
  int N;
  string S;
  cin >> N >> S;
  vector<string> ans(2, "");
  bool flag = false;
  rep(i, N) {
    if(flag) {
      ans[0] += "0";
      ans[1] += S[i];
    } else {
      if(S[i] == '2') {
	rep(j, 2) ans[j] += "1";
      } else if(S[i] == '1') {
	if(i) {
	  ans[0] += "1";
	  ans[1] += "0";
	  flag = true;

	} else {
	  rep(j, 2) ans[j] += "2";
	}
      } else {
	rep(j, 2) ans[j] += "0";
      }
    }
    // rep(i, 2) cout << ans[i] << endl;
  }
  rep(i, 2) cout << ans[i] << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
