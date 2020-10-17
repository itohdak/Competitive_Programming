#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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

class AqaAsadiGroups {
public:
  ll minimumDifference(vector<int> skills, int k) {
    int n = skills.size();
    vector<ll> sum(n+1);
    rep(i, n) sum[i+1] = sum[i] + skills[i];
    vector<vector<ll>> dp(n+1, vector<ll>(k, longinf));
    {
      dp[0][0] = 0;
      ll diff = sum[n];
      rep(j, k) {
        if(j) dp[0][j] = dp[0][j-1]+diff*diff;
      }
    }
    for(int i=1; i<=n; i++) {
      rep(j, k-1) {
        for(int from=0; from<=i; from++) {
          ll diff = sum[n]-(sum[i]-sum[from])*k;
          dp[i][j+1] = min(dp[from][j]+diff*diff, dp[i][j+1]);
        }
      }
    }
    ll mn = longinf;
    rep(from, n+1) {
      ll diff = sum[n]-(sum[n]-sum[from])*k;
      mn = min(dp[from][k-1]+diff*diff, mn);
    }
    return mn;
  }
};

int main() {
  cout << AqaAsadiGroups().minimumDifference({1, 2}, 2) << "\n";
  cout << AqaAsadiGroups().minimumDifference({1, 2}, 1) << "\n";
  cout << AqaAsadiGroups().minimumDifference({1, 2, 3, 4}, 2) << "\n";
  cout << AqaAsadiGroups().minimumDifference({1, 2}, 5) << "\n";
  return 0;
};
