#include "declaration.h"

int readFile(node* L) {//��ȡ�ļ� 
	FILE* fpr = fopen("data.txt", "r");
	node st;//�ṹ
	node* s;
	node* t = L;//tָ��List��ͷ���
	if (fpr == NULL) {
		printf("���ļ�ʧ��");
		return 0;
	}
	else {
		while (fscanf(fpr, "%lld %s %s %d %d %d %lf %d %d %lf %d", &st.number, st.name, st.sex, &st.chinese, &st.math, &st.english, &st.ave, &st.stuMarks, &st.teaMarks, &st.compMarks, &st.compRank) != EOF) {
			//���ļ������ݶ���st��ʱ���
			s = (node*)malloc(sizeof(node));//sָ���·�����ڴ�
			*s = st;//st�����ݴ浽�շ�����ڴ���
			t->next = s;//Listͷ���next�����½ڵ�
			t = s;//tָ���½ڵ�
			t->next = NULL;//�½ڵ�nextָ���
		}
	}
	fclose(fpr);//�ر��ļ�ָ�� 
	return 1;
}

int saveFile(node* L) {//�����ļ�
	FILE* fpw = fopen("data.txt", "w");
	if (fpw == NULL) {
		printf("���ļ�ʧ��");
		return 0;
	}//���ļ�ʧ�� 
	node* p = L->next;
	while (p != NULL) {
		fprintf(fpw, "%lld %s %s %d %d %d %lf %d %d %lf %d\n", p->number, p->name, p->sex, p->chinese, p->math, p->english, p->ave, p->stuMarks, p->teaMarks, p->compMarks, p->compRank);
		p = p->next;
	}
	fclose(fpw);//�ر��ļ�ָ�� 
	return 1;
}

