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

int A[100][100][100];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> X1(n), Y1(n), Z1(n), X2(n), Y2(n), Z2(n);
  rep(i, n) {
    cin >> X1[i] >> Y1[i] >> Z1[i] >> X2[i] >> Y2[i] >> Z2[i];
  }
  rep(i, 100) rep(j, 100) rep(k, 100) A[i][j][k] = -1;
  rep(l, n) {
    REP(i, X1[l], X2[l]) REP(j, Y1[l], Y2[l]) REP(k, Z1[l], Z2[l]) A[i][j][k] = l;
  }
  int dx[] = {-1, 1, 0, 0, 0, 0};
  int dy[] = {0, 0, -1, 1, 0, 0};
  int dz[] = {0, 0, 0, 0, -1, 1};
  set<pair<int, int>> st;
  rep(i, 100) rep(j, 100) rep(k, 100) {
    rep(d, 6) {
      int di = i+dx[d], dj = j+dy[d], dk = k+dz[d];
      if(di < 0 || di >= 100 || dj < 0 || dj >= 100 || dk < 0 || dk >= 100) continue;
      if(A[i][j][k] != -1 && A[di][dj][dk] != -1 && A[i][j][k] != A[di][dj][dk]) {
	int mn = min(A[i][j][k], A[di][dj][dk]);
	int mx = max(A[i][j][k], A[di][dj][dk]);
	st.insert({mn, mx});
      }
    }
  }
  vector<int> cnt(n);
  for(auto [a, b]: st) {
    cnt[a]++;
    cnt[b]++;
  }
  // cout << st << endk;
  rep(i, n) cout << cnt[i] << endk;
  return 0;
}
