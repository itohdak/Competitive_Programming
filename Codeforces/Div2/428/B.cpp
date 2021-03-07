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
  int n, k; cin >> n >> k;
  vector<int> A(k); rep(i, k) cin >> A[i];
  int four = n, two = 2*n;
  rep(i, k) {
    while(A[i]>=4 && four) {
      A[i] -= 4;
      four--;
    }
  }
  int one = 0;
  rep(i, k) {
    while(A[i]>=2 && two) {
      A[i] -= 2;
      two--;
    }
    while(A[i]>=2 && four) {
      A[i] -= 2;
      four--;
      one++;
    }
  }
  one += two;
  one += four*2;
  rep(i, k) {
    while(A[i] && one) {
      A[i]--;
      one--;
    }
  }
  if(accumulate(all(A), 0LL)) cout << "NO" << endk;
  else cout << "YES" << endk;
  return 0;
}
