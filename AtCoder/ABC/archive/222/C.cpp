#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<string> S(2*n);
  vector<vector<int>> B(2*n, vector<int>(m));
  rep(i, 2*n) {
    cin >> S[i];
    rep(j, m) {
      if(S[i][j] == 'G') B[i][j] = 0;
      if(S[i][j] == 'P') B[i][j] = 1;
      if(S[i][j] == 'C') B[i][j] = 2;
    }
  }
  vector<pair<int, int>> A(2*n);
  rep(i, 2*n) A[i] = {0, i};
  rep(j, m) {
    vector<pair<int, int>> next;
    rep(i, n) {
      auto [w1, i1] = A[2*i];
      auto [w2, i2] = A[2*i+1];
      if((B[i1][j]+1)%3 == B[i2][j]) w2++;
      if((B[i2][j]+1)%3 == B[i1][j]) w1++;
      next.push_back({w1, i1});
      next.push_back({w2, i2});
    }
    A = next;
    sort(all(A), [&](pair<int, int> p1, pair<int, int> p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      else return p1.first > p2.first;
    });
  }
  rep(i, 2*n) cout << A[i].second+1 << endk;
  return 0;
}
