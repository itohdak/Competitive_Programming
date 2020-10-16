#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int Q;
  cin >> Q;
  rep(q, Q) {
    ll N;
    cin >> N;
    int MAX_N = 100;
    vector<int> A(MAX_N);
    rep(i, MAX_N) {
      A[i] = N % 3;
      N /= 3;
    }
    // rep(i, MAX_N) {
    //   cout << A[MAX_N-1-i] << ' ';
    // }
    // cout << endl;
    int p = -1;
    for(int i=MAX_N-1; i>=0; i--) {
      if(A[i] == 2) {
        p = i;
        break;
      }
    }
    if(p != -1) {
      int q = MAX_N;
      for(int i=p; i<MAX_N; i++) {
        if(A[i] == 1 || A[i] == 2)
          A[i] = 0;
        else {
          A[i] = 1;
          q = i;
          break;
        }
      }
      for(int i=q-1; i>=0; i--) {
        A[i] = 0;
      }
    }
    ll ans = 0;
    ll tmp = 1;
    rep(i, MAX_N) {
      ans += tmp * A[i];
      tmp *= 3;
    }
    cout << ans << endl;
  }
  return 0;
}

