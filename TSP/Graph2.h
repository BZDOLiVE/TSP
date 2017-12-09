#pragma once
#include<iostream>
#define N 6
#define INF 99999999

using namespace std;

class Decision {
public:
	int weight = 0;//当前决策的路径长度
	vector<int> root;//按照顺序存下来当前决策经过的点
};

class Graph2 {
private:
	//表示图的矩阵
	int Matrix[N][N] = { 0, 12, 23, 34, 45, 56,
						12, 0, 43, 51, 32, 82,
						23, 43, 0, 64, 73, 89,
						34, 51, 64, 0, 54, 90,
						45, 32, 73, 54, 0, 17,
						56, 82, 89, 90, 17, 0 };
	//int Matrix[4][4] = {0,2,1,6,2,0,5,3,1,5,0,4,6,3,4,0};
	//动态规划表
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
		//先把表中不需要填的地方置-1,把需要填的地方设成无穷大
		//0这行除了最后一个都填-1
		for (int j = 0; j < (int)pow(2, N - 1); j++) {
			d[0][j].weight = -1;
		}
		d[0][31].weight = 999999;
		//其他的行每2的n-1次方次反转一下填的东西，分别填无穷大和-1
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
		//至此初始化结束
	}

	void DTSP() {
		int column = (int)pow(2, N - 1);//表格列数
		//先把第一列填好，分别是每个点回到0的距离
		for (int i = 1; i < N; i++) {
			d[i][0].weight = Matrix[i][0];
			d[i][0].root.push_back(i);
		}

		//从第二列开始一列一列填表
		for (int j = 1; j < column; j++) {
			for (int i = 1; i < N; i++) {
				if (d[i][j].weight == -1)
					continue;

				//从各种情况中挑出来一个最小的填进去
				int min = 999999;
				int a, b;
				for (int k : transfer(j)/*用k遍历当前的j表示的那个点集*/) {
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
		//字符串反转  
		//s.begin() 获得字符串的开始位置  
		//s.end() 获得字符串的结尾位置  
		//std::reverse(s.begin(), s.end());

		//cout << s << endl;
		//c_str() 将string类型的字符创转化为char*  
		//const char *sss=s.c_str();  
		//cout.width(11);  
		//cout<<n<<(n<0?"-->-":"-->")<<sss<<"\n";  
		//二进制转换完毕

		vector<int> temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				temp.push_back(i + 1);
			}
		}
		return temp;
	}

};

