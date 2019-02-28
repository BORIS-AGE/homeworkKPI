// KPI_homework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>

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

int main()
{
	srand(time(NULL));

	lab_14 lab = lab_14();
	/*lab.addGood(105.3, 3);
	lab.addUser(100);

	lab.recordFiles(lab);*/

	lab_14 lab2 = lab.getRecordedFiles();
	//lab2.printFiles();

	/*ifstream file2;
	file2.open("users.txt");
	if (!file2.is_open())
	{
		cout << "file2: reading error\n";
	}
	lab_14 ll;
	while (file2.read((char*)&ll, sizeof(lab_14)))
	{
		ll.printFiles();
	}
	file2.close();*/
	//system("pause");
}

