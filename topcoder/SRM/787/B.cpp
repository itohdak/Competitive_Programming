#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

class AqaAsadiPlays {
public:
  int getMin(vector<int> A) {
    int n = A.size();
    sort(all(A), greater<int>());
    int GCD = A[0];
    int i = 0;
    int res = i;
    while(i < n) {
      int tmp = gcd(GCD, A[i]);
      while(i < n && tmp <= A[i]) {
        tmp = gcd(tmp, A[i]);
        i++;
      }
      if(i == n) break;
      res = i;
      GCD = tmp;
    }
    return (res==0 ? -1 : res);
  }
};
