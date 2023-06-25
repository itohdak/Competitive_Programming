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
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ld m1 = (ld)(x1+x2)/2, m2 = (ld)(y1+y2)/2;
  ld th = atan2(y2-y1, x2-x1);
  // cout << th << endk;
  vector<int> A(n), B(n);
  vector<ld> C(n), D(n);
  rep(i, n) {
    cin >> A[i] >> B[i];
    ld c = A[i]-m1;
    ld d = B[i]-m2;
    C[i] =   cos(th) * c + sin(th) * d;
    D[i] = - sin(th) * c + cos(th) * d;
  }
  cout << fixed << setprecision(10);
  rep(i, n) {
    cout << C[i] << ' ' << D[i] << endk;
  }
  return 0;
}
