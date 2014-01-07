namespace pqs{
  /************int同士の冪乗************
返り値	- a^b
  ************************************/
  int powi(int a, int b){
	int answer=1;
	for(int i=0 ; i<b ; i++) answer *= a;
	return answer;
  }

  /*********Hadamardゲート生成*********
			answer		- 答えを入れる
			qubit_num	- ゲートをかけるqubitの数
			返り値		- 何となくanswerのポインタ
  ************************************/
  qOperator* makeHadamard(qOperator* answer, int qubit_num){
	//とりあえずhadamard_1を作る
	double s1_2 = sqrt(0.5);
	vector<T> tripletList;
	tripletList.push_back(T(0,0,cmplx(s1_2,0.0)));
	tripletList.push_back(T(0,1,cmplx(s1_2,0.0)));
	tripletList.push_back(T(1,0,cmplx(s1_2,0.0)));
	tripletList.push_back(T(1,1,cmplx(-s1_2,0.0)));
	qOperator hadamard_1(2,2);
	hadamard_1.setFromTriplets(tripletList.begin(), tripletList.end());
	//ここまで

	//生成
	answer->insert(0,0) = 1;
	for(int i=0;i<qubit_num;i++)	tensor(answer, hadamard_1, 2, *answer, powi(2,i));

	return answer;
  }
}
