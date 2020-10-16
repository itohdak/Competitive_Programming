#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <map>

using namespace std;
#define ll long long

void printInOrder(map<char, int> alpha,
		  vector<char> cAlpha,
		  vector<int> order) {
  for(int i=0; i<order.size(); i++) {
    for(int j=0; j<alpha[cAlpha[order[i]]]; j++)
      cout << cAlpha[order[i]];
  }
  cout << endl;
}

void solve() {
  string S;
  cin >> S;
  int n = S.size();
  map<char, int> alpha;
  for(int i=0; i<n; i++) {
    if(alpha.find(S[i]) == alpha.end())
      alpha[S[i]] = 1;
    else
      alpha[S[i]]++;
  }
  int nAlpha = alpha.size();
  vector<char> cAlpha;
  vector<int> order;
  for(map<char, int>::iterator it=alpha.begin(); it!=alpha.end(); it++) {
    cAlpha.push_back(it->first);
  }
  if(nAlpha >= 6) {
    if(nAlpha % 2 == 1)
      order.push_back(nAlpha-1);
    for(int i=0; i<nAlpha/2; i++) {
      order.push_back(i);
      order.push_back(i+nAlpha/2);
    }
    printInOrder(alpha, cAlpha, order);
  } else if(nAlpha == 1) {
    order.push_back(0);
    printInOrder(alpha, cAlpha, order);
  } else if(nAlpha == 2) {
    if(cAlpha[0]+1 == cAlpha[1])
      cout << "No answer" << endl;
    else {
      order.push_back(0);
      order.push_back(1);
      printInOrder(alpha, cAlpha, order);
    }
  } else if(nAlpha == 3) {
    if(cAlpha[0]+1 == cAlpha[1] && cAlpha[1]+1 == cAlpha[2])
      cout << "No answer" << endl;
    else if(cAlpha[0]+1 == cAlpha[1]) {
      int odr[] = {0, 2, 1};
      for(int i=0; i<nAlpha; i++)
	order.push_back(odr[i]);
      printInOrder(alpha, cAlpha, order);
    } else {
      int odr[] = {2, 0, 1};
      for(int i=0; i<nAlpha; i++)
	order.push_back(odr[i]);
      printInOrder(alpha, cAlpha, order);
    }
  } else if(nAlpha == 4) {
    int odr[] = {2, 0, 3, 1};
    for(int i=0; i<nAlpha; i++)
      order.push_back(odr[i]);
    printInOrder(alpha, cAlpha, order);
  } else if(nAlpha == 5) {
    int odr[] = {0, 3, 1, 4, 2};
    for(int i=0; i<nAlpha; i++)
      order.push_back(odr[i]);
    printInOrder(alpha, cAlpha, order);
  }
}

int main(){
  int T;
  cin >> T;
  for(int t=0; t<T; t++) {
    solve();
  }
  return 0;
}

