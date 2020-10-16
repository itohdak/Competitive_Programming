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
  int nr, ng, nb;
  cin >> nr >> ng >> nb;
  vector<vector<ll> > RGB(3);
  int n[] = {nr, ng, nb};
  rep(i, 3) {
    rep(j, n[i]) {
      ll in;
      cin >> in;
      RGB[i].push_back(in);
    }
    sort(all(RGB[i]));
  }
  ll mn = LONG_LONG_MAX;
  rep(i, 3) {
    rep(j, 3) {
      rep(k, 3) {
	if(i != j && j != k && k != i) {
	  vector<ll>::iterator ai, bi, ci;
	  ai = RGB[i].begin();
	  bi = lower_bound(all(RGB[j]), *ai);
	  ci = lower_bound(all(RGB[k]), *bi);
	  while(ci != RGB[k].end()) {
	    bi = upper_bound(all(RGB[j]), *ci);
	    if(bi != RGB[j].begin()) bi--;
	    ai = upper_bound(all(RGB[i]), *bi);
	    if(ai != RGB[i].begin()) ai--;
	    ll a = *ai, b = *bi, c = *ci;
	    if(a <= b && b <= c) {
	      mn = min((a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a), mn);
	      bi = lower_bound(all(RGB[j]), (double)(*ai+*ci)/2);
	      if(bi != RGB[j].end()) {
		b = *bi;
		mn = min((a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a), mn);
	      }
	      if(bi != RGB[j].begin()) {
		b = *(--bi);
		mn = min((a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a), mn);
	      }
	    }
	    ci++;
	  }
	}
      }
    }
  }
  cout << mn << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
