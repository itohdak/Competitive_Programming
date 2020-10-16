#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return (x / g) * (y / g);
}

#define MOD 1000000007
ll mod_inv(ll a, ll m=MOD) {
  ll x = 0, y = 1, gcd = m;
  ll px = 1, py = 0, pgcd = a;
  ll tmp = 0;
  while(gcd > 0) {
    ll quotient = pgcd / gcd;

    tmp = x;
    x = px - quotient * tmp;
    px = tmp;

    tmp = y;
    y = py - quotient * tmp;
    py = tmp;

    tmp = gcd;
    gcd = pgcd - quotient * tmp;
    pgcd = tmp;
  }

  if(px < 0)
    px += m;

  return px;
}

int main(){
  ll n;
  int k;
  cin >> n >> k;
  find_divisor(n);
  int n_div = divisor.size();
  vector<vector<ll> > trans(n_div, vector<ll>());
  vector<ll> trans_sum(n_div, 0);
  for(int i=0; i<n_div; i++) {
    ll t_sum = 0;
    for(int j=0; j<=i; j++) {
      if(divisor[i] % divisor[j] == 0) {
	trans[i].push_back(j);
	t_sum++;
      }
    }
    trans_sum[i] = mod_inv(t_sum);
  }

  vector<vector<ll> > dp(n_div+1, vector<ll>(k, 0LL));
  for(int j=0; j<k; j++) {
    for(int i=0; i<n_div; i++) {
      if(j == 0) {
  	dp[i][j] = 1LL * trans_sum[n_div-1];
      } else {
	for(int k=0; k<trans[i].size(); k++) {
	  int t = trans[i][k];
	  dp[t][j] = (dp[t][j] + dp[i][j-1] * trans_sum[i] % MOD) % MOD;
	}
      }
    }
  }
  ll ret = 0LL;
  for(int i=0; i<n_div; i++) {
    ret = (ret + divisor[i] * dp[i][k-1] % MOD) % MOD;
  }
  cout << ret << endl;

  // for(int i=0; i<n_div; i++) {
  //   cout << divisor[i] << ' ';
  //   for(int j=0; j<n_div; j++) {
  //     cout << trans[i][j] << ' ';
  //   }
  //   cout << trans_sum[i] << ' ';
  //   cout << endl;
  // }

  return 0;
}
