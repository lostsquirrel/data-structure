
/*矩阵
 	类型名称： 矩阵（ Matrix）
	数据对象集： 一个MxN的矩阵A<sub(MxN)> = (a<sub(ij)>) (i=1, …, M; j=1, …, N )由MxN个三
	元组< a, i, j >构成，其中
		a是矩阵元素的值(二维数组？一维数组？十字链表？)，
		i是元素所在的行号,
		j是元素所在的列号。
	操作集： 对于任意矩阵A、 B、 C <属于> Matrix，以及整数i、 j、 M、 N
		Matrix Create( int M, int N )：返回一个MxN的空矩阵；
		int GetMaxRow( Matrix A )：返回矩阵A的总行数；
		int GetMaxCol( Matrix A )：返回矩阵A的总列数；
		ElementType GetEntry( Matrix A, int i, int j )：返回矩阵A的第i行、第j列的元素；
		Matrix Add( Matrix A, Matrix B )：如果A和B的行、列数一致，则返回矩阵C=A+B(先按行加？先按列加？什么语言？)，否则返回错误标志；
		Matrix Multiply( Matrix A, Matrix B )：如果A的列数等于B 的行数，则返回矩阵C=AxB(先按行加？先按列加？什么语言？)，否则返回错误标志；
 * */
#include <stdio.h>

typedef int ElementType;

typedef struct m {

} Matrix;
/*返回一个MxN的空矩阵；*/
Matrix Create( int M, int N );
/*返回矩阵A的总行数；*/
int GetMaxRow( Matrix A );
/*返回矩阵A的总列数；*/
int GetMaxCol( Matrix A );
/*返回矩阵A的第i行、第j列的元素；*/
ElementType GetEntry( Matrix A, int i, int j );
/*如果A和B的行、列数一致，则返回矩阵C=A+B(先按行加？先按列加？什么语言？)，否则返回错误标志；*/
Matrix Add( Matrix A, Matrix B );
/*如果A的列数等于B 的行数，则返回矩阵C=AB，否则返回错误标志；*/
Matrix Multiply( Matrix A, Matrix B );

ElementType getEntry(Matrix a, int x, int y);
int main(void) {
	ElementType e = 3;
	printf("%d\n", e);
}
