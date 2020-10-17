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

class NextOlympics {
public:
  int countDays(string today) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y = atoi(today.substr(0, 4).c_str());
    int m = atoi(today.substr(5, 2).c_str());
    int d = atoi(today.substr(8, 2).c_str());
    if(y == 2021 && m == 7) {
      return 23-d;
    } else {
      int res = 23;
      int curMonth = 6;
      while(curMonth != m) {
        res += days[curMonth-1];
        curMonth--;
        if(curMonth==0) curMonth=12;
      }
      res += days[m-1]-d;
      return res;
    }
  }
};
