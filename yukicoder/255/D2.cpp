#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<vector<ll>> matmul(vector<vector<ll>>& A,
                           vector<vector<ll>>& B) {
  int n = A.size();
  int m = B.size();
  int l = B[0].size();
  vector<vector<ll>> ret(n, vector<ll>(l));
  rep(i, n) rep(k, l) rep(j, m) ret[i][k] += A[i][j] * B[j][k];
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  vector<vector<ll>> A(3, vector<ll>(1));
  cin >> n >> A[0][0] >> A[1][0] >> A[2][0];
  n--;
  vector<vector<ll>> M = {{ 1, -1,  0},
                          { 0,  1, -1},
                          {-1,  0,  1}};
  vector<vector<vector<ll>>> MM(60, vector<vector<ll>>(3, vector<ll>(3)));
  copy(all(M), begin(MM[0]));
  for(int i=1; i<60; i++) {
    MM[i] = matmul(MM[i-1], MM[i-1]);
    rep(j, 3) rep(k, 3) (MM[i][j][k] += mod) %= mod;
  }
  vector<vector<ll>> K = {{1, 0, 0},
                          {0, 1, 0},
                          {0, 0, 1}};
  rep(i, 60) if(n>>i&1) {
    K = matmul(K, MM[i]);
    rep(j, 3) rep(k, 3) (K[j][k] += mod) %= mod;
  }
  A = matmul(K, A);
  rep(i, 3) {
    cout << (A[i][0]+mod)%mod << ' ';
  }
  cout << "\n";
  return 0;
}
