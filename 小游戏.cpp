#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<WinBase.h>

time_t timep;
unsigned abc;
#define abc = time(&timep);
int P1A;
int P2A;
int P1D;
int P2D;
int P1HP;
int P2HP;
double P1S;
double P2S;
int P1M;
int P2M;
int P1C;
int P2C;
#define srand(abc);

int al(int x) {/*roll攻击和护甲*/
	int a;
	a = (rand() % (x + 2)) + x + 1;
	return a;
}

int bl(int x) {//判断闪避和暴击
	int arry[10] = { 0 };
	for (int a = 0; a < x; a++) {
		arry[a] = 1;
	}
	int a = rand() % 10;
	if (arry[a] == 1)
		return 1;
	else if (arry[a] == 0)
		return 0;
}

void P1(int p, int h, double s, double l) {//输入p1加点
	int a;
	a = p + h + s + l;
	if (a >= 14) {
		printf("输入错误，超过上限，请重新输入\n");
		scanf_s("%d %d %lf %lf", &p, &h, &s, &l);
		P1(p,h,s,l);
	}
	P1A = p + 2;
	P1D = h + 2;
	P1HP = (h + 1) * 10 + 500;
	P1S = (1 - (s + 1) / 10) * 2;
	(int)P1M =  s + 1;
	P1C = l + 1;

}

void P2(int p, int h, double s, double l) {//输入p2加点
	int a;
	a = p + h + s + l;
	if (a >= 14) {
		printf("输入错误，超过上限，请重新输入\n");
		scanf_s("%d %d %lf %lf", &p, &h, &s, &l);
		P2(p,h,s,l);
	}
	P2A = p + 2;
	P2D = h + 2;
	P2HP = (h + 1) * 10 + 500;
	P2S = (1 - (s + 1) / 10) * 2;
	(int)P2M = s + 1;
	P2C = l + 1;

}

void jewelP1(int x) {
	if (x != 1 && x != 2 && x != 3 && x != 4) {
		printf("输入错误，请重新输入\n");
		scanf_s("%d", &x);
		jewelP1(x);
	}
	switch (x) {
	case'1':
		P1A += 5;
		break;
	case'2':
		P1D += 5;
		P1HP += 50;
		break;
	case'3':
		P1S = (1 - (10 - P1S * 5) / 10) * 2;
		break;
	case'4':
		P1C += 5;
		break;
	
	}
}

void jewelP2(int x) {
	if (x != 1 && x != 2 && x != 3 && x != 4) {
		printf("输入错误，请重新输入\n");
		scanf_s("%d", &x);
		jewelP2(x);
	}
	switch (x) {
	case'1':
		P2A += 5;
		break;
	case'2':
		P2D += 5;
		P2HP += 50;
		break;
	case'3':
		P2S = (1 - (10 - P2S * 5) / 10) * 2;
		break;
	case'4':
		P2C += 5;
		break;
	}
}

void turn(double x, double y) {
	int s;
	int k=0;
	int g=0;
	if (x <= y) {
	b:Sleep(x * 1000);
		k = 0;
		g = 0;
		s = bl(P2M);
		if (s == 1) {
			printf("P2闪避成功\n");
			goto a;
		}
		s = bl(P1C);
		if (s == 1) {
			printf("P1出现暴击\n");
			k = al(P1A)*2.25;
			g = al(P2D);
			if (k <= g) {
				printf("P1攻击未能破甲\n");
			}
			else if (k > g) {
				P2HP = P2HP - (k - g);
				printf("P1对P2造成了%d点伤害，现在P2HP为%d\n", k - g, P2HP);
			}
		}
		else if (s != 1) {
			k = al(P1A);
			g = al(P2D);
			if (k <= g) {
				printf("P1攻击未能破甲\n");
			}
			else if (k > g) {
				P2HP = P2HP - (k - g);
				printf("P1对P2造成了%d点伤害，现在P2HP为%d\n", k - g, P2HP);
			}
		}
	a:Sleep((y - x) * 1000);
		k = 0;
		g = 0;
		s = bl(P1M);
		if (s == 1) {
			printf("P1闪避成功\n");
			goto b;
		}
		s = bl(P2C);
		if (s == 1) {
			printf("P2出现暴击\n");
			k = al(P2A)*2.25;
			g = al(P1D);
			if (k <= g) {
				printf("P2攻击未能破甲\n");
			}
			else if (k > g) {
				P1HP = P1HP - (k - g);
				printf("P2对P1造成了%d点伤害，现在P2HP为%d\n", k - g, P1HP);
			}
		}
		else if (s != 1) {
			k = al(P2A);
			g = al(P1D);
			if (k <= g) {
				printf("P2攻击未能破甲\n");
			}
			else if (k > g) {
				P1HP = P1HP - (k - g);
				printf("P2对P1造成了%d点伤害，现在P2HP为%d\n", k - g, P1HP);
			}
		}
		
	}
	
	if (x > y) {
		d:Sleep(y * 1000);
			k = 0;
			g = 0;
			s = bl(P1M);
			if (s == 1) {
				printf("P1闪避成功\n");
				goto c;
			}
			s = bl(P2C);
			if (s == 1) {
				printf("P2出现暴击\n");
				k = al(P2A)*2.25;
				g = al(P1D);
				if (k <= g) {
					printf("P2攻击未能破甲");
				}
				else if (k > g) {
					P1HP = P1HP - (k - g);
					printf("P2对P1造成了%d点伤害，现在P2HP为%d\n", k - g, P1HP);
				}
			}
			else if (s != 1) {
				k = al(P2A);
				g = al(P1D);
				if (k <= g) {
					printf("P2攻击未能破甲");
				}
				else if (k > g) {
					P1HP = P1HP - (k - g);
					printf("P2对P1造成了%d点伤害，现在P2HP为%d\n", k - g, P1HP);
				}
			}
		c:Sleep((x - y) * 1000);
			k = 0;
			g = 0;
			s = bl(P2M);
			if (s == 1) {
				printf("P2闪避成功\n");
				goto d;
			}
			s = bl(P1C);
			if (s == 1) {
				printf("P1出现暴击\n");
				k = al(P1A)*2.25;
				g = al(P2D);
				if (k <= g) {
					printf("P1攻击未能破甲");
				}
				else if (k > g) {
					P2HP = P2HP - (k - g);
					printf("P1对P2造成了%d点伤害，现在P2HP为%d\n", k - g, P2HP);
				}

			}
			else if (s != 1) {
				k = al(P1A);
				g = al(P2D);
				if (k <= g) {
					printf("P1攻击未能破甲");
				}
				else if (k > g) {
					P2HP = P2HP - (k - g);
					printf("P1对P2造成了%d点伤害，现在P2HP为%d\n", k - g, P2HP);
				}

			}
		}
	

	}


int main() {
	int a;
	int b, c, v, j, s, g;
    double d,f;
	printf("智障互A V0.001\n");
	printf("请输入1开始游戏,输入别的任意键退出游戏\n");
	scanf_s("%d", &a);
	if (a != 1)
		return 0;
	printf("请P1设置加点\n");
	printf("力量：1\n体质：1\n敏捷：1\n幸运：1\n(所有属性初始默认为1，有10点自由属性点，力量影响攻击，体质影响hp和护甲，敏捷影响攻速和闪避，幸运影响暴击率\n");
	scanf_s("%d %d %lf %lf", &b, &c, &d, &f);
	P1(b, c, d, f);
	printf("请P2设置加点\n");
	printf("力量：1\n体质：1\n敏捷：1\n幸运：1\n(所有属性初始默认为1，有10点自由属性点，力量影响攻击，体质影响hp和护甲，敏捷影响攻速和闪避，幸运影响暴击率\n");
	scanf_s("%d %d %lf %lf", &b, &c, &d, &f);
	P2(b, c, d, f);
	printf("请P1选择武器或者铠甲\n1、武器  2、铠甲（武器和铠甲都各自加10点攻击或者护甲，都有三个孔打宝石）\n");
	scanf_s("%d",&s);
	if (s == 1) {
		P1A += 10;
	}
	else if (s == 2) {
		P1D += 10;
	}
	else if (s != 1 && s != 2) {
		P1A += 10;
		P1D += 10;
	}
	printf("请P2选择武器或者铠甲\n1、武器  2、铠甲（武器和铠甲都各自加10点攻击或者护甲，都有三个孔打宝石）\n");
	scanf_s("%d", &g);
	if (g == 1) {
		P2A += 10;
	}
	else if (g == 2) {
		P2D += 10;
	}
	else if (g != 1 && g != 2) {
		P2A += 10;
		P2D += 10;
	}
	printf("请P1选择宝石：1、力量宝石 2、体质宝石 3、攻速宝石 4、幸运宝石（宝石加值均为5） \n");
	scanf_s("%d", &c);
	jewelP1(c);
	scanf_s("%d", &v);
	jewelP1(v);
	scanf_s("%d", &j);
	jewelP1(j);
	printf("请P2选择宝石：1、力量宝石 2、体质宝石 3、攻速宝石 4、幸运宝石（宝石加值均为5） \n");
	scanf_s("%d", &c);
	jewelP1(c);
	scanf_s("%d", &v);
	jewelP1(v);
	scanf_s("%d", &j);
	jewelP1(j);
	printf("准备结束，显示P1、P2现在的属性\n");
	printf("P1:\n HP:%d\n 攻击：%d-%d\n 护甲：%d-%d\n 攻速：%lf\n 闪避率：%d0%%\n 暴击率：%d0%%\n",P1HP,P1A, P1A + 2, P1D, P1D + 2, P1S, P1M, P1C);
	printf("P2:\n HP:%d\n 攻击：%d-%d\n 护甲：%d-%d\n 攻速：%lf\n 闪避率：%d0%%\n 暴击率：%d0%%\n",P2HP,P2A, P2A + 2, P2D, P2D + 2, P2S, P2M, P2C);
	system("pause");
	for (; P1HP > 0 && P2HP > 0;) {
		turn(P1S, P2S);
	
	}
	if (P1HP <= 0) {
		printf("P2获胜\n");
}
	else if (P2HP <= 0) {
		printf("P1获胜\n");

	}
	printf("请输入任意键结束游戏\n");
	system("pause");
	return 0;
}
 
