#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <iomanip>

using namespace std;
#define ll long long

double intersection(const ll x1, const ll y1, const ll x2, const ll y2, const ll s){
  ll X = x2 - x1, Y = y2 - y1;
  return (double)X / Y * (s - y1) + x1;
}

int main(){
  ll s, a, b;
  int n;
  cin >> s >> a >> b >> n;
  vector<ll> L(n), R(n);
  for(int i=0; i<n; i++)
    cin >> L[i] >> R[i];

  int q;
  cin >> q;
  for(int i=0; i<q; i++){
    ll x, y;
    cin >> x >> y;
    double last_r = (double)a;
    double ans = 0.0;

    int begin, end;
    int low = 0, high = n-1;
    while(low < high){
      int mid = 0;
      if(intersection(x, y, R[mid], 0, s) > a)
	high = mid;
      else
	low = mid + 1;
    }
    begin = low;
    low = 0, high = n-1;
    while(low < high){
      int mid = 0;
      if(intersection(x, y, L[mid], 0, s) < b)
	low = mid + 1;
      else
	high = mid;
    }
    end = high;
    for(int j=begin; j<=end; j++){
      double l = intersection(x, y, L[j], 0, s);
      double r = intersection(x, y, R[j], 0, s);
      if(r > last_r){
	ans += max(0.0, min(r, (double)b) - max(last_r, l));
	last_r = r;
	if(last_r > b)
	  break;
      } else {
	continue;
      }
    }
    cout << fixed << setprecision(15) << ans << endl;
  }
  return 0;
}

