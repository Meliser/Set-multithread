#pragma once
#ifndef _NODE_H_
#define _NODE_H_
#include<iostream>
using std::cout;
using std::endl;
template<typename T>
class Node {
	Node* left;
	Node* right;
	T data;
public:
	Node(Node* _left = nullptr, Node* _right = nullptr, T _data = T()) :
		left(_left), right(_right), data(_data) {
		//cout << "Node()" << endl;
	}
	/*~Node()
	{
		cout << "~Node()"<<endl;
	}*/
	//const
	Node* get_left() const {
		return left;
	}
	Node* get_right() const {
		return right;
	}
	const T& get_data() const {
		return data;
	}
	//const
	void set_left(Node* _left) {
		left = _left;
	}
	void set_right(Node* _right) {
		right = _right;
	}
};
#endif