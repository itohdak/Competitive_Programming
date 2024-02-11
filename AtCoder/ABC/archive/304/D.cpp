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
  int w, h; cin >> w >> h;
  int n; cin >> n;
  vector<int> P(n), Q(n);
  rep(i, n) {
    cin >> P[i] >> Q[i];
  }
  int a; cin >> a;
  vector<int> A(a+2); rep(i, a) cin >> A[i+1];
  A[a+1] = w;
  int b; cin >> b;
  vector<int> B(b+2); rep(i, b) cin >> B[i+1];
  B[b+1] = h;
  map<ll, int> cnt;
  rep(i, n) {
    int pa = lower_bound(all(A), P[i]) - begin(A);
    int pb = lower_bound(all(B), Q[i]) - begin(B);
    // cout << A << B << endk;
    // cout << P[i] << ' ' << Q[i] << endk;
    // cout << pa << ' ' << pb << endk;
    ll id = 1LL*pa*(b+1)+pb;
    // cout << id << endk;
    cnt[id]++;
  }
  int mx = 0, mn = inf;
  for(auto [_, v]: cnt) {
    chmax(mx, v);
    chmin(mn, v);
  }
  if(cnt.size() < 1LL*(a+1)*(b+1)) chmin(mn, 0);
  cout << mn << ' ' << mx << endk;
  return 0;
}
