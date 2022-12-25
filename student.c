#include "declaration.h"

void addStudent(node* L) {//����ѧ����Ϣ 
	system("cls");
	node st;
	int choice = 0;
	while (1) {
		printf("����������ѧ�������Ϣ\n");
		printf("ѧ��(10λ��)��");
		while (1) {
			scanf("%lld", &st.number);
			node* p = searchId(st.number, L);
			if (p == NULL && st.number >= 1000000000 && st.number <= 9999999999) {
				break;
			}
			else {
				printf("��ѧ����ѧ���Ѵ��ڻ򳤶Ȳ���������������ѧ�ţ�\n");
			}
		}
		printf("����(4��������)��");
		while (1) {
			scanf("%s", st.name);
			node* p = searchName(st.name, L);
			int len = strlen(st.name);
			if (p == NULL && len <= 10) {
				break;
			}
			else {
				printf("��ѧ���������Ѵ��ڻ򳤶Ȳ���������������������\n");
			}
		}
		printf("�Ա�(��|Ů)��");
		while (1) {
			scanf("%s", st.sex);
			if (strlen(st.sex) == 2) {
				break;
			}
			else {
				printf("���벻����(�Ա�ӦΪ���� / Ů)�����������Ա�\n");
			}
		}
		printf("���ĳɼ�(0~100)��");
		while (1) {
			scanf("%d", &st.chinese);
			if (st.chinese >= 0 && st.chinese <= 100) {
				break;
			}
			else {
				printf("����ķ���������Ӧ��0~100֮�䣡�������������ĳɼ���\n");
			}
		}
		printf("��ѧ�ɼ�(0~100)��");
		while (1) {
			scanf("%d", &st.math);
			if (st.math >= 0 && st.math <= 100) {
				break;
			}
			else {
				printf("����ķ���������Ӧ��0~100֮�䣡������������ѧ�ɼ���\n");
			}
		}
		printf("Ӣ��ɼ�(0~100)��");
		while (1) {
			scanf("%d", &st.english);
			if (st.english >= 0 && st.english <= 100) {
				break;
			}
			else {
				printf("����ķ���������Ӧ��0~100֮�䣡����������Ӣ��ɼ���\n");
			}
		}
		printf("ѧ�������ɼ�(0~100)��");
		while (1) {
			scanf("%d", &st.stuMarks);
			if (st.stuMarks >= 0 && st.stuMarks <= 100) {
				break;
			}
			else {
				printf("����ķ���������Ӧ��0~100֮�䣡����������ѧ�������ɼ���\n");
			}
		}
		printf("�ο���ʦ����(0~100)��");
		while (1) {
			scanf("%d", &st.teaMarks);
			if (st.teaMarks >= 0 && st.teaMarks <= 100) {
				break;
			}
			else {
				printf("����ķ���������Ӧ��0~100֮�䣡�����������ο���ʦ���֣�\n");
			}
		}
		st.ave = (st.chinese + st.math + st.english) / 3;
		st.compMarks = st.ave * 0.6 + st.stuMarks * 0.1 + st.teaMarks * 0.3;

		insertList(&List, st);//�������� 
		
		scoreSort(&List);//��������

		printf("�Ƿ���Ҫ��������ѧ����Ϣ�����ǣ�1 / ��0��\n");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
}

void insertList(node* L, node e) {//ͷ�巨 �ұ�ͷ���������
	node* h = L;//ͷ�ڵ� 
	node* s = (node*)malloc(sizeof(node));
	*s = e;
	s->next = h->next;
	h->next = s;
	saveFile(L);
}

node* searchId(long long number, node* L) {//��ѧ�Ų��� 
	node* p = L;
	while (p->next != NULL) {//�������� 
		if (p->next->number == number) {
			return p;//����ָ�򡰴��ƥ����ѧ����һλ���ڽṹ�ĵ�ַ����ָ��
		}
		p = p->next;

	}
	return NULL;
}

node* searchName(char name[], node* L) {//���������� 
	node* p = L;
	while (p->next != NULL) {//�������� 
		if (strcmp(name, p->next->name) == 0) {
			return p;//����ָ�򡰴��ƥ����ѧ����һλ���ڽṹ�ĵ�ַ����ָ��
		}
		p = p->next;

	}
	return NULL;
}

void deleteStudent(node* L) {
	//ɾ��ѧ����Ϣ 
	system("cls");
	int choice = 0;
	long long id;
	char name[50];
	node* st;
	printf("=======================================================\n");
	printf("|            1.��ѧ�Ų�ѯ��Ҫɾ����Ϣ��ѧ��           |\n");
	printf("|            2.��������ѯ��Ҫɾ����Ϣ��ѧ��           |\n");
	printf("=======================================================\n");
	printf("�������ѯ��ʽ��");
	scanf("%d", &choice);
	if (choice != 1 && choice != 2) {
		printf("�����������������ѡ��:");
		scanf("%d", &choice);
	}
	if (choice == 1) {
		printf("��������Ҫɾ����Ϣ��ѧ����ѧ��(10λ��)��");
		scanf("%lld", &id);
		st = searchId(id, L);
		if (st == NULL) {
			printf("�Ҳ�������\n");
			system("pause");
			return;
		}
	}
	else if (choice == 2) {
		printf("��������Ҫɾ����Ϣ��ѧ����������");
		scanf("%s", name);
		st = searchName(name, L);
		if (st == NULL) {
			printf("�Ҳ�������\n");
			system("pause");
			return;
		}
	}
	node* p = st;
	st = st->next;///����ָ�򡰴��ƥ����ѧ����һλ���ڽṹ���ĵ�ַ
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("|ѧ��\t\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|ƽ����\t|ѧ��������|��ʦ����|�۲�÷�\t|�۲�����  |\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");;
	printf("ȷ��Ҫɾ����(�ǣ�1/��0)\n");
	scanf("%d", &choice);
	if (choice == 1) {
		node* s = p->next;//sָp�󣬼�ָ�򡰴��ƥ����ѧ�����ڽṹ�ĵ�ַ��
		p->next = s->next;//pָ�򡰴��ƥ����ѧ�����ڽṹ����һλ�ĵ�ַ��
		free(s);//�ͷ�sָ��Ľṹ 
		scoreSort(&List);//��������
		saveFile(L);
		printf("��ɾ����");
	}
	else {
		printf("δ����ɾ��������");
		return;
	}

}

void modifyStudent(node* L) {
	//�޸�ѧ����Ϣ 
	system("cls");
	int choice = 0;
	long long id;
	char name[50];
	node* st;
	printf("=======================================================\n");
	printf("|            1.��ѧ�Ų�ѯ��Ҫ�޸���Ϣ��ѧ��           |\n");
	printf("|            2.��������ѯ��Ҫ�޸���Ϣ��ѧ��           |\n");
	printf("=======================================================\n");
	printf("�������ѯ��ʽ��");
	while (choice != 1 && choice != 2) {
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("��������Ҫ�޸���Ϣ��ѧ����ѧ��(10λ��)��");
			scanf("%lld", &id);
			st = searchId(id, L);
			if (st == NULL) {
				printf("�Ҳ�������\n");
				system("pause");
				return;
			}
			break;
		case 2:
			printf("��������Ҫ�޸���Ϣ��ѧ����������");
			scanf("%s", name);
			st = searchName(name, L);
			if (st == NULL) {
				printf("�Ҳ�������\n");
				system("pause");
				return;
			}
			break;
		default:
			printf("�������������������ѯ��ʽ:");
			break;
		}
	}
	st = st->next;
	while (1) {
		system("cls");
		printf("��ǰ��ѧ������Ϣ���£�\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("|ѧ��\t\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|ƽ����\t|ѧ��������|��ʦ����|�۲�÷�\t|�۲�����  |\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("=======================================================\n");
		printf("|                    0.�޸�ѧ��ѧ��                   |\n");
		printf("|                    1.�޸�ѧ������                   | \n");
		printf("|                    2.�޸�ѧ���Ա�                   |\n");
		printf("|                    3.�޸����ĳɼ�                   |\n");
		printf("|                    4.�޸���ѧ�ɼ�                   |\n");
		printf("|                    5.�޸�Ӣ��ɼ�                   | \n");
		printf("|                    6.�޸�ѧ��������                 | \n");
		printf("|                    7.�޸Ľ�ʦ����                   | \n");
		printf("|                    8.����ϵͳ������                 | \n");
		printf("=======================================================\n");
		printf("������ѡ�");

		scanf("%d", &choice);
		switch (choice) {
		case 0:
			printf("������ѧ�ţ�");
			while (1) {
				long long temp;
				scanf("%lld", &temp);
				node* p = searchId(temp, L);
				if (p == NULL && temp >= 1000000000 && temp <= 9999999999) {
					st->number = temp;
					break;
				}
				else {
					printf("��ѧ����ѧ���Ѵ��ڻ򳤶Ȳ���������������ѧ�ţ�\n");
				}
			}

			break;
		case 1:
			printf("����������(�������Ҫ����4����)��");
			while (1) {
				char temp[50];
				scanf("%s", temp);
				node* p = searchName(temp, L);
				int len = strlen(temp);
				if (p == NULL && len <= 10) {
					strcpy(st->name, temp);
					break;
				}
				else {
					printf("�������Ѵ��ڻ򳤶Ȳ���������������������\n");
				}
			}

			break;
		case 2:
			printf("�������Ա�(��|Ů)��");
			while (1) {
				scanf("%s", st->sex);
				if (strlen(st->sex) == 2) {
					break;
				}
				else {
					printf("���벻����(�Ա�ӦΪ���� / Ů)�����������Ա�\n");
				}
			}
			break;
		case 3:
			printf("���������ĳɼ�(0~100)��");
			while (1) {
				scanf("%d", &st->chinese);
				if (st->chinese >= 0 && st->chinese <= 100) {
					break;
				}
				else {
					printf("����ķ���������Ӧ��0~100֮�䣡�������������ĳɼ���\n");
				}
			}
			break;
		case 4:
			printf("��������ѧ�ɼ�(0~100)��");
			while (1) {
				scanf("%d", &st->math);
				if (st->math >= 0 && st->math <= 100) {
					break;
				}
				else {
					printf("����ķ���������Ӧ��0~100֮�䣡������������ѧ�ɼ���\n");
				}
			}
			break;
		case 5:
			printf("������Ӣ��ɼ�(0~100)��");
			while (1) {
				scanf("%d", &st->english);
				if (st->english >= 0 && st->english <= 100) {
					break;
				}
				else {
					printf("����ķ���������Ӧ��0~100֮�䣡����������Ӣ��ɼ���\n");
				}
			}
			break;
		case 6:
			printf("������ͬѧ������(0~100)��");
			while (1) {
				scanf("%d", &st->stuMarks);
				if (st->stuMarks >= 0 && st->stuMarks <= 100) {
					break;
				}
				else {
					printf("����ķ���������Ӧ��0~100֮�䣡����������ͬѧ�����֣�\n");
				}
			}
			break;
		case 7:
			printf("�������ʦ����(0~100)��");
			while (1) {
				scanf("%d", &st->teaMarks);
				if (st->teaMarks >= 0 && st->teaMarks <= 100) {
					break;
				}
				else {
					printf("����ķ���������Ӧ��0~100֮�䣡�����������ʦ���֣�\n");
				}
			}
			break;
		case 8:
			printf("������ϵͳ�����棬");
			return;
		}
		st->ave = (st->chinese + st->math + st->english) / 3;
		st->compMarks = st->ave * 0.6 + st->stuMarks * 0.1 + st->teaMarks * 0.3;
		scoreSort(&List);//��������
		saveFile(L);

		printf("�Ƿ�����޸ĸ�ѧ������Ϣ��(�ǣ�1/��0)\n");
		scanf("%d", &choice);
		if (choice == 0) {
			printf("�޸ĳɹ����޸ĺ��ѧ������Ϣ��ɼ����£�\n");
			break;
		}
	}

	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("|ѧ��\t\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|ƽ����\t|ѧ��������|��ʦ����|�۲�÷�\t|�۲�����  |\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");;
}

void searchStudent(node* L) {//��ѯѧ����Ϣ 
	system("cls");
	int choice = 0;
	long long id;
	char name[50];
	node* st;
	printf("=======================================================\n");
	printf("|                  1.��ѧ�Ų�ѯѧ����Ϣ               |\n");
	printf("|                  2.��������ѯѧ����Ϣ               |\n");
	printf("=======================================================\n");
	printf("�������ѯ��ʽ��");
	while (choice != 1 && choice != 2) {
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("��������Ҫ�޸���Ϣ��ѧ����ѧ��(10λ��)��");
			scanf("%lld", &id);
			st = searchId(id, L);
			if (st == NULL) {
				printf("�Ҳ�������\n");
				system("pause");
				return;
			}
			break;
		case 2:
			printf("��������Ҫ�޸���Ϣ��ѧ����������");
			scanf("%s", name);
			st = searchName(name, L);
			if (st == NULL) {
				printf("�Ҳ�������\n");
				system("pause");
				return;
			}
			break;
		default:
			printf("�������������������ѯ��ʽ:");
			break;
		}
	}
	st = st->next;
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("|ѧ��\t\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|ƽ����\t|ѧ��������|��ʦ����|�۲�÷�\t|�۲�����  |\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
}



_Bool comp(node a, node b) {//����ȽϹ��� 
	return a.compMarks > b.compMarks;
}//ǰ���ں󷵻��棬С�ڵ��ڷ��ؼ�

void scoreSort(node* L) {//��ѧ���ɼ�����ð�����򣬴Ӹߵ��� 
	for (node* p = L->next; p != NULL; p = p->next) //����
	{
		for (node* q = p; q != NULL; q = q->next)
		{
			if (!comp(*p, *q))
			{//��� ǰС�ڵ��ں� ����н��� 
				//����������
				node t = *p;
				*p = *q;
				*q = t;
				//����ָ����
				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
			}
		}
	}
	int rank = 1;
	double scoreTemp = 0;
	int rankTemp = 1;
	int first = 0;
	for (node* a = L->next; a != NULL; a = a->next)
	{
		if (first == 0) {//�����׸����ݸ���һ��
			a->compRank = 1;
			scoreTemp = a->compMarks;
			first++;
			continue;
		}

		if (a->compMarks == scoreTemp) {//����۲�������ϸ�����һ����ֱ�Ӱ��ϸ����ݵ�����������
			a->compRank = rankTemp;
			rank++;
		}
		else {
			rank++;
			a->compRank = rank;
			scoreTemp = a->compMarks;
			rankTemp = a->compRank;
		}


	}
}

void outputSort(node* L) {//���ѧ����Ϣ 
	system("cls");
	scoreSort(&List);
	node* p = L->next;
	if (p != NULL) {
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("|ѧ��\t\t|����\t|�Ա�\t|����\t|��ѧ\t|Ӣ��\t|ƽ����\t|ѧ��������|��ʦ����|�۲�÷�\t|�۲�����  |\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		while (p != NULL) {
			printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", p->number, p->name, p->sex, p->chinese, p->math, p->english, p->ave, p->stuMarks, p->teaMarks, p->compMarks, p->compRank);
			printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");;
			p = p->next;
		}
	}

}
