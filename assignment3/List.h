
/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
///
/// @see 
///
class ListNode
{
public:
	ListNode() : _next(NULL), _prev(NULL) { }
	ListNode(int data) : _data(data), _next(NULL), _prev(NULL) { }

	int &data() { return _data; }

	const int data() const { return _data; }

protected:
	int _data; 
	ListNode *_next, *_prev; 

	friend class CPPList; 

}; // class ListNode�ඨ�����.


/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
///
/// @see 
///
class CPPList
{
public:
	// CPPList�๹�캯��.
	CPPList() : _head(NULL), _tail(NULL), _size(0) { }
	CPPList(const CPPList &rhs); 
	CPPList &operator=(const CPPList &rhs); 


	// CPPList����������
	~CPPList(); 

	// CPPList��ӿ�.
public:
	// �б��Ƿ�Ϊ��
	bool is_empty() const { return _head == NULL; }

	// �б�Ԫ�ظ���
	int size() const { return _size; }

	// ����list��Ч�ڵ����ʼλ��begin����ֹλ��end
	// ��Щ�ڵ�Ӧ��begin��ʼ����end������������������end����
	// ��˵�listΪ��ʱ������ֵӦ����begin==end
	ListNode *begin() { return _head; }
	ListNode *end() { return NULL; }  
	const ListNode *begin() const { return _head; }
	const ListNode *end() const { return NULL; }  

	// ����current��ȡ��һ���ڵ㣬Ӧ�ж�current��Ч��
	// ��Ч��ֱ�ӷ���NULL
	ListNode *next(const ListNode *current); 
	const ListNode *next(const ListNode *current) const { return const_cast<CPPList *>(this)->next(current);  }; 
	
	// β��׷������
	void append(int); 

	// ��current֮ǰ��Զ���ݣ�Ӧ�ж�current��Ч��
	// ��Ч�����趯��
	void insert(ListNode *current, int); 

	// ɾ��current��ǰ�ڵ㣬Ӧ�ж�current��Ч��
	// ��Ч�����趯��
	void remove(ListNode *current); 

	// �������
	void clear(); 

	// CPPList��˽���ͳ�Ա����.
private:
	///< ������ĳ�Ա��������û�У���ɾ������. 
	ListNode *_head; 
	ListNode *_tail; 
	int _size; 

}; // class CPPList�ඨ�����.