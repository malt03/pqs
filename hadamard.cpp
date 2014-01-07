#include <iostream>
#include <vector>
#include "pqs"
#include "mkhadamard.h"

using namespace std;
using namespace pqs;



int main(){
  qOperator H2(64,64);
  makeHadamard(&H2, 6);
  
  cout << H2 << endl;
}
