#include <iostream>
#include "pqs"
#include <vector>
#include <gtest/gtest.h>

using namespace std;
using namespace pqs;

typedef Triplet<cmplx> T;

int main(){
  vector<T> tripletList;
  tripletList.push_back(T(0,0,cmplx(0.5,0.0)));
  tripletList.push_back(T(1,0,cmplx(0.5,0.0)));
  tripletList.push_back(T(2,0,cmplx(0.5,0.0)));
  tripletList.push_back(T(3,0,cmplx(0.5,0.0)));
  tripletList.push_back(T(0,1,cmplx(0.5,0.0)));
  tripletList.push_back(T(1,1,cmplx(-0.5,0.0)));
  tripletList.push_back(T(2,1,cmplx(0.5,0.0)));
  tripletList.push_back(T(3,1,cmplx(-0.5,0.0)));
  tripletList.push_back(T(0,2,cmplx(0.5,0.0)));
  tripletList.push_back(T(1,2,cmplx(0.5,0.0)));
  tripletList.push_back(T(2,2,cmplx(-0.5,0.0)));
  tripletList.push_back(T(3,2,cmplx(-0.5,0.0)));
  tripletList.push_back(T(0,3,cmplx(0.5,0.0)));
  tripletList.push_back(T(1,3,cmplx(-0.5,0.0)));
  tripletList.push_back(T(2,3,cmplx(-0.5,0.0)));
  tripletList.push_back(T(3,3,cmplx(0.5,0.0)));
  qOperator H(4,4);
  H.setFromTriplets(tripletList.begin(), tripletList.end());
  tripletList.clear();
  tripletList.push_back(T(0,0,cmplx(1.0,0.0)));
  tripletList.push_back(T(1,1,cmplx(1.0,0.0)));
  tripletList.push_back(T(3,2,cmplx(1.0,0.0)));
  tripletList.push_back(T(2,3,cmplx(1.0,0.0)));
  qOperator CNOT(4,4);
  CNOT.setFromTriplets(tripletList.begin(), tripletList.end());

  qubit value[] = {
	qubit(sqrt(cmplx(0.5,0.0)), sqrt(cmplx(0.5,0.0))),
	qubit(sqrt(cmplx(0.3,0.0)), sqrt(cmplx(0.7,0.0))),
	qubit(sqrt(cmplx(0.3,0.0)), sqrt(cmplx(0.7,0.0))),
  };
  qSystem psi(3,value);

  int pos[] = {0,1};
  cout << CNOT << endl;

  cout << psi << endl;
  psi.calculate(CNOT, pos, 2);
  cout << psi << endl;
}
