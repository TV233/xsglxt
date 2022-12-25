#include "declaration.h"

int readFile(node* L) {//读取文件 
	FILE* fpr = fopen("data.txt", "r");
	node st;//结构
	node* s;
	node* t = L;//t指向List的头结点
	if (fpr == NULL) {
		printf("读文件失败");
		return 0;
	}
	else {
		while (fscanf(fpr, "%lld %s %s %d %d %d %lf %d %d %lf %d", &st.number, st.name, st.sex, &st.chinese, &st.math, &st.english, &st.ave, &st.stuMarks, &st.teaMarks, &st.compMarks, &st.compRank) != EOF) {
			//将文件中数据读入st临时存放
			s = (node*)malloc(sizeof(node));//s指向新分配的内存
			*s = st;//st的数据存到刚分配的内存中
			t->next = s;//List头结点next连到新节点
			t = s;//t指向新节点
			t->next = NULL;//新节点next指向空
		}
	}
	fclose(fpr);//关闭文件指针 
	return 1;
}

int saveFile(node* L) {//保存文件
	FILE* fpw = fopen("data.txt", "w");
	if (fpw == NULL) {
		printf("打开文件失败");
		return 0;
	}//打开文件失败 
	node* p = L->next;
	while (p != NULL) {
		fprintf(fpw, "%lld %s %s %d %d %d %lf %d %d %lf %d\n", p->number, p->name, p->sex, p->chinese, p->math, p->english, p->ave, p->stuMarks, p->teaMarks, p->compMarks, p->compRank);
		p = p->next;
	}
	fclose(fpw);//关闭文件指针 
	return 1;
}

