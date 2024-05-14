#pragma once
#define PRINT_INFO
using namespace std;
/*
	list()��Ĭ�Ϲ��캯��������һ��������
	list(size_type n, const T& value = T())������һ������n��Ԫ�ص�����Ԫ��ֵΪvalue��
	list(InputIterator first, InputIterator last)������һ������Ԫ��Ϊ[first, last)��Χ�ڵ�Ԫ�ء�
	list(const list& other)���������캯����
	list(list&& other)���ƶ����캯����
	list(std::initializer_list<T> il)���ó�ʼ���б�������
	��������
	~list()����������������Ԫ�ء�
	��ֵ����
	list& operator=(const list& other)��������ֵ��������
	list& operator=(list&& other)���ƶ���ֵ��������
	list& operator=(std::initializer_list<T> il)����ֵ��ʼ���б��е�Ԫ�ء�
	*/
	/*
	������
iterator begin() noexcept������ָ���һ��Ԫ�صĵ�������
const_iterator begin() const noexcept������ָ���һ��Ԫ�صĳ�����������
iterator end() noexcept������ָ������ĩβ�ĵ���������ָ����ЧԪ�أ���
const_iterator end() const noexcept������ָ������ĩβ�ĳ�����������
reverse_iterator rbegin() noexcept������ָ���������һ��Ԫ�صķ����������
const_reverse_iterator rbegin() const noexcept������ָ���������һ��Ԫ�صĳ��������������
reverse_iterator rend() noexcept������ָ�������һ��Ԫ��֮ǰλ�õķ����������
const_reverse_iterator rend() const noexcept������ָ�������һ��Ԫ��֮ǰλ�õĳ��������������
����
bool empty() const noexcept���ж������Ƿ�Ϊ�ա�
size_type size() const noexcept������������Ԫ�صĸ�����
size_type max_size() const noexcept��������������ɵ����Ԫ�ظ�����
Ԫ�ط���
reference front()�����������һ��Ԫ�ص����á�
const_reference front() const�����������һ��Ԫ�صĳ������á�
reference back()�������������һ��Ԫ�ص����á�
const_reference back() const�������������һ��Ԫ�صĳ������á�
�޸���
void assign(size_type n, const T& value)��������ֵΪn��valueԪ�ء�
template <class InputIterator> void assign(InputIterator first, InputIterator last)��������ֵΪ[first, last)��Χ�ڵ�Ԫ�ء�
void assign(std::initializer_list<T> il)��������ֵΪ��ʼ���б��е�Ԫ�ء�
void push_front(const T& value)��������ͷ������һ��Ԫ��value��
void push_front(T&& value)��������ͷ������һ���ƶ���Ԫ�ء�
void push_back(const T& value)��������β������һ��Ԫ��value��
void push_back(T&& value)��������β������һ���ƶ���Ԫ�ء�
void pop_front()��ɾ������ͷ����Ԫ�ء�
void pop_back()��ɾ������β����Ԫ�ء�
iterator insert(const_iterator position, const T& value)����positionλ�ò���һ��Ԫ��value��
iterator insert(const_iterator position, T&& value)����positionλ�ò���һ���ƶ���Ԫ�ء�
iterator insert(const_iterator position, size_type n, const T& value)����positionλ�ò���n��Ԫ��value��
template <class InputIterator> iterator insert(const_iterator position, InputIterator first, InputIterator last)����positionλ�ò���[first, last)��Χ�ڵ�Ԫ�ء�
iterator insert(const_iterator position, std::initializer_list<T> il)����positionλ�ò����ʼ���б��е�Ԫ�ء�
iterator erase(const_iterator position)��ɾ��positionλ�õ�Ԫ�ء�
iterator erase(const_iterator first, const_iterator last)��ɾ��[first, last)��Χ�ڵ�Ԫ�ء�
void swap(list& other)������������������ݡ�
void resize(size_type n)���������С����Ϊn�����´�С���ڵ�ǰ��С�������ֵ��ʼ����Ԫ�ء�
void resize(size_type n, const T& value)���������С����Ϊn�����´�С���ڵ�ǰ��С�������valueֵ��Ԫ�ء�
void clear() noexcept���������
����
void splice(const_iterator position, list& other)����other����������Ԫ���ƶ���this�����positionλ�á�
void splice(const_iterator position, list& other, const_iterator i)����other�����е�iλ�õ�Ԫ���ƶ���this�����positionλ�á�
void splice(const_iterator position, list& other, const_iterator first, const_iterator last)����other������[first, last)��Χ�ڵ�Ԫ���ƶ���this�����positionλ�á�
void remove(const T& value)��ɾ������������ֵΪvalue��Ԫ�ء�
template <class Predicate> void remove_if(Predicate pred)��ɾ����������������ν��pred��Ԫ�ء�
void unique()��ɾ�����������ڵ��ظ�Ԫ�ء�
template <class BinaryPredicate> void unique(BinaryPredicate binary_pred)��ɾ�����������ڵ��ظ�Ԫ�أ���binary_pred�ж�����Ԫ���Ƿ���ȡ�
void merge(list& other)����other����ϲ���this�����У�Ҫ������������
template <class Compare> void merge(list& other, Compare comp)����other����ϲ���this�����У���comp��������
void sort()��������Ԫ�ؽ�������
template <class Compare> void sort(Compare comp)����comp������Ԫ�ؽ�������
void reverse() noexcept����ת������Ԫ�ص�˳��*/

template<typename T>
class MyList
{

private:
	//��������Ľڵ�ṹ
	struct Node {
		T* _myval = nullptr;			//������
		Node* _pre = nullptr;			//ָ��ǰһ������ָ��
		Node* _next = nullptr;		//ָ���һ������ָ��
		Node() {};
		Node(const T& value) {
			_myval = static_cast<T*>(::operator new(sizeof(T)));
			_myval[0] = value;
		}
	};

	Node* _FirstNode;		//˫�����ͷ���
	Node* _TailNode;		//˫�����β���
	size_t _size;			//�����ŵ����ݵĸ���

public:

	//���캯��
	
	//Ĭ�Ϲ��캯��
	MyList():_FirstNode(nullptr),_TailNode(nullptr),_size(0){};

	//��ʼ���б���
	MyList(std::initializer_list<T> inil) {
		for (const T& value : inil)push_back(value);
	}




	//������β������һ��Ԫ��value
	void push_back(const T& value) {
		Node* new_node = new Node{value};
		//�������Ϊ�գ�����г�ʼ����
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

	//������ͷ������һ��Ԫ��value
	void push_head(const T& value) {
		Node* new_node = new Node{ value };
		//�������Ϊ�գ�����г�ʼ����
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
		//���캯��
		MyListIterator(T* m) :iter(m){};
		
		//������
		T& operator*() {
			return *iter;
		}

		//ǰ++
		MyListIterator& operator++() {
			++iter;
			return *this;
		}

		//��++
		MyListIterator operator++(int) {
			MyListIterator temp{ iter };
			++iter;
			return temp;
		}

		//���أ�= ��==
		bool operator==(const MyListIterator& right) { return iter == right.iter; }
		bool operator!=(const MyListIterator& right) { return iter != right.iter; }

		//+������

		MyListIterator operator+(const int& index) {
			MyListIterator temp{ iter + index };
			return temp;
		}

		//-������
		size_t operator-(const MyListIterator& right) {
			size_t temp = this->iter - right.iter;
			return temp;
		}
	};

	//����ָ���һ��Ԫ�صĵ�����
	MyListIterator begin() {
		return MyListIterator(_FirstNode);
	}

	//����ָ�����һ��Ԫ�صĵ�����
	MyListIterator end() {
		return MyListIterator(_TailNode);
	}












	/*void push_front(const T& value)��������ͷ������һ��Ԫ��value��
void push_front(T&& value)��������ͷ������һ���ƶ���Ԫ�ء�
void push_back(const T& value)��������β������һ��Ԫ��value��
void push_back(T&& value)��������β������һ���ƶ���Ԫ�ء�
void pop_front()��ɾ������ͷ����Ԫ�ء�
void pop_back()��ɾ������β����Ԫ�ء�
void remove(const T& value)��ɾ������������ֵΪvalue��Ԫ�ء�
void sort()��������Ԫ�ؽ�������
void reverse() noexcept����ת������Ԫ�ص�˳��
bool empty() const noexcept���ж������Ƿ�Ϊ�ա�
size_type size() const noexcept������������Ԫ�صĸ�����
size_type max_size() const noexcept��������������ɵ����Ԫ�ظ�����

*/





};

