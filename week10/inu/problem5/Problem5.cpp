#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string cells[50][50];
int parent[50][50];

vector<string> split(string str) {
	istringstream iss(str);
	string buffer;
	vector<string> result;

	while (getline(iss, buffer, ' ')) {
		result.push_back(buffer);
	}

	return result;
}

int toNumber(int r, int c) {
	return r * 50 + (c + 1);
}

vector<int> toCell(int num) {
	vector<int> cell(2);
	int r = num / 50;
	int c = num % 50 - 1;

	if (c == -1) {
		r--;
		c = 49;
	}

	cell[0] = r;
	cell[1] = c;

	return cell;
}

void updateCell(int r, int c, string value) {
	int num = parent[r][c];
	vector<int> cell = toCell(num);
	r = cell[0];
	c = cell[1];
	cells[r][c] = value;
}

void updateValue(string value1, string value2) {
	for(int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++) {
			string& val = cells[i][j];
			if (!val.compare(value1))
				val = value2;
		}
}

void merge(int r1, int c1, int r2, int c2) {
	int num1 = parent[r1][c1];
	int num2 = parent[r2][c2];
	vector<int> cell = toCell(num1);
	string value = cells[cell[0]][cell[1]];

	if (!value.compare("EMPTY"))
		value = cells[r2][c2];

	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			if (num2 == parent[i][j]) {
				parent[i][j] = num1;
				cells[i][j] = "EMPTY";
			}

	cells[r1][c1] = value;
}

void unmerge(int r, int c) {
	int num = parent[r][c];
	vector<int> cell = toCell(num);
	string value = cells[cell[0]][cell[1]];

	for(int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++) {
			if (num == parent[i][j]) {
				parent[i][j] = toNumber(i, j);
				cells[i][j] = "EMPTY";
			}
		}

	cells[r][c] = value;
}

vector<string> solution(vector<string> commands) {
	vector<string> answer;

	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++) {
			parent[i][j] = toNumber(i, j);
			cells[i][j] = "EMPTY";
		}		

	for (string command : commands) {
		vector<string> result = split(command);
		string word = result[0];
		
		if (!word.compare("UPDATE")) {
			int len = (int)result.size();

			if (len == 4) {
				int r = stoi(result[1]);
				int c = stoi(result[2]);
				string value = result[3];
				updateCell(r - 1, c - 1, value);
			}
			else {
				string value1 = result[1];
				string value2 = result[2];
				updateValue(value1, value2);
			}
		}
		else if (!word.compare("MERGE")) {
			int r1 = stoi(result[1]);
			int c1 = stoi(result[2]);
			int r2 = stoi(result[3]);
			int c2 = stoi(result[4]);
			merge(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
		}
		else if (!word.compare("UNMERGE")) {
			int r = result[1][0] - '0';
			int c = result[2][0] - '0';
			unmerge(r - 1, c - 1);
		}
		else if (!word.compare("PRINT")) {
			int r = stoi(result[1]);
			int c = stoi(result[2]);
			int num = parent[r - 1][c - 1];
			vector<int> cell = toCell(num);
			answer.push_back(cells[cell[0]][cell[1]]);
		}
	}

	return answer;
}

int main() {
	vector<string> commands = {
		"UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1"
	};

	vector<string> answer = solution(commands);

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++)
			cout << toNumber(i, j) << ' ';
		cout << '\n';
	}
		
	for (int i = 1; i <= 2500; i++) {
		vector<int> cell = toCell(i);
		cout << cell[0] << ' ' << cell[1] << '\n';
	}
}
//"UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"
//"UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1"