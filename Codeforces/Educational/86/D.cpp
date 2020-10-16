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

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> M(N), C(K);
  rep(i, N) {
    cin >> M[i];
    M[i]--;
  }
  sort(all(M), greater<int>());
  rep(i, K) cin >> C[i];
  vector<int> cnt(K);
  rep(i, N) cnt[M[i]]++;
  rrep(i, K) if(i!=K-1) cnt[i] += cnt[i+1];
  int mx = 0;
  rep(i, K) mx = max((cnt[i]+C[i]-1)/C[i], mx);
  vector<vector<int>> ans(mx);
  rep(i, N) ans[i%mx].push_back(M[i]);
  cout << mx << endl;
  rep(i, mx) {
    cout << ans[i].size() << ' ';
    for(int j: ans[i]) cout << j+1 << ' ';
    cout << endl;
  }
  return 0;
}
