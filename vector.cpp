#include<iostream>
#include<vector>
#include "MyVector.h"
#include "MyList.h"
#include<stack>
#include<list>

/*
仿照vector，使用模板类的方式，实现MyVector
实现基本功能：构造，析构，赋值，增删改查，遍历（迭代器），自动扩容
底层通过数组实现
*/




int main() {


//list

	list<int> list1;
	list1.push_back(1);
	for (auto i : list1)cout << i <<" ";
	cout << endl;

	
	

	list<int> list2{1,2,3};
	for (auto i : list2)cout << i << " ";
	cout << endl;

	list<int> list3(5,5);
	for (auto i : list3)cout << i << " ";
	cout << endl;

	list<int> list4(list3.begin(), list3.end());
	for (auto i : list4)cout << i << " ";
	cout << endl;


	list<int> list5{ list4 };
	for (auto i : list5)cout << i << " ";
	cout << endl;

	list<int> list6{ list<int>{1,2,3,6,7,6,6} };
	for (auto i : list6)cout << i << " ";
	cout << endl;

	cout << "MyList\n";
	MyList<int> mlist1{ 1,2,3,4,5 };
	for (auto i : mlist1)cout << i << " ";









	//std::vector<int> ve1{ 1,2,3 };
	//	//list<int> li1;
	//cout<<ve1.capacity()<<endl;
	//cout<<	ve1.max_size()<<endl;
	/*std::vector<int>ve2(10);
	std::vector<int>ve3 = { 1,2,2 };

	std::vector<int>ve4(4, 10);

	std::vector<int>ve5 = ve4;*/

	//std::vector<int>ve6 = std::vector<int>{ 1,2,3 };

	//std::list<int> lst = { 1, 2, 3, 4, 5 };
	//std::vector<int> ve7(lst.begin(), lst.end());
	//ve7.begin();
	//ve1.push_back(0);
	//ve1.push_back(1);
	////ve1.insert(1, 2);
	//for (int val : ve1) {
	//	std::cout << val << std::endl;
	//}
	////ve1.pop_back();

	//cout << ve1.at(1) << endl;
	
	////ve1[1] = 2;
	//cout << ve1[0] << endl;
	//cout << ve1.capacity();

	////vector<vector<int>> vel(5);
	//MyVector<int> yb = {1,2,3,4,5};
	///*for (int i = 0; i < 5; i++) {
	//	cout<<yb.at(i)<<endl;
	//}*/

	//MyVector<int>yb2(5);


	//MyVector<int>yb3 = yb;
	///*for (int i = 0; i < 5; i++) {
	//	cout << yb3.at(i) << endl;
	//}*/

	//
	////移动构造

	//MyVector<int>yb4{move(MyVector<int>{ 6,6,7,6,6 })};
	////for (int i = 0; i < 5; i++) {
	////	cout << yb4.at(i) << endl;
	////}

	//////n个相同值初始化
	//MyVector<int>yb5(5, 1);
	////for (int i = 0; i < 5; i++)cout << yb5.at(i) << endl;
	////


	////拷贝赋值

	//yb4 = yb5;
	//for (int i = 0; i < 5; i++)cout << yb4.at(i) << endl;




	////移动赋值

	//yb = move(yb5);
	//for (int i = 0; i < 5; i++)cout << yb[i] << endl;
	//cout << yb.capacity() << endl;
	//yb.push_back(999);
	//yb.push_back(99);
	//yb.push_back(9);
	//cout << yb.capacity() << endl;
	//for (int i = 0; i < 8; i++)cout << yb[i] << endl;
	//yb.pop_back();
	//yb.pop_back();
	//
	//yb.pop_back();
	//for (int i = 0; i < yb.size(); i++)cout << yb[i] << endl;

	//yb.push_back(888);
	//yb.push_back(88);
	//yb.push_back(8);

	//for (int i = 0; i < yb.size(); i++)cout << yb[i] << endl;



	//for (MyVector<int>::MyVectorIterator it = yb.begin(); it != yb.end(); ++it) {
	//	std::cout << *it << " ";
	//}

	//yb.insert(yb.begin() + 3, 5);
	//for (MyVector<int>::MyVectorIterator it = yb.begin(); it != yb.end(); ++it) {
	//	std::cout << *it << " ";
	//}

	///*for (int i = 0; i < 5; i++) {
	//	cout << yb2.at(i) << endl;
	//}*/
}