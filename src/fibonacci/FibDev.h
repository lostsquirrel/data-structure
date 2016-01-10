/*#include <inttypes.h>*/

//计算Fibonacci数列的第n项（迭代版）：O(n)
long long fibI(int n) {
	//初始化：fib(-1)、fib(0)
	long long f = 1, g = 0;
	//依据原始定义，通过n次加法和减法计算fib(n)
	while (0 < n--) {
		g += f;
		f = g - f;
	}
	return g; //返回
}
//计算Fibonacci数列的第n项（二分递归版）：O(2^n)
long long fib(int n) {
	//若到达递归基，直接取值
	//否则，递归计算前两项，其和即为正解
	return (2 > n) ? (long long ) n : fib(n - 1) + fib(n - 2);
}
//计算Fibonacci数列第n项（线性递归版）：入口形式fib(n, prev)
long long fib(int n, long long& prev ) {
	//若到达递归基，则
		if ( 0 == n ) {
			//直接取值：fib(-1) = 1, fib(0) = 0
			prev = 1; return 0;
		} else {
			//否则//递归计算前两项
			long long prevPrev;
			prev = fib (n - 1, prevPrev);
			//其和即为正解
			return prevPrev + prev;
		}
	}
//用辅助变量记录前一项，返回数列的当前项，O(n)
