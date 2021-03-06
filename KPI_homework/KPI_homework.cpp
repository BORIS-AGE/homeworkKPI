// KPI_homework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <queue>

#define str1 "83n4v834nrv83br8y3o4cyn438tmy3i4ynro83y4tyncob"
 
using namespace std;

void showMyArray(int**H, int x, int y, string name);
void fillByRandom(int**H, int x, int y);
int calculate(int**H, int x, int y);

void lab_9() {
	map<string, int> list;
	map<string, int> resultList;

	//const defining
	/*list.insert(make_pair("vasia", 2000));
	list.insert(make_pair("sia", 6));
	list.insert(make_pair("mmm", 2018));
	list.insert(make_pair("sss", 5));*/

	//runtime adding
	int numbOfPeople;
	cout << "enter number of people: "; cin >> numbOfPeople; cout << "\n";
	for (int i = 0; i < numbOfPeople; i++)
	{
		string name; int age;
		cout << i << ": enter name: "; cin >> name;
		cout << i << ": enter age: "; cin >> age;
		list.insert(make_pair(name, age));
		cout << "////////////////////////" << endl;
	}

	cout << "old array:" << endl;
	map<string, int>::iterator it = list.begin();
	while (it != list.end())
	{
		cout << it->first << " - " << it->second << endl;
		if (it->second >= 1998)
		{
			resultList.insert(make_pair(it->first, it->second));
		}
		it++;
	}

	cout << "\nnew array:" << endl;
	map<string, int>::iterator it2 = resultList.begin();
	while (it2 != resultList.end())
	{
		cout << it2->first << " - " << it2->second<<endl;
		it2++;
	}

}

void lab_10() {
	int **A = new int*[5];
	int **B = new int*[4];

	fillByRandom(A,5,6);
	fillByRandom(B, 4, 3);

	showMyArray(A, 5, 6, "array A"); showMyArray(B, 4, 3, "\narray B");

	int a = calculate(A, 5, 6);
	int b = calculate(B, 4, 3);
	cout << "\nresults:\nA: " << a << "\nb: " << b << endl;
}

void showMyArray(int**H, int x, int y, string name) {
	cout << name << endl;
	for (int i = 0; i < x; i++)
	{
		for (int z = 0; z < y; z++)
		{
			cout<< H[i][z]<<", ";
		}
		cout << endl;
	}
}

void fillByRandom(int**H, int x, int y) {
	for (int i = 0; i < x; i++)
	{
		H[i] = new int[y];
		for (int z = 0; z < y; z++)
		{
			H[i][z] = rand()%100;
		}
	}
}

int calculate(int**H, int x, int y) {
	int result = 0;
	for (int i = 0; i < x; i++)
	{
		for (int z = 0; z < y; z++)
		{
			if (H[i][z] > 0)
			{
				result += H[i][z];
			}
			
		}
	}
	return result;
}

void lab_11() {
	string str = "(dwas)dsda(Asdw0 )sdwa(";
	int open = 0; int close = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '(')
		{
			open++;
		}
		if (str.at(i) == ')')
		{
			close++;
		}
	}
	string res = "";
	if (open == close)
	{
		res = "true";
	}
	else {
		res = "false";
	}
	cout<<"open: " << open << ", close: " << close << endl << "equals: " << res << endl;
}

void lab_12() {
	string S1 = "qwsdfghjm,k."; string S2 = "zcdxvfbghiko"; string S3 = "swadefgthujkl;'[";
	int mCase;
	cout << "choose case 1, 2 or 3: "; cin >> mCase;
	if (mCase > 3 || mCase < 1)
	{
		cout << "enter another value" << endl;
		return;
	}
	string result = ""; int counter = 0;
	if (mCase == 2)
	{
		for (int i = 0; i < S2.size(); i++)
		{
			for (int j = 0; j < S3.size(); j++)
			{
				if (S2.at(i) == S3.at(j)) {
					result += S2.at(i);
					counter++;
					break;
				}
			}
		}
		for (int i = 0; i < S1.size(); i++)
		{
			for (int j = 0; j < S3.size(); j++)
			{
				if (S1.at(i) == S3.at(j)) {
					result += S1.at(i);
					counter++;
					break;
				}
			}
		}
	}
	if (mCase == 1)
	{
		for (int i = 0; i < S2.size(); i++)
		{
			for (int j = 0; j < S3.size(); j++)
			{
				if (S2.at(i) == S3.at(j)) {
					result += S2.at(i);
					counter++;
					break;
				}
			}
		}
		for (int i = 0; i < result.size(); i++)
		{
			bool del = true;
			for (int j = 0; j < S1.size(); j++)
			{
				if (result.at(i) == S1.at(j)) {
					del = false;
					break;
				}
			}
			if (del)
			{
				counter--;
				string  newRes = "";
				for (size_t m = 0; m < result.size(); m++)
				{
					if (m != i)
					{
						newRes += result.at(m);
					}
				}
				result = newRes;
			}
		}
	}
	if (mCase == 3)
	{
		result = S3;
		counter = S3.size();
		for (int i = 0; i < result.size(); i++)
		{
			bool del = false;
			for (int j = 0; j < S2.size(); j++)
			{
				if (result.at(i) == S2.at(j)) {
					del = true;
					break;
				}
			}
			if (del)
			{
				counter--;
				string  newRes = "";
				for (size_t m = 0; m < result.size(); m++)
				{
					if (m != i)
					{
						newRes += result.at(m);
					}
				}
				result = newRes;
				i = -1;
			}
		}
		for (int i = 0; i < result.size(); i++)
		{
			bool del = false;
			for (int j = 0; j < S1.size(); j++)
			{
				if (result.at(i) == S1.at(j)) {
					del = true;
					break;
				}
			}
			if (del)
			{
				counter--;
				string  newRes = "";
				for (size_t m = 0; m < result.size(); m++)
				{
					if (m != i)
					{
						newRes += result.at(m);
					}
				}
				result = newRes;
				i = -1;
			}
		}
	}
	cout << "\nstr1 = " << S1 << "\n str2 = " << S2 << "\nstr3 = " << S3 << endl<<endl;
	cout << "result: " << counter << " - matces, string: " << result << endl;
}

void lab_13() {
	ofstream file1;
	ofstream file2;
	int** arr1;
	int** arr2;
	int X, Y;
	cout << "enter width: "; cin >> X;
	cout << "enter height: "; cin >> Y;
	arr1 = new int*[Y];
	arr2 = new int*[X];
	file1.open("first.txt");
	file2.open("second.txt");
	file1 << "width: "<<X<<", heght: "<< Y<<"\n";
	for (int i = 0; i < Y; i++)
	{
		arr1[i] = new int[X];
		for (int j = 0; j < X; j++)
		{
			int val = rand() % 10;
			arr1[i][j] = val;
			file1 << val << "\t";
			cout<< val << "\t";
		}
		file1 << "\n";
		cout << "\n";
	}

	file1 << "\n";
	cout << endl;
	file1 << "width: " << Y << ", heght: " << X << "\n";
	for (int i = 0; i < X; i++)
	{
		arr2[i] = new int[Y];
		for (int j = 0; j < Y; j++)
		{
			int val = rand() % 10;
			arr2[i][j] = val;
			file1 << val << "\t";
			cout << val << "\t";
		}
		file1 << "\n";
		cout << "\n";
	}

	
	int** res = new int*[X];
	cout << "result: \n";
	file2 << "width: " << X << ", height: " << X << "\n";

	for (int i = 0; i < X; i++)
	{
		res[i] = new int[X];
		for (int j = 0; j < X; j++)
		{
			res[i][j] = 0;
			for (int m = 0; m < Y; m++)
			{
				res[i][j] += arr1[m][j] * arr2[i][m];
			}
			cout << res[i][j] << ", ";
			file2 << res[i][j] << "\t";
		}
		file2 << "\n";
		cout << "\n";
	}

	file2.flush();
	file2.close();
	file1.flush();
	file1.close();

}

class lab_14 {
public:
	class User {
	public:
		double money;
		double getMony() { return money; }
		User(int mon) {
			money = mon;
		}
	};
	class Good {
	public:
		double price;
		int benefit;
		double getPrice() { return price; }
		int getBenefit() { return benefit; }
		Good(double pr, int ben) {
			benefit = ben;
			price = pr;
		}
	};

	vector<User> users;
	vector<Good> goods;

	void recordFiles(lab_14 ll) {
		ofstream file1;
		file1.open("users.txt");
		if (!file1.is_open())
		{
			cout << "file1: openning error in recording\n";
			return;
		}
		file1.write((char*)& ll, sizeof(lab_14));

		file1.flush();
		file1.close();
	}
	void addUser(double money) {
		User user = User(money);
		users.push_back(user);
	}
	void addGood(double price, int quolity) {
		Good good = Good(price, quolity);
		goods.push_back(good);
	}
	lab_14 getRecordedFiles() {
		ifstream file1;
		file1.open("users.txt");
		if (!file1.is_open())
		{
			cout << "file1: reading error\n";
			return lab_14();
		}

		lab_14 ll = lab_14();
		file1.read((char*)&ll, sizeof(lab_14));
		file1.close();
		
		return ll;
	}
	void printFiles() {
		cout << "users: \n";
		for (int i = 0; i < users.size(); i++)
		{
			cout << i + 1 << ": " << users.at(i).getMony()<<endl;
		}
		cout << "goods: \n";
		for (int i = 0; i < goods.size(); i++)
		{
			cout << i << ": " << goods.at(i).getPrice()<<" - "<< goods.at(i).getBenefit() << endl;
		}
	}
};

class kp_1 {
private:
	int size, depth = 0, depth2 = 0;
	vector<int> deps;
	class Node {
	public:
		int key;
		Node* left;
		Node* right;
		Node(int key) {
			left = NULL;
			right = NULL;
			this->key = key;
		}
	};
	

	void tryNext(int key, Node* curr) {
		if (key > curr->key)
		{
			if (curr->right == NULL)
			{
				curr->right = new Node(key);
			}
			else {
				tryNext(key, curr->right);
			}
		}
		else {
			if (curr->left == NULL)
			{
				curr->left = new Node(key);
			}
			else {
				tryNext(key, curr->left);
			}
		}
	}

public:
	Node* head;
	int sum = 0;

	kp_1(int key) {
		size = 1;
		head = new Node(key);
	}

	void addElem(int key) {
		size++;
		if (key > head->key)
		{
			if (head->right == NULL)
			{
				head->right = new Node(key);
			}
			else {
				tryNext(key, head->right);
			}
		}
		else {
			if (head->left == NULL)
			{
				head->left = new Node(key);
			}
			else {
				tryNext(key, head->left);
			}
		}
	}

	void preOrder(Node* curr) {
		if (curr != NULL)
		{
			cout << curr->key << ", ";
			preOrder(curr->left);
			preOrder(curr->right);
		}
	}

	void inOrder(Node* curr) {
		if (curr != NULL)
		{
			inOrder(curr->left);
			cout << curr->key << ", ";
			inOrder(curr->right);
		}
	}

	void postOrder(Node* curr) {
		if (curr != NULL) {
			postOrder(curr->left);
			postOrder(curr->right);
			cout << curr->key << ", ";
		}
	}

	void levelOrderPrint(Node *root) {
		if (root == NULL)
		{
			return;
		}
		queue<Node *> q; // Создаем очередь
		q.push(root); // Вставляем корень в очередь

		while (!q.empty()) // пока очередь не пуста
		{
			Node* temp = q.front(); // Берем первый элемент в очереди
			q.pop();  // Удаляем первый элемент в очереди
			cout << temp->key << " "; // Печатаем значение первого элемента в очереди

			if (temp->left != NULL)
				q.push(temp->left);  // Вставляем  в очередь левого потомка

			if (temp->right != NULL)
				q.push(temp->right);  // Вставляем  в очередь правого потомка
		}
	}

	void count2(Node* curr) {
		if (curr != NULL) {
			depth2++;

			//cout << "\n depth: " << depth << "\ndepth2: " << depth2 << "\nkey: " << curr->key << endl;
			if (depth2 > depth)
			{
				deps.push_back(depth);
				depth++;
				cout << curr->key << ", ";
				sum += curr->key;
			}

			count2(curr->right);
			
			count2(curr->left);

			depth2--;
			
		}
	}

	/*kp_1R kp = kp_1R(7);
	int arr[19] = { 246,50,622,948,541,112,89,940,885,490,234,157,882,176,415,136,195,144,232 };

	for (int a : arr) {
		kp.addElem(a);
	}

	kp.count(kp.head);
	cout << "\nnodes: " << kp.numberOfNodes << endl;

	system("pause");*/
};

void lab_15() {
	ifstream file1;
	ofstream file2;

	file1.open("first.txt");
	file2.open("second.txt");

	string str = "";
	string res = "";

	while (!file1.eof())
	{
		getline(file1, str);
		res += " " + str + "\n";
	}
	cout << res << endl;
	
	file2 << res;
}

void lab_16() {
	cout << "enter string: ";
	string str; //cin >> str; 
	str = str1;
	bool exit1 = false, exit2 = false;
	int width, height;
	vector<int> arr2;

	// get all numeric and first char with numeric
	for (int i = 0; i < str.length(); i++)
	{
		char temp = str.at(i);
		bool isNumeric = false;

		switch (temp)
		{
		case '1':
			isNumeric = true;
			break;
		case '2':
			isNumeric = true;
			break;
		case '3':
			isNumeric = true;
			break;
		case '4':
			isNumeric = true;
			break;
		case '5':
			isNumeric = true;
			break;
		case '6':
			isNumeric = true;
			break;
		case '7':
			isNumeric = true;
			break;
		case '8':
			isNumeric = true;
			break;
		case '9':
			isNumeric = true;
			break;
		default:
			break;
		}

		if (isNumeric)
		{
			arr2.push_back(temp - 48);
			if (!exit1)
			{
				height = temp - 48;
				exit1 = true;
			}
		}
		if (!isNumeric && !exit2)
		{
			width = (int)temp;
			exit2 = true;
		}
		
	}

	cout << "width: " << width << "\nheight: " << height << endl;

	//fill with 0
	int** arr = new int*[height];
	for (int i = 0; i < height; i++)
	{
		arr[i] = new int[width];
		for (int j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}

	int a = 0, b = 0;
	for (int i = 0; i < arr2.size(); i++)
	{
		if (a > height)
		{
			a = 0;
		}
		if (b > width)
		{
			a++;
			b = 0;
		}

		arr[a][b++] = arr2.at(i);
	}

	cout << endl << endl;
	//cout
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}

}

void lab_17(){
	
}

class kp_1R {
private:

	class Node {
	public:
		int key;
		int level;
		Node* left;
		Node* right;
		Node(int key, int level) {
			left = NULL;
			right = NULL;
			this->key = key;
			this->level = level;
		}
	};


	void tryNext(int key, Node* curr, int level) {
		if (key > curr->key)
		{
			if (curr->right == NULL)
			{
				curr->right = new Node(key, level);
			}
			else {
				tryNext(key, curr->right, level + 1);
			}
		}
		else {
			if (curr->left == NULL)
			{
				curr->left = new Node(key, level);
			}
			else {
				tryNext(key, curr->left, level + 1);
			}
		}
	}

public:
	Node* head;
	int numberOfNodes = 0;

	kp_1R(int key) {
		head = new Node(key, 1);
	}

	void addElem(int key) {
		int level = 2;
		if (key > head->key)
		{
			if (head->right == NULL)
			{
				head->right = new Node(key, level);
			}
			else {
				tryNext(key, head->right, level + 1);
			}
		}
		else {
			if (head->left == NULL)
			{
				head->left = new Node(key, level);
			}
			else {
				tryNext(key, head->left, level + 1);
			}
		}
	}

	void preOrder(Node* curr) { // прямой
		if (curr != NULL)
		{
			cout << curr->key << ", ";
			preOrder(curr->left);
			preOrder(curr->right);
		}
	}

	void inOrder(Node* curr) { // симетрический
		if (curr != NULL)
		{
			inOrder(curr->left);
			cout << curr->key << ", ";
			inOrder(curr->right);
		}
	}

	void postOrder(Node* curr) { // обратный, зворотній
		if (curr != NULL) {
			postOrder(curr->left);
			postOrder(curr->right);
			cout << curr->key << ", ";
		}
	}

	void levelOrderPrint(Node *root) {
		if (root == NULL)
		{
			return;
		}
		queue<Node *> q; // Создаем очередь
		q.push(root); // Вставляем корень в очередь

		while (!q.empty()) // пока очередь не пуста
		{
			Node* temp = q.front(); // Берем первый элемент в очереди
			q.pop();  // Удаляем первый элемент в очереди
			cout << temp->key << " - "<<temp->level<<", "; // Печатаем значение первого элемента в очереди

			if (temp->left != NULL)
				q.push(temp->left);  // Вставляем  в очередь левого потомка

			if (temp->right != NULL)
				q.push(temp->right);  // Вставляем  в очередь правого потомка
		}
	}

	int count(Node* curr) {
		if (curr != NULL)
		{
			if (curr->level % 2 == 1 && curr->key % 7 == 0)
			{
				numberOfNodes++;
				cout << curr->key << ", ";
			}
			
			count(curr->left);
			count(curr->right);
			return numberOfNodes;
		}
	}

};

class kp_2 {
private:	
	vector<int>* arr;

public:
	static const int amount = 523;
	static const int range = 13000;
	int compare = 0, check = 0;

	kp_2(int key) {
		arr = new vector<int>[this->amount];
		int position = key % this->amount;
		arr[key].push_back(key);
	}

	void addElem(int key) {
		arr[key % this->amount].push_back(key);
	}

	vector<int> searchItems(int start, int end) {
		vector<int> values = vector<int>();
		for (int i = start; i < end; i++)
		{
			//cout << i << " - ";
			vector<int>::iterator it = arr[i % this->amount].begin();
			check++;
			while (it != arr[i % this->amount].end())
			{
				//cout << *it << ", ";
				values.push_back(*it);
				it++;
			} //cout << endl;
		}
		cout << endl << "if: " << check << endl;
		check = 0;
		return values;
	}

	void deleteItems(int start, int end) {
		for (int i = start; i < end; i++)
		{
			check++;
			if (!arr[i % this->range].empty())
			{
				arr[i % this->range].clear();
			}
		}
		cout << endl << "if: " << check << endl;
	}
	
};


class kp_2_1 {
private:
	vector<int>* arr;

public:
	static const int amount = 523;
	static const int range = 13000;
	int compare = 0, check = 0;


	kp_2_1(int key) {
		arr = new vector<int>[this->range];
		arr[key].push_back(key);
	}

	void addElem(int key) {
		check++;
		if (arr[key].empty())
		{
			arr[key].push_back(key);
		}
	}

	vector<int> searchItems(int start, int end) {
		vector<int> values = vector<int>();
		for (int i = start; i < end; i++)
		{
			check++;
			if (!arr[i].empty())
			{
				int res = arr[i].at(0);

				//cout << i << " - " << res << endl;
				values.push_back(res);
			}
			
		}
		cout << endl << "if: " << check << endl;
		check = 0;
		return values;
	}

	void deleteItems(int start, int end) {
		for (int i = start; i < end; i++)
		{
			check++;
			if (!arr[i].empty())
			{
				arr[i].clear();
			}
		}
		cout << endl << "if: " << check << endl;
		check = 0;
	}
};


/*kp_2 kp = kp_2(rand() % kp.amount);

for (int i = 0; i < kp.amount - 1; i++)
{
	kp.addElem(rand() % kp.amount);
}
cout << endl << "if: " << kp.check << endl;
kp.check = 0;

kp.searchItems(0, kp.amount);

cout << "size: " << sizeof(kp) << endl;

kp.deleteItems(0, kp.amount);*/

/*kp_2_1 kp = kp_2_1(rand() % kp.range);

for (int i = 0; i < kp.amount - 1; i++)
{
	kp.addElem(rand() % kp.range);
}
kp.searchItems(200, 3000);
cout << "size: " << sizeof(kp) << endl;

kp.deleteItems(100, 200); */

void kp3() {
	const int size = 5;
	int result = 0;
	long startTime = time(NULL);
	int arr[size][size] = {
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5},
		{1,2,3,4,5}
	};

	int arr2[6][6] = {
		{1,2,3,4,5,6},
		{1,2,3,4,5,6},
		{1,2,3,4,5,6},
		{1,2,3,4,5,6},
		{1,2,3,4,5,6},
		{1,2,3,4,5,6}
	};

	int a = 0;
	if (size % 2 == 1)
	{
		a = size / 2;
	}else {
		a = size / 2 - 1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ( ( j <=  i && i <= a) || (j <= size - (i) - 1 && i >= a)|| (j >= i && i >= a) || (j >= size - (i)-1 && i <= a) )
			{
				cout << arr[i][j] << "\t";
				if (result < arr[i][j])
				{
					result = arr[i][j];
				}
			}
			else {
				cout << "\t";
			}
		}cout << endl;
	}
	long endTime = time(NULL);
	cout << "result: " << result << endl << "time: " << startTime - endTime << endl;

}

int main()
{
	srand(time(NULL));

	kp3();

} 



