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

#define MAX_N 200
void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<vector<int> > pos(MAX_N);
  vector<vector<int> > cnt(N+1, vector<int>(MAX_N));
  rep(i, MAX_N) pos[i].push_back(0);
  rep(i, N) {
    cin >> A[i];
    A[i]--;
    pos[A[i]].push_back(i+1);
    rep(j, MAX_N) cnt[i+1][j] = cnt[i][j] + (A[i]==j);
  }
  rep(i, MAX_N) pos[i].push_back(N+1);

  int mx = 0;
  rep(a, MAX_N) {
    int n = pos[a].size();
    rep(k, n/2) {
      rep(b, MAX_N) {
	int al = pos[a][k];
	int ar = pos[a][n-1-k];
	int len = k*2+(cnt[ar-1][b]-cnt[al][b]);
	mx = max(len, mx);
      }
    }
  }
  cout << mx << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
