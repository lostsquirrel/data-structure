#include <stdio.h>
#include <math.h>

int char2int(int c) {
	switch(c) {
		case '0':
		return 0;
		case '1':
		return 1;
		
		case '2':
		return 2;
		
		case '3':
		return 3;
		
		case '4':
		return 4;
		
		case '5':
		return 5;
		
		case '6':
		return 6;
		
		case '7':
		return 7;
		
		case '8':
		return 8;
		
		case '9':
		return 9;

		case ' ':
		return  -1;

		case '-':
		return  -2;

		case '\n':
		return -3;
	}
	return -9;
}

int max_subsqu_sum_4(int a[], int n) {
	int i;
	int sum = 0;
	int max_sum = 0;
	for (i = 0; i < n; ++i) {
		sum += a[i];
	
		if (sum > max_sum) {
			max_sum  = sum;
		} else if (sum < 0) {
			sum = 0;
		}
	}
	return max_sum;
}


int main( ) {
	/*
	int i, c;
	int line = 0;
	
	int a[10];
	for (i = 0; i < 10; ++i) {
		a[i] = -1;
	}
	int index_a = 0;

	int b[720000];
	for (i = 0; i < 720000; ++i) {
		b[i] = -1;
	}
	int index_b = 0;
	// printf( "Enter a value :");
	while((c = getchar( )) != EOF ) {
		// printf("line:%d\n", line);
		
		if (c == '\n') {
			line++;
			if (line > 1) {
				break;
			}
		} else {
			if (line == 0) {
				a[index_a] = c;
				index_a++;
			} else if (line == 1) {
				b[index_b] = c;
				index_b++;
			}
		}
	}

	int x;
	int t = 0;
	int n = 0;
	for(x = 10 - 1; x >= 0; x--) {
		if (char2int(a[x]) < 0) {
			//去掉不连续数字
			n = 0;
			t = 0;
		}

		if (char2int(a[x]) > 0) {
			// printf("%c, %d, %d\n", a[x], t, n);
			n += char2int(a[x]) * pow(10, t);
			t++;
		}
	}

	// printf( "You entered: %d \n", n);

	int res[n];
	for (x = 0; i< 6; x++) {
		res[x] = -1;
	}
	int temp[6];
	for (x = 0; i< 6; x++) {
		temp[x] = -1;
	}
	int m;
	int r;
	t = 0;
	int tag = 1;
	int index = 0;
	int out = 0;
	for (x = 0; x < 720000; x++) {
		int y = char2int(b[x]);
		// printf("y = %d\n", y);
		if(y >= 0) {
			temp[t] = y;
			// printf("temp[%d] = %d\n", t, y);
			t++;

		} else if (y == -2) {
			tag = -1;
		} else if((y == -1 ) || (y == -9 && out == 0)){  //空格 换行
			if(t > 0) {
				m = 0;
				r = 0;
				while(t > r) {
					// printf("m = %d\n", m);
					m += temp[t - 1 - r] * pow(10, r);
					// printf("\\pow(10, %d) = %f\n", r, pow(10, r));
					// printf("t=%d, r=%d, e=%d, m=%d\n",t, r, temp[t - r - 1], m);
					r++;
					temp[t] =  -1;
				}
				if (m != 0) {
					res[index] = m * tag;
					index++;
					tag = 1;
				}
			}
			if (y == -9) {
				out++;
			}
			t = 0;
		} else if (y == -9) {
			break;
		}
	}
*/
	// 准备数据 n, res[]
	int i, n, a[100000];  
	
	scanf("%d", &n);  
	for(i=0; i<n; i++)   {  
		scanf("%d", &a[i]);  
	}  
	printf("%d\n", max_subsqu_sum_4(a, n));
	return 0;
}