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
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  int ans = 0;
  rep(i, N) {
    if(i) {
      if(A[i] < A[i-1]) {
	ll a = A[i-1] - A[i];
	int tmp = 1;
	while(a) {
	  ans = max(tmp, ans);
	  tmp++;
	  a >>= 1;
	}
	A[i] = A[i-1];
      }
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
