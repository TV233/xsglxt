#include "declaration.h"

int main(void)//主函数 
{
	system("color 3f");//设置控制台背景为浅蓝色
	int choice = 0;
	enter();//密码认证
	readFile(&List);//进入程序后先读取文件 初始化
	while (1)
	{
		welcome();//主界面
		scanf("%d", &choice);
		switch (choice)
		{
		case 0: help();
			break;//帮助
		case 1: addStudent(&List);//增加学生信息 
			break;
		case 2: deleteStudent(&List);//删除学生信息 
			break;
		case 3: modifyStudent(&List);//修改学生信息 
			break;
		case 4: searchStudent(&List);//查询学生信息 
			break;
		case 5: outputSort(&List);//输出成绩排名 
			break;
		case 6: changePassword();//修改密码 
			break;
		case 7: info();//系统信息
			break;
		case 8: goodBye();//退出系统
			break;
		}
		system("pause");
	}
	return 0;
}







void welcome() {//主菜单界面 
	system("cls");//清屏 
	time_t t;//用来存储日历时间类型的变量
	struct tm* p;//用来保存时间和日期的结构类型的指针p
	time(&t);//将当前时间赋给t
	p = gmtime(&t);//获取 GMT 时间 

	printf("=======================================================\n");
	printf("|                                                     |\n");
	printf("|                学 生 综 合 评 价 系 统              |\n");
	printf("|                                                     |\n");
	printf("=======================================================\n");
	printf("|                     系统功能菜单                    |\n");
	printf("|                ------------------------             |  \n");
	printf("|                   0.系统帮助及说明                  | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   1.添加学生信息                    |\n");
	printf("|                ------------------------             |  \n");
	printf("|                   2.删除学生信息                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   3.修改学生信息                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   4.查询学生信息                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   5.输出学生综合排名                |    \n");
	printf("|                ------------------------             |  \n");
	printf("|                   6.修改登录信息                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   7.系统版本信息                    |   \n");
	printf("|                ------------------------             |  \n");
	printf("|                   8.退出管理系统                    |   \n");
	printf("|                ------------------------             |  \n");
	printf("|                                                     |  \n");
	printf("|        访问时间 %d年%02d月%02d日  %02d时%02d分%02d秒        |  \n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
	printf("=======================================================\n");
	printf("请输入你想要进行的操作（数字）: ");
}




void printHeart() {//打印爱心 
	float a, x, y;
	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			a = x * x + y * y - 1;
			//这里的@符号即为打印出的心形图案符号
			char ch = a * a * a - x * x * y * y * y <= 0.0f ? '@' : ' ';
			putchar(ch);
			//或者putchar(a*a*a-x*x*y*y*y<=0.0f?'*':' ');
		}
		printf("\n");
	}
}

void goodBye() {//结束程序 
	system("cls");
	printf("=======================================================\n");
	printf("|                                                     |\n");
	printf("|                     欢迎下次使用！                  |\n");
	printf("|                                                     |\n");
	printf("=======================================================\n");
	Sleep(1000);
	printHeart();
	Sleep(100);
	exit(0);
}
void help()
{
	printf("\n");
	printf("初次进入系统，请先输入“1”，并输入学生信息\n");
	printf("输入的学生信息，学号应为10位，姓名应不多于4个汉字\n");
	printf("请按照菜单提示键入数字代号\n");
	printf("再次欢迎您的使用，祝您使用愉快！\n\n");
}
void info() {
	printf("\n");
	printf("正式版本V1.1\nBy 第7小组\nAll rights reserved.\n");
	printf("\n");
}

