// 二分查找算法（版本B）：在有序向量的区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size
template<typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
	while (1 < hi - lo) { //每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
		Rank mi = (lo + hi) >> 1; //以中点为轴点
		(e < A[mi]) ? hi = mi : lo = mi; //经比较后确定深入[lo, mi)或[mi, hi)
	} //出口时hi = lo + 1，查找区间仅含一个元素A[lo]
	return (e == A[lo]) ? lo : -1; //查找成功时返回对应的秩；否则统一返回-1
} //有多个命中元素时，不能保证返回秩最大者；查找失败时，简单地返回-1，而不能指示失败的位置
