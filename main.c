#include<stdio.h>
#include<string.h>//操作字符串 
#include<stdlib.h>//malloc()函数 ,反回的类型是void*，要进行类型转换
#include<windows.h>//清屏函数头文件 
#include<time.h>//调用并显示当前时间 
#include<conio.h> //隐藏密码输入函数getch()的头文件 


char password[20], key[20];//初始密码 
 
void save_password(char s[]) {//将修改后的密码保存 
	FILE* fp = fopen("password.txt", "w+");
	fprintf(fp, "%s", s);
	fclose(fp);
}
 
typedef struct Node {
	long long number;//学号
	char name[50];//姓名
	char sex[10];//性别
	int chinese, math, english; 
	double ave;
	int stuMarks;//同学互评分
	int teaMarks;//任课教师评分
	double compMarks;//综测总分
	int compRank;//综测名次

	struct Node* next;
}node;
 
node List;//链表 
 
void hide_password(char* pswd, unsigned maxlen) {//隐藏密码进行输入 
	int index = 0;
	char buff = '\0';
 
	while ((buff = getch()) != '\r') {
		if (buff == '\b' && index != 0) {
			index--;
			printf("\b \b");
		}
		else if (index < maxlen - 1 && buff != '\b') {
			pswd[index++] = buff;
			putchar('*');
		}
	}
	pswd[index] = '\0';
}
 
int readFile(node* L) {//读取文件 
	FILE* fpr = fopen("score.txt", "r");
	node st;//结构
	node* s;
	node* t = L;//t指向List的地址
	if (fpr == NULL) {
		return 0;
	}
	else {
		while (fscanf(fpr, "%lld %s %s %d %d %d %lf %d %d %lf %d", &st.number, st.name, st.sex, &st.chinese, &st.math, &st.english, &st.ave, &st.stuMarks, &st.teaMarks, &st.compMarks, &st.compRank) != EOF) {
			s = (node*)malloc(sizeof(node));//s开天辟地
			*s = st;//指st
			t->next = s;//List下一个连到st
			t = s;//t指st
			t->next = NULL;//st的下一个变空
		}
	}
	fclose(fpr);//关闭文件指针 
	return 1;
}
 
int saveFile(node* L) {//保存文件
	FILE* fpw = fopen("score.txt", "w");
	if (fpw == NULL) return 0;//打开文件失败 
	node* p = L->next;
	while (p != NULL) {
		fprintf(fpw, "%lld %s %s %d %d %d %lf %d %d %lf %d\n", p->number, p->name, p->sex, p->chinese, p->math, p->english, p->ave, p->stuMarks, p->teaMarks, p->compMarks, p->compRank);
		p = p->next;
	}
	fclose(fpw);//关闭文件指针 
	return 1;
}
 
void enter() {//登录界面
	system("cls");//清屏 
	time_t t;
	struct tm* p;
	time(&t);
	p = gmtime(&t);
	printf("\t\t\t\t**********************************************\n");
	printf("\t\t\t\t**--------------%d年%02d月%02d日--------------**\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
	printf("\t\t\t\t****************当前时间%02d时%02d分%***************\n", 8 + p->tm_hour, p->tm_min);
	printf("\t\t\t\t**********************************************\n");
	printf("\t\t\t\t**                                          **\n");
	printf("\t\t\t\t**             学生成绩管理系统             **\n");
	printf("\t\t\t\t**                                          **\n");
	printf("\t\t\t\t**********************************************\n");
	printf("\t\t\t\t**     感谢使用本系统，希望您使用愉快！     **\n");
	printf("\t\t\t\t**********************************************\n");
	printf("\t\t\t\t**    制作者：小菜鸡    学号：1008965223    **\n");
	printf("\t\t\t\t**         班级：计算机类201班              **\n");
	printf("\t\t\t\t**      学院：计算机与电子信息学院          **\n");
	printf("\t\t\t\t**********************************************\n");
	printf("请输入密码(初始密码123456)\n");
	int sum2 = 0;
	while (1) {
		FILE* fpr = fopen("password.txt", "r");
		char inital[20] = "123456";
		if (fpr == NULL)save_password(inital);
		else {
			hide_password(key, 21);
			printf("\n");
			fgets(password, 21, fpr);
			fclose(fpr);
			int n = strlen(key), m = strlen(password);
			if (n != m) {
				sum2++;
				if (sum2 >= 5) {
					printf("多次输入密码错误！系统关闭！\n");
					sum2 = 0;
					exit(0);
				}
				printf("密码错误！请重新输入！你还有%d次机会！\n", 5 - sum2);
			}
			else {
				int sum1 = 0;
				for (int i = 0; i < n; i++) {
					if (key[i] != password[i]) {
						sum1++;
					}
				}
				if (sum1 == 0) {
					printf("登录成功！\n");
					break;
				}
				else {
					sum2++;
					if (sum2 >= 5) {
						printf("多次输入密码错误！系统关闭！\n");
						sum2 = 0;
						exit(0);
					}
					printf("密码错误！请重新输入！你还有%d次机会！\n", 5 - sum2);
				}
			}
		}
	}
}
 
void welcome() {//主菜单界面 
	system("cls");//清屏 
	time_t t;
	struct tm* p;
	time(&t);
	p = gmtime(&t);
	printf("\t\t\t\t**********************************************\n");
	printf("\t\t\t\t**--------------%d年%02d月%02d日--------------**\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
	printf("\t\t\t\t****************当前时间%02d时%02d分%***************\n", 8 + p->tm_hour, p->tm_min);
	printf("\t\t\t\t**********************************************\n");
	printf("\t\t\t\t**                                          **\n");
	printf("\t\t\t\t**               欢迎进入！                 **\n");
	printf("\t\t\t\t**                                          **\n");
	printf("\t\t\t\t**********************************************\n");
	printf("\t\t\t\t**---------------功能菜单-------------------**\n");
	printf("\t\t\t\t**       增加学生信息 ------------1         **\n");
	printf("\t\t\t\t**       删除学生信息 ------------2         **\n");
	printf("\t\t\t\t**       修改学生信息 ------------3         **\n");
	printf("\t\t\t\t**       查询学生信息 ------------4         **\n");
	printf("\t\t\t\t**       输出成绩排名 ------------5         **\n");
	printf("\t\t\t\t**       修改登录密码 ------------6         **\n");
	printf("\t\t\t\t**       退出管理系统 ------------0         **\n");
	printf("\t\t\t\t**********************************************\n");
	printf("请输入你想要进行的操作（数字）: ");
}
 
int change() {
	printf("注：修改密码后需要重新登录！\n");
	printf("请输入原来的密码：\n");
	while (1) {
		hide_password(key, 21);
		printf("\n");
		int n = strlen(key), m = strlen(password);
		if (n != m) {
			printf("密码错误！\n");
		}
		else {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if (key[i] != password[i]) {
					sum++;
				}
			}
			if (sum == 0) {
				break;
			}
			else {
				printf("密码错误！\n");
			}
		}
	}
	printf("请输入想要更改的密码：\n");
	hide_password(password, 21);
	save_password(password);
	printf("\n修改成功！请重新登录！\n");
	enter();
	return 0;
}
 
void insertlist(node* L, node e) {//头插法 且表头不存放数据
	node* h = L;//头节点 
	node* s = (node*)malloc(sizeof(node));
	*s = e;
	s->next = h->next;
	h->next = s;
	saveFile(L);
}
 
node* searchid(long long number, node* L) {//按学号查找 
	node* p = L;
	while (p->next != NULL) {//遍历链表 
		if (p->next->number == number) { 
			return p;//返回指向“存放匹配了学号上一位所在结构的地址”的指针
		}
		p = p->next;
 
	}
	return NULL;
}
 
node* searchname(char name[], node* L) {//按姓名查找 
	node* p = L;
	while (p->next != NULL) {//遍历链表 
		if (strcmp(name, p->next->name) == 0) {
			return p;//返回指向“存放匹配了学号上一位所在结构的地址”的指针
		}
		p = p->next;
 
	}
	return NULL;
}
 
void new_student(node* L) {//增加学生信息 
	system("cls");
	node st;
	int choice = 0;
	while (1) {
		printf("请输入新增学生相关信息\n");
		printf("学号(10位数)：");
		while (1) {
			scanf("%lld", &st.number);
			node* p = searchid(st.number, L);
			if (p == NULL && st.number >= 1000000000 && st.number <= 9999999999) {
				break;
			}
			else {
				printf("该学生的学号已存在或长度不合理！请重新输入学号！\n");
			}
		}
		printf("姓名(中文最长不要超4个字)：");
		while (1) {
			scanf("%s", st.name);
			node* p = searchname(st.name, L);
			int len = strlen(st.name);
			if (p == NULL && len <= 10) {
				break;
			}
			else {
				printf("该学生的姓名已存在或长度不合理！请重新输入姓名！\n");
			}
		}
		printf("性别(男|女)：");
		while (1) {
			scanf("%s", st.sex);
			if (strlen(st.sex) == 2) {
				break;
			}
			else {
				printf("输入不合理！(性别应为：男 / 女)请重新输入性别！\n");
			}
		}
		printf("语文成绩(0~100)：");
		while (1) {
			scanf("%d", &st.chinese);
			if (st.chinese >= 0 && st.chinese <= 100) {
				break;
			}
			else {
				printf("输入的分数不合理！应在0~100之间！请重新输入语文成绩！\n");
			}
		}
		printf("数学成绩(0~100)：");
		while (1) {
			scanf("%d", &st.math);
			if (st.math >= 0 && st.math <= 100) {
				break;
			}
			else {
				printf("输入的分数不合理！应在0~100之间！请重新输入数学成绩！\n");
			}
		}
		printf("英语成绩(0~100)：");
		while (1) {
			scanf("%d", &st.english);
			if (st.english >= 0 && st.english <= 100) {
				break;
			}
			else {
				printf("输入的分数不合理！应在0~100之间！请重新输入英语成绩！\n");
			}
		}
		printf("学生互评成绩(0~100)：");
		while (1) {
			scanf("%d", &st.stuMarks);
			if (st.stuMarks >= 0 && st.stuMarks <= 100) {
				break;
			}
			else {
				printf("输入的分数不合理！应在0~100之间！请重新输入学生互评成绩！\n");
			}
		}
		printf("任课老师评分(0~100)：");
		while (1) {
			scanf("%d", &st.teaMarks);
			if (st.teaMarks >= 0 && st.teaMarks <= 100) {
				break;
			}
			else {
				printf("输入的分数不合理！应在0~100之间！请重新输入任课老师评分！\n");
			}
		}
		st.ave = (st.chinese + st.math + st.english) / 3;
		st.compMarks = st.ave * 0.6 + st.stuMarks * 0.1 + st.teaMarks * 0.3;
		st.compRank = 1;
		insertlist(&List, st);
		printf("是否需要继续输入学生信息？（是：1 / 否：0）\n");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
}
 
void deletestu(node* p) {//删除学生信息 
	node* s = p->next;//s指p后，即指向“存放匹配了学号所在结构的地址”
	p->next = s->next;//p指向“存放匹配了学号所在结构的下一位的地址”
	s->next = NULL;//先把s空了
	free(s);//kill *s 
}
 
void delete_student(node* L) {
	//删除学生信息 
	system("cls");
	long long id;
	node* p;
	printf("请输入删除学生的学号(10位数)：");
	scanf("%lld", &id);
	node* st = searchid(id, L);
	p = st;
	if (st == NULL) {
		printf("找不到对象！");
		return;
	}
	st = st->next;///进入指向“存放匹配了学号上一位所在结构”的地址
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
	printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分\t|任课教师评分\t|综测得分\t|综测排名\t|\n");
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t\t|%d\t\t|%.2f\t\t|%d\t|\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks,st->compMarks,st->compRank);
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
	deletestu(p);
	saveFile(L);
}
 
void modify_student(node* L) {
	//修改学生信息 
	/*system("cls");
	int choice = -1;
	long long  id;
	printf("请输入要查找的学生学号(10位数)：");
	scanf("%lld", &id);
	node* st = searchid(id, L);
 
	if (st == NULL) {
		printf("查无此人！");
		return;
	}
	st = st->next;
	while (1) {
		system("cls");
		printf("_________________________________________________________________________________\n");
		printf("|学号\t\t|姓名\t|性别\t|高数\t|英语\t|大物\t|离散\t|线代\t|总分\t|\n");
		printf("_________________________________________________________________________________\n");
		printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->math, st->english, st->phisics, st->scatter, st->generation, st->sum);
		printf("_________________________________________________________________________________\n");
		printf("**********************************************\n");
		printf("**          修改学生姓名--------- 1         **\n");
		printf("**          修改学生性别--------- 2         **\n");
		printf("**          修改高数成绩--------- 3         **\n");
		printf("**          修改英语成绩--------- 4         **\n");
		printf("**          修改大物成绩--------- 5         **\n");
		printf("**          修改离散成绩--------- 6         **\n");
		printf("**          修改线代成绩--------- 7         **\n");
		printf("**********************************************\n");
		printf("请输入要修改的信息：");
 
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("请输入姓名(中文最长不要超过4个字)：");
			while (1) {
				scanf("%s", st->name);
				node* p = searchname(st->name, L);
				int len = strlen(st->name);
				if (p == NULL && len <= 10) {
					break;
				}
				else {
					printf("该姓名已存在或长度不合理！请重新输入姓名！\n");
				}
			}
 
			break;
		case 2:
			printf("请输入性别(男|女)：");
			while (1) {
				scanf("%s", st->sex);
				if (strlen(st->sex) == 2) {
					break;
				}
				else {
					printf("输入不合理！(性别应为：男 / 女)请重新输入性别！\n");
				}
			}
			break;
		case 3:
			printf("请输入高数成绩(0~100)：");
			while (1) {
				scanf("%d", &st->math);
				if (st->math >= 0 && st->math <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入高数成绩！\n");
				}
			}
			break;
		case 4:
			printf("请输入英语成绩(0~100)：");
			while (1) {
				scanf("%d", &st->english);
				if (st->english >= 0 && st->english <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入英语成绩！\n");
				}
			}
			break;
		case 5:
			printf("请输入大物成绩(0~100)：");
			while (1) {
				scanf("%d", &st->phisics);
				if (st->phisics >= 0 && st->phisics <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入大物成绩！\n");
				}
			}
			break;
		case 6:
			printf("请输入离散成绩(0~100)：");
			while (1) {
				scanf("%d", &st->scatter);
				if (st->scatter >= 0 && st->scatter <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入离散成绩！\n");
				}
			}
			break;
		case 7:
			printf("请输入线代成绩(0~100)：");
			while (1) {
				scanf("%d", &st->generation);
				if (st->generation >= 0 && st->generation <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入线代成绩！\n");
				}
			}
			break;
		}
		st->sum = st->math + st->english + st->phisics + st->scatter + st->generation;
		printf("是否继续修改该学生的信息？(是：1/否：0)\n");
		scanf("%d", &choice);
		if (choice == 0) {
			printf("修改成功！修改后该学生的信息与成绩如下：\n");
			break;
		}
	}
	printf("_________________________________________________________________________________\n");
	printf("|学号\t\t|姓名\t|性别\t|高数\t|英语\t|大物\t|离散\t|线代\t|总分\t|\n");
	printf("_________________________________________________________________________________\n");
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|\n", st->id, st->name, st->sex, st->math, st->english, st->phisics, st->scatter, st->generation, st->sum);
	printf("_________________________________________________________________________________\n");
	saveFile(L);*/
}
 
void search_student(node* L) {//查询学生信息 
	system("cls");
	int choice = 0;
	long long id;
	char name[50];
	node* st;
	printf("按学号查询----- 1\n");
	printf("按姓名查询----- 2\n");
	printf("请输入查询方式：");
	scanf("%d", &choice);
	if (choice == 1) {
		printf("请输入要查询的学号(10位数)：");
		scanf("%lld", &id);
		st = searchid(id, L);
		if (st == NULL) {
			printf("找不到对象！\n");
		}
		else {
			st = st->next;
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
			printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分\t|任课教师评分\t|综测得分\t|综测排名\t|\n");
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
			printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t\t|%d\t\t|%.2f\t\t|%d\t|\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks,st->compMarks,st->compRank);
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
		}
	}
	else if (choice == 2) {
		printf("请输入要查询的姓名：");
		scanf("%s", name);
		st = searchname(name, L);
		if (st == NULL) {
			printf("找不到对象！\n");
		}
		else {
			st = st->next;
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
			printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分\t|任课教师评分\t|综测得分\t|综测排名\t|\n");
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
			printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t\t|%d\t\t|%.2f\t\t|%d\t|\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks,st->compMarks,st->compRank);			
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
		}
	}
}

int maxscore(node* L, int mode) {//查找各科最高分 
	/*int max = 0;
	node* p = L->next;
	if (mode == 1) {//高数最高分 
		while (p != NULL) {
			if (p->math > max) {
				max = p->math;
			}
			p = p->next;
		}
		return max;
	}
	else if (mode == 2) {//英语最高分 
		while (p != NULL) {
			if (p->english > max) {
				max = p->english;
			}
			p = p->next;
		}
		return max;
	}
	else if (mode == 3) {//大物最高分 
		while (p != NULL) {
			if (p->phisics > max) {
				max = p->phisics;
			}
			p = p->next;
		}
		return max;
	}
	else if (mode == 4) {//离散最高分 
		while (p != NULL) {
			if (p->scatter > max) {
				max = p->scatter;
			}
			p = p->next;
		}
		return max;
	}
	else if (mode == 5) {//线代最高分 
		while (p != NULL) {
			if (p->generation > max) {
				max = p->generation;
			}
			p = p->next;
		}
		return max;
	}
	else if (mode == 6) {//总分最高分 
		while (p != NULL) {
			if (p->sum > max) {
				max = p->sum;
			}
			p = p->next;
		}
		return max;
	}
 */
}
 
_Bool cmp(node a, node b) {//排序比较规则 
	return a.compMarks > b.compMarks;}
 
void ScoreSort(node* L) {//将学生成绩进行排序，从高到低 
	for (node* p = L->next; p != NULL; p = p->next) {
		for (node* q = p; q != NULL; q = q->next) {
			if (!cmp(*p, *q)) {//如果不符合排序规则则进行交换 
				//交换数据域
				node t = *p;
				*p = *q;
				*q = t;
				//交换指针域
				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
			}
		}
	}
}
 
void output_sort(node* L) {//输出学生信息 
	system("cls");
	ScoreSort(&List);
	node* p = L->next;
	if (p != NULL) {
		printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
		printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分\t|任课教师评分\t|综测得分\t|综测排名\t|\n");
		printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
		while (p != NULL) {
			printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t\t|%d\t\t|%.2f\t\t|%d\t|\n", p->number, p->name, p->sex, p->chinese, p->math, p->english, p->ave, p->stuMarks, p->teaMarks, p->compMarks, p->compRank);
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
			p = p->next;
		}
	}
	//printf("语文最高分：%d  ", maxscore(&List, 1)); printf("数学最高分：%d\n", maxscore(&List, 2));
	//printf("英语最高分：%d  ", maxscore(&List, 3)); printf("离散最高分：%d\n", maxscore(&List, 4));
	//printf("线代最高分：%d  ", maxscore(&List, 5)); printf("总分最高分：%d\n", maxscore(&List, 6));
 
}
 
void printflove() {//打印爱心 
	float a, x, y;
	for (y = 1.5f; y > -1.5f; y -= 0.1f) {
		for (x = -1.5f; x < 1.5f; x += 0.05f) {
			a = x * x + y * y - 1;
			char ch = a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ';
			putchar(ch);
		}
		printf("\n");
		printf("\t\t\t  ");
	}
}
 
void goodbye() {//结束程序 
	system("cls");
	printflove();
	printf("\t**********************************************\n");
	printf("\t\t\t\t**                                          **\n");
	printf("\t\t\t\t**        欢迎下次使用！~再见！~~           **\n");
	printf("\t\t\t\t**                                          **\n");
	printf("\t\t\t\t**********************************************\n");
	exit(0);
}
int main()//主函数 
{
	int choice = 0;
	//enter();
	readFile(&List);//进入程序后先读取文件,少了这句之前存的成绩都不能输出来 
	while (1) 
	{
		welcome();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			new_student(&List);//增加学生信息 
			break;
		case 2:
			delete_student(&List);//删除学生信息 
			break;
		case 3:
			modify_student(&List);//修改学生信息 
			break;
		case 4:
			search_student(&List);//查询学生信息 
			break;
		case 5:
			output_sort(&List);//输出成绩排名 
			break;
		case 6:
			change();//修改密码 
			break;
		case 0:
			goodbye();//结束程序
			break;
		}
		printf("是否需要继续操作？(是：1/否：0)\n");
		scanf("%d", &choice);
		if (choice == 0) {
			goodbye();
		}
	}
	return 0;
}