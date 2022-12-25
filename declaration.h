#include<stdio.h>//标准输入输出函数库
#include<string.h>//操作字符串 
#include<stdlib.h>////标准函数库
#include<windows.h>//清屏函数头文件 
#include<time.h>//调用并显示当前时间 
#include<conio.h> //隐藏密码输入函数getch()的头文件 


char password[20], key[20];//密码声明 

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

void savePassword(char s[]);
void scoreSort(node* L);
void hidePassword(char* password, unsigned maxlen);//输入时隐藏密码 
int readFile(node* L);
int saveFile(node* L);
void enter();
void welcome();
int changePassword();
void insertList(node* L, node e);
node* searchId(long long number, node* L);
node* searchName(char name[], node* L);
void addStudent(node* L);
void deleteStudent(node* L);
void modifyStudent(node* L);
void searchStudent(node* L);
void outputSort(node* L);
void printHeart();
void goodBye();
void help();
void info();