#include "declaration.h"

void addStudent(node* L) {//增加学生信息 
	system("cls");
	node st;
	int choice = 0;
	while (1) {
		printf("请输入新增学生相关信息\n");
		printf("学号(10位数)：");
		while (1) {
			scanf("%lld", &st.number);
			node* p = searchId(st.number, L);
			if (p == NULL && st.number >= 1000000000 && st.number <= 9999999999) {
				break;
			}
			else {
				printf("该学生的学号已存在或长度不合理！请重新输入学号！\n");
			}
		}
		printf("姓名(4个字以内)：");
		while (1) {
			scanf("%s", st.name);
			node* p = searchName(st.name, L);
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

		insertList(&List, st);//插入链表 
		
		scoreSort(&List);//排名更新

		printf("是否需要继续输入学生信息？（是：1 / 否：0）\n");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
	}
}

void insertList(node* L, node e) {//头插法 且表头不存放数据
	node* h = L;//头节点 
	node* s = (node*)malloc(sizeof(node));
	*s = e;
	s->next = h->next;
	h->next = s;
	saveFile(L);
}

node* searchId(long long number, node* L) {//按学号查找 
	node* p = L;
	while (p->next != NULL) {//遍历链表 
		if (p->next->number == number) {
			return p;//返回指向“存放匹配了学号上一位所在结构的地址”的指针
		}
		p = p->next;

	}
	return NULL;
}

node* searchName(char name[], node* L) {//按姓名查找 
	node* p = L;
	while (p->next != NULL) {//遍历链表 
		if (strcmp(name, p->next->name) == 0) {
			return p;//返回指向“存放匹配了学号上一位所在结构的地址”的指针
		}
		p = p->next;

	}
	return NULL;
}

void deleteStudent(node* L) {
	//删除学生信息 
	system("cls");
	int choice = 0;
	long long id;
	char name[50];
	node* st;
	printf("=======================================================\n");
	printf("|            1.按学号查询需要删除信息的学生           |\n");
	printf("|            2.按姓名查询需要删除信息的学生           |\n");
	printf("=======================================================\n");
	printf("请输入查询方式：");
	scanf("%d", &choice);
	if (choice != 1 && choice != 2) {
		printf("输入错误，请重新输入选项:");
		scanf("%d", &choice);
	}
	if (choice == 1) {
		printf("请输入需要删除信息的学生的学号(10位数)：");
		scanf("%lld", &id);
		st = searchId(id, L);
		if (st == NULL) {
			printf("找不到对象！\n");
			system("pause");
			return;
		}
	}
	else if (choice == 2) {
		printf("请输入需要删除信息的学生的姓名：");
		scanf("%s", name);
		st = searchName(name, L);
		if (st == NULL) {
			printf("找不到对象！\n");
			system("pause");
			return;
		}
	}
	node* p = st;
	st = st->next;///进入指向“存放匹配了学号上一位所在结构”的地址
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
	printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分|教师评分|综测得分\t|综测排名  |\n");
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
	printf("确定要删除吗？(是：1/否：0)\n");
	scanf("%d", &choice);
	if (choice == 1) {
		node* s = p->next;//s指p后，即指向“存放匹配了学号所在结构的地址”
		p->next = s->next;//p指向“存放匹配了学号所在结构的下一位的地址”
		free(s);//释放s指向的结构 
		scoreSort(&List);//重新排序
		saveFile(L);
		printf("已删除，");
	}
	else {
		printf("未进行删除操作，");
		return;
	}

}

void modifyStudent(node* L) {
	//修改学生信息 
	system("cls");
	int choice = 0;
	long long id;
	char name[50];
	node* st;
	printf("=======================================================\n");
	printf("|            1.按学号查询需要修改信息的学生           |\n");
	printf("|            2.按姓名查询需要修改信息的学生           |\n");
	printf("=======================================================\n");
	printf("请输入查询方式：");
	while (choice != 1 && choice != 2) {
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("请输入需要修改信息的学生的学号(10位数)：");
			scanf("%lld", &id);
			st = searchId(id, L);
			if (st == NULL) {
				printf("找不到对象！\n");
				system("pause");
				return;
			}
			break;
		case 2:
			printf("请输入需要修改信息的学生的姓名：");
			scanf("%s", name);
			st = searchName(name, L);
			if (st == NULL) {
				printf("找不到对象！\n");
				system("pause");
				return;
			}
			break;
		default:
			printf("输入有误，请重新输入查询方式:");
			break;
		}
	}
	st = st->next;
	while (1) {
		system("cls");
		printf("当前该学生的信息如下：\n");
		printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
		printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分|教师评分|综测得分\t|综测排名  |\n");
		printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
		printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
		printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
		printf("=======================================================\n");
		printf("|                    0.修改学生学号                   |\n");
		printf("|                    1.修改学生姓名                   | \n");
		printf("|                    2.修改学生性别                   |\n");
		printf("|                    3.修改语文成绩                   |\n");
		printf("|                    4.修改数学成绩                   |\n");
		printf("|                    5.修改英语成绩                   | \n");
		printf("|                    6.修改学生互评分                 | \n");
		printf("|                    7.修改教师评分                   | \n");
		printf("|                    8.返回系统主界面                 | \n");
		printf("=======================================================\n");
		printf("请输入选项：");

		scanf("%d", &choice);
		switch (choice) {
		case 0:
			printf("请输入学号：");
			while (1) {
				long long temp;
				scanf("%lld", &temp);
				node* p = searchId(temp, L);
				if (p == NULL && temp >= 1000000000 && temp <= 9999999999) {
					st->number = temp;
					break;
				}
				else {
					printf("该学生的学号已存在或长度不合理！请重新输入学号！\n");
				}
			}

			break;
		case 1:
			printf("请输入姓名(中文最长不要超过4个字)：");
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
			printf("请输入语文成绩(0~100)：");
			while (1) {
				scanf("%d", &st->chinese);
				if (st->chinese >= 0 && st->chinese <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入语文成绩！\n");
				}
			}
			break;
		case 4:
			printf("请输入数学成绩(0~100)：");
			while (1) {
				scanf("%d", &st->math);
				if (st->math >= 0 && st->math <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入数学成绩！\n");
				}
			}
			break;
		case 5:
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
		case 6:
			printf("请输入同学互评分(0~100)：");
			while (1) {
				scanf("%d", &st->stuMarks);
				if (st->stuMarks >= 0 && st->stuMarks <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入同学互评分！\n");
				}
			}
			break;
		case 7:
			printf("请输入教师评分(0~100)：");
			while (1) {
				scanf("%d", &st->teaMarks);
				if (st->teaMarks >= 0 && st->teaMarks <= 100) {
					break;
				}
				else {
					printf("输入的分数不合理！应在0~100之间！请重新输入教师评分！\n");
				}
			}
			break;
		case 8:
			printf("将返回系统主界面，");
			return;
		}
		st->ave = (st->chinese + st->math + st->english) / 3;
		st->compMarks = st->ave * 0.6 + st->stuMarks * 0.1 + st->teaMarks * 0.3;
		scoreSort(&List);//重新排序
		saveFile(L);

		printf("是否继续修改该学生的信息？(是：1/否：0)\n");
		scanf("%d", &choice);
		if (choice == 0) {
			printf("修改成功！修改后该学生的信息与成绩如下：\n");
			break;
		}
	}

	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
	printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分|教师评分|综测得分\t|综测排名  |\n");
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
}

void searchStudent(node* L) {//查询学生信息 
	system("cls");
	int choice = 0;
	long long id;
	char name[50];
	node* st;
	printf("=======================================================\n");
	printf("|                  1.按学号查询学生信息               |\n");
	printf("|                  2.按姓名查询学生信息               |\n");
	printf("=======================================================\n");
	printf("请输入查询方式：");
	while (choice != 1 && choice != 2) {
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("请输入需要修改信息的学生的学号(10位数)：");
			scanf("%lld", &id);
			st = searchId(id, L);
			if (st == NULL) {
				printf("找不到对象！\n");
				system("pause");
				return;
			}
			break;
		case 2:
			printf("请输入需要修改信息的学生的姓名：");
			scanf("%s", name);
			st = searchName(name, L);
			if (st == NULL) {
				printf("找不到对象！\n");
				system("pause");
				return;
			}
			break;
		default:
			printf("输入有误，请重新输入查询方式:");
			break;
		}
	}
	st = st->next;
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
	printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分|教师评分|综测得分\t|综测排名  |\n");
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
	printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", st->number, st->name, st->sex, st->chinese, st->math, st->english, st->ave, st->stuMarks, st->teaMarks, st->compMarks, st->compRank);
	printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
}



_Bool comp(node a, node b) {//排序比较规则 
	return a.compMarks > b.compMarks;
}//前大于后返回真，小于等于返回假

void scoreSort(node* L) {//将学生成绩进行冒泡排序，从高到低 
	for (node* p = L->next; p != NULL; p = p->next) //遍历
	{
		for (node* q = p; q != NULL; q = q->next)
		{
			if (!comp(*p, *q))
			{//如果 前小于等于后 则进行交换 
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
	int rank = 1;
	double scoreTemp = 0;
	int rankTemp = 1;
	int first = 0;
	for (node* a = L->next; a != NULL; a = a->next)
	{
		if (first == 0) {//链表首个数据赋第一名
			a->compRank = 1;
			scoreTemp = a->compMarks;
			first++;
			continue;
		}

		if (a->compMarks == scoreTemp) {//如果综测分数与上个数据一样，直接把上个数据的排名赋予他
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

void outputSort(node* L) {//输出学生信息 
	system("cls");
	scoreSort(&List);
	node* p = L->next;
	if (p != NULL) {
		printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
		printf("|学号\t\t|姓名\t|性别\t|语文\t|数学\t|英语\t|平均分\t|学生互评分|教师评分|综测得分\t|综测排名  |\n");
		printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");
		while (p != NULL) {
			printf("|%lld\t|%s\t|%s\t|%d\t|%d\t|%d\t|%.2f\t|%d\t   |%d\t    |%.2f\t|%d\t   |\n", p->number, p->name, p->sex, p->chinese, p->math, p->english, p->ave, p->stuMarks, p->teaMarks, p->compMarks, p->compRank);
			printf("—————————————————————————————————————————————————————————————————————————————————————————————————————————————\n");;
			p = p->next;
		}
	}

}
