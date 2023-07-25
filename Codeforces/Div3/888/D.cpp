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
  vector<ll> A(n-1); rep(i, n-1) cin >> A[i];
  set<ll> st;
  rep(i, n) st.insert(i+1);
  vector<ll> tmp;
  rep(i, n-1) {
    ll d = (i==0 ? A[i] : A[i]-A[i-1]);
    if(st.count(d)) st.erase(d);
    else tmp.push_back(d);
  }
  if(tmp.size() > 1) {
    cout << "NO" << endk;
  } else if(tmp.size() == 0) {
    ll a = *st.begin();
    if(1LL*n*(n+1)/2 - A[n-2] == a) cout << "YES" << endk;
    else cout << "NO" << endk;
  } else {
    ll t = tmp[0];
    ll a = *st.begin();
    ll b = *(++st.begin());
    if(t == a+b) cout << "YES" << endk;
    else cout << "NO" << endk;
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
