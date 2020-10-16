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
  if(N <= 3) cout << -1 << endl;
  else if(N == 4) cout << "2 4 1 3" << endl;
  else {
    int tmp = 1;
    while(tmp <= N) {
      cout << tmp << ' ';
      tmp += 2;
    }
    tmp -= 2;
    if(N%2) {
      tmp -= 3;
      cout << tmp << ' ';
      tmp += 2;
      cout << tmp << ' ';
      tmp -= 4;
    } else {
      tmp -= 3;
      cout << tmp << ' ';
      tmp += 4;
      cout << tmp << ' ';
      tmp -= 2;
      cout << tmp << ' ';
      tmp -= 4;
    }
    while(tmp >= 2) {
      cout << tmp << ' ';
      tmp -= 2;
    }
    cout << endl;
  }
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
