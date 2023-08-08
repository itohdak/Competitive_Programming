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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  map<ll, int> cnt;
  rep(i, n) cnt[A[i]]++;
  int q; cin >> q;
  vector<ll> X(q), Y(q);
  rep(i, q) {
    cin >> X[i] >> Y[i];
  }
  vector<ll> ans(q);
  rep(i, q) {
    ll x = X[i], y = Y[i];
    ll d = x*x-4*y;
    if(d < 0) {
      ans[i] = 0;
    } else {
      ll rt = sqrtl(d);
      if(rt*rt != d) {
	ans[i] = 0;
      } else if(abs(x)%2 != rt%2) {
	ans[i] = 0;
      } else {
	if(rt == 0) {
	  ll a = x/2;
	  if(!cnt.count(a)) ans[i] = 0;
	  else ans[i] = 1LL*cnt[a]*(cnt[a]-1)/2;
	} else {
	  ll a = (x-rt)/2, b = (x+rt)/2;
	  if(!cnt.count(a) || !cnt.count(b)) ans[i] = 0;
	  else ans[i] = 1LL*cnt[a]*cnt[b];
	}
      }
    }
  }
  rep(i, q) cout << ans[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
