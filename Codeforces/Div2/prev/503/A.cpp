#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll n, h, a, b;
  int k;
  cin >> n >> h >> a >> b >> k;
  for(int i=0; i<k; i++){
    ll ta, fa, tb, fb, ca, cb, tfa, tfb;
    cin >> ta >> fa >> tb >> fb;
    if(a <= fa && fa <= b){
      ca = 0;
      tfa = fa;
    } else if(a > fa){
      ca = abs(fa - a);
      tfa = a;
    } else {
      ca = abs(fa - b);
      tfa = b;
    }
    if(a <= fb && fb <= b){
      cb = 0;
      tfb = fb;
    } else if(a > fb){
      cb = abs(fb - a);
      tfb = a;
    } else {
      cb = abs(fb - b);
      tfb = b;
    }
    ll ans = abs(ta - tb) + ca + cb + abs(tfa - tfb);
    cout << ans << endl;
  }
  return 0;
}

