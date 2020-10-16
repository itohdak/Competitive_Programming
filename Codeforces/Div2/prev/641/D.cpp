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
  ll K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  rep(i, N) {
    cin >> A[i];
    if(A[i] > K)       B[i] = 2;
    else if(A[i] == K) B[i] = 1;
    else               B[i] = 0;
  }
  if(N == 1) {
    cout << (B[0] == 1 ? "yes" : "no") << endl;
    return;
  }
  bool ok1 = false, ok2 = false;
  rep(i, N) {
    if(B[i] == 1) ok1 = true;
    for(int j=i+1; j<=i+2; j++) {
      if(j < N && B[i] > 0 && B[j] > 0) ok2 = true;
    }
  }
  cout << (ok1 && ok2 ? "yes" : "no") << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

