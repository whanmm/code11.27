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
//类型声明：

//人的信息
typedef struct PeoInfo {
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}PeoInfo;

//通讯录
typedef struct Contact {
	PeoInfo data[100];//存放人的信息
	int count;//记录通讯录里的人数
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//显示信息
void ShowContact(const Contact* pc);

//删除信息
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);
//修改联系人
void ModifContact(Contact* pc);
//排序通讯录里的内容
void SortContact(Contact* pc);