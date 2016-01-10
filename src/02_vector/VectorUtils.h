#include <iostream>
#include "Vector.h"

//随机置乱向量，使各元素等概率出现亍殏一位置
template<typename T> void permute(Vector<T>& V);

//less than
template<typename T> static bool lt(T* a, T* b) {
	std::cout << "with * " << a << std::endl;
	return lt(*a, *b);
}
//less than
template<typename T> static bool lt(T& a, T& b) {
	std::cout << "with & " << a << std::endl;
	return a < b;
}
//equal
template<typename T> static bool eq(T* a, T* b) {
	std::cout << "with * " << a << std::endl;
	return eq(*a, *b);
}
//equal
template<typename T> static bool eq(T& a, T& b) {
	std::cout << "with & " << a << std::endl;
	return a == b;
}
