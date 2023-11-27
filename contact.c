#include "contact.h"
void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == 100) {
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����������:\n");
	scanf("%s", pc->data[pc->count].name);
	printf("���������䣺\n");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰��\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("���ӳɹ�\n");
}


void ShowContact(const Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%-20s\t%-3s\t%-5s\t%-15s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++) {
		printf("%-20s\t%-3d\t%-5s\t%-15s\t%-30s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);

	}
}


static int FindByName(Contact* pc, char name[]) {
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++) {
		if (0 == strcmp(pc->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	assert(pc);
	int i = 0;
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ�����˵����֣�\n");
	scanf("%s", name);

	//ɾ��
	
	// //1.����
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫɾ�����˲�����\n");
	}
	
	//2.ɾ��
	for (i = pos; i < pc->count-1; i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}


void SearchContact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("���������֣�");
	scanf("%s", name);
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	
	//2.��ӡ
	printf("%-20s\t%-3s\t%-5s\t%-15s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-3d\t%-5s\t%-15s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);

}

void ModifContact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ����֣�");
	scanf("%s", name);
	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	//�޸�
	printf("����������:\n");
	scanf("%s", pc->data[pos].name);
	printf("���������䣺\n");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pos].sex);
	printf("������绰��\n");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pos].addr);
}
int cmp_by_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//������������
//��qsort;
void SortContact(Contact* pc) {
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_by_name);
	printf("����ɹ�\n");

}