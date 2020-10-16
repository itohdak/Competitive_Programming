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
  vector<int> N(3);
  rep(i, 3) cin >> N[i];
  if(N[0]==0 && N[1]==0) {
    rep(i, N[2]+1) cout << "1";
    cout << endl;
  } else if(N[0]==0 && N[2]==0){
    string tmp = "1";
    rep(i, N[1]+1) {
      cout << tmp;
      tmp = (tmp=="1"?"0":"1");
    }
    cout << endl;
  } else if(N[1]==0 && N[2]==0) {
    rep(i, N[0]+1) cout << "0";
    cout << endl;
  } else {
    string ans = "";
    if(N[1]%2==0) ans += "1";
    ans += "0";
    rep(i, N[0]) ans += "0";
    string tmp = "1";
    rep(i, (N[1]-1)/2*2+1) {
      ans += tmp;
      tmp = (tmp=="1"?"0":"1");
    }
    rep(i, N[2]) {
      ans += "1";
    }
    cout << ans << endl;
  }
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
