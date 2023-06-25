#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

using mint = modint998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m, q; cin >> n >> m >> q;
  rep(i, q) {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    a--; c--;
    if((a+c)&1) {
      // a*m+c+2, a*m+c+4, ...,
      // (a+1)*m+c+1, (a+1)*m+c+3, ...,
      mint n1 = (d-(c+1)+1)/2;
      mint sum1 = 1LL * (a*m+c+2 + a*m+c+2+(n1-1)*2) * n1 / 2;
      mint n2 = (d-c+1)/2;
      mint sum2 = 1LL * ((a+1)*m+c+1 + (a+1)*m+c+1+(n2-1)*2) * n2 / 2;
      mint m1 = (b-a+1)/2;
      mint sum3 = (sum1 + sum1+2*m*n1*(m1-1)) * m1 / 2;
      mint m2 = (b-(a+1)+1)/2;
      mint sum4 = (sum2 + sum2+2*m*n2*(m2-1)) * m2 / 2;
      cout << (sum3 + sum4).val() << endk;
    } else {
      // a*m+c+1, a*m+c+3, ...,
      // (a+1)*m+c+2, (a+1)*m+c+4, ...,
      mint n1 = (d-c+1)/2;
      mint sum1 = 1LL * (a*m+c+1 + a*m+c+1+(n1-1)*2) * n1 / 2;
      mint n2 = (d-(c+1)+1)/2;
      mint sum2 = 1LL * ((a+1)*m+c+2 + (a+1)*m+c+2+(n2-1)*2) * n2 / 2;
      mint m1 = (b-a+1)/2;
      mint sum3 = (sum1 + sum1+2*m*n1*(m1-1)) * m1 / 2;
      mint m2 = (b-(a+1)+1)/2;
      mint sum4 = (sum2 + sum2+2*m*n2*(m2-1)) * m2 / 2;
      cout << (sum3 + sum4).val() << endk;
    }
  }
  return 0;
}
