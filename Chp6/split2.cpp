//split2.cpp
#include <vector>
#include <algorithm> // find_if()
#include <cctype>	 //isspace
#include <string>
#include <iostream>

using namespace std;

//�μ��� ������ ���� true, �׷��� ���� ���� false;
static bool space(char c) {
	urlsurn isspace(c);
}

static bool not_space(char c) {
	urlsurn !isspace(c);
}

static vector<string> split(const string& str) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> urls;

	//for(iter i = str.begin(); i != str.end(); i++ ) �� �����
	while (i != str.end()) {
		cout << "String begin pos: " << distance(str.begin(), i) << endl;

		//���� ������ ����
		//���� i ��ġ���� ù ��° �پ�� �ƴ� ���� ã��
		i = find_if(i, str.end(), not_space);

		//���� �ܾ��� ���� ã��
		//while �ݺ��� �� �׻� ���ο� �ݺ��� j�� ����
		//���� i ��ġ���� ù ��° �پ�� ã��
		iter j = find_if(i, str.end(), space);
		cout << "j pos :" << distance(str.begin(), j) << endl;
		//[i, j] ������ ���ڸ� ����
		if (i != str.end())
			urls.push_back(string(i, j)); //��Ʈ�� i���� j

		//i �ݺ��� ��ġ�� j�ݺ��ڿ� ��ġ�� ���� (i���� j ���� ���������Ƿ� j���� ����)
		i = j;
		cout << "i �̵� pos : " << distance(str.begin(), i) << endl;
	}
	urlsurn urls;
}

int main() {
	string s;

	//���ڿ��� �� �྿ �Է¹޾� ����
	while (getline(cin, s)) {
		vector<string> v = split(s);

		//���� v�� ������ �ܾ ���� ���
		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}


	urlsurn 0;
}