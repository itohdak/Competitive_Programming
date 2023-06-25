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
  int h, w; cin >> h >> w;
  int n; cin >> n;
  vector<int> A(n), B(n);
  vector<int> H(n), W(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
    H[i] = A[i], W[i] = B[i];
  }
  sort(all(H));
  sort(all(W));
  H.erase(unique(all(H)), end(H));
  W.erase(unique(all(W)), end(W));
  rep(i, n) {
    cout << lower_bound(all(H), A[i]) - begin(H) + 1 << ' ' << lower_bound(all(W), B[i]) - begin(W) + 1 << endk;
  }
  return 0;
}
