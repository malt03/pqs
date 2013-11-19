#include <iostream>
#include "../pqs"
#include <vector>
#include <gtest/gtest.h>

using namespace std;
using namespace pqs;
typedef Triplet<cmplx> T;


TEST(CNOT, PQS){
  vector<T> tripletList;
  tripletList.push_back(T(0,0,cmplx(1.0,0.0)));
  tripletList.push_back(T(1,1,cmplx(1.0,0.0)));
  tripletList.push_back(T(3,2,cmplx(1.0,0.0)));
  tripletList.push_back(T(2,3,cmplx(1.0,0.0)));
  qOperator CNOT(4,4);
  CNOT.setFromTriplets(tripletList.begin(), tripletList.end());

  qubit value[] = {
	qubit(sqrt(cmplx(1.0/3.0,0.0)), sqrt(cmplx(2.0/3.0,0.0))),
	qubit(sqrt(cmplx(1.0/4.0,0.0)), sqrt(cmplx(3.0/4.0,0.0))),
  };
  qSystem psi(2,value);
  psi.calculate(CNOT);

  tripletList.push_back(T(0,0,cmplx(1.0/12.0,0.0)));
  tripletList.push_back(T(0,1,cmplx(1.0/4.0*sqrt(3.0),0.0)));
  tripletList.push_back(T(0,2,cmplx(1.0/2.0*sqrt(6.0),0.0)));
  tripletList.push_back(T(0,3,cmplx(1.0/6.0*sqrt(2.0),0.0)));
  tripletList.push_back(T(1,0,cmplx(1.0/4.0*sqrt(3.0),0.0)));
  tripletList.push_back(T(1,1,cmplx(1.0/4.0,0.0)));
  tripletList.push_back(T(1,2,cmplx(1.0/2.0*sqrt(2.0),0.0)));
  tripletList.push_back(T(1,3,cmplx(1.0,0.0)));
  tripletList.push_back(T(2,0,cmplx(1.0,0.0)));
  tripletList.push_back(T(2,1,cmplx(1.0,0.0)));
  tripletList.push_back(T(2,2,cmplx(1.0,0.0)));
  tripletList.push_back(T(2,3,cmplx(1.0,0.0)));
  tripletList.push_back(T(3,0,cmplx(1.0,0.0)));
  tripletList.push_back(T(3,1,cmplx(1.0,0.0)));
  tripletList.push_back(T(3,2,cmplx(1.0,0.0)));
  tripletList.push_back(T(3,3,cmplx(1.0,0.0)));
  qSystem
}
