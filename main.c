#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*学号、姓名、性别、联系电话、语文、数学、外语三门单科成绩、考试平均成绩、
考试名次、同学互评分、任课教师评分、综合测评总分、综合测评名次。*/
struct student {
	char number[14];
	char name[20];
	int sex;
	char phonenum[12];
	struct marks
	{
		int chinese;
		int maths;
		int english;
		double ave;
		int rank;
		int stuMarks;
		int teaMarks;
		int compMarks;
		int compRank;
	};
	struct student *next;
}s[30];

void Menu();//主菜单 
void help();//帮助 
/*int input(struct students s[], int n); //学生数据输入    
void output(struct students s[], int n);//学生数据输出 
void change(struct students s[], int n);//更改学生信息 
void searchMenu();//查询功能子菜单 
void search(struct students s[], int n);//查询功能 
int del(struct students s[], int n);//删除学生信息 
int add(struct students s[], int n);
//void createFile(FILE *fp);//创建文件 
void saveFile(struct students s[], int n, FILE* fp);//保存文件 
void sort(struct students s[], int n);//总成绩排名 */
int main() 
{
	int n;//学生数量 
	int choice;//菜单选项 
	int x;//输入返回主菜单 
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
			break;
		case 2:
			//output(s, n);
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
			//createFile(fp); 
			//saveFile(s, n, fp);
			exit(0);
		}
		system("cls");
	}
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
	printf("                   2.输出学生信息                      \n");
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
