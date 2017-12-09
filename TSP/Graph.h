//贪心加穷举解TSP
#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct Vertex {//图的顶点
	string data;
	string info = "#";
};

struct Edge {//图的边
	int pro_vertex;//起始顶点
	int vertex;//目标顶点
	int	weight = 0;//权重
};

struct Root {//求解最短路径问题时用来保存路径
	string root;
	int weight = 0;
};

class Graph {
private:
	int n;//顶点个数
	vector<Vertex> vertex_vector;//用于存放每个顶点数据的vector
	vector<vector<Edge>*>edges_vector;//用于存放每个顶点都与哪些顶点相连的vector
	vector<bool> visited;//用于标记顶点是否已被访问
public:
	Graph() {
		n = 0;
	}
	~Graph() {
		for (int i = 0; i < edges_vector.size(); i++) {
			(*edges_vector[i]).clear();
			delete edges_vector[i];
		}
	}

	//向图中插入一个顶点
	void insert_vertex(Vertex _v) {
		vertex_vector.push_back(_v);
		vector<Edge>* temp1 = new vector<Edge>;
		edges_vector.push_back(temp1);
		bool v = false;
		visited.push_back(v);
		n++;
	}

	//向图中插入一条边
	void insert_edge(int x, int y, int _weight = 0) {
		Edge tempx, tempy;
		tempx.vertex = x;
		tempx.pro_vertex = y;
		tempy.vertex = y;
		tempy.pro_vertex = x;
		tempx.weight = _weight;
		tempy.weight = _weight;
		if (x < n && y < n && x != y) {
			edges_vector[x]->push_back(tempy);
			edges_vector[y]->push_back(tempx);
		}
		else if (x == y) {
			tempx.weight = 0;
			edges_vector[x]->push_back(tempx);
		}
		else {
			cout << "顶点不存在" << endl;
		}
	}


	
	//深度遍历
	void dfs(int vertex_num) 
	{
		cout << vertex_vector[vertex_num].data << endl;
		visited[vertex_num] = true;
		/*//adj_vertex为枚举变量, 对edges[vertex_num]中的每一个元素进行遍历,注意：edges[vertex]是一个vector<int>
		for (int adj_vertex : (*edges_vector[vertex_num])) {
			if (!visited[adj_vertex]) {
				dfs(adj_vertex);
			}
		}*/
		//上面那段for循环效果等于这个
		for (int i = 0; i < edges_vector[vertex_num]->size(); i++) {
			if (!visited[(*edges_vector[vertex_num])[i].vertex]) {
				dfs((*edges_vector[vertex_num])[i].vertex);
			}
		}
	}

	//深度遍历
	void DFS(int vertex_num) {
		dfs(vertex_num);
		for (int i = 0; i < visited.size(); i++) {
			visited[i] = false;
		}
	}

	//广度遍历
	void BFS(int start_vertex) {
		queue<int> bfs_queue;
		bfs_queue.push(start_vertex);
		visited[start_vertex] = true;
		while (!bfs_queue.empty()) {
			int vertex = bfs_queue.front();
			cout << vertex_vector[vertex].data << "  ";
			bfs_queue.pop();
			for (Edge adj_vertex : (*edges_vector[vertex])) {
				if (!visited[adj_vertex.vertex]) {
					visited[adj_vertex.vertex] = true;
					bfs_queue.push(adj_vertex.vertex);
				}
			}
		}
		cout << endl;
		for (int i = 0; i < visited.size(); i++) {
			visited[i] = false;
		}
	}

	//利用广度优先遍历查找图中指定元素，返回角标
	/*int search(string _data) {
		int num = -1;
		queue<int> bfs_queue;
		bfs_queue.push(0);
		visited[0] = true;
		while (!bfs_queue.empty()) 
		{
			int vertex = bfs_queue.front();
			if (vertex_vector[vertex].data == _data) {
				cout << vertex_vector[vertex].data << ": " << vertex_vector[vertex].info << endl;
				num = vertex;
				break;
			}
			
			bfs_queue.pop();
			for (Edge adj_vertex : (*edges_vector[vertex])) 
			{
				if (!visited[adj_vertex.vertex]) {
					visited[adj_vertex.vertex] = true;
					bfs_queue.push(adj_vertex.vertex);
				}
			}
		}
		for (int i = 0; i < visited.size(); i++) {
			visited[i] = false;
		}
		return num;
	}*/



	//建一个图
	void build() {
		Vertex node0;
		node0.data = "0北京";
		insert_vertex(node0);
		Vertex node1;
		node1.data = "1上海";
		insert_vertex(node1);
		Vertex node2;
		node2.data = "2广州";
		insert_vertex(node2);
		Vertex node3;
		node3.data = "3深圳";
		insert_vertex(node3);
		Vertex node4;
		node4.data = "4成都";
		insert_vertex(node4);
		Vertex node5;
		node5.data = "5杭州";
		insert_vertex(node5);
		Vertex node6;
		node6.data = "6武汉";
		insert_vertex(node6);
		Vertex node7;
		node7.data = "7天津";
		insert_vertex(node7);
		Vertex node8;
		node8.data = "8南京";
		insert_vertex(node8);
		Vertex node9;
		node9.data = "9重庆";
		insert_vertex(node9);
		Vertex node10;
		node10.data = "10西安";
		insert_vertex(node10);
		Vertex node11;
		node11.data = "11长沙";
		insert_vertex(node11);
		Vertex node12;
		node12.data = "12青岛";
		insert_vertex(node12);
		Vertex node13;
		node13.data = "13沈阳";
		insert_vertex(node13);
		Vertex node14;
		node14.data = "14大连";
		insert_vertex(node14);
		Vertex node15;
		node15.data = "15厦门";
		insert_vertex(node15);
		Vertex node16;
		node16.data = "16苏州";
		insert_vertex(node16);
		Vertex node17;
		node17.data = "17宁波";
		insert_vertex(node17);
		Vertex node18;
		node18.data = "18无锡";
		insert_vertex(node18);


		insert_edge(0, 0);
		insert_edge(0, 1, 1328);
		insert_edge(0, 2, 2267);
		insert_edge(0, 3, 2372);
		insert_edge(0, 4, 2001);
		insert_edge(0, 5, 1591);
		insert_edge(0, 6, 1200);
		insert_edge(0, 7, 137);
		insert_edge(0, 8, 1162);
		insert_edge(0, 9, 1936);
		insert_edge(0, 10, 1159);
		insert_edge(0, 11, 1593);
		insert_edge(0, 12, 819);
		insert_edge(0, 13, 889);
		insert_edge(0, 14, 938);
		insert_edge(0, 15, 2287);
		insert_edge(0, 16, 1379);
		insert_edge(0, 17, 1651);
		insert_edge(0, 18, 1337);

		insert_edge(1, 1);
		insert_edge(1, 2, 1532);
		insert_edge(1, 3, 1680);
		insert_edge(1, 4, 2159);
		insert_edge(1, 5, 202);
		insert_edge(1, 6, 811);
		insert_edge(1, 7, 1325);
		insert_edge(1, 8, 301);
		insert_edge(1, 9, 1949);
		insert_edge(1, 10, 1509);
		insert_edge(1, 11, 1173);
		insert_edge(1, 12, 800);
		insert_edge(1, 13, 2107);
		insert_edge(1, 14, 2254);
		insert_edge(1, 15, 1110);
		insert_edge(1, 16, 84);
		insert_edge(1, 17, 333);
		insert_edge(1, 18, 126);


		insert_edge(2, 2);
		insert_edge(2, 3, 147);
		insert_edge(2, 4, 2233);
		insert_edge(2, 5, 1607);
		insert_edge(2, 6, 1022);
		insert_edge(2, 7, 2404);
		insert_edge(2, 8, 1803);
		insert_edge(2, 9, 1907);
		insert_edge(2, 10, 2176);
		insert_edge(2, 11, 707);
		insert_edge(2, 12, 2326);
		insert_edge(2, 13, 2969);
		insert_edge(2, 14, 3246);
		insert_edge(2, 15, 850);
		insert_edge(2, 16, 1878);
		insert_edge(2, 17, 1670);
		insert_edge(2, 18, 1920);

		insert_edge(3, 3);
		insert_edge(3, 4, 2157);
		insert_edge(3, 5, 1496);
		insert_edge(3, 6, 1196);
		insert_edge(3, 7, 2367);
		insert_edge(3, 8, 1707);
		insert_edge(3, 9, 1844);
		insert_edge(3, 10, 2160);
		insert_edge(3, 11, 854);
		insert_edge(3, 12, 2413);
		insert_edge(3, 13, 3149);
		insert_edge(3, 14, 3296);
		insert_edge(3, 15, 825);
		insert_edge(3, 16, 1754);
		insert_edge(3, 17, 1632);
		insert_edge(3, 18, 1731);

		insert_edge(4, 4);
		insert_edge(4, 5, 2842);
		insert_edge(4, 6, 1289);
		insert_edge(4, 7, 2458);
		insert_edge(4, 8, 1858);
		insert_edge(4, 9, 504);
		insert_edge(4, 10, 842);
		insert_edge(4, 11, 1358);
		insert_edge(4, 12, 2688);
		insert_edge(4, 13, 2751);
		insert_edge(4, 14, 3081);
		insert_edge(4, 15, 2471);
		insert_edge(4, 16, 2075);
		insert_edge(4, 17, 2245);
		insert_edge(4, 18, 2033);

		insert_edge(5, 5);
		insert_edge(5, 6, 807);
		insert_edge(5, 7, 1512);
		insert_edge(5, 8, 488);
		insert_edge(5, 9, 2312);
		insert_edge(5, 10, 1558);
		insert_edge(5, 11, 989);
		insert_edge(5, 12, 1424);
		insert_edge(5, 13, 2105);
		insert_edge(5, 14, 2345);
		insert_edge(5, 15, 1194);
		insert_edge(5, 16, 271);
		insert_edge(5, 17, 149);
		insert_edge(5, 18, 212);

		insert_edge(6, 6);
		insert_edge(6, 7, 1313);
		insert_edge(6, 8, 516);
		insert_edge(6, 9, 1159);
		insert_edge(6, 10, 1025);
		insert_edge(6, 11, 413);
		insert_edge(6, 12, 1518);
		insert_edge(6, 13, 1912);
		insert_edge(6, 14, 2242);
		insert_edge(6, 15, 1175);
		insert_edge(6, 16, 743);
		insert_edge(6, 17, 983);
		insert_edge(6, 18, 701);

		insert_edge(7, 7);
		insert_edge(7, 8, 1024);
		insert_edge(7, 9, 2078);
		insert_edge(7, 10, 1310);
		insert_edge(7, 11, 1697);
		insert_edge(7, 12, 750);
		insert_edge(7, 13, 689);
		insert_edge(7, 14, 924);
		insert_edge(7, 15, 2278);
		insert_edge(7, 16, 1241);
		insert_edge(7, 17, 1529);
		insert_edge(7, 18, 1199);

		insert_edge(8, 8);
		insert_edge(8, 9, 1646);
		insert_edge(8, 10, 1208);
		insert_edge(8, 11, 900);
		insert_edge(8, 12, 837);
		insert_edge(8, 13, 1806);
		insert_edge(8, 14, 1953);
		insert_edge(8, 15, 1390);
		insert_edge(8, 16, 217);
		insert_edge(8, 17, 605);
		insert_edge(8, 18, 175);

		insert_edge(9, 9);
		insert_edge(9, 10, 790);
		insert_edge(9, 11, 922);
		insert_edge(9, 12, 2349);
		insert_edge(9, 13, 2776);
		insert_edge(9, 14, 3011);
		insert_edge(9, 15, 2188);
		insert_edge(9, 16, 1865);
		insert_edge(9, 17, 2128);
		insert_edge(9, 18, 1823);

		insert_edge(10, 10);
		insert_edge(10, 11, 1469);
		insert_edge(10, 12, 1572);
		insert_edge(10, 13, 2092);
		insert_edge(10, 14, 2228);
		insert_edge(10, 15, 2240);
		insert_edge(10, 16, 1425);
		insert_edge(10, 17, 1620);
		insert_edge(10, 18, 1383);

		insert_edge(11, 11);
		insert_edge(11, 12, 1619);
		insert_edge(11, 13, 2262);
		insert_edge(11, 14, 2536);
		insert_edge(11, 15, 1198);
		insert_edge(11, 16, 1119);
		insert_edge(11, 17, 1138);
		insert_edge(11, 18, 1077);

		insert_edge(12, 12);
		insert_edge(12, 13, 1463);
		insert_edge(12, 14, 1679);
		insert_edge(12, 15, 2328);
		insert_edge(12, 16, 1054);
		insert_edge(12, 17, 1628);
		insert_edge(12, 18, 1012);

		insert_edge(13, 13);
		insert_edge(13, 14, 397);
		insert_edge(13, 15, 2971);
		insert_edge(13, 16, 2023);
		insert_edge(13, 17, 2281);
		insert_edge(13, 18, 1981);

		insert_edge(14, 14);
		insert_edge(14, 15, 3106);
		insert_edge(14, 16, 2170);
		insert_edge(14, 17, 2521);
		insert_edge(14, 18, 2128);

		insert_edge(15, 15);
		insert_edge(15, 16, 1197);
		insert_edge(15, 17, 790);
		insert_edge(15, 18, 1231);

		insert_edge(16, 16);
		insert_edge(16, 17, 407);
		insert_edge(16, 18, 42);

		insert_edge(17, 17);
		insert_edge(17, 18, 446);

		insert_edge(18, 18);
	}

	//矩阵形式输出
	void output() {
		for (int i = 0; i < edges_vector.size(); i++) {
			for (int j = 0; j < (*edges_vector[i]).size(); j++) {
				cout << (*edges_vector[i])[j].weight << "        ";
			}
			cout << endl;
		}
	}

	//贪心算法解TSP问题
	int Greedy(int start, vector<bool> visited, int size) {
		int next_vertex = start;
		visited[start] = true;
		int min_dist;
		Root root;
		root.root += vertex_vector[next_vertex].data;

		//首先找出离出发点最远的点
		int max_dist = 0;//最远距离
		int max_vertex;//最远的那个点
		for (Edge &j : *edges_vector[start])
		{
			if (j.weight > max_dist && visited[j.vertex] == false)
			{
				max_dist = j.weight;
				max_vertex = j.vertex;
			}
		}

		int start_dist = 0;//距离出发点的距离
		int flag = 0;//用于判断是不是往远离出发点的地方走
		for (int i = 0; i < size - 1; i++)
		{
			min_dist = 9000000;
			visited[next_vertex] = true;
			if (next_vertex == max_vertex) {
				flag = 1;
			}
			start_dist = (*edges_vector[next_vertex])[start].weight;
			for (Edge &j : *edges_vector[next_vertex])
			{
				if (flag == 0)
				{
					if (visited[j.vertex] == false && j.weight < min_dist && j.weight != 0 && (*edges_vector[j.vertex])[start].weight > start_dist)
					{
						min_dist = j.weight;
						next_vertex = j.vertex;
					}
				}
				else {
					if (visited[j.vertex] == false && j.weight < min_dist && j.weight != 0)
					{
						min_dist = j.weight;
						next_vertex = j.vertex;
					}
				}
			}
			root.weight += min_dist;
			root.root += "->";
			root.root += vertex_vector[next_vertex].data;
		}

		//for (Edge &j : *edges_vector[next_vertex]) {
		//if (j.vertex == start) {
		//root.weight += j.weight;
		//}
		//}

		root.weight += (*edges_vector[next_vertex])[start].weight;
		root.root += "->";
		root.root += vertex_vector[start].data;

		cout << root.root << " " << root.weight << endl;

		return root.weight;

	}

	//穷举法解TSP
	void Exhaustive(int start_vertex, int vertex, vector<bool> visited, int weight, int &max_weight, string root) {
		if (weight > max_weight) {
			return;
		}

		visited[vertex] = true;
		int flag = 0;
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == false) {
				break;
			}
			else {
				flag++;
			}
		}
		if (flag == visited.size()) {
			weight += (*edges_vector[vertex])[start_vertex].weight;
			if (weight > max_weight) {
				return;
			}
			root += "->";
			root += vertex_vector[start_vertex].data;

			if (weight < max_weight) {
				max_weight = weight;			
				cout << root << "  " << weight << endl;
			}
			return;
		}		
		for (Edge &j : *edges_vector[vertex])
		{
			if (visited[j.vertex] == false) {
				int temp_weight = weight;
				string temp_root = root;
				weight += j.weight;
				root += "->";
				root += vertex_vector[j.vertex].data;			
				Exhaustive(start_vertex, j.vertex, visited, weight, max_weight, root);
				weight = temp_weight;
				root = temp_root;
			}
		}
	}

	void TSP(int start, int size) {
		vector<bool> temp_visited = visited;
		int max_weight = Greedy(start, temp_visited, size);	
		cout << "以上是近似解是否求解精确解？输入Y继续求解，输入N退出程序" << endl;
		string a;
		cin >> a;
		if (a == "Y") {
			string root = vertex_vector[start].data;
			Exhaustive(start, start, temp_visited, 0, max_weight, root);
		}
		else {
			exit(0);
		}

	}

	void SolveTSP() {
		for (int i = 0; i < visited.size(); i++) {
			visited[i] = true;
		}
		cout << "请输入要访问的城市的编号:(输入-1结束,第一个城市将作为起始城市)" << endl;
		vector<int> vec;
		while (1) {
			int a;
			cin >> a;
			if (a == -1) {
				break;
			}
			bool flag = 1;
			if (!vec.empty()) {
				for (int i = 0; i < vec.size(); i++) {
					if (a == vec[i]) {
						flag = 0;
					}
				}
			}
			if (flag && a < vertex_vector.size() && a >= 0) {
				vec.push_back(a);
			}
		}
		for (int i = 0; i < vec.size(); i++) {
			visited[vec[i]] = false;
		}
		if (!vec.empty()) {
			TSP(vec[0], vec.size());
		}
		for (int i = 0; i < visited.size(); i++) {
			visited[i] = false;
		}
	}
};
