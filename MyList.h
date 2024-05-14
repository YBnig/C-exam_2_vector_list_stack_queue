#pragma once
#define PRINT_INFO
using namespace std;
/*
	list()：默认构造函数，创建一个空链表。
	list(size_type n, const T& value = T())：创建一个包含n个元素的链表，元素值为value。
	list(InputIterator first, InputIterator last)：创建一个链表，元素为[first, last)范围内的元素。
	list(const list& other)：拷贝构造函数。
	list(list&& other)：移动构造函数。
	list(std::initializer_list<T> il)：用初始化列表创建链表。
	析构函数
	~list()：销毁链表及其所有元素。
	赋值操作
	list& operator=(const list& other)：拷贝赋值操作符。
	list& operator=(list&& other)：移动赋值操作符。
	list& operator=(std::initializer_list<T> il)：赋值初始化列表中的元素。
	*/
	/*
	迭代器
iterator begin() noexcept：返回指向第一个元素的迭代器。
const_iterator begin() const noexcept：返回指向第一个元素的常量迭代器。
iterator end() noexcept：返回指向链表末尾的迭代器（不指向有效元素）。
const_iterator end() const noexcept：返回指向链表末尾的常量迭代器。
reverse_iterator rbegin() noexcept：返回指向链表最后一个元素的反向迭代器。
const_reverse_iterator rbegin() const noexcept：返回指向链表最后一个元素的常量反向迭代器。
reverse_iterator rend() noexcept：返回指向链表第一个元素之前位置的反向迭代器。
const_reverse_iterator rend() const noexcept：返回指向链表第一个元素之前位置的常量反向迭代器。
容量
bool empty() const noexcept：判断链表是否为空。
size_type size() const noexcept：返回链表中元素的个数。
size_type max_size() const noexcept：返回链表可容纳的最大元素个数。
元素访问
reference front()：返回链表第一个元素的引用。
const_reference front() const：返回链表第一个元素的常量引用。
reference back()：返回链表最后一个元素的引用。
const_reference back() const：返回链表最后一个元素的常量引用。
修改器
void assign(size_type n, const T& value)：将链表赋值为n个value元素。
template <class InputIterator> void assign(InputIterator first, InputIterator last)：将链表赋值为[first, last)范围内的元素。
void assign(std::initializer_list<T> il)：将链表赋值为初始化列表中的元素。
void push_front(const T& value)：在链表头部插入一个元素value。
void push_front(T&& value)：在链表头部插入一个移动的元素。
void push_back(const T& value)：在链表尾部插入一个元素value。
void push_back(T&& value)：在链表尾部插入一个移动的元素。
void pop_front()：删除链表头部的元素。
void pop_back()：删除链表尾部的元素。
iterator insert(const_iterator position, const T& value)：在position位置插入一个元素value。
iterator insert(const_iterator position, T&& value)：在position位置插入一个移动的元素。
iterator insert(const_iterator position, size_type n, const T& value)：在position位置插入n个元素value。
template <class InputIterator> iterator insert(const_iterator position, InputIterator first, InputIterator last)：在position位置插入[first, last)范围内的元素。
iterator insert(const_iterator position, std::initializer_list<T> il)：在position位置插入初始化列表中的元素。
iterator erase(const_iterator position)：删除position位置的元素。
iterator erase(const_iterator first, const_iterator last)：删除[first, last)范围内的元素。
void swap(list& other)：交换两个链表的内容。
void resize(size_type n)：将链表大小调整为n，若新大小大于当前大小，则插入值初始化的元素。
void resize(size_type n, const T& value)：将链表大小调整为n，若新大小大于当前大小，则插入value值的元素。
void clear() noexcept：清空链表。
操作
void splice(const_iterator position, list& other)：将other链表中所有元素移动到this链表的position位置。
void splice(const_iterator position, list& other, const_iterator i)：将other链表中的i位置的元素移动到this链表的position位置。
void splice(const_iterator position, list& other, const_iterator first, const_iterator last)：将other链表中[first, last)范围内的元素移动到this链表的position位置。
void remove(const T& value)：删除链表中所有值为value的元素。
template <class Predicate> void remove_if(Predicate pred)：删除链表中所有满足谓词pred的元素。
void unique()：删除链表中相邻的重复元素。
template <class BinaryPredicate> void unique(BinaryPredicate binary_pred)：删除链表中相邻的重复元素，用binary_pred判断相邻元素是否相等。
void merge(list& other)：将other链表合并到this链表中，要求两者已排序。
template <class Compare> void merge(list& other, Compare comp)：将other链表合并到this链表中，用comp进行排序。
void sort()：对链表元素进行排序。
template <class Compare> void sort(Compare comp)：用comp对链表元素进行排序。
void reverse() noexcept：反转链表中元素的顺序。*/

template<typename T>
class MyList
{

private:
	//定义链表的节点结构
	struct Node {
		T* _myval = nullptr;			//数据域
		Node* _pre = nullptr;			//指向前一个结点的指针
		Node* _next = nullptr;		//指向后一个结点的指针
		Node() {};
		Node(const T& value) {
			_myval = static_cast<T*>(::operator new(sizeof(T)));
			_myval[0] = value;
		}
	};

	Node* _FirstNode;		//双链表的头结点
	Node* _TailNode;		//双链表的尾结点
	size_t _size;			//链表存放的数据的个数

public:

	//构造函数
	
	//默认构造函数
	MyList():_FirstNode(nullptr),_TailNode(nullptr),_size(0){};

	//初始化列表构造
	MyList(std::initializer_list<T> inil) {
		for (const T& value : inil)push_back(value);
	}




	//在链表尾部插入一个元素value
	void push_back(const T& value) {
		Node* new_node = new Node{value};
		//如果链表为空，则进行初始插入
		if (_FirstNode == nullptr) {
			_FirstNode = new_node;
			_TailNode = new_node;
		}
		else {
			_TailNode->_next = new_node;
			new_node->_pre = _TailNode;
		}

		_size++;
	}

	//在链表头部插入一个元素value
	void push_head(const T& value) {
		Node* new_node = new Node{ value };
		//如果链表为空，则进行初始插入
		if (_FirstNode == nullptr) {
			_FirstNode = new_node;
			_TailNode = new_node;
		}
		else {
			_FirstNode->_pre = new_node;
			new_node->_next = _FirstNode;
			_FirstNode = new_node;
		}

		_size++;
	}






	class MyListIterator {
	private:
		T* iter;
	public:
		//构造函数
		MyListIterator(T* m) :iter(m){};
		
		//解引用
		T& operator*() {
			return *iter;
		}

		//前++
		MyListIterator& operator++() {
			++iter;
			return *this;
		}

		//后++
		MyListIterator operator++(int) {
			MyListIterator temp{ iter };
			++iter;
			return temp;
		}

		//重载！= ，==
		bool operator==(const MyListIterator& right) { return iter == right.iter; }
		bool operator!=(const MyListIterator& right) { return iter != right.iter; }

		//+的重载

		MyListIterator operator+(const int& index) {
			MyListIterator temp{ iter + index };
			return temp;
		}

		//-的重载
		size_t operator-(const MyListIterator& right) {
			size_t temp = this->iter - right.iter;
			return temp;
		}
	};

	//返回指向第一个元素的迭代器
	MyListIterator begin() {
		return MyListIterator(_FirstNode);
	}

	//返回指向最后一个元素的迭代器
	MyListIterator end() {
		return MyListIterator(_TailNode);
	}












	/*void push_front(const T& value)：在链表头部插入一个元素value。
void push_front(T&& value)：在链表头部插入一个移动的元素。
void push_back(const T& value)：在链表尾部插入一个元素value。
void push_back(T&& value)：在链表尾部插入一个移动的元素。
void pop_front()：删除链表头部的元素。
void pop_back()：删除链表尾部的元素。
void remove(const T& value)：删除链表中所有值为value的元素。
void sort()：对链表元素进行排序。
void reverse() noexcept：反转链表中元素的顺序
bool empty() const noexcept：判断链表是否为空。
size_type size() const noexcept：返回链表中元素的个数。
size_type max_size() const noexcept：返回链表可容纳的最大元素个数。

*/





};

