#pragma once
#define PRINT_INFO
using namespace std;
#include<assert.h>

template<typename T>
class MyVector
{
private:

	T* _Mydate;			//���Ԫ�ص�����
	size_t _Mysize;		//������Ԫ�ظ���
	size_t _Mycapacity;	//�����ܵ������ɸ�Ԫ�صĸ���

	//resize����,�����¿ռ䣬��СΪ�ɿռ��������ͬʱ�������������ͷžɿռ�
	void resize() {
		T* _New_date = static_cast<T*>(::operator new(sizeof(T) * _Mycapacity * 2)); //��������Ϊԭ��������
		for (size_t i = 0; i < _Mysize; i++) {
			_New_date[i] = _Mydate[i];
		}
		::operator delete(_Mydate);			//�ͷžɿռ�
		_Mydate = _New_date;				//��ָ��ɿռ��ָ��ָ���¿ռ���׵�ַ
		_Mycapacity = _Mycapacity * 2;
	}
public:

	//���ɹ�����
	//Ĭ�Ϲ���
	MyVector()  : _Mysize(0), _Mycapacity(10) {
	#ifdef PRINT_INFO
		cout << "MyVector()" << endl;
	#endif 
		_Mydate = static_cast<T*>(::operator new(sizeof(T)* _Mycapacity));     //��ֹ�ظ�����T�Ĺ��캯��
	}
	
	// ʹ�ó�ʼ���б��ʼ��
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

	//ʹ�� n ��Ĭ��ֵ��ʼ��,�����Ŀ����ʵ�ֳ�ʼ��������ʹ��new,������::operator new
	MyVector(const int& n) :_Mydate(new T[n]), _Mysize(n), _Mycapacity(n) {
	#ifdef PRINT_INFO
		cout<<"MyVector(const int& n)" << endl;
	#endif 

	}

	// ʹ�� n ����ͬ��ֵ��ʼ��
	MyVector(const size_t& n,const T& m):_Mysize(n),_Mycapacity(n){
	#ifdef PRINT_INFO
		cout << "MyVector(const size_t& n,const T& m)" << endl;
	#endif 
		_Mydate = static_cast<T*>(::operator new(sizeof(T)*_Mycapacity));
		for (size_t i = 0; i < n; i++)_Mydate[i] = m;
	}

	//��������
	//std::vector<int>ve5 = ve4;
	MyVector(const MyVector& right) :_Mysize(right._Mysize),_Mycapacity(right._Mycapacity){
	#ifdef PRINT_INFO
		cout << "MyVector(const MyVector& right)" << endl;
	#endif 
		_Mydate = static_cast<T*>(::operator new(sizeof(T) * _Mysize));
		for (size_t i = 0; i < _Mysize; i++) _Mydate[i] = right._Mydate[i];
	}

	//�ƶ�����
	//std::vector<int>ve6 = std::vector<int>{ 1,2,3 };
	MyVector(MyVector&& right) :_Mydate(right._Mydate),_Mysize(right._Mysize), _Mycapacity(right._Mycapacity) {
	#ifdef PRINT_INFO
		cout << "MyVector(MyVector&& right)" << endl;
	#endif 
		right._Mydate = nullptr;
	}

	//ʹ�õ���������

	//��������
	~MyVector(){
	#ifdef PRINT_INFO
		cout << "~MyVector()" << endl;
	#endif 

		::operator delete(_Mydate);
	}

	//��ֵ����

	//������ֵ!!!����ʱ��Ϊ��	MyVector(const MyVector& right) :_My_size(right._My_size),_My_capacity(right._My_capacity)
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

	//�ƶ���ֵ
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

	//������:MyVectorIterator

	class MyVectorIterator {
	private:
		T* iter = nullptr;
	public:

		MyVectorIterator(T* date) :iter(date) {};

		//������
		T& operator*()const {
			return *iter;
		}
	
		
		//ǰ++
		MyVectorIterator& operator++() {
			++iter;
			return *this;
		}

		//��++
		//Ϊ������ǰ�úͺ�������������������������������һ��int���͵���Ԫ���������������ʵ�ʵ����в�ʹ�ã����������ֺ���ǩ����
		MyVectorIterator operator++(int) {
			MyVectorIterator temp{ iter };
			iter++;
			return temp;
		}

		//�Ƚϲ���

		bool operator==(const MyVectorIterator& right) { return iter == right.iter; }
		bool operator!=(const MyVectorIterator& right) { return iter != right.iter; }

		//+������

		MyVectorIterator operator+(const int& index) {
			MyVectorIterator temp{ iter + index };
			return temp;
		}

		//-������
		size_t operator-(const MyVectorIterator& right) {
			size_t temp = this->iter - right.iter;
			return temp;
		}
	};

	//begin,����ָ���һ��Ԫ�صĵ�����

	MyVectorIterator begin() { return MyVectorIterator(_Mydate); }

	//end����ָ���һ��Ԫ�صĵ�����

	MyVectorIterator end() { return MyVectorIterator(_Mydate + _Mysize); }

	//size
	size_t size() {
		return _Mysize;
	}

	//capacity
	size_t capacity() {
		return _Mycapacity;
	}


	//empty�ж��Ƿ�Ϊ��
	bool empty() { return _Mysize == 0; }

	//clear�������
	 
	void clear() {
		_Mysize = 0;
	}


	//insert��Ŀ��λ�ò���
	
	void insert(MyVectorIterator iter,const T& n) {
		//���ж������Ƿ񹻣������������
		if (_Mysize == _Mycapacity)resize();
		size_t m = iter - begin();
		for (size_t i = _Mysize; i > m; --i) {
			_Mydate[i] = _Mydate[i - 1];
		}
		_Mydate[m] = n;
		_Mysize++;
	}


	//pop_backĩβ����
	void pop_back() {
		if (_Mysize < 1)return;
		_Mysize--;
	}


	//push_backĩβ����
	void push_back(const T& t) {

		//���ж������Ƿ񹻣������������
		if (_Mysize == _Mycapacity)resize();
		_Mydate[_Mysize++] = t;
	}


	//atʵ�����ȡ��
	T at(const int& index) {
		if (_Mysize <= index)return NULL;
		return _Mydate[index];
	}


	//[]ʵ��ͨ����������Ԫ��
	T& operator[](const size_t& index) {
		assert(_Mysize > index);
			
		return _Mydate[index];
	}

};

