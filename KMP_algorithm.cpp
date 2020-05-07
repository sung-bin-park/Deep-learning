#include<iostream>
#include<string>
#include<vector>
using namespace std;
//make init_next table
vector<int> next_table(string pattern) {
	int j = 0;
	int size = pattern.size();
	//initialize table for 0
	vector<int> table(size, 0);
	//making table
	for (int i = 1; i < size; i++) {
		while (pattern[i] != pattern[j] && j > 0)j = table[j - 1];
		if (pattern[i] == pattern[j])table[i] = ++j;
	}
	return table;
}
//KMP string search algorithm
void KMP(string str, string pattern) {
	vector<int> table = next_table(pattern);
	int parentsize = str.size();
	int patternsize = pattern.size();
	int j = 0;
	int sum = 0;
	//find pattern
	for (int i = 0; i < parentsize; i++) {
		while (j > 0 && str[i] != pattern[j])j = table[j - 1];
		if (str[i] == pattern[j]) 
			if(j==patternsize-1){
				cout << "find at " << i - patternsize + 2 << " string\n";
				j = table[j];
			}
			else j++;
	}
}

int main() {
	string pattern = "bc";
	string str = "abcabdcbcba";
	cout << "str : " << str << endl;
	cout << "pattern : " << pattern << endl;
	KMP(str, pattern);
	return 0;
}