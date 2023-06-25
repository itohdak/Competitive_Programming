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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(n); rep(i, n) cin >> B[i];
  sort(all(A), greater<int>());
  sort(all(B), greater<int>());
  vector<ll> sumA(n+1); rep(i, n) sumA[i+1] = sumA[i] + A[i];
  vector<ll> sumB(n+1); rep(i, n) sumB[i+1] = sumB[i] + B[i];
  auto bsearch = [&]() {
    auto test = [&](int m) {
      int need = (n+m)-(n+m)/4;
      ll a = 100 * min(need, m) + sumA[max(0, need-min(need, m))];
      ll b = sumB[min(n, need)];
      return a >= b;
    };
    int ok = 200000, ng = -1;
    while(ok-ng > 1) {
      int mid = (ok + ng) / 2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
