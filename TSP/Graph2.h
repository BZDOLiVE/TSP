#pragma once
#include<iostream>
#define N 6
#define INF 99999999

using namespace std;

class Decision {
public:
	int weight = 0;//��ǰ���ߵ�·������
	vector<int> root;//����˳���������ǰ���߾����ĵ�
};

class Graph2 {
private:
	//��ʾͼ�ľ���
	int Matrix[N][N] = { 0, 12, 23, 34, 45, 56,
						12, 0, 43, 51, 32, 82,
						23, 43, 0, 64, 73, 89,
						34, 51, 64, 0, 54, 90,
						45, 32, 73, 54, 0, 17,
						56, 82, 89, 90, 17, 0 };
	//int Matrix[4][4] = {0,2,1,6,2,0,5,3,1,5,0,4,6,3,4,0};
	//��̬�滮��
	Decision d[N][32];
public:
	Graph2() {	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << Matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		//�Ȱѱ��в���Ҫ��ĵط���-1,����Ҫ��ĵط���������
		//0���г������һ������-1
		for (int j = 0; j < (int)pow(2, N - 1); j++) {
			d[0][j].weight = -1;
		}
		d[0][31].weight = 999999;
		//��������ÿ2��n-1�η��η�תһ����Ķ������ֱ���������-1
		for (int i = 1; i < N; i++) {
			int skip = pow(2, i - 1);
			int count = 0;
			bool flag = true;
			for (int j = 0; j < (int)pow(2, N - 1); j++) {
				if (flag) {
					d[i][j].weight = 999999;
				}
				else {
					d[i][j].weight = -1;
				}
				count++;
				if (count == skip) {
					count = 0;
					flag = !flag;
				}
			}
		}
		//���˳�ʼ������
	}

	void DTSP() {
		int column = (int)pow(2, N - 1);//�������
		//�Ȱѵ�һ����ã��ֱ���ÿ����ص�0�ľ���
		for (int i = 1; i < N; i++) {
			d[i][0].weight = Matrix[i][0];
			d[i][0].root.push_back(i);
		}

		//�ӵڶ��п�ʼһ��һ�����
		for (int j = 1; j < column; j++) {
			for (int i = 1; i < N; i++) {
				if (d[i][j].weight == -1)
					continue;

				//�Ӹ��������������һ����С�����ȥ
				int min = 999999;
				int a, b;
				for (int k : transfer(j)/*��k������ǰ��j��ʾ���Ǹ��㼯*/) {
					int temp = Matrix[i][k] + d[k][j - (int)pow(2, k - 1)].weight;
					if (temp < min) {
						min = temp;
						a = k; b = j - (int)pow(2, k - 1);
					}
				}
				d[i][j].weight = min;
				d[i][j].root = d[a][b].root;
				d[i][j].root.push_back(i);
			}
		}

		int min = 999999;
		int a, b;
		for (int k : transfer(N - 1)) {
			int temp = Matrix[0][k] + d[k][column - 1 - (int)pow(2, k - 1)].weight;
			if (temp < min) {
				min = temp;
				a = k; b = column - 1 - (int)pow(2, k - 1);
			}
		}
		d[0][column - 1].weight = min;
		d[0][column - 1].root = d[a][b].root;
		d[0][column - 1].root.push_back(0);
		cout << min << endl;
		for (int i = 0; i < d[0][column - 1].root.size(); i++) {
			cout << d[0][column - 1].root[i] << "  ";
		}
	}

	vector<int> transfer(int j) {
		string s;
		s = "";
		for (int a = j; a; a = a / 2)
		{
			s = s + (a % 2 ? '1' : '0');
		}
		//�ַ�����ת  
		//s.begin() ����ַ����Ŀ�ʼλ��  
		//s.end() ����ַ����Ľ�βλ��  
		//std::reverse(s.begin(), s.end());

		//cout << s << endl;
		//c_str() ��string���͵��ַ���ת��Ϊchar*  
		//const char *sss=s.c_str();  
		//cout.width(11);  
		//cout<<n<<(n<0?"-->-":"-->")<<sss<<"\n";  
		//������ת�����

		vector<int> temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				temp.push_back(i + 1);
			}
		}
		return temp;
	}

};

