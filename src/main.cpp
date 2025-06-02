#include <iostream>

template<typename T>
class DLList {
public:

	DLList();
	~DLList();
	void pop_front();
	void pop_back();
	void push_front(T data);
	void push_back(T data);
	void insert(T data, const int index);
	void remove(const int index);
	int GetSize() const { return size; }
	void Print();
	void InversePrint();
	void clear();
	T& operator[](const int index);

private:
	class Node {
	public:

		Node(T data = T(), Node* ptrNext = nullptr, Node* ptrPrev = nullptr) {
			this->data = data;
			this->ptrNext = ptrNext;
			this->ptrPrev = ptrPrev;
		}

		~Node() = default;

		Node* ptrNext; 
		Node* ptrPrev;
		T data;
	};

	Node* GetNode(const int index);

	int size;
	Node* head;
	Node* tail;
};

template<typename T>
DLList<T>::DLList() {
	// Создаём пустой список 
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
void DLList<T>::push_front(T data) {
	// Добавляем элемент в начало 
	head = new Node(data, head);

	if (head->ptrNext != nullptr) { // Если это не первый элемент, то второму элементу нужно поменять указатель на предыдущий элемент 
		head->ptrNext->ptrPrev = head;
	}
	if (tail == nullptr) tail = head; // Если это первый элемент, то конец и начало совпадают 
	size++;
}

template<typename T>
void DLList<T>::Print() {
	// Выводим все элементы начиная с головы 
	Node* currunt = head;
	while (currunt != nullptr) {
		std::cout << currunt->data << '\t';
		currunt = currunt->ptrNext;
	}
	std::cout << std::endl;
}

template<typename T>
void DLList<T>::InversePrint() {
	// Выводим все элементы начиная с конца  
	Node* currunt = tail;
	while (currunt != nullptr) {
		std::cout << currunt->data << '\t';
		currunt = currunt->ptrPrev;
	}
	std::cout << std::endl;
}

template<typename T>
void DLList<T>::push_back(T data) {
	// Добавляем элемент в конец 
	tail = new Node(data, nullptr, tail);

	if (tail->ptrPrev != nullptr) { // Если элемент не единственный, то нужно предпоследнему элементу поменять указатель на следующий элемент на конец списка 
		tail->ptrPrev->ptrNext = tail;
	}
	if (head == nullptr) head = tail; // Если это первый элемент, то конец и начало совпадают 
	size++;
}

template<typename T>
void DLList<T>::pop_front() {
	// Удаляем элемент из начала 
	if (head == nullptr) return;
	Node* temp = head->ptrNext;
	delete head;
	// Следующий элемент становится началом, его указатель на предыдущий элемент обнуляется 
	head = temp;
	head->ptrPrev = nullptr;
	size--;
}

template<typename T>
void DLList<T>::pop_back() {
	// Удаляем элемент из конца  
	if (tail == nullptr) return;
	Node* temp = tail->ptrPrev;
	delete tail;
	// Следующий элемент становится началом, его указатель на предыдущий элемент обнуляется 
	tail = temp;
	tail->ptrNext = nullptr;
	size--;
}

template<typename T>
void DLList<T>::clear() {
	// Полностью очищаем список  
	while (size) {
		pop_front();
	}
}

template<typename T>
typename DLList<T>::Node* DLList<T>::GetNode(const int index) {

	if (index < 0 || index >= size) throw std::exception("Index out of range");

	if (index < size / 2) { // Если элемент ближе к началу, то начинаем искать с начала 

		Node* current = head; int currentIndex = 0;

		while (currentIndex != index) {

			current = current->ptrNext;
			currentIndex++;
		}
		return current;
	}
	else { // Если элемент во второй половине, то начинаем искать с конца 
		Node* current = tail; int currentIndex = size-1;

		while (currentIndex != index) {

			current = current->ptrPrev;
			currentIndex--;
		}
		return current;
	}
}

template<typename T>
T& DLList<T>::operator[](const int index) {
	return GetNode(index)->data;
}

template<typename T>
void DLList<T>::insert(T data, const int index) {

	if (index < 0 || index > size) throw std::exception("Index out of range");

	if (index == 0) push_front(data);
	else if (index == size) push_back(data);
	else {
		Node* current = GetNode(index - 1);
		current->ptrNext = new Node(data, current->ptrNext, current);
		current->ptrNext->ptrNext->ptrPrev = current->ptrNext;
		size++;
	}
}

template<typename T>
void DLList<T>::remove(const int index) {
	if (index < 0 || index >= size) throw std::exception("Index out of range");

	if (index == 0) pop_front();
	else if (index == size - 1) pop_back();
	else {
		Node* current = GetNode(index - 1);
		Node* toDelete = current->ptrNext;

		current->ptrNext = toDelete->ptrNext;
		toDelete->ptrNext->ptrPrev = current;
		delete toDelete;
		size--;
	}
}

template<typename T>
DLList<T>::~DLList() {
	clear();
}

int main()
{
	DLList<int> lst;

	lst.push_back(17);
	lst.push_back(10);
	lst.push_back(9);

	lst.Print();

	int a = 3;
	lst.insert(7, a);

	lst.Print();
	lst.InversePrint();

	lst.remove(a);

	lst.Print();
	lst.InversePrint();

	return 0;
}
