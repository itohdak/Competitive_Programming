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

void solve() {
  int N;
  cin >> N;
  vector<int> A(3);
  cin >> A[0] >> A[1] >> A[2];
  string S;
  cin >> S;
  vector<int> B(3);
  string U = "RPS";
  rep(i, N) {
    rep(j, 3) {
      if(S[i] == U[j]) B[j]++;
    }
  }
  int cnt = 0;
  rep(i, 3) cnt += min(B[i], A[(i+1)%3]);
  if(cnt < (N+1)/2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    string T(N, ' ');
    rep(i, N) {
      rep(j, 3) {
        if(S[i] == U[j] && A[(j+1)%3] > 0) {
          A[(j+1)%3]--;
          T[i] = U[(j+1)%3];
          break;
        }
      }
    }
    rep(i, N) {
      if(T[i] == ' ') {
        rep(j, 3) {
          if(A[j] > 0) {
            A[j]--;
            T[i] = U[j];
            break;
          }
        }
      }
    }
    cout << T << endl;
  }
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}

