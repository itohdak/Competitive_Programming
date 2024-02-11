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
  int n, m; cin >> n >> m;
  vector<int> A(n); rep(i, n) cin >> A[i];
  ll cum = accumulate(all(A), 0LL);
  map<int, ll> mp;
  rep(i, n) {
    mp[A[i]%m] += A[i];
    mp[A[i]%m+m] += A[i];
  }
  // cout << mp << endk;
  auto itr = mp.begin();
  map<int, ll> mp2;
  ll mx = 0;
  while(itr != mp.end()) {
    int s = itr->first;
    int tmp = -1;
    ll cum2 = 0;
    while(itr != mp.end() && (tmp == -1 || itr->first == tmp+1)) {
      // cout << *itr << endk;
      cum2 += itr->second;
      tmp = itr->first;
      itr++;
    }
    mp2[s] = cum2;
    chmax(mx, cum2);
    if(s >= m) break;
  }
  // cout << mp2 << endk;
  cout << max(0LL, cum-mx) << endk;
  return 0;
}
