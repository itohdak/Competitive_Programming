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
  vector<ll> X(n); rep(i, n) cin >> X[i];
  ll mn = *min_element(all(X)), mx = *max_element(all(X));
  vector<int> cnt(3);
  rep(i, n) cnt[X[i]-mn]++;
  if(mx-mn == 0 || mx-mn == 1) {
    cout << n << endk;
    rep(i, n) cout << X[i] << ' ';
    cout << endk;
  } else if(mx-mn == 2) {
    int c1 = min(cnt[0], cnt[2])*2;
    int c2 = cnt[1]/2*2;
    if(n-c1 < n-c2) {
      cout << n-c1 << endk;
      rep(i, cnt[0]-c1/2) cout << mn << ' ';
      rep(i, cnt[1]+c1) cout << mn+1 << ' ';
      rep(i, cnt[2]-c1/2) cout << mn+2 << ' ';
      cout << endk;
    } else {
      cout << n-c2 << endk;
      rep(i, cnt[0]+c2/2) cout << mn << ' ';
      rep(i, cnt[1]-c2) cout << mn+1 << ' ';
      rep(i, cnt[2]+c2/2) cout << mn+2 << ' ';
      cout << endk;
    }
  } else {
    assert(false);
  }
  return 0;
}
