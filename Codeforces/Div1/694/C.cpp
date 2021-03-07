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
  int n; ll k; cin >> n >> k;
  // vector<ll> A(n, k);
  // cout << A << endk;
  // rep(i, 100) {
  //   vector<ll> next(n);
  //   rep(j, n) {
  //     next[j] = ((j+1)%n==0 ? 0 : A[(j+1)%n]/2) + ((j+n-1)%n==0 ? A[(j+n-1)%n] : (A[(j+n-1)%n]+1)/2);
  //   }
  //   A = next;
  //   cout << A << endk;
  // }
  auto test = [&](int mid) {
    vector<ll> ret(3);
    cout << "? " << mid+1 << endl;
    cin >> ret[1];
    cout << "? " << (mid+n-1)%n+1 << endl;
    cin >> ret[0];
    cout << "? " << (mid+1)%n+1 << endl;
    cin >> ret[2];
    return ret[0] < ret[1] && ret[1] < ret[2];
  };
  auto bsearch = [&]() {
    int ok = n, ng = -1;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = n;
    }
  };
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
