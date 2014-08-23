/**************************************************************
*
*	@subSequence.cpp
*		'Find power set of characters in a string'
*
*	@date 08/15/2014 
*
*	@author Swapna Iyer
**************************************************************/


#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

#define cps CLOCKS_PER_SEC*1000
/**************************************************************
*
*	    !!! PRINTS BRUTE FORCE's OUTPUT TO CONSOLE !!!
*
*	Brute Force algorithm: Find all nCm combinations
*	for n => length of input string, S
*	    m => varies from 0 to n 
*     
*	Time complexity: O(n* 2^n)
* Space complexity: O(1)
*
**************************************************************/

void findSeqBFprint(const string& S) {

	int len = S.size();
	int base = 0;
	string subSeq;
	int numOfVariants = pow(2,len);

	ofstream of;
	cout << "\nSEQ: " << S << endl;
	cout << "len: " << len  << " numOfVariants: " << numOfVariants << endl;
	for(int variant = 0; variant < numOfVariants; ++variant) {

		//int mask 
		int mask = 1;
		int pos =0;
		while(mask <= pow(2,len)) {
			if((variant & mask) != 0) {
				subSeq += S[pos];
			}
			pos += 1;
			mask = mask << 1;
		}
		cout << "variant: " << variant << " : " << subSeq << endl;
		subSeq.clear();
	}
}



/****
*
*	Brute Force algorithm: Find all nCm combinations
*	for n => length of input string, S
*	    m => varies from 0 to n 
*     
*	Time complexity: O(n* 2^n)
*	Space complexity: O(1)
*
*****/

void findSeqBF(const string& S) {

	int len = S.size();
	int base = 0;
	string subSeq;
	int numOfVariants = pow(2,len);

  // FILEI/O_
	ofstream of;
	of.open("BF.txt", ios::trunc| ios::out);
	cout << "\n N: " << len << " Parent Seq: "<< S << endl;
	of << "\n N: " << len << " Parent Seq: "<< S << endl;
	time_t start = clock();
  // FILEI/O_

	for(int variant = 0; variant < numOfVariants; ++variant) {

		//int mask 
		int mask = 1;
		int pos =0;
		while(mask <= pow(2,len)) {
			if((variant & mask) != 0) {
				subSeq += S[pos];
			}
			pos += 1;
			mask = mask << 1;
		}
		of << "variant: " << variant << " : " << subSeq << endl;
		subSeq.clear();

	}
  // FILEI/O_
	of << " RUN TIME: ";
	of << static_cast<float>(clock() - start)/cps << " ms" << endl;
	cout << " RUN TIME: ";
	cout << static_cast<float>(clock() - start)/cps << " ms" << endl;
	of.close();
  // FILEI/O_
}



/**************************************************************
*
*	Dynamic algorithm: Find all nCm combinations
*	for n => length of input string, S
*	    m => varies from 0 to n 
*    
*		  binomial coefficient => bc
*			n/2 => k
*		  Using	upper bound of bc => 4^(k)/sqrt(pi*k) 	
*			Max value of bc => bcMax => (2^n)*0.798/sqrt(n)
*
*	Time complexity: O(n*bcMax)
*	Space complexity: O(bcMax)
*
********************************************************************/

struct SeqIdx {
  int idx;
  string seq;

        SeqIdx(int i, string s):idx(i) { seq = s;}
};
typedef vector<vector<SeqIdx> > SeqSet;

void findSeqDynamic(const string& S) {

	int len = S.size();
	SeqSet Sq(2); //only need previous seq to make next set 
	int i = 0;
	int iter = 1;
	int prev = 0; //0 th row
	int cur = 1;   //1 st row
	Sq[prev].push_back(SeqIdx(-1, ""));

  // FILEI/O_
	ofstream of;
	of.open("DY.txt", ios::trunc| ios::out);
	cout << "\n N: " << len << " Parent Seq: "<< S << endl;
	of << "\n N: " << len << " Parent Seq: "<< S << endl;
	time_t start = clock();
	of << "\niter: " << iter++ << " seq: " << Sq[prev][0].seq << endl;
  // FILEI/O_

	while( i < len) {

		for(int j = 0; j < Sq[prev].size(); ++j) {
			for(int m = 0; m < len; ++m) {

				// new subSeq is old subSeq appened by all 
				// all choices of left over elements in S
			
				if(Sq[prev][j].idx < m) {
					Sq[cur].push_back(SeqIdx(m, Sq[prev][j].seq + S[m]));	
					int sz = Sq[cur].size();
					of << "iter: " << iter++ << " seq: " << Sq[cur][sz-1].seq << endl;
				}
			}	
		}
		//prev ^= 1 << 0;
		//cur ^= 1 << 0;
		prev ^= 1;
		cur ^= 1;
		Sq[cur].clear();
		i++;
		//cout << i << endl;
	}
  // FILEI/O_
	of << " RUN TIME: ";
	of << static_cast<float>(clock() - start)/cps << " ms" << endl;
	cout << " RUN TIME: ";
	cout << static_cast<float>(clock() - start)/cps << " ms" << endl;
	of.close();
  // FILEI/O_
}



void runPrint() {

  cout << "\nTest 1. Brute Force Method \n" << endl;
	findSeqBFprint("a");
	findSeqBFprint("ab");
	findSeqBFprint("abc");
	findSeqBFprint("abcd");
	findSeqBFprint("xx");
	findSeqBFprint("xyx");
}

void runBF() {

	cout << "\nTest 2. Brute Force Method " << endl;
	cout << "Result in file: BF.txt" << endl;

	findSeqBF("abdwde"); //N => 6
	findSeqBF("abcdefg"); //N => 7 
	findSeqBF("abcdefgi"); //N => 8 
	findSeqBF("123456789"); //N => 9 
	findSeqBF("0123456789"); //N => 10
	findSeqBF("abcdefghijklmnopqrst"); //N => 20
	findSeqBF("12abcdefghijklmnopqrst"); //N => 22
	findSeqBF("1234abcdefghijklmnopqrst"); //N => 24

}

void runDynamic() {

	cout << "\nTest 3. Dynamic Method " << endl;
	cout << "Result in file: DY.txt" << endl;

	findSeqDynamic("abdwde"); //N => 6
	findSeqDynamic("abcdefg"); //N => 7 
	findSeqDynamic("abcdefgi"); //N => 8 
	findSeqDynamic("123456789"); //N => 9 
	findSeqDynamic("0123456789"); //N => 10
	findSeqDynamic("abcdefghijklmnopqrst"); //N => 20
	findSeqDynamic("12abcdefghijklmnopqrst"); //N => 22
	findSeqDynamic("1234abcdefghijklmnopqrst"); //N => 24

}

void runDY26(string& seq) {

	cout << "\nTest 5. Dynamic Method " << endl;
	cout << "Result in file: DY.txt" << endl;

	if(seq.size() == 0) { seq = "123456abcdefghijklmnopqrst"; }

	findSeqDynamic(seq); //N => 26
	//findSeqDynamic("1234abcdefghijklmnopqrstuvwxyz"); // N => 30
}

void runBF26(string& seq) {

	cout << "\nTest 5. Brute Force " << endl;
	cout << "Result in file: BF.txt" << endl;

	if(seq.size() == 0) { seq = "123456abcdefghijklmnopqrst"; }

	findSeqBF(seq); //N => 26
}


void runAll() {

  cout << "Run all... \n" << endl;
	runPrint();
	runBF();
	runDynamic();

}



int main(int argc, char* argv[]) {

	if(argc < 2) {

		cerr << "Usage: " << argv[0];
		cout << " [print | BF | DY | all | BF26 <sequence> | DY26 <sequence> ]\n\n";
		cout << " [ print: canned test: Brute Force- print to console]" << endl;
		cout << " [ BF: canned test: Brute Force- save to file]" << endl;
		cout << " [ DY: canned test: Dynamic- save to file]" << endl;
		cout << " [ all:  run 1, 2, 3]" << endl;
		cout << " [ DY26: Dynamic on user provided sequence ]" << endl;
		cout << " [ BF26: Brute Force on user provided sequence ]\n" << endl;
		return 1;
	}

	string seq = "";	
	if(argc > 2) {
	cout << argc << endl;
		seq = argv[2];
	}

	if(argv[1] == string("print"))
		runPrint();
	else if(argv[1] == string("BF")) {
		runBF();
	}
	else if(argv[1] == string("DY")) {
		runDynamic();
	}
	else if(argv[1] == string("all")) {
		runAll();
	}
	else if(argv[1] == string("BF26")) {
		runBF26(seq);
	}
	else if(argv[1] == string("DY26")) {
		runDY26(seq);
	}
	else {
		cerr << "Invalid Choice.." << endl;
		cout << " [print | BF | DY | all | BF26 <sequence> | DY26 <sequence> ]\n" << endl;
	}
	return 0;

}
