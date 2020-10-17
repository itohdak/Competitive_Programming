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

class AqaAsadiNames {
public:
  string getName(string Dad, string Mom, string FirstChild, string Gender) {
    vector<vector<string>> nameSeparate(3, vector<string>(2));
    vector<string> name = {Dad, Mom, FirstChild};
    rep(j, 3) {
      int i = 0;
      while(name[j][i] != ' ') i++;
      nameSeparate[j][0] = name[j].substr(0, i);
      nameSeparate[j][1] = name[j].substr(i+1);
    }
    set<char> st = {'A', 'E', 'I', 'O', 'U', 'Y'};
    string genderFirst = (st.count(FirstChild[0]) ? "Girl" : "Boy");
    if(genderFirst == Gender) {
      if(Gender == "Girl") {
        return nameSeparate[1][0] + ' ' + nameSeparate[2][1];
      } else {
        return nameSeparate[0][0] + ' ' + nameSeparate[2][1];
      }
    } else {
      if(Gender == "Girl") {
        return nameSeparate[1][1] + ' ' + nameSeparate[1][0];
      } else {
        return nameSeparate[0][1] + ' ' + nameSeparate[0][0];
      }
    }
  };
};
