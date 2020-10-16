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
  vector<int> A(N);
  vector<ll> B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  vector<vector<int> > cnt(N+1, vector<int>(3));
  int a[] = {-1, 0, 1};
  rep(i, N) {
    rep(j, 3) {
      cnt[i+1][j] = cnt[i][j];
      if(A[i] == a[j]) cnt[i+1][j]++;
    }
  }
  bool ok = true;
  rep(i, N) {
    if((B[i]-A[i]>0 && cnt[i][2]==0) ||
       (A[i]-B[i]>0 && cnt[i][0]==0)) {
      ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
