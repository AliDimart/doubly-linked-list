#pragma once

#include "DLList.h"

template<typename T>
class Deque {
public:
	// Класс двусторонней очереди 
	Deque() = default;
	~Deque() = default;
	void push_back(const T value);
	void push_front(const T value);
	T pop_back();
	T pop_front();

private:
	DLList<T> lst;
};

template<typename T>
void Deque<T>::push_back(const T value) {
	lst.push_back(value);
}

template<typename T>
void Deque<T>::push_front(const T value) {
	lst.push_front(value);
}

template<typename T>
T Deque<T>::pop_back() {
	T temp = lst[lst.GetSize() - 1];
	lst.pop_back();
	return temp;
}

template<typename T>
T Deque<T>::pop_front() {
	T temp = lst[0];
	lst.pop_front();
	return temp;
}
