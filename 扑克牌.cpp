#include<Windows.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void z(int x, int y) { //转化函数
	if (x == 0 && y == 0)
		printf("SA ");
	else if (x == 0 && y == 10)
		printf("SJ ");
	else if (x == 0 && y == 11)
		printf("SQ ");
	else if (x == 0 && y == 12)
		printf("SK ");
	else if (x == 1 && y == 0)
		printf("HA ");
	else if (x == 1 && y == 10)
		printf("HJ ");
	else if (x == 1 && y == 11)
		printf("HQ ");
	else if (x == 1 && y == 12)
		printf("HK ");
	else if (x == 2 && y == 0)
		printf("DA ");
	else if (x == 2 && y == 10)
		printf("DJ ");
	else if (x == 2 && y == 11)
		printf("DQ ");
	else if (x == 2 && y == 12)
		printf("DK ");
	else if (x == 3 && y == 0)
		printf("CA ");
	else if (x == 3 && y == 10)
		printf("CJ ");
	else if (x == 3 && y == 11)
		printf("CQ ");
	else if (x == 3 && y == 12)
		printf("CK ");
	else if (x == 0 && y != 10 && y != 11 && y != 12)
		printf("S%d ",y+1);
	else if (x == 1 && y != 10 && y != 11 && y != 12)
		printf("H%d ",y+1);
	else if (x == 2 && y != 10 && y != 11 && y != 12)
		printf("D%d ",y+1);
	else if (x == 3 && y != 10 && y != 11 && y != 12)
		printf("C%d ",y+1);
}//转换输出函数

void fa() {
	time_t t;
	int a;
	int b=0;
	a=time(&t);
	srand(a);
	int i = 0;
	int j = 0;
	static int arry[4][13] = { { 1,2,3,4,5,6,7,8,9,10,11,12,13 },{ 1,2,3,4,5,6,7,8,9,10,11,12,13 }, { 1,2,3,4,5,6,7,8,9,10,11,12,13 }, { 1,2,3,4,5,6,7,8,9,10,11,12,13 } };
	for (; b < 13 ; ) {
		
		i = rand() % 4;
		j = rand() % 13;
		if (arry[i][j] == 0) {
			continue;
		}
		b++;
		z(i, j);
		arry[i][j] = 0;
	
	}
}

int main() {
	printf("第一个人的牌：\n");
	fa();
	printf("\n");
	printf("第二个人的牌：\n");
	fa();
	printf("\n");
	printf("第三个人的牌：\n");
	fa();
	printf("\n");
	printf("第四个人的牌：\n");
	fa();
	printf("\n");
	system("pause");
	return 0;
}