#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ID 10
#define MAX_NAME 30
#define MAX_STUDENTS 100


typedef struct {
	char number[14];
	char name[20];
	int sex;
	char phoneNum[12];
	struct marks
	{
		double chinese;
		double math;
		double english;
		double ave;
		int rank;
		double stuMarks;//同学互评分
		double teaMarks;//任课教师评分
		double compMarks;//综测总分
		int compRank;//综测名次
	};
}Student;

typedef struct node {
	Student s;
	struct node* next;
}Node;

typedef struct {
	Node* head;
	int current_num;
}Linkedlist;
void info_init(Linkedlist* h);
void info_init(Linkedlist* h) {
	FILE* fp;
	if ((fp = fopen("data.txt", "r")) == NULL) {
		if ((fp = fopen("data.txt", "w")) == NULL)
			printf("创建学生数据文件失败！\n");
	}
	else {
		Student s;
		Node* node;
		h->head = NULL;
		h->current_num = 0;
		while (!feof(fp)) {
			fscanf(fp, "%s", s.number);
			fscanf(fp, "\t%s", s.name);
			fscanf(fp, "\t%d", &s.sex);
			fscanf(fp, "\t%lf", &s.chinese);
			fscanf(fp, "\t%lf", &s.math);
			fscanf(fp, "\t%lf", &s.english);
			fscanf(fp, "\t%lf", &s.ave);
			fscanf(fp, "\t%lf", &s.stuMarks);
			fscanf(fp, "\t%lf", &s.teaMarks);
			fscanf(fp, "\t%lf", &s.compMarks);
			fscanf(fp, "\t%d\n", &s.compRank);

			node = (Node*)malloc(sizeof(Node));
			node->s = s;
			node->next = h->head;
			h->head = node;
			h->current_num += 1;
		}
	}
	fclose(fp);
	printf("初始化完成\n学生数据总数为%d \n", h->current_num);
}

void Menu();//主菜单 
void help();//帮助
void add(Linkedlist* h);//输入
void saveFile(Linkedlist* h);//保存
void destroy(Linkedlist* h);//删库跑路
void printData(Linkedlist* h);//输出
/*void search(struct students s[], int n);//查询功能
//void searchMenu();//查询功能子菜单
//void change(struct student s[], int n);//更改学生信息
void sort(struct students s[], int n);//总成绩排名 */


//int input(struct student s[], int n); //学生数据输入
//void output(struct student s[], int n);//学生数据输出


//void saveFile(struct student s[], int n, FILE* fp);//保存文件

//int del(struct students s[], int n);//删除学生信息
//int add(struct students s[], int n);



int main()
{
	Linkedlist* h = (Linkedlist*)malloc(sizeof(Linkedlist));
	//FILE* fp = fopen("data.txt", "a");
	int n = 1;//学生数量 初始为1
	int choice;//菜单选项 
	int x;//输入返回主菜单
	//init(s);
	info_init(h);
	while (1)
	{
		Menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			help();
			break;
		case 1:
			//n = input(s, n);
			add(h);
			break;
		case 2:
			printData(h);
			break;
		case 3:
			//change(s, n);
			break;
		case 4:
			//search(s, n);
			break;
		case 5:
			//n = add(s, n);
			break;
		case 6:
			//n = del(s, n);
			break;
		case 7:
			saveFile(h);
			//createFile(fp); 
			//saveFile(s, n, fp);
			exit(0);
		}
		system("cls");
	}
	//fclose(fp);
	return 0;
}

void Menu() {
	printf("=======================================================\n");
	printf("                                                       \n");
	printf("                   学生综合评价管理系统                  \n");
	printf("                                                       \n");
	printf("=======================================================\n");
	printf("                     系统功能菜单                      \n");
	printf("                ------------------------               \n");
	printf("                   0.系统帮助及说明                    \n");
	printf("                ------------------------               \n");
	printf("                   1.输入学生信息                      \n");
	printf("                ------------------------               \n");
	printf("                   2.输出学生信息                     \n");
	printf("                ------------------------               \n");
	printf("                   3.更改学生信息                      \n");
	printf("                ------------------------               \n");
	printf("                   4.查看学生信息                      \n");
	printf("                ------------------------               \n");
	printf("                   5.插入学生信息                      \n");
	printf("                ------------------------               \n");
	printf("                   6.删除学生信息                      \n");
	printf("                ------------------------               \n");
	printf("                   7.保存学生信息并退出程序            \n");
	printf("=======================================================\n");
	printf("请输入菜单编号（0-7）：");
}

void help()
{
	//system("cls");
	printf("\n");
	printf("欢迎使用学生系统帮助！\n");
	printf("初次进入系统后，请先输入“1”，并输入学生信息\n");
	printf("学号为13位，姓名和使用拼音字母输入，性别用0/1代表男/女，\n");
	printf("请按照菜单提示键入数字代号\n");
	printf("感谢您的使用！\n\n");
	system("pause");

}

void printData(Linkedlist* h) {
	if (h->current_num <= 0)
		printf("啊这，链表是空的！ \n");
	Node* p = h->head;
	printf("以下为学生信息\n");
	printf("学号\t\t姓名\t性别\t语文成绩 数学成绩 英语成绩 考试平均成绩 同学互评分 任课老师评分 综测分数 综测排名\n");
	while (p) {
		printf("%s\t", p->s.number);
		printf("%s\t", p->s.name);
		printf("%d\t", p->s.sex);
		printf("%.2f\t", p->s.chinese);
		printf("%.2f\t", p->s.math);
		printf("%.2f\t", p->s.english);
		printf("%.2f\t", p->s.ave);
		printf("%.2f\t", p->s.stuMarks);
		printf("%.2f\t", p->s.teaMarks);
		printf("%.2f\t", p->s.compMarks);
		printf("%d\n", p->s.compRank);
		p = p->next;
	}
	system("pause");
}

void add(Linkedlist* h) {
	if (h->current_num >= MAX_STUDENTS) {
		printf("链表满，请删除一些学生数据\n");
		return;
	}
	Node* p = (Node*)malloc(sizeof(Node)), * tmp;
	Student s;
	printf("学号: ");
	scanf("%s", s.number);
	printf("姓名: ");
	scanf("%s", s.name);
	printf("性别: ");
	scanf("%d", &s.sex);
	printf("语文: ");
	scanf("%lf", &s.chinese);
	printf("数学: ");
	scanf("%lf", &s.math);
	printf("英语: ");
	scanf("%lf", &s.english);
	printf("学生: ");
	scanf("%lf", &s.stuMarks);
	printf("老师: ");
	scanf("%lf", &s.teaMarks);
	s.ave = (s.chinese + s.math + s.english) / 3;
	s.compMarks = s.ave * 0.6 + s.stuMarks * 0.1 + s.teaMarks * 0.3;
	s.compRank = 1;
	p->s = s;

	printf("请输入数据插入位置\n \
           0: 头部; 1: 尾部; i : 第i位 \n");
	int index;
	scanf("%d", &index);
	switch (index) {
	case 0:
		p->next = h->head;
		h->head = p;
		h->current_num += 1;
		break;
	case 1:
		tmp = h->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = p;
		p->next = NULL;
		h->current_num += 1;
		break;
	default:
		if (index <= MAX_STUDENTS) {
			tmp = h->head;
			for (int i = 0; i < index; i++)
				tmp = tmp->next;
			p->next = tmp->next;
			tmp->next = p;
			h->current_num += 1;
		}
		else
			printf("该位置不存在！ \n");
		break;
	}
	printf("操作成功！ \n");
}

void saveFile(Linkedlist* h) {
	FILE* fp;
	Node* p = h->head;
	int count = 0;
	if ((fp = fopen("data.txt", "w")) == NULL) {
		printf("打开学生数据文件失败！ \n");
		return;
	}
	while (p) {
		fprintf(fp,"%s\t", p->s.number);
		fprintf(fp,"%s\t", p->s.name);
		fprintf(fp,"%d\t", p->s.sex);
		fprintf(fp,"%lf\t", p->s.chinese);
		fprintf(fp,"%lf\t", p->s.math);
		fprintf(fp,"%lf\t", p->s.english);
		fprintf(fp,"%lf\t", p->s.ave);
		fprintf(fp,"%lf\t", p->s.stuMarks);
		fprintf(fp,"%lf\t", p->s.teaMarks);
		fprintf(fp,"%lf\t", p->s.compMarks);
		fprintf(fp,"%d\n", p->s.compRank);
		p = p->next;
		count++;
	}
	fclose(fp);
	destroy(h);
	if (count > 0)
		printf("%d个学生数据已经写入文件 \n", count);
	else
		printf("没有学生数据被写入文件\n");

}

void destroy(Linkedlist* h) {
	if (h->current_num > 0) {
		Node* pre = h->head;
		Node* p = pre->next;
		while (p) {
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
		h->head = NULL;
		h->current_num = 0;
	}
}

