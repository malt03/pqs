#include <iostream>
#include "pqs"
#include "matrixcalc.h"

using namespace std;
using namespace pqs;

int main(){
  int n = 1000;
  vector<T> tripletList;
  for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  tripletList.push_back(T(i,j,cmplx(1,0.0)));
	}
  }
  sMatrix H(n,n);
  H.setFromTriplets(tripletList.begin(), tripletList.end());
  sMatrix ans(n,n);

  //add(ans, H, H);
  ans = H + H;
  //cout << ans << endl;
}
