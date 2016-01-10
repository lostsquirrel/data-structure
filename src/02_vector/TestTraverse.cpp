/*
 * TestTraverse.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: lisong
 */

#include <iostream>
#include "Vector.h"
using namespace std;

template <typename T> struct Increase //函数对象：逑增一个T类对象
 { virtual void operator()(T& e) { e++; } }; //假讴T可直接逑增戒已重载++

template <typename T> void increase(Vector<T> & V) //统一逑增向量中癿各元素
{ V.traverse(Increase<T>()); } //以Increase<T>()为基本操作迕行遍历

int main(void) {

	return 0;
}
