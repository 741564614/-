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

int al(int x) {/*roll�����ͻ���*/
	int a;
	a = (rand() % (x + 2)) + x + 1;
	return a;
}

int bl(int x) {//�ж����ܺͱ���
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

void P1(int p, int h, double s, double l) {//����p1�ӵ�
	int a;
	a = p + h + s + l;
	if (a >= 14) {
		printf("������󣬳������ޣ�����������\n");
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

void P2(int p, int h, double s, double l) {//����p2�ӵ�
	int a;
	a = p + h + s + l;
	if (a >= 14) {
		printf("������󣬳������ޣ�����������\n");
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
		printf("�����������������\n");
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
		printf("�����������������\n");
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
			printf("P2���ܳɹ�\n");
			goto a;
		}
		s = bl(P1C);
		if (s == 1) {
			printf("P1���ֱ���\n");
			k = al(P1A)*2.25;
			g = al(P2D);
			if (k <= g) {
				printf("P1����δ���Ƽ�\n");
			}
			else if (k > g) {
				P2HP = P2HP - (k - g);
				printf("P1��P2�����%d���˺�������P2HPΪ%d\n", k - g, P2HP);
			}
		}
		else if (s != 1) {
			k = al(P1A);
			g = al(P2D);
			if (k <= g) {
				printf("P1����δ���Ƽ�\n");
			}
			else if (k > g) {
				P2HP = P2HP - (k - g);
				printf("P1��P2�����%d���˺�������P2HPΪ%d\n", k - g, P2HP);
			}
		}
	a:Sleep((y - x) * 1000);
		k = 0;
		g = 0;
		s = bl(P1M);
		if (s == 1) {
			printf("P1���ܳɹ�\n");
			goto b;
		}
		s = bl(P2C);
		if (s == 1) {
			printf("P2���ֱ���\n");
			k = al(P2A)*2.25;
			g = al(P1D);
			if (k <= g) {
				printf("P2����δ���Ƽ�\n");
			}
			else if (k > g) {
				P1HP = P1HP - (k - g);
				printf("P2��P1�����%d���˺�������P2HPΪ%d\n", k - g, P1HP);
			}
		}
		else if (s != 1) {
			k = al(P2A);
			g = al(P1D);
			if (k <= g) {
				printf("P2����δ���Ƽ�\n");
			}
			else if (k > g) {
				P1HP = P1HP - (k - g);
				printf("P2��P1�����%d���˺�������P2HPΪ%d\n", k - g, P1HP);
			}
		}
		
	}
	
	if (x > y) {
		d:Sleep(y * 1000);
			k = 0;
			g = 0;
			s = bl(P1M);
			if (s == 1) {
				printf("P1���ܳɹ�\n");
				goto c;
			}
			s = bl(P2C);
			if (s == 1) {
				printf("P2���ֱ���\n");
				k = al(P2A)*2.25;
				g = al(P1D);
				if (k <= g) {
					printf("P2����δ���Ƽ�");
				}
				else if (k > g) {
					P1HP = P1HP - (k - g);
					printf("P2��P1�����%d���˺�������P2HPΪ%d\n", k - g, P1HP);
				}
			}
			else if (s != 1) {
				k = al(P2A);
				g = al(P1D);
				if (k <= g) {
					printf("P2����δ���Ƽ�");
				}
				else if (k > g) {
					P1HP = P1HP - (k - g);
					printf("P2��P1�����%d���˺�������P2HPΪ%d\n", k - g, P1HP);
				}
			}
		c:Sleep((x - y) * 1000);
			k = 0;
			g = 0;
			s = bl(P2M);
			if (s == 1) {
				printf("P2���ܳɹ�\n");
				goto d;
			}
			s = bl(P1C);
			if (s == 1) {
				printf("P1���ֱ���\n");
				k = al(P1A)*2.25;
				g = al(P2D);
				if (k <= g) {
					printf("P1����δ���Ƽ�");
				}
				else if (k > g) {
					P2HP = P2HP - (k - g);
					printf("P1��P2�����%d���˺�������P2HPΪ%d\n", k - g, P2HP);
				}

			}
			else if (s != 1) {
				k = al(P1A);
				g = al(P2D);
				if (k <= g) {
					printf("P1����δ���Ƽ�");
				}
				else if (k > g) {
					P2HP = P2HP - (k - g);
					printf("P1��P2�����%d���˺�������P2HPΪ%d\n", k - g, P2HP);
				}

			}
		}
	

	}


int main() {
	int a;
	int b, c, v, j, s, g;
    double d,f;
	printf("���ϻ�A V0.001\n");
	printf("������1��ʼ��Ϸ,������������˳���Ϸ\n");
	scanf_s("%d", &a);
	if (a != 1)
		return 0;
	printf("��P1���üӵ�\n");
	printf("������1\n���ʣ�1\n���ݣ�1\n���ˣ�1\n(�������Գ�ʼĬ��Ϊ1����10���������Ե㣬����Ӱ�칥��������Ӱ��hp�ͻ��ף�����Ӱ�칥�ٺ����ܣ�����Ӱ�챩����\n");
	scanf_s("%d %d %lf %lf", &b, &c, &d, &f);
	P1(b, c, d, f);
	printf("��P2���üӵ�\n");
	printf("������1\n���ʣ�1\n���ݣ�1\n���ˣ�1\n(�������Գ�ʼĬ��Ϊ1����10���������Ե㣬����Ӱ�칥��������Ӱ��hp�ͻ��ף�����Ӱ�칥�ٺ����ܣ�����Ӱ�챩����\n");
	scanf_s("%d %d %lf %lf", &b, &c, &d, &f);
	P2(b, c, d, f);
	printf("��P1ѡ��������������\n1������  2�����ף����������׶����Լ�10�㹥�����߻��ף����������״�ʯ��\n");
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
	printf("��P2ѡ��������������\n1������  2�����ף����������׶����Լ�10�㹥�����߻��ף����������״�ʯ��\n");
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
	printf("��P1ѡ��ʯ��1��������ʯ 2�����ʱ�ʯ 3�����ٱ�ʯ 4�����˱�ʯ����ʯ��ֵ��Ϊ5�� \n");
	scanf_s("%d", &c);
	jewelP1(c);
	scanf_s("%d", &v);
	jewelP1(v);
	scanf_s("%d", &j);
	jewelP1(j);
	printf("��P2ѡ��ʯ��1��������ʯ 2�����ʱ�ʯ 3�����ٱ�ʯ 4�����˱�ʯ����ʯ��ֵ��Ϊ5�� \n");
	scanf_s("%d", &c);
	jewelP1(c);
	scanf_s("%d", &v);
	jewelP1(v);
	scanf_s("%d", &j);
	jewelP1(j);
	printf("׼����������ʾP1��P2���ڵ�����\n");
	printf("P1:\n HP:%d\n ������%d-%d\n ���ף�%d-%d\n ���٣�%lf\n �����ʣ�%d0%%\n �����ʣ�%d0%%\n",P1HP,P1A, P1A + 2, P1D, P1D + 2, P1S, P1M, P1C);
	printf("P2:\n HP:%d\n ������%d-%d\n ���ף�%d-%d\n ���٣�%lf\n �����ʣ�%d0%%\n �����ʣ�%d0%%\n",P2HP,P2A, P2A + 2, P2D, P2D + 2, P2S, P2M, P2C);
	system("pause");
	for (; P1HP > 0 && P2HP > 0;) {
		turn(P1S, P2S);
	
	}
	if (P1HP <= 0) {
		printf("P2��ʤ\n");
}
	else if (P2HP <= 0) {
		printf("P1��ʤ\n");

	}
	printf("�����������������Ϸ\n");
	system("pause");
	return 0;
}
 
