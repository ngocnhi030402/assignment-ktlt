#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void find_all_subset(vector<int>& S0, vector<vector<int> >& returndata, vector<int>& S) {
	for (int i = 0; i < S0.size(); i++) {
		//try
		S.push_back(S0[i]);
		returndata.push_back(S);
		vector<int> S1(S0);
		S1.erase( S1.begin(),S1.begin()+i+1);
		find_all_subset(S1, returndata, S);
		S.erase(S.end() - 1);
	}
}
//driver/wrapper
void find_all_subset(vector<int>& S0, vector<vector<int> >& returndata) {
	vector<int> zeroSet;
	find_all_subset(S0, returndata, zeroSet);
}

void print(vector<int>& S0, vector<vector<int> >& returndata) {
	for (int& x : S0)
		cout << setw(5) << x;
	cout << '\n';
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//find_all_subset;
}