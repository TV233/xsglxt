#include<stdio.h>//��׼�������������
#include<string.h>//�����ַ��� 
#include<stdlib.h>////��׼������
#include<windows.h>//��������ͷ�ļ� 
#include<time.h>//���ò���ʾ��ǰʱ�� 
#include<conio.h> //�����������뺯��getch()��ͷ�ļ� 


char password[20], key[20];//�������� 

typedef struct Node {
	long long number;//ѧ��
	char name[50];//����
	char sex[10];//�Ա�
	int chinese, math, english;
	double ave;
	int stuMarks;//ͬѧ������
	int teaMarks;//�ον�ʦ����
	double compMarks;//�۲��ܷ�
	int compRank;//�۲�����

	struct Node* next;
}node;

node List;//���� 

void savePassword(char s[]);
void scoreSort(node* L);
void hidePassword(char* password, unsigned maxlen);//����ʱ�������� 
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