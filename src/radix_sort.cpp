#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
	ofstream output("out.txt");

	for (int i = 0; i<velikost; i++)
		output << polje[i] << ' ';
}

void binary_radix_sort(vector<int>& A){
    const int bits = 8;
    vector<int> B(A.size());

    for(int k= 0; k < bits; k++){
        int C[2] = {0};

        for(int i = 0; i < A.size(); i++){
            C[(A[i] >> k)& 1]++;
        }

        C[1] += C[0];

        for(int i = A.size()-1; i >= 0; i--){
            B[--C[(A[i] >> k) & 1]] = A[i];
        }

        swap(A,B);
    }
}

int main(int argc, const char* argv[]) {
	vector<int> A;

	if (argc < 3) return 0;
	if (!Branje_Stevil(A, argv[2])) return 0;

	if (argv[1][0] == '0') {

        binary_radix_sort(A);

	}
	
	Izpis_Stevil(&A[0],A.size());

	return 0;
}