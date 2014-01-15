#include <Eigen/SparseCore>

namespace pqs{
  void add(sMatrix& ans, sMatrix& a, sMatrix& b){
	if(ans.rows() == a.rows() && ans.cols() == a.cols() && a.rows() == b.rows() && a.cols() == b.cols()){
	  int i, j;
#pragma omp parallel for private(j)
	  for(i=0;i<ans.cols();i++){
		for(j=0;j<ans.rows();j++){
		  if(a.coeff(j,i)!=cmplx(0) || b.coeff(j,i)!=cmplx(0))
			ans.coeffRef(j,i) = a.coeff(j,i) + b.coeff(j,i);
		}
	  }
	}
  }

  void multi(sMatrix& ans, sMatrix& a, sMatrix& b){
	if(ans.cols() == b.cols() && ans.rows() == a.rows() && a.cols() == b.rows()){
	  int i, j, k;
#pragma omp parallel for private(j)
	  for(i=0;i<ans.cols();i++){
		for(j=0;j<ans.rows();j++){
		  cmplx answer = cmplx(0);
		  for(k=0;k<a.cols();k++) answer += a.coeff(j,k) * b.coeff(k,i);
		  if(answer != cmplx(0))  ans.coeffRef(j,i) = answer;
		}
	  }
	}
  }
}
