#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define LEN 100/*Sleep����*/

/*ȫ�ֱ���node*/
struct node {
	int n;
	char back[11][10];
	struct node* next;
};

/*ȫ�ֱ���first*/
struct node* first = NULL;

/*ȫ�ֱ���abcd*/
int a, b, c, d;

/*ȫ�ֱ���back*/
char back[11][10];

/*ȫ�ֱ���n ����*/
int n = 0;

void recover();/*��������*/
void print();/*�������*/
void start();/*��ʼ*/
void state();/*˵��*/
int in();/*����*/
void turn();/*��ҳ*/
struct node* add();/*��������*/
struct node* ret();/*����*/
int judge(int x);/*�жϻ����*/
struct node* read();

/*****************************************
main����
*****************************************/
int main(void)
{
	start();
	recover();
	add();
	for (;;) {
		print();
		int www=in();
		if (www==1) 
			goto mark;
		if (www == 2)
			goto marrk;
		back[c][d] = back[a][b];/*������ֻ�������*/
		back[a][b] = '.';
		/*�˴�Ϊswitchѡ�������������Լ��Ƿ����*/
		/*�ж���Ӯ*/
	    mark:
		n++;
		add();
		marrk:
		turn();
	}
	getchar();
	getchar();/*getchar���ڱ����������*/
	return 0;
}

void recover()/*��������*/
{
	int i = 0, n = 0;
	for (i = 0; i < 10; ) {
		back[i][0] = '1';
		back[i][0] += i - 1;
		i++;

	}
	for (n = 0; n < 10; n++) {
		back[0][n] = '0';
		back[0][n] += n;


	}
	for (i = 1; i < 11; i++) {
		for (n = 1; n < 10; n++) {
			back[i][n] = '.';
		}
	}
	back[10][0] = '0';

	back[10][1] = 'v';
	back[10][9] = 'v';

	back[10][2] = 'h';
	back[10][8] = 'h';

	back[10][3] = 'e';
	back[10][7] = 'e';

	back[10][4] = 'g';
	back[10][6] = 'g';

	back[10][5] = 'o';

	back[7][1] = 't';
	back[7][3] = 't'; 
	back[7][5] = 't'; 
	back[7][7] = 't';
	back[7][9] = 't';

	back[8][2] = 'c';
	back[8][8] = 'c';



	back[1][1] = 'V';
	back[1][9] = 'V';

	back[1][2] = 'H';
	back[1][8] = 'H';

	back[1][3] = 'E';
	back[1][7] = 'E';

	back[1][4] = 'G';
	back[1][6] = 'G';

	back[1][5] = 'O';

	back[4][1] = 'T';
	back[4][3] = 'T';
	back[4][5] = 'T';
	back[4][7] = 'T';
	back[4][9] = 'T';

	back[3][2] = 'C';
	back[3][8] = 'C';

}

void print()/*�������*/
{
	int i = 0, n = 0;
	for (i = 0; i < 11; i++) {
		for (n = 0; n < 10; n++) {
			printf("%c ", back[i][n]);
		}
		printf("\n");
	}
	state();
}

void start()/*��ʼ*/
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("�й�����\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("Press ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("Enter ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("to Start\n");

	getchar();
}

void state()/*˵��*/
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN );
	printf("11:�µ�һ��\n12:����\n13:����\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

int in()/*����*/
{
	printf("\nThe original position\nx:");
	scanf_s("%d", &a);
	int www=judge(a);
	if (www == 1)
		return 1;
	if (www == 2)
		return 2;
	printf("y:");
	scanf_s("%d",&b);
	printf("The current position\nx:");
	scanf_s("%d", &c);
	printf("y:");
	scanf_s("%d", &d);
	return 0;
}

void turn()/*��ҳ*/
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n " 
	"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

struct node* add()/*back������˴ε����̣�n������Ƕ��ٲ��������ڻ�����Һ�ɾ������*/
{
	struct node* new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("NULL Error\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	for (int i = 0; i < 11; i++) {
		for (int s = 0; s < 10; s++) {
			new_node->back[i][s] = back[i][s];
		}
	}
	new_node->next = first;
	first = new_node;
}

struct node* ret()/*����*/
{
	struct node* cur;
	struct node* prev;
	if (first == NULL) {
		goto mark;
	}
	cur = first->next;
	free(first);
	first = cur;
	if (first == NULL)
		goto mark;
	for (int i = 0; i < 11; i++) {
		for (int s = 0; s < 10; s++) {
			back[i][s] = first->back[i][s];
		}
	}
mark:;
}

int judge(int x)/*�ж����¿��֣����壬����*/
{
	switch (x) {
	case 11:recover();
		return 1;
	case 12:ret();
		return 2;
	case 13:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN  | FOREGROUND_RED );
		turn();
		printf("                        Wasted");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		getchar();
		getchar();
		exit(0);
		return 1;
	case 14:read();
		return 1;
	}
	return 0;
}

struct node* read() {
	struct node* read;
	for (read = first; read != NULL; read = read->next) {
		for (int i = 0; i < 11; i++) {
			for (int s = 0; s < 10; s++) {
				printf("%c ", read->back[i][s]);
			}
			printf("\n");
	}
	Sleep(100);
	printf("...\n");
}
}