#include <cstdlib>
#include "VectorUtils.h"

//随机置乱向量，使各元素等概率出现亍殏一位置
template<typename T> void permute(Vector<T>& V) {
	//自后向前
	for (int i = V.size(); i > 0; i--) {
		//V[i - 1]不V[0, i)中某一随机元素交换
		swap(V[i - 1], V[rand() % i]);
	}
}
