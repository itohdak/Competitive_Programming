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

class SquareCityWalking {
public:
  int largestGCD(int n, vector<int> A) {
    int ans = 1;
    for(int m=1; m<=100; m++) {
      vector<vector<bool>> able(n, vector<bool>(n));
      rep(i, n) rep(j, n) {
        if(i==0 && j==0) able[0][0] = (A[0]%m==0);
        else {
          if(i>0 && able[i-1][j]) able[i][j] = true;
          if(j>0 && able[i][j-1]) able[i][j] = true;
          if(A[i*n+j]%m!=0) able[i][j] = false;
        }
      }
      if(able[n-1][n-1]) ans = m;
    }
    return ans;
  }
};
