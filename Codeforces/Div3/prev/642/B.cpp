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
  int N, K;
  cin >> N >> K;
  priority_queue<int> A, B;
  rep(i, N) {
    int a;
    cin >> a;
    A.push(a);
  }
  rep(i, N) {
    int b;
    cin >> b;
    B.push(b);
  }
  int ans = 0;
  rep(i, N) {
    if(A.top() >= B.top() || K == 0) {
      ans += A.top();
      A.pop();
    } else {
      ans += B.top();
      B.pop();
      K--;
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
