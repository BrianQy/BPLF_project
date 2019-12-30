#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define LEN 100/*Sleep长度*/

/*全局变量node*/
struct node {
	int n;
	char back[11][10];
	struct node* next;
};

/*全局变量first*/
struct node* first = NULL;

/*全局变量abcd*/
int a, b, c, d;

/*全局变量back*/
char back[11][10];

/*全局变量n 步数*/
int n = 0;

void recover();/*重置棋盘*/
void print();/*输出棋盘*/
void start();/*开始*/
void state();/*说明*/
int in();/*输入*/
void turn();/*翻页*/
struct node* add();/*链表增加*/
struct node* ret();/*悔棋*/
int judge(int x);/*判断悔棋等*/
struct node* read();

/*****************************************
main函数
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
		back[c][d] = back[a][b];/*这两行只是玩玩的*/
		back[a][b] = '.';
		/*此处为switch选择走哪种棋子以及是否吃子*/
		/*判断输赢*/
	    mark:
		n++;
		add();
		marrk:
		turn();
	}
	getchar();
	getchar();/*getchar用于避免结束运行*/
	return 0;
}

void recover()/*重置棋盘*/
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

void print()/*输出棋盘*/
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

void start()/*开始*/
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("中国象棋\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("Press ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
	printf("Enter ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	printf("to Start\n");

	getchar();
}

void state()/*说明*/
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN );
	printf("11:新的一局\n12:悔棋\n13:认输\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

int in()/*输入*/
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

void turn()/*翻页*/
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n " 
	"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

struct node* add()/*back是输入此次的棋盘，n是这次是多少步，可用于悔棋查找和删除棋盘*/
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

struct node* ret()/*悔棋*/
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

int judge(int x)/*判断重新开局，悔棋，认输*/
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