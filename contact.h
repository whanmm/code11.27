#pragma 
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 15
#define MAX_ADDR 30
//����������

//�˵���Ϣ
typedef struct PeoInfo {
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}PeoInfo;

//ͨѶ¼
typedef struct Contact {
	PeoInfo data[100];//����˵���Ϣ
	int count;//��¼ͨѶ¼�������
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ʾ��Ϣ
void ShowContact(const Contact* pc);

//ɾ����Ϣ
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);
//�޸���ϵ��
void ModifContact(Contact* pc);
//����ͨѶ¼�������
void SortContact(Contact* pc);