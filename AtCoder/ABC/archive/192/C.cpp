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
  ll n; int k; cin >> n >> k;
  ll ans = n;
  vector<int> N;
  while(n) {
    N.push_back(n%10);
    n /= 10;
  }
  rep(i, k) {
    sort(all(N));
    ll ne = 0;
    ll pw = 1;
    rep(j, N.size()) {
      ne += (N[j]-N[N.size()-1-j]) * pw;
      pw *= 10;
    }
    ans = ne;
    vector<int> nextN;
    while(ne) {
      nextN.push_back(ne%10);
      ne /= 10;
    }
    N = nextN;
  }
  cout << ans << endk;
  return 0;
}
