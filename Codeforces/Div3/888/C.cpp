#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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

void solve() {
  int n, k; cin >> n >> k;
  vector<int> C(n); rep(i, n) cin >> C[i];
  vector<int> A;
  rep(i, n) if(C[i] == C[0]) A.push_back(i);
  vector<int> B;
  rrep(i, n) if(C[i] == C[n-1]) B.push_back(i);
  if(C[0] == C[n-1]) {
    if(A.size() >= k) {
      cout << "YES" << endk;
    } else {
      cout << "NO" << endk;
    }
  } else {
    if(A.size() < k || B.size() < k) {
      cout << "NO" << endk;
    } else if(A[k-1] < B[k-1]) {
      cout << "YES" << endk;
    } else {
      cout << "NO" << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
