#include "declaration.h"

void savePassword(char s[])
{   //���޸ĺ�����뱣�� 
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
	printf("ע���޸��������Ҫ���µ�¼��\n");
	printf("������ԭ�������룺\n");
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
				printf("��������������ϵͳ�رգ�\n");
				sum2 = 0;
				exit(0);
			}
			printf("����������������룡�㻹��%d�λ��ᣡ\n", 5 - sum2);
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
					printf("��������������ϵͳ�رգ�\n");
					sum2 = 0;
					exit(0);
				}
				printf("����������������룡�㻹��%d�λ��ᣡ\n", 5 - sum2);
			}
		}
	}
	printf("��������Ҫ���ĵ�����(19λ�������ֻ���ĸ�����)��\n");
	hidePassword(password, 20);
	savePassword(password);
	printf("\n�޸ĳɹ��������µ�¼��\n");
	enter();
	return 0;
}

void enter()
{   //��¼����
	system("cls");//���� 
	printf("=======================================================\n");
	printf("|                                                     |\n");
	printf("|                ѧ �� �� �� �� �� ϵ ͳ              |\n");
	printf("|                                                     |\n");
	printf("=======================================================\n");
	printf("|                    ��ӭʹ�ñ�ϵͳ	              |\n");
	printf("=======================================================\n");
	printf("                ����������(��ʼ����654321)\n\t\t\t");
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
					printf("��������������ϵͳ�رգ�\n");
					sum2 = 0;
					exit(0);
				}
				printf("����������������룡�㻹��%d�λ��ᣡ\n", 5 - sum2);
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
					printf("��¼�ɹ���\n");
					break;
				}
				else
				{
					sum2++;
					if (sum2 >= 5)
					{
						printf("��������������ϵͳ�رգ�\n");
						sum2 = 0;
						exit(0);
					}
					printf("����������������룡�㻹��%d�λ��ᣡ\n", 5 - sum2);
				}
			}
		}
	}
}