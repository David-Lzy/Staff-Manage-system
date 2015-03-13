// 职工管理系统.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
struct  workers_and_staff_members employee [MAX_INFO_COUNT];
unsigned int iNo = 0;

//
extern void main()
{
	char choice='0';	
	welcome_to_use();
	showtime();
	iNo = laod_informaion(employee,MAX_INFO_COUNT);
	if(iNo>=MAX_INFO_COUNT)
	{
		printf("对不起，员工数量已经达到容量上线，增加员工数据功能将不可用!\n");
		printf("请联系管理员进行系统升级或者将部分原有员工数据删除!\n");
	}
	while(1)
	{
		printf("现有员工记录总数为%d.\n",iNo);
        if(iNo<MAX_INFO_COUNT)
		{
		    printf("想要添加职工管理记录，请按A！\n");
		}
		printf("想要查询职工管理记录，请按S！\n");
		printf("想要删除职工管理记录，请按D！\n");
		printf("想要对某职工记录操作，请按E！\n");
		printf("想要显示所以职工记录，请按P！\n");
		printf("想要保存当前职工记录，请按V！\n");
		printf("想要退出职工管理系统，请按Q！\n");
        printf("->");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if((choice=='a'||choice=='A')&&(iNo<MAX_INFO_COUNT))
		{				
		    input_information(employee,iNo);
			show_employee_information(employee,iNo);
			iNo++;
			printf("确定要将该员工信息保存吗？\n Y/N?\n");
			while(1)
			{
				scanf("%c",&choice);
				while(choice=='\n')
				{
					scanf("%c",&choice);
				}
				if((choice=='y')||(choice=='Y'))
				{
					Save(employee,iNo);
					printf("信息添加成功!\n");
					printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					if(iNo>=MAX_INFO_COUNT)
					{
						printf("对不起，员工数量已经达到容量上线，增加员工数据功能将不可用!\n");
						printf("请联系管理员进行系统升级或者将部分原有员工数据删除!\n");
					}
					system("pause");
					break;
				}		
				else if((choice=='N')||(choice=='n'))
				{
					printf("你选择了放弃保存！\n");
					iNo--;
					system("pause");
					break;
				}
				else
				{
					continue;
				}
			}
		}
		else if(choice=='e'||choice=='E')
		{
			printf("要先找到该员工！再进行操作\n");
			printf("找到员工请按F,按其他键返回!\n");
			printf("->");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if(choice=='f'||choice=='F')
			{
				Ways_of_Search(employee,iNo);
			}
		}
		else if(choice=='s'||choice=='S')
		{
			printf("直接显示符合条件的员工数据请按Q；\n");
			printf("想一边显示一边对数据进行修改请C；\n");
			printf("返回主页面请按B\n");
			printf("->");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if(choice=='q'||choice=='Q')
			{
				Ways_of_Search_without_change(employee,iNo);
			}
			if(choice=='c'||choice=='C')
			{
				Ways_of_Search(employee,iNo);
			}		
		}
		else if(choice=='d'||choice=='D')
		{
			Ways_of_Delete(employee,&iNo);
		}
		else if(choice=='v'||choice=='V')
		{
			Save(employee,iNo);
		}
		else if(choice=='q'||choice=='Q')
		{
			Thankyou_to_use();
			exit(0);
		}
		else if(choice=='p'||choice=='P')
		{
			int i = 0;
			while(i<iNo)
			{
				show_employee_information(employee,i);
				i++;
			}
		}
		else
		{
			printf("输入了无效字符！\n");
			system("cls");
		}
	}
	Thankyou_to_use();
}
