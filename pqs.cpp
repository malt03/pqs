#include <iostream>
#include <vector>
#include "pqs"

using namespace std;
using namespace pqs;

typedef Triplet<cmplx> T;

int main(){
  vector<T> tripletList;
  tripletList.push_back(T(0,0,cmplx(1.0,0.0)));
  tripletList.push_back(T(1,1,cmplx(1.0,0.0)));
  tripletList.push_back(T(3,2,cmplx(1.0,0.0)));
  tripletList.push_back(T(2,3,cmplx(1.0,0.0)));
  qOperator CNOT(4,4);
  CNOT.setFromTriplets(tripletList.begin(), tripletList.end());

  qubit value[] = {
	qubit(sqrt(cmplx(0.5,0.0)), sqrt(cmplx(0.5,0.0))),
	qubit(sqrt(cmplx(0.1,0.0)), sqrt(cmplx(0.9,0.0))),
  };
  qSystem psi(2,value);
  cout << "Before:\n" << psi << endl;
  cout << "-----------------------------------------------" << endl;

  int pos[] = {0,1};
  psi.calculate(CNOT, pos, 2);
  cout << "After:" << endl << psi << endl;
}
