#include <bits/stdc++.h>
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
  int N;
  cin >> N;
  // sum_{n=1}^{N} {n-delta} = n + (n-1)-1 + (n-2) + (n-3)-1 + ...
  // delta = (n % 2 == 0) ? 1 : 0
  // n * (n+1) / 2 - n / 2 = n * n / 2
  rep(i, N) {
    ll tmp = i+1;
    rep(j, N) {
      cout << tmp << ' ';
      tmp += (j % 2 == 0 ? 2*(N-i)-1 : 2*i+1);
    }
    cout << endl;
  }
  return 0;
}

