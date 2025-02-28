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
  int n; cin >> n;
  vector<int> A(n+1); rep(i, n) cin >> A[i+1];
  vector<int> ans(n+1);
  vector<int> B;
  for(int i=n; i>=1; i--) {
    int sum = 0;
    for(int j=i; j<=n; j+=i) {
      sum += ans[j];
    }
    if(sum%2 != A[i]) {
      ans[i] = 1;
      B.push_back(i);
    }
  }
  sort(all(B));
  cout << B.size() << endk;
  if(B.size()) for(int b: B) cout << b << ' '; cout << endk;
  return 0;
}
