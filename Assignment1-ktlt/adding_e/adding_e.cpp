// adding_e.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
string hmuhmu(string s) {
	string a, b;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '@') {
			s.erase(s.begin() + i, s.begin() + i + 1);
			if (s[i + 1] == '@' || s[i + 1] == '#') {
				continue;
			}
			else {
				for (int j = i; j < s.length(); j++) {
					if (s[j] == '#' || s[j] == '@') {
						reverse(s.begin() + i, s.begin() + j);
						break;
					}
					else {
						if (j != s.length() - 1) {
							continue;
						}
						else {
							reverse(s.begin() + i, s.begin() + s.length());
							break;
						}
					}
				}
			}
		}
		if (s[i] == '#') {
			for (int j = i + 1; j < s.length(); j++) {
				if (s[j] == '#' || s[j] == '@') {
					s.erase(s.begin() + i, s.begin() + i + 1);
					b = s[j - 2] + 1;
					s.insert(j - 1, b);
					break;
				}
				else {
					if (j != s.length() - 1) {
						continue;

					}
					else {
						s.erase(s.begin() + i, s.begin() + i + 1);
						b = s[s.length() - 1] + 1;
						s.insert(s.length(), b);
						break;
					}
				}
			}
		}
	}
	//ABCDDEFGFBAMTLDKNKFSJOGNFYEIHITSEHDJFGH
	cout << "s: " << s << endl;
	return s;
}
string s_erase(string s) {
	string a;
	for (int i = 0; i < s.length(); i++) {
		if (i % 3 != 0) {
			a += s[i];
		}
	}

	for (int i = 0; i < a.length(); i++) {
		for (int j = i + 1; j < a.length(); j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	return a;
}
int main()
{
	string s,a,b;
	getline(cin, s);
	cout << s_erase(s);d
	return 0;

}

