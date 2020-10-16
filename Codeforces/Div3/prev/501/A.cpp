#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data{
  int l;
  int r;
};
bool comp(data d1, data d2){
  if(d1.l == d2.l)
    return d1.r <= d2.r;
  else
    return d1.l <= d2.l;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<data> D;
  for(int i=0; i<n; i++){
    int l, r;
    cin >> l >> r;
    data d = {l, r};
    D.push_back(d);
  }
  sort(D.begin(), D.end(), comp);
  
  int ret = 0;
  vector<int> retv;
  int tmp = 1;
  for(int i=0; i<n; i++){
    ret += max(0, D[i].l - tmp);
    for(int j=tmp; j<D[i].l; j++)
      retv.push_back(j);
    tmp = max(D[i].r + 1, tmp);
  }
  ret += max(0, m - tmp + 1);
  for(int i=tmp; i<=m; i++)
    retv.push_back(i);
  cout << ret << endl;
  if(ret != (int)retv.size())
    cout << "something wrong" << endl;
  for(int i=0; i<retv.size(); i++)
    cout << retv[i] << ' ';
  cout << endl;
  return 0;
}

