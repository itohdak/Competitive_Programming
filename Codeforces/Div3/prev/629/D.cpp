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
  cin >> N;
  vector<int> T(N);
  rep(i, N) cin >> T[i];
  vector<int> ans(N);
  ans[0] = 1;
  int mx = 1;
  int cnt = 0;
  rep(i, N-1) {
    if(i) {
      if(T[i-1] == T[i]) {
	ans[i] = ans[i-1];
	cnt++;
      } else {
	ans[i] = 3-ans[i-1];
      }
      mx = max(ans[i], mx);
    }
  }
  if(T[N-2] != T[N-1] && T[N-1] != T[0]) {
    if(ans[N-2] == ans[0]) ans[N-1] = 3-ans[0];
    else if(cnt) {
      bool flip = false;
      rep(i, N-1) {
	if(i) {
	  if(flip) ans[i] = 3-ans[i];
	  else if(T[i] == T[i-1]) {
	    ans[i] = 3-ans[i];
	    flip = true;
	  }
	}
      }
      ans[N-1] = 3-ans[0];
    } else ans[N-1] = 3;
  } else if(T[N-2] != T[N-1]) {
    ans[N-1] = 3-ans[N-2];
  } else if(T[N-1] != T[0]) {
    ans[N-1] = 3-ans[0];
  } else {
    ans[N-1] = 1;
  }
  mx = max(ans[N-1], mx);
  cout << mx << endl;
  rep(i, N) cout << ans[i] << ' '; cout << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
