#include "declaration.h"

int main(void)//������ 
{
	system("color 3f");//���ÿ���̨����Ϊǳ��ɫ
	int choice = 0;
	enter();//������֤
	readFile(&List);//���������ȶ�ȡ�ļ� ��ʼ��
	while (1)
	{
		welcome();//������
		scanf("%d", &choice);
		switch (choice)
		{
		case 0: help();
			break;//����
		case 1: addStudent(&List);//����ѧ����Ϣ 
			break;
		case 2: deleteStudent(&List);//ɾ��ѧ����Ϣ 
			break;
		case 3: modifyStudent(&List);//�޸�ѧ����Ϣ 
			break;
		case 4: searchStudent(&List);//��ѯѧ����Ϣ 
			break;
		case 5: outputSort(&List);//����ɼ����� 
			break;
		case 6: changePassword();//�޸����� 
			break;
		case 7: info();//ϵͳ��Ϣ
			break;
		case 8: goodBye();//�˳�ϵͳ
			break;
		}
		system("pause");
	}
	return 0;
}







void welcome() {//���˵����� 
	system("cls");//���� 
	time_t t;//�����洢����ʱ�����͵ı���
	struct tm* p;//��������ʱ������ڵĽṹ���͵�ָ��p
	time(&t);//����ǰʱ�丳��t
	p = gmtime(&t);//��ȡ GMT ʱ�� 

	printf("=======================================================\n");
	printf("|                                                     |\n");
	printf("|                ѧ �� �� �� �� �� ϵ ͳ              |\n");
	printf("|                                                     |\n");
	printf("=======================================================\n");
	printf("|                     ϵͳ���ܲ˵�                    |\n");
	printf("|                ------------------------             |  \n");
	printf("|                   0.ϵͳ������˵��                  | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   1.���ѧ����Ϣ                    |\n");
	printf("|                ------------------------             |  \n");
	printf("|                   2.ɾ��ѧ����Ϣ                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   3.�޸�ѧ����Ϣ                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   4.��ѯѧ����Ϣ                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   5.���ѧ���ۺ�����                |    \n");
	printf("|                ------------------------             |  \n");
	printf("|                   6.�޸ĵ�¼��Ϣ                    | \n");
	printf("|                ------------------------             |  \n");
	printf("|                   7.ϵͳ�汾��Ϣ                    |   \n");
	printf("|                ------------------------             |  \n");
	printf("|                   8.�˳�����ϵͳ                    |   \n");
	printf("|                ------------------------             |  \n");
	printf("|                                                     |  \n");
	printf("|        ����ʱ�� %d��%02d��%02d��  %02dʱ%02d��%02d��        |  \n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min, p->tm_sec);
	printf("=======================================================\n");
	printf("����������Ҫ���еĲ��������֣�: ");
}




void printHeart() {//��ӡ���� 
	float a, x, y;
	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			a = x * x + y * y - 1;
			//�����@���ż�Ϊ��ӡ��������ͼ������
			char ch = a * a * a - x * x * y * y * y <= 0.0f ? '@' : ' ';
			putchar(ch);
			//����putchar(a*a*a-x*x*y*y*y<=0.0f?'*':' ');
		}
		printf("\n");
	}
}

void goodBye() {//�������� 
	system("cls");
	printf("=======================================================\n");
	printf("|                                                     |\n");
	printf("|                     ��ӭ�´�ʹ�ã�                  |\n");
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
	printf("���ν���ϵͳ���������롰1����������ѧ����Ϣ\n");
	printf("�����ѧ����Ϣ��ѧ��ӦΪ10λ������Ӧ������4������\n");
	printf("�밴�ղ˵���ʾ�������ִ���\n");
	printf("�ٴλ�ӭ����ʹ�ã�ף��ʹ����죡\n\n");
}
void info() {
	printf("\n");
	printf("��ʽ�汾V1.1\nBy ��7С��\nAll rights reserved.\n");
	printf("\n");
}

