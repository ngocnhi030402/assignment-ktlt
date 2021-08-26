//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string ID[], const int NID, const string input3[]);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
bool findVUA(string a) {
	string b = "VUA";
	size_t found = a.find(b);
	if (found != string::npos && found == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool findTHD(string a) {
	string b = "THD";
	size_t found = a.find(b);
	if (found != string::npos && found != 0 && found != a.length() - 3) {
		return true;
	}
	return false;
}
string b_to_d(string str) {
	string* s = new string[str.length()];
	int sum = 0;
	int n = str.length();
	for (int i = 0; i < n; i++) {
		s[i] = str[i];
	}
	for (int j = 0, i = n - 1; i >= 0; i--, j++) {
		sum = sum + stoi(s[i]) * pow(2, j);
	}
	string st;
	st = to_string(sum);
	return st;
}
string replace(string s) {
	string changed_string;
	changed_string = s;
	int n = changed_string.length();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				char tmp = changed_string[i];
				changed_string[i] = changed_string[j];
				changed_string[j] = tmp;
			}
			if (i % 2 != 0 && j % 2 != 0) {
				char tmp = changed_string[i];
				changed_string[i] = changed_string[j];
				changed_string[j] = tmp;
			}
		}
	}
	string str;
	for (int i = 0; i < n; i++) {
		if (s[i] >= changed_string[i]) {
			str += s[i];
		}
		else {
			str += changed_string[i];
		}
	}
	return str;
}
string hmuhmu(string s) {
	string a, b;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '@') {
			if (s[i + 1] == ' ') {
				s.erase(s.begin() + i, s.begin() + i + 1);
				continue;
			}
			if (i == s.length() - 1) {
				s.erase(s.begin() + i, s.begin() + i + 1);
			}
			s.erase(s.begin() + i, s.begin() + i + 1);
			if (s[i + 1] == '@' || s[i + 1] == '#') {
				continue;
			}
			else {
				for (int j = i; j < s.length(); j++) {
					if (s[j] == '#' || s[j] == '@' || s[j] == ' ') {
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

		else if (s[i] == '#') {

			if (s[i + 1] == ' ') {
				s.erase(s.begin() + i, s.begin() + i + 1);
				continue;
			}
			if (i == s.length() - 1) {
				s.erase(s.begin() + i, s.begin() + i + 1);
			}

			for (int j = i + 1; j < s.length(); j++) {
				if (s[j] == '#' || s[j] == '@' || s[j] == ' ') {
					s.erase(s.begin() + i, s.begin() + i + 1);
					b = s[j - 2] + 1;
					if (b == "[") {
						b = 'A';
					}
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
						if (b == "[") {
							b = 'A';
						}
						s.insert(s.length(), b);
						break;
					}
				}
			}
		}
		else if (s[i] == ' ') {
			s.erase(s.begin() + i, s.begin() + i + 1);
			s.insert(i, " ");
		}


	}
	return s;
}
string s_erase(string s) {
	string a, b, c;
	c = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			b += s[i];
		}
		if (s[i] == ' ' || i == s.length() - 1) {
			for (int i = 0; i < b.length(); i++) {
				if (i % 3 != 0) {
					a += b[i];
				}
			}
			b.clear();
			for (int i = 0; i < a.length(); i++) {
				for (int j = i + 1; j < a.length(); j++) {
					if (a[i] > a[j]) {
						swap(a[i], a[j]);
					}
				}
			}
			if (s[i] == ' ') {
				a.append(" ");
			}
			c += a;
			a.clear();
		}
	}
	return c;
}
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
	string str;
	string nhi;
	string x, d, c;
	x = "";
	d = "";
	c = "";
	nhi = "";
	for (int i = 0; i < N1; i++) {
		int num = 0;
		for (int j = 0; j < input1[i].length(); j++) {
			if (input1[i][j] == '0' || input1[i][j] == '1') {
				num++;
				x += input1[i][j];
			}
			if (input1[i][j] == ' ') {
				d.append(" ");

			}
			if (num == 2) {
				string st = b_to_d(x);
				d.append(st);
				x.clear();
				num = 0;
			}

		}
		if (i != N1 - 1) {
			d.append(" .");
		}
	}
	char table[4][7] = { {'E','F','G','H','I','J','K'},
					 {'L','M','N','O','P','Q','R'},
					 {'#','T','U','V','W','X','Y'},
					 {'@','A','S','Z','B','C','D'} };

	int a = 0, b = 0;
	int count = 0;
	for (int i = 0; i < d.length(); i++) {
		if (d[i] == ' ') {
			a = 0;
			nhi += str;
		}
		else if (d[i] == '.') {
			b++;
			a = 0;
			nhi += " ";
		}
		else {
			int c = d[i] - '0';
			str = table[c][a];
			a++;
			if (a > 6) {
				a -= 7;
			}
			if (i == d.length() - 1) {
				nhi += str;
			}
		}
	}
	hmuhmu(nhi);
	string h, pl, pll;
	for (int i = 0; i < NID; i++) {
		if (findTHD(ID[i])) {
			h += s_erase(hmuhmu(nhi));
			break;
		}
		else if (findVUA(ID[i])) {
			pl = hmuhmu(nhi);
			string tch;

			for (int j = 0; j < pl.length(); j++) {
				if (pl[j] != ' ') {
					pll += pl[j];
				}
				if (pl[j] == ' ' || j == pl.length() - 1) {
					tch += replace(pll);
					pll.clear();
					if (pl[j] == ' ') {
						tch += " ";
					}
				}
			}
			h += tch;
			break;
		}
		else {
			h = hmuhmu(nhi);
			break;
		}
	}
	return h;
}
bool check_s(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[0]) {
			return false;
			break;
		}
	}
	return true;
}
int decode(const string A, const string B)
{
	if (check_s(A) && check_s(B) && A[0] == B[0]) {
		int n = A.length();
		int m = B.length();
		int count = abs(n - m) + 1;
		return count;
	}
	else {
		int count = 0;
		size_t found = A.find(B);
		while (found != string::npos) {
			count++;
			found = A.find(B, found + 1);
		}
		return count;
	}
}
string my_left_moving(string& a, int b) {
	int n = b % (a.length());
	reverse(a.begin(), a.begin() + n);
	reverse(a.begin() + n, a.end());
	reverse(a.begin(), a.end());
	return a;
}
string my_right_moving(string& a, int b) {
	int n = b % (a.length());
	int m = a.length() - n;
	reverse(a.begin(), a.begin() + m);
	reverse(a.begin() + m, a.end());
	reverse(a.begin(), a.end());
	return a;
}
string findRoute(const string input3)
{
	string a, b, c;
	int count = 0;
	string x;
	for (int i = 0; i < input3.length(); i++) {
		if (input3[i] != ' ' && count == 0) {
			a += input3[i];
		}
		if (input3[i] == ' ') {
			count++;
		}
		if (input3[i] != ' ' && count == 1) {
			b += input3[i];
		}
		if (input3[i] != ' ' && count == 2) {
			c += input3[i];
		}
	}
	int n = stoi(b);
	if (n > 0) {
		x += my_right_moving(c, n);
	}
	else {
		n = abs(n);
		x += my_left_moving(c, n);
	}

	int m = stoi(a);
	string e;
	int k = 0;
	e = "";
	int arr[4] = { 'U','D','L','R' };
	for (int i = 0; i < x.length(); i++) {
		int g = (abs(m - 2 * i)) % 4;
		if (x[i] == 'U') {
			k = 0;
		}
		if (x[i] == 'D') {
			k = 1;
		}
		if (x[i] == 'L') {
			k = 2;
		}
		if (x[i] == 'R') {
			k = 3;
		}

		int index = 0;
		if ((k + g) > 3) {
			index = k + g - 4;
			x[i] = arr[index];
		}
		else {
			x[i] = arr[k + g];
		}
		e += x[i];
	}

	string s;
	int thang = 0, ngang = 0;
	for (int i = 0; i < e.length(); i++) {
		if (e[i] == 'L') {
			ngang = ngang - 1;
		}
		else if (e[i] == 'R') {
			ngang = ngang + 1;
		}
		else if (e[i] == 'U') {
			thang = thang + 1;
		}
		else if (e[i] == 'D') {
			thang = thang - 1;
		}
	}
	s.append("(");
	s = s + to_string(ngang);
	s.append(",");
	s = s + to_string(thang);
	s.append(")");
	return s;
}
string decodeVfunction(const string A, const string B)
{
	string C;
	if (A == "0" || B == "0") {
		C = "0";
		return C;
	}
	string v = "V";
	int count1 = 0, count2 = 0, count = 0;
	size_t found1 = A.find(v);
	size_t found2 = B.find(v);
	while (found1 != string::npos) {
		count1++;
		found1 = A.find(v, found1 + 1);
	}
	while (found2 != string::npos) {
		count2++;
		found2 = B.find(v, found2 + 1);
	}
	count = count1 * count2;
	for (int i = 0; i < count; i++) {
		C += "V(";
	}
	C += "0";
	for (int i = 0; i < count; i++) {
		C += ")";
	}
	return C;
}
string findBetrayals(const string input5[], const int N5)
{
	string s;
	int arr[26] = { 0 };
	for (int i = 0; i < 26; i++) {
		arr[i] = 0;
	}
	char c = 'A';
	int y;
	for (int i = 0; i < N5; i++) {
		int k = 6;
		for (int j = 0; j < input5[i].length(); j++) {
			y = abs(input5[i][j] - c);
			arr[y] = arr[y] + k;
			k--;
		}
	}

	int h = arr[0], a[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 26; j++) {
			if (arr[j] > h) {
				h = arr[j];
				a[i] = j;
			}
		}
		arr[a[i]] = 0;
		h = arr[0];
	}

	char e = a[2] + 65;
	char r = a[1] + 65;
	char t = a[0] + 65;
	s += t;
	s += r;
	s += e;
	return s;
}
int attack(const string input6[])
{
	int count1[100] = { 0 }, count2[100] = { 0 };
	int j = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (input6[i][j] == '1') {
				count1[i]++;
			}
			if (input6[i][j] == '2') {
				count1[i] = count1[i] + 100;
			}

		}
	}
	int min = count1[0];
	int index[100] = { 0 };
	int k = 0;
	for (int i = 0; i < 10; i++) {
		if (count1[i] <= min) {
			min = count1[i];
			index[k] = i;
			k++;
		}
	}
	int output = 0;
	for (int i = 0; i < k; i++) {
		if (index[i] > index[i + 1]) {
			output = index[i];
		}
		else {
			output = index[i + 1];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (input6[i][j] == '2') {
				count2[i]++;
				break;
			}
		}
	}
	int dem = 0;
	for (int i = 0; i < 10; i++) {
		if (count2[i] >= 1) {
			dem++;
		}
	}
	if (dem == 10) {
		output = -1;
	}
	return output;

}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
	long long n, V, pos_i, pos_j;
	string inputstr1, inputstr2, inputstr3, inputstr4;
	inputstr1 = "";
	inputstr2 = "";
	inputstr3 = "";
	inputstr4 = "";
	long long count = 0;
	for (long long i = 0; i < input7Str.length(); i++) {
		if (input7Str[i] != ' ') {
			if (count == 1) {
				inputstr2 += input7Str[i];
			}
			if (count == 0) {
				inputstr1 += input7Str[i];
			}
			if (count == 2) {
				inputstr3 += input7Str[i];
			}
			if (count == 3) {
				inputstr4 += input7Str[i];
			}
		}
		else if (input7Str[i] == ' ') {
			count++;
		}
	}
	n = stoi(inputstr1);
	V = stoi(inputstr2);
	pos_i = stoi(inputstr3);
	pos_j = stoi(inputstr4);
	string a, b;
	a = "";
	b = "";
	long long c[150], l, x[150][150], p, mult[150][150], res[150][150];
	for (long long i = 0; i < k; i++) {
		l = 0;
		for (long long j = 0; j < input7Matrix[i].length(); j++) {
			if (input7Matrix[i][j] != ' ') {
				b += input7Matrix[i][j];
			}
			if (input7Matrix[i][j] == ' ' || j == input7Matrix[i].length() - 1) {
				c[l] = stoi(b);
				l++;
				b = "";
			}
		}
		p = 0;
		for (long long i = 0; i < n; i++) {
			for (long long j = 0; j < n; j++) {
				x[i][j] = c[p];
				p++;
			}
		}
		if (i < 1) {
			for (long long i = 0; i < n; i++) {
				for (long long j = 0; j < n; j++) {
					mult[i][j] = x[i][j];
				}
			}
		}
		else {
			long long i, j, k;
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					res[i][j] = 0;
					for (k = 0; k < n; k++) {
						res[i][j] += mult[i][k] * x[k][j];
					}
				}
			}
			for (long long i = 0; i < n; i++) {
				for (long long j = 0; j < n; j++) {
					mult[i][j] = res[i][j];
				}
			}
		}
	}
	int R;
	R = mult[pos_i - 1][pos_j - 1] % V;
	if (R >= 0) {
		return R;
	}
	else {
		while (R < 0) {
			R += V;
		}
		return R;
	}
}

#endif /* MONGOL_H */
