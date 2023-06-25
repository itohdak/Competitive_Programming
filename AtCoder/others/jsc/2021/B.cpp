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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(m); rep(i, m) cin >> B[i];
  int i = 0, j = 0;
  vector<int> ans;
  while(i < n || j < m) {
    if(i == n) {
      ans.push_back(B[j]);
      j++;
    } else if(j == m) {
      ans.push_back(A[i]);
      i++;
    } else if(A[i] == B[j]) {
      i++; j++;
    } else if(A[i] > B[j]) {
      ans.push_back(B[j]);
      j++;
    } else {
      ans.push_back(A[i]);
      i++;
    }
  }
  for(int a: ans) cout << a << ' ';
  cout << endk;
  return 0;
}
