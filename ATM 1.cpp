#include<stdio.h>
#include<stdlib.h>

int language;//1-Chinese,2-English

typedef struct Account
{
	char name[100];
	char idCard[19];
	char tel[12];
	char username[25];
	char password[7];
	float money;
	
	struct Account * next;//下一个结点的地址 
}Account;

Account * head=NULL;//指向头结点的指针
Account * tail=NULL;//指向尾结点的指针 

void signUp()
{
	//申请一块内存空间，将其地址赋值给指针newNodeP 
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	
	//为节点赋值 
	if(language==1)
	{
		printf("输入姓名：\n");
	}
	else if(language==2)
	{
		printf("Input name:\n");
	}
	scanf("%s",newNodeP->name);
	
	if(language==1)
	{
		printf("输入身份证：\n");
	}
	else if(language==2)
	{
		printf("Input idCard:\n");
	}
	scanf("%s",newNodeP->idCard);
	
	if(language==1)
	{
		printf("输入电话：\n");
	}
	else if(language==2)
	{
		printf("Input tel:\n");
	}
	scanf("%s",newNodeP->tel);
	
	if(language==1)
	{
		printf("输入卡号：\n");
	}
	else if(language==2)
	{
		printf("Input username:\n");
	}
	scanf("%s",newNodeP->username);
	
	if(language==1)
	{
		printf("输入密码：\n");
	}
	else if(language==2)
	{
		printf("Input password:\n");
	}
	scanf("%s",newNodeP->password);
	
	newNodeP->money=0.0f;
	newNodeP->next=NULL;
	
	//将结点添加到链表 
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	if(language==1)
	{
		printf("添加成功！\n");
	}
	else if(language==2)
	{
		printf("added！\n");
	}
}

void signIn()
{
	
}

void showMenu()
{
	while(1)
	{
		system("cls");
		if(language==1)
		{
			printf("按1, 开户\n");
			printf("按2, 登陆\n");
			printf("按3, 退出\n");
		}
		else if(language==2)
		{
			printf("Press 1, sign up\n");
			printf("Press 2, sign in\n");
			printf("Press 3，sign out\n");
		}
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUp();
		}
		else if(n==2)
		{
			signIn();
		}
		else if(n==3)
		{
			return; 
		}
	}
}

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		printf("%s %s %s %s %s\n",curP->name,curP->idCard,curP->tel,curP->username,curP->password);
		curP=curP->next;
	}
}

int main()
{
	printf("欢迎来到银行\n");
	printf("Welcome to bank\n");
	
	printf("按1，中文服务\n");
	printf("Press 2，English Service\n");
	scanf("%d",&language);
	
	showMenu();
	printLinkedList();
	
	return 0;	
}
