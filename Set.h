#pragma once
#ifndef _SET_H_
#define _SET_H_
#include "Node.h"
#include <thread>
#include "Timer.h"
template<typename T>
class Set {
public:
	Set() :root(nullptr) {};
	~Set();
	void insert(const T &data);
private:
	Node<T>* root;
	void whereToInsert(const T &_data);
	void clear(Node<T>* current);
};

template<typename T>
Set<T>::~Set()
{
	if (!root) {
		return;
	}
#ifdef MULTI
	thread th(&Set<T>::clear, this, root->get_right());
	root->set_right(nullptr);
#endif
	clear(root);
	root = nullptr;
#ifdef MULTI
	th.join();
#endif
}

template<typename T>
void Set<T>::insert(const T &data) {
	if (root == nullptr) {
		root = new Node<T>(nullptr, nullptr, data);
		return;
	}
	whereToInsert(data);
}

template<typename T>
void Set<T>::whereToInsert(const T &_data) {
	Node<T> *current = root;
	while (true)
	{
		if (_data == current->get_data()) {
			return;
		}
		if (_data < current->get_data()) {
			if (current->get_left() == nullptr) {
				current->set_left(new Node<T>(nullptr, nullptr, _data));
				return;
			}
			else {
				current = current->get_left();
			}
		}
		if (_data > current->get_data()) {
			if (current->get_right() == nullptr) {
				current->set_right(new Node<T>(nullptr, nullptr, _data));
				return;
			}
			else {
				current = current->get_right();
			}
		}
	}
}

template<typename T>
void Set<T>::clear(Node<T>* current) {

	if (current->get_left()) {
		clear(current->get_left());
		current->set_left(nullptr);
	}
	if (current->get_right()) {
		clear(current->get_right());
		current->set_right(nullptr);
	}
	if (!(current->get_left()) and !(current->get_right())) {
		cout << "Node deleted with " << current->get_data() << " thread " << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(50));
		delete current;
		return;
	}
}

#endif
