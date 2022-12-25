#include "declaration.h"

void savePassword(char s[])
{   //将修改后的密码保存 
	FILE* fp = fopen("password.txt", "w+");
	fprintf(fp, "%s", s);
	fclose(fp);
}

void hidePassword(char* password, unsigned maxlen)
{
	int index = 0;
	char buff = '\0';

	while ((buff = getch()) != '\r')
	{
		if (buff == '\b' && index != 0)
		{
			index--;
			printf("\b \b");
		}
		else if (index < maxlen - 1 && buff != '\b')
		{
			password[index++] = buff;
			putchar('*');
		}
	}
	password[index] = '\0';
}

int changePassword()
{
	printf("注：修改密码后需要重新登录！\n");
	printf("请输入原来的密码：\n");
	int sum2 = 0;
	while (1)
	{
		hidePassword(key, 20);
		printf("\n");
		int n = strlen(key), m = strlen(password);
		if (n != m)
		{

			sum2++;
			if (sum2 >= 5)
			{
				printf("多次输入密码错误！系统关闭！\n");
				sum2 = 0;
				exit(0);
			}
			printf("密码错误！请重新输入！你还有%d次机会！\n", 5 - sum2);
		}
		else
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (key[i] != password[i])
				{
					sum++;
				}
			}
			if (sum == 0)
			{
				break;
			}
			else
			{
				sum2++;
				if (sum2 >= 5)
				{
					printf("多次输入密码错误！系统关闭！\n");
					sum2 = 0;
					exit(0);
				}
				printf("密码错误！请重新输入！你还有%d次机会！\n", 5 - sum2);
			}
		}
	}
	printf("请输入想要更改的密码(19位以内数字或字母的组合)：\n");
	hidePassword(password, 20);
	savePassword(password);
	printf("\n修改成功！请重新登录！\n");
	enter();
	return 0;
}

void enter()
{   //登录界面
	system("cls");//清屏 
	printf("=======================================================\n");
	printf("|                                                     |\n");
	printf("|                学 生 综 合 评 价 系 统              |\n");
	printf("|                                                     |\n");
	printf("=======================================================\n");
	printf("|                    欢迎使用本系统	              |\n");
	printf("=======================================================\n");
	printf("                请输入密码(初始密码654321)\n\t\t\t");
	int sum2 = 0;
	while (1)
	{
		FILE* fpr = fopen("password.txt", "r");
		char inital[20] = "654321";
		if (fpr == NULL)savePassword(inital);
		else
		{
			hidePassword(key, 20);
			printf("\n");
			fgets(password, 20, fpr);
			fclose(fpr);
			int n = strlen(key), m = strlen(password);
			if (n != m)
			{
				sum2++;
				if (sum2 >= 5)
				{
					printf("多次输入密码错误！系统关闭！\n");
					sum2 = 0;
					exit(0);
				}
				printf("密码错误！请重新输入！你还有%d次机会！\n", 5 - sum2);
			}
			else
			{
				int sum1 = 0;
				for (int i = 0; i < n; i++)\
				{
					if (key[i] != password[i])
					{
						sum1++;
					}
				}
				if (sum1 == 0)
				{
					printf("登录成功！\n");
					break;
				}
				else
				{
					sum2++;
					if (sum2 >= 5)
					{
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