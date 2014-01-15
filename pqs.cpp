#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "pqs"

using namespace std;
using namespace pqs;

typedef Triplet<cmplx> T;

int main(){
  Eigen::initParallel();
  omp_set_num_threads(1);
  Eigen::setNbThreads(1);
  cout << omp_get_max_threads() << endl;
  ofstream log("log_par.txt");
  struct timeval s, e;

  double r2 = 1.0/sqrt(2.0);
  vector<T> tripletList;
  tripletList.push_back(T(0,0,cmplx(r2,0.0)));
  tripletList.push_back(T(1,0,cmplx(r2,0.0)));
  tripletList.push_back(T(0,1,cmplx(r2,0.0)));
  tripletList.push_back(T(1,1,cmplx(-r2,0.0)));
  qOperator H(2,2);
  H.setFromTriplets(tripletList.begin(), tripletList.end());

  qubit* value;


  for(int n=10;n<=10;n++){
	gettimeofday(&s, NULL);

	value = new qubit[n];
	for(int i=0;i<n;i++){
	  value[i] = qubit(cmplx(1.0,0.0), cmplx(0.0,0.0));
	}
  
	qSystem psi(n,value);
	int pos[1];

	for(int i=0;i<n;i++){
	  pos[0] = i;
	  psi.calculate(H, pos, 1);
	}
  
	delete [] value;
	gettimeofday(&e, NULL);
	log << n << "\t" << ((e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6) << endl;
	cout << n << " : " << ((e.tv_sec - s.tv_sec) + (e.tv_usec - s.tv_usec)*1.0E-6) << endl;
  }
}
