#pragma once
#define PRINT_INFO
using namespace std;
#include<assert.h>

template<typename T>
class MyVector
{
private:

	T* _Mydate;			//存放元素的数组
	size_t _Mysize;		//容器中元素个数
	size_t _Mycapacity;	//容器总的能容纳该元素的个数

	//resize扩容,创建新空间，大小为旧空间的两倍，同时调用析构函数释放旧空间
	void resize() {
		T* _New_date = static_cast<T*>(::operator new(sizeof(T) * _Mycapacity * 2)); //容量扩大为原来的两倍
		for (size_t i = 0; i < _Mysize; i++) {
			_New_date[i] = _Mydate[i];
		}
		::operator delete(_Mydate);			//释放旧空间
		_Mydate = _New_date;				//将指向旧空间的指针指向新空间的首地址
		_Mycapacity = _Mycapacity * 2;
	}
public:

	//若干构造器
	//默认构造
	MyVector()  : _Mysize(0), _Mycapacity(10) {
	#ifdef PRINT_INFO
		cout << "MyVector()" << endl;
	#endif 
		_Mydate = static_cast<T*>(::operator new(sizeof(T)* _Mycapacity));     //防止重复调用T的构造函数
	}
	
	// 使用初始化列表初始化
	//std::vector<int> vec = {1,2,3,4,5};
	MyVector(const std::initializer_list<T>& _ini_list):_Mysize(_ini_list.size()),_Mycapacity(_ini_list.size()) {
	#ifdef PRINT_INFO
		cout<<"MyVector(std::initializer_list<T>& _ini_list)" << endl;
	#endif 

		_Mydate = static_cast<T*>(::operator new(sizeof(T) * _Mycapacity));
	
		size_t i = 0;
		for (const T& value : _ini_list) {
			_Mydate[i++] = value;
		}
	}

	//使用 n 个默认值初始化,这里的目的是实现初始化，所以使用new,而不是::operator new
	MyVector(const int& n) :_Mydate(new T[n]), _Mysize(n), _Mycapacity(n) {
	#ifdef PRINT_INFO
		cout<<"MyVector(const int& n)" << endl;
	#endif 

	}

	// 使用 n 个相同的值初始化
	MyVector(const size_t& n,const T& m):_Mysize(n),_Mycapacity(n){
	#ifdef PRINT_INFO
		cout << "MyVector(const size_t& n,const T& m)" << endl;
	#endif 
		_Mydate = static_cast<T*>(::operator new(sizeof(T)*_Mycapacity));
		for (size_t i = 0; i < n; i++)_Mydate[i] = m;
	}

	//拷贝构造
	//std::vector<int>ve5 = ve4;
	MyVector(const MyVector& right) :_Mysize(right._Mysize),_Mycapacity(right._Mycapacity){
	#ifdef PRINT_INFO
		cout << "MyVector(const MyVector& right)" << endl;
	#endif 
		_Mydate = static_cast<T*>(::operator new(sizeof(T) * _Mysize));
		for (size_t i = 0; i < _Mysize; i++) _Mydate[i] = right._Mydate[i];
	}

	//移动构造
	//std::vector<int>ve6 = std::vector<int>{ 1,2,3 };
	MyVector(MyVector&& right) :_Mydate(right._Mydate),_Mysize(right._Mysize), _Mycapacity(right._Mycapacity) {
	#ifdef PRINT_INFO
		cout << "MyVector(MyVector&& right)" << endl;
	#endif 
		right._Mydate = nullptr;
	}

	//使用迭代器构造

	//析构函数
	~MyVector(){
	#ifdef PRINT_INFO
		cout << "~MyVector()" << endl;
	#endif 

		::operator delete(_Mydate);
	}

	//赋值函数

	//拷贝赋值!!!编译时行为：	MyVector(const MyVector& right) :_My_size(right._My_size),_My_capacity(right._My_capacity)
	MyVector& operator =(const MyVector& right){
	#ifdef PRINT_INFO
		cout << "MyVector& operator =(const MyVector& right)" << endl;
	#endif 
		if (this->_Mydate == right._Mydate)return *this;
		
		::operator delete(this->_Mydate);
		_Mysize = right._Mysize;
		_Mycapacity = right._Mycapacity;
		_Mydate = static_cast<T*>(::operator new(sizeof(T) * _Mycapacity));
		for (size_t i = 0; i < _Mysize; i++)_Mydate[i] = right._Mydate[i];

		return *this;
	}

	//移动赋值
	MyVector& operator =(MyVector&& right) {
	#ifdef PRINT_INFO
		cout << "MyVector& operator =(MyVector&& right)" << endl;
	#endif 

		::operator delete(this->_Mydate);
		_Mysize = right._Mysize;
		_Mycapacity = right._Mycapacity;
		_Mydate = right._Mydate;
		right._Mydate = nullptr;

		return *this;
	}

	//迭代器:MyVectorIterator

	class MyVectorIterator {
	private:
		T* iter = nullptr;
	public:

		MyVectorIterator(T* date) :iter(date) {};

		//解引用
		T& operator*()const {
			return *iter;
		}
	
		
		//前++
		MyVectorIterator& operator++() {
			++iter;
			return *this;
		}

		//后++
		//为了区分前置和后置增量运算符，后置增量运算符接收一个int类型的哑元参数，这个参数在实际调用中不使用，仅用于区分函数签名。
		MyVectorIterator operator++(int) {
			MyVectorIterator temp{ iter };
			iter++;
			return temp;
		}

		//比较操作

		bool operator==(const MyVectorIterator& right) { return iter == right.iter; }
		bool operator!=(const MyVectorIterator& right) { return iter != right.iter; }

		//+的重载

		MyVectorIterator operator+(const int& index) {
			MyVectorIterator temp{ iter + index };
			return temp;
		}

		//-的重载
		size_t operator-(const MyVectorIterator& right) {
			size_t temp = this->iter - right.iter;
			return temp;
		}
	};

	//begin,返回指向第一个元素的迭代器

	MyVectorIterator begin() { return MyVectorIterator(_Mydate); }

	//end返回指向第一个元素的迭代器

	MyVectorIterator end() { return MyVectorIterator(_Mydate + _Mysize); }

	//size
	size_t size() {
		return _Mysize;
	}

	//capacity
	size_t capacity() {
		return _Mycapacity;
	}


	//empty判断是否为空
	bool empty() { return _Mysize == 0; }

	//clear清空数组
	 
	void clear() {
		_Mysize = 0;
	}


	//insert在目标位置插入
	
	void insert(MyVectorIterator iter,const T& n) {
		//先判断容量是否够，否则进行扩容
		if (_Mysize == _Mycapacity)resize();
		size_t m = iter - begin();
		for (size_t i = _Mysize; i > m; --i) {
			_Mydate[i] = _Mydate[i - 1];
		}
		_Mydate[m] = n;
		_Mysize++;
	}


	//pop_back末尾弹出
	void pop_back() {
		if (_Mysize < 1)return;
		_Mysize--;
	}


	//push_back末尾插入
	void push_back(const T& t) {

		//先判断容量是否够，否则进行扩容
		if (_Mysize == _Mycapacity)resize();
		_Mydate[_Mysize++] = t;
	}


	//at实现随机取数
	T at(const int& index) {
		if (_Mysize <= index)return NULL;
		return _Mydate[index];
	}


	//[]实现通过索引访问元素
	T& operator[](const size_t& index) {
		assert(_Mysize > index);
			
		return _Mydate[index];
	}

};

