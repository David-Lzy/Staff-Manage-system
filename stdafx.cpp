/ stdafx.cpp : 只包括标准包含文件的源文件
// 职工管理系统.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"
//欢迎观看本职工管理系统的源代码；
//李正阳create 2012—12—21
//指导老师：冯志勇

// TODO: 在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用
extern void welcome_to_use()
{
	printf("    \n\n\n\n");
	printf("      ===============================\n");
	printf("      == 欢 迎 使 用 职工管理系统！==\n");
	printf("      ==  Desinged  by  李 正 阳！ ==\n");
	printf("      == 联 系 电 话 : 18652680086 ==\n");
	printf("      ==   Copyrights 1993-2013    ==\n");
	printf("      ==  All   Rights  Reserved   ==\n");
	printf("      ===============================\n");
}
extern void Thankyou_to_use()
{
	printf("    \n\n\n\n");
	printf("      ==============================================\n");
	printf("      == 十 分 感 谢 使 用 本 职 工 管 理 系 统 ！==\n");
	printf("      == 本 人 联 系 电 话：1 8 6 5 2 6 8 0 0 8 6 ==\n");
	printf("      == 李正阳Working Studio;All Rights Reserved ==\n");
	printf("      == Some parts guided by teacher FZY,Thanks！==\n");
	printf("      ==============================================\n");
	system("pause");
}
//////////////////////////////////////////////////////////////////////////
//下面是一级函数
//////////////////////////////////////////////////////////////////////////
extern int laod_informaion(struct workers_and_staff_members employee[],int maxCount)
{
	FILE *fileopen;
	fileopen=fopen("workers_and_staff_members.db","rb" );
	if(fileopen!=NULL)
	{
		int i=0;
		while(!feof(fileopen))
		{
			if(fread(&employee[i],sizeof(struct workers_and_staff_members),1,fileopen)>0)
			{
				i++;
				if(i>=maxCount)
				{
					break;
				}
			}
		}
		fclose(fileopen);
		return i;
	}
	return 0;
}
extern int Save(workers_and_staff_members employee[],unsigned int iNo)
{
	FILE *fileopen;
	fileopen = fopen("workers_and_staff_members.db","wb");
	if(fileopen!=NULL)
	{
		fwrite(employee,sizeof(struct workers_and_staff_members),iNo,fileopen);//把第iNo个员工的数据写入文件
		fclose(fileopen);
		return 1;
	}
	return 0;
}
extern int Modify_information(workers_and_staff_members employee[],unsigned int iNo)//用于修改员工数据
{
	input_password();
	char choice;
	FILE *fileopen;
	fileopen = fopen("workers_and_staff_members.db","w+");
rescanf:printf("你想要对该员工的数据全部修改还是部分修改？\n");
	printf("要对该员工的数据进行全部修改,请按1;部分修改,请按2\n");
	scanf("%c",&choice);
	while(choice=='\n')
	{
		scanf("%c",&choice);
	}
	if(choice=='1')
	{
		change_information(employee,iNo);

	}
	else if(choice=='2')
	{
		printf("请选择你想要对数据修改的部分\n");
		printf("****************************\n");
		printf("修改员工编号，请选择1；\n");
		printf("修改员工姓名，请选择2；\n");
		printf("修改员工性别，请选择3；\n");
		printf("修改员工职位，请选择4；\n");
		printf("修改出生日期，请选择5；\n");
		printf("修改就职日期，请选择6；\n");
		printf("修改合同时长，请选择7；\n");
		printf("修改现居地址，请选择8；\n");
		printf("修改手机号码，请选择9；\n");
		printf("修改身份证号，请选择0；\n");
		printf("修改其它备注，请选择R。\n->");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		switch(choice)
		{
		case '1':
			change_number(employee,iNo);
			break;
		case '2':
			change_name(employee,iNo);
			break;
		case '3':
			change_sex(employee,iNo);
			break;
		case '4':
			change_position(employee,iNo);
			break;
		case '5':
			change_birthday(employee,iNo);
			break;
		case '6':
			change_obtain_employmen_time(employee,iNo);
			break;
		case '7':
			change_Contract_expiration_time(employee,iNo);
			break;
		case '8':
			change_Now_lives_in(employee,iNo);
			break;
		case '9':
			change_cell_phone_number(employee,iNo);
			break;
		case '0':
			change_identity_card_number(employee,iNo);
			break;
		case 'r':
			change_Other_information_structures(employee,iNo);
			break;
		case 'R':
			change_Other_information_structures(employee,iNo);
			break;
		default:
			printf("请输入1~10之间与R的数！，重新输入请按A,按其他键退出并返回主节面！\n");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if((choice=='a')||choice=='A')
			{
				goto rescanf;
			}
			else
			{
				break;
			}
		}

	}
	else
	{
		printf("输入了无效字符！\n");
		system("cls");
		goto rescanf;
	}
	if(fileopen!=NULL)
	{
		fwrite(&employee[iNo],sizeof(struct workers_and_staff_members),1,fileopen);//把第iNo个员工的数据写入文件
		fclose(fileopen);
		return 1;
	}
	return 0;
}
extern void input_password()
{
	unsigned long password;
	int scanf_times=4;
	while(scanf_times>0)
	{
		printf("现在请进行密码认证！");
		printf("请输入密码->");
		scanf("%d",&password);
		if(password==PassWord)
		{
			printf("密码认证成功");
			system("cls");
			printf("\n");
			break;
		}
		else
		{
			printf("密码认证失败！\n");
			printf("你还有%d次输入机会！\n",scanf_times);
			scanf_times--;
		}
	}
	if(scanf_times==0)
	{
		printf("非法使用！程序将自动关闭！");
		system("cls");
		exit(0);

	}
}
extern void showtime()
{
	char *wday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	printf("\t今日时间：%d %d %d %s\n\n", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday,wday[p->tm_wday]);
}
extern void show_age(struct workers_and_staff_members employee[],unsigned int iNo)
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	employee[iNo].age=((1900+p->tm_year)-(employee[iNo].birthday.year));
	if((1900+p->tm_mon)<(employee[iNo].birthday.mounth))
	{
		employee[iNo].age--;
	}
	else if((1900+p->tm_mday)<(employee[iNo].birthday.day))
	{
		employee[iNo].age--;
	}

}
extern void input_information(struct workers_and_staff_members employee[],unsigned int iNo)
{
		 printf("输入职工数据:\n");
		 add_new_number(employee,iNo);
		 add_new_name(employee,iNo);
		 add_new_sex(employee,iNo);
		 add_new_birthday(employee,iNo);
		 add_new_cell_phone_number(employee,iNo);
		 add_new_identity_card_number(employee,iNo);
		 add_new_obtain_employmen_time(employee,iNo);
		 add_new_Contract_expiration_time(employee,iNo);
		 add_new_position(employee,iNo);
		 add_Now_lives_in(employee,iNo);
		 add_new_Other_information_structures(employee,iNo);
}
extern void change_information(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("输入职工数据:\n");
	change_number(employee,iNo);
	change_name(employee,iNo);
	change_sex(employee,iNo);
	change_birthday(employee,iNo);
	change_cell_phone_number(employee,iNo);
	change_identity_card_number(employee,iNo);
	change_obtain_employmen_time(employee,iNo);
	change_Contract_expiration_time(employee,iNo);
	change_position(employee,iNo);
	change_Now_lives_in(employee,iNo);
	change_Other_information_structures(employee,iNo);
}
extern void show_employee_information(workers_and_staff_members employee[],unsigned int iNo)
{
	printf("**********************************************************\n");	
	printf("**该职工的职工编号是:%d\n",employee[iNo].number,employee[iNo].sex);
	if(employee[iNo].sex==0)
	{
		printf("**该职工的姓名性别是:%s\t男\n",employee[iNo].name);
	}
	else if(employee[iNo].sex==1)
	{
		printf("**该职工的姓名性别是:%s\t女\n",employee[iNo].name);
	}
	printf("**该职工的联系电话是:%s\n",employee[iNo].cell_phone_number);
	show_age(employee,iNo);
	printf("**该职工的年龄职位是:%d岁\t%s\n",employee[iNo].age,employee[iNo].position);
	printf("**该职工的身份证号是:%s\n",employee[iNo].identity_card_number);
	printf("**该职工的出生日期是:%d年%d月%d日\n",employee[iNo].birthday.year,employee[iNo].birthday.mounth,employee[iNo].birthday.day);
	printf("**该职工的就职日期是:%d年%d月%d日\n",employee[iNo].obtain_employmen_time.year,employee[iNo].obtain_employmen_time.mounth,employee[iNo].obtain_employmen_time.day);
	printf("**该职工的合同年限是:%d年%d月%d日\n",employee[iNo].Contract_expiration_time.year,employee[iNo].Contract_expiration_time.mounth,employee[iNo].Contract_expiration_time.day);
	printf("**该职工的现居地址是:%s%s%s\n",employee[iNo].Now_lives_in.province,employee[iNo].Now_lives_in.city_or_zone,employee[iNo].Now_lives_in.detailed_address);
	printf("**********************************************************\n");	
}
extern void Ways_of_Search(workers_and_staff_members employee[],unsigned int iNo)
{
	char choice;
	int year;
	int mounth;
	int day;
	while(1)
	{
		printf("选择你想要查找的方式：\n");
		printf("按照员工编号查找，请选择1；\n");
		printf("按照员工姓名查找，请选择2；\n");
		printf("按照员工职位查找，请选择3；\n");
		printf("按照出生日期查找，请选择4；\n");
		printf("按照就职日期查找，请选择5；\n");
		printf("按照合同时长查找，请选择6；\n");
		printf("按照手机号码查找，请选择7；\n");
		printf("按照身份证号查找，请选择8；\n");
		printf("返回，请选择Q；\n->");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if(choice=='q'||choice=='Q')
		{
			break;
		}
		switch(choice)
		{
		case '1':
			Search_By_number(employee,iNo);
		break;
		case '2':
			Search_By_name(employee,iNo);
		break;
		case '3':
			Search_By_position(employee,iNo);
		break;
		case '4':
			Search_By_birthay(employee,iNo);
		break;
		case '5':
			Search_By_obtain_employmen_time(employee,iNo);
		break;
		case '6':
			Search_By_Contract_expiration_time(employee,iNo);
		break;
		case '7':
		    Search_By_cell_phone_number(employee,iNo);
		case '8':
			Search_By_identity_card_number(employee,iNo);
		default:
			printf("请输入1~8之间的数！，重新输入请按r,按其他键退出并返回主节面！\n");
			system("PAUSE");
			break;
		}
	}

}
extern void Ways_of_Search_without_change(workers_and_staff_members employee[],unsigned int iNo)
{
	char choice;
	while(1)
	{
		printf("选择你想要查找的方式：\n");
		printf("按照员工编号查找，请选择1；\n");
		printf("按照员工姓名查找，请选择2；\n");
		printf("按照员工职位查找，请选择3；\n");
		printf("按照出生日期查找，请选择4；\n");
		printf("按照就职日期查找，请选择5；\n");
		printf("按照合同时长查找，请选择6；\n");
		printf("按照手机号码查找，请选择7；\n");
		printf("按照身份证号查找，请选择8；\n");
		printf("返回，请选择Q；\n->");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if((choice=='q')||choice=='Q')
		{
			break;
		}
		switch(choice)
		{
		case '1':
			Search_By_number_without_change(employee,iNo);
			break;
		case '2':
			Search_By_name_without_change(employee,iNo);
			break;
		case '3':
			Search_By_position_without_change(employee,iNo);
			break;
		case '4':
			Search_By_birthay_without_change(employee,iNo);
			break;
		case '5':
			Search_By_obtain_employmen_time_without_change(employee,iNo);
			break;
		case '6':
			Search_By_Contract_expiration_time_without_change(employee,iNo);
			break;
		case '7':
			Search_By_number_without_change(employee,iNo);
			break;
		case '8':
			Search_By_identity_card_number_without_change(employee,iNo);
			break;
		default:
			printf("请输入1~8之间的数！，重新输入请按r,按其他键退出并返回主节面！\n");
			system("PAUSE");
			break;
		}
	}
}
extern void Ways_of_Delete(workers_and_staff_members employee[],unsigned int *iNo)
{
	char choice;
	while(1)
	{
		printf("现在请你选择想要删除的方式:\n");
		printf("按照员工编号删除，请选择1；\n");
		printf("按照员工姓名删除，请选择2；\n");
		printf("按照员工职位删除，请选择3；\n");
		printf("按照手机号码删除，请选择4；\n");
		printf("按照出生日期删除，请选择5；\n");
		printf("按照身份证号删除，请选择6；\n");
		printf("想要返回开始界面，请选择Q；\n->");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if(choice=='Q' || choice=='q')
		{
			break;
		}
		switch(choice)
		{
		case '1':
			Delete_employee_information_by_number(employee,iNo);
			break;
		case '2':
			Delete_employee_information_by_name(employee,iNo);
			break;
		case '3':
			Delete_employee_information_by_cell_phone_number(employee,iNo);
			break;
		case '4':
			Delete_employee_information_by_position(employee,iNo);
			break;
		case '5':
			Delete_employee_information_by_birthday(employee,iNo);
			break;
		case '6':
			Delete_employee_information_by_identity_card_number(employee,iNo);
			break;
		default:
			printf("请输入1~6之间的数！，重新输入请按r,按其他键退出并返回主节面！\n");
			break;
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//下面是函数 Ways_of_Delete的二级子函数
//////////////////////////////////////////////////////////////////////////
extern void Delete_employee_information_by_position(workers_and_staff_members employee[],unsigned int *iNo)
{
	input_password();
	char choice;
	int count = *iNo;
	char position[40];
	printf("现在请输入你想要删除的员工的职位：\n->");
	scanf("%s",position);
	int isfind=0;
	int Delete=0;
	int i = 0;
	while(i<count)
	{
		if(strcmp(employee[i].position,position)==0)
		{
			printf("下面是符合筛选条件的职工的信息。请认真确认是否是你要删除的那个！\n");		
			show_employee_information(employee,i);
			printf("要删除这个员工的信息请按Q，跳过请按其他键。\n");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if((choice=='q')||(choice=='Q'))
			{
				employee[i].number=0;
				for(int j=i+1;j<count;j++)
				{
					employee[j-1] = employee[j];
				}
				(*iNo)--;
				count --;
				Delete++;
			}
			else
			{
				i++;
			}
			isfind++;
		}
		else
		{
			i++;
		}
	}
	if(isfind==0)
	{
		printf("对不起，找不到到符合您要求的员工！!\n");

	}
	else
	{
		printf("一共找到了%d个符合您要求的员工，删除了其中的%d个!\n");
	}

}
extern void Delete_employee_information_by_name(workers_and_staff_members employee[],unsigned int *iNo)
{
	input_password();
	char choice;
	int count = *iNo;
	char name[20];
	printf("现在请输入你想要删除的员工的名字：\n->");
	scanf("%s",name);
	int isfind=0;
	int Delete=0;
	int i=0;
	while(i<count)
	{
		if(strcmp(employee[i].name,name)==0)
		{
			printf("下面是符合筛选条件的职工的信息。请认真确认是否是你要删除的那个！\n");		
			show_employee_information(employee,i);
			printf("要删除这个员工的信息请按Q，跳过请按其他。\n->");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if((choice=='q')||(choice=='Q'))
			{
				employee[i].number=0;
				for(int j=i+1;j<count;j++)
				{
					employee[j-1] = employee[j];
				}
				(*iNo)--;
				count--;
				Delete++;
			}
			else
			{
				i++;
			}
			isfind++;
		}
		else
		{
			i++;
		}
	}
	if(isfind==0)
	{
		printf("对不起，找不到到符合您要求的员工！\n像要重新输如请按R，退出程序请按Q,按其他任意键返回主界面!");


	}
	else
	{
		printf("一共找到了%d个符合您要求的员工，删除了其中的%d个!\n想要继续删除请按R，退出程序请按Q,按其他任意键返回主界面!",isfind,Delete);

	}

}
extern void Delete_employee_information_by_number(workers_and_staff_members employee[],unsigned int *iNo)
{
	input_password();
	char choice;
	int count = *iNo;
	int number1;
	int number2;
	printf("现在请输入你想要删除的员工的职工号：\n->");
	scanf("%d",&number1);
	while ((number1/Employee_Number)<1||(number1/Employee_Number)>=10)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%d",&number1);
	}
	printf("现在请再次输入该员工的职工号以此来确认：");
	scanf("%d",&number2);
	while((number1-number2)!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		scanf("%d",&number2);
	}
	int isfind=0;
	int Delete=0;
	int i=0;
	while(i<count)
	{
		if((employee[i].number-number1)==0)
		{
			printf("下面是符合筛选条件的职工的信息。请认真确认是否是你要删除的那个！\n");		
			show_employee_information(employee,i);
			printf("要删除这个员工的信息请按Q，跳过请按其他。\n");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if((choice=='q')||(choice=='Q'))
			{
				employee[i].number=0;
				for(int j=i+1;j<count;j++)
				{
					employee[j-1] = employee[j];
				}
				(*iNo)--;
				count--;
				Delete++;
			}
			else
			{
				i++;
			}
			isfind++;
		}
		else
		{
			i++;
		}
	}
	if(isfind==0)
	{
		printf("对不起，找不到到符合您要求的员工！\n");

	}
	else
	{
		printf("一共找到了%d个符合您要求的员工，删除了其中的%d个!\n",isfind,Delete);

	}

}
extern void Delete_employee_information_by_birthday(workers_and_staff_members employee[],unsigned int *iNo)
{
	input_password();
	char choice;
	int count = *iNo;
	int isfind=0;
	int Delete=0;
	int year;
	int mounth;
	int day;
	while(1)
	{
		printf("输入职工的出生日期(年<>/月/日)。\n输入年之后摁Enter键再输入月，\n输入日同上)->");
		scanf("%d",&year);
		scanf("%d",&mounth);
		scanf("%d",&day);
		if((year<1950)||(year)>(This_year-18)||((mounth)>12)||(mounth)<1||((day)>31))
		{
			printf("日期输入错误！\n请重新输入！");
		}
		else
		{

			break;
		}
	}

	int i = 0;
	while(i<count)
	{
		if((employee[i].birthday.year-year==0)||(employee[i].birthday.mounth-mounth==0)||(employee[i].birthday.day-day==0))
		{
			printf("下面是符合筛选条件的职工的信息。请认真确认是否是你要删除的那个！\n");		
			show_employee_information(employee,i);
			printf("要删除这个员工的信息请按Q，跳过请按其他。\n");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if((choice=='q')||(choice=='Q'))
			{
				employee[i].number=0;
				for(int j=i+1;j<count;j++)
				{
					employee[j-1] = employee[j];
				}
				(*iNo)--;
				count--;
				Delete++;
			}
			else
			{
				i++;
			}
			isfind++;
		}
		else
		{
			i++;
		}
	}
	if(isfind==0)
	{
		printf("对不起，找不到到符合您要求的员工！\n像要重新输如请按R，退出程序请按Q,按其他任意键返回主界面!");


	}
	else
	{
		printf("一共找到了%d个符合您要求的员工，删除了其中的%d个!\n想要继续删除请按R，退出程序请按Q,按其他任意键返回主界面!",isfind,Delete);

	}

}
extern void Delete_employee_information_by_cell_phone_number(workers_and_staff_members employee[],unsigned int *iNo)
{
	back:
	input_password();
	char choice;
	int count = *iNo;
	char number1[11];
	char number2[11];
	printf("现在请输入你想要删除的员工的手机号：\n->");
	scanf("%s",number1);
    while ((strlen(number1)-11)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",&number1);
	}
	printf("现在请再次输入该员工的手机号以此来确认：");
	scanf("%s",number2);
	if((strlen(number1)-strlen(number1))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		goto back;
	}
	int isfind=0;
	int Delete=0;
	int i=0;
	while(i<count)
	{
		if(strcmp(employee[i].cell_phone_number,number2))
		{
			printf("下面是符合筛选条件的职工的信息。请认真确认是否是你要删除的那个！\n");		
			show_employee_information(employee,i);
			printf("要删除这个员工的信息请按Q，跳过请按其他键。\n");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if((choice=='q')||(choice=='Q'))
			{
				employee[i].number=0;
				for(int j=i+1;j<count;j++)
				{
					employee[j-1] = employee[j];
				}
				(*iNo)--;
				count--;
				Delete++;
			}
			else
			{
				i++;
			}
			isfind++;
		}
		else
		{
			i++;
		}
	}
	if(isfind==0)
	{
		printf("对不起，找不到到符合您要求的员工！\n");

	}
	else
	{
		printf("一共找到了%d个符合您要求的员工，删除了其中的%d个!\n",isfind,Delete);

	}

}
extern void Delete_employee_information_by_identity_card_number(workers_and_staff_members employee[],unsigned int *iNo)
{
back:
	input_password();
	char choice;
	int count = *iNo;
	char number1[19];
	char number2[19];
	printf("现在请输入你想要删除的员工的身份证号：\n->");
	scanf("%s",number1);
	while ((strlen(number1)-18)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",&number1);
	}
	printf("现在请再次输入该员工的手机号以此来确认：");
	scanf("%s",number2);
	if((strlen(number1)-strlen(number1))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		goto back;
	}
	int isfind=0;
	int Delete=0;
	int i=0;
	while(i<count)
	{
		if(strcmp(employee[i].identity_card_number,number2))
		{
			printf("下面是符合筛选条件的职工的信息。请认真确认是否是你要删除的那个！\n");		
			show_employee_information(employee,i);
			printf("要删除这个员工的信息请按Q，跳过请按其他键。\n");
			scanf("%c",&choice);
			while(choice=='\n')
			{
				scanf("%c",&choice);
			}
			if((choice=='q')||(choice=='Q'))
			{
				employee[i].number=0;
				for(int j=i+1;j<count;j++)
				{
					employee[j-1] = employee[j];
				}
				(*iNo)--;
				count--;
				Delete++;
			}
			else
			{
				i++;
			}
			isfind++;
		}
		else
		{
			i++;
		}
	}
	if(isfind==0)
	{
		printf("对不起，找不到到符合您要求的员工！\n");

	}
	else
	{
		printf("一共找到了%d个符合您要求的员工，删除了其中的%d个!\n",isfind,Delete);

	}

}
//////////////////////////////////////////////////////////////////////////
//下面是函数Modify_information的二级子函数
//////////////////////////////////////////////////////////////////////////
extern void change_number(struct workers_and_staff_members employee[],unsigned int iNo)
{
	int count = iNo;
    back:
	printf("10位职工号->");
	unsigned long number1;
	scanf("%d",&number1);
	if((number1/Employee_Number)<1||(number1/Employee_Number)>=10)
	{
		printf("输入错误！\n请重新输入！");
        goto back;
	}
	else
	{
		for(int i=0;i<=count;i++)
		{
			unsigned long realnumber = employee[i].number;
			if((realnumber-number1)==0)
			{
				employee[iNo].number=number1;
			}
			else
			{
				printf("警告！无特殊情况不允许修改编号！您真的要修改吗？\n");	
				printf("确认修改请按Y，重新输入按R，退出程序请按Q！\n");	
				char a;
				scanf("%d",&a);
				if((a=='q')||(a=='Q'))
				{
					exit(0);
				}
				else if((a=='r')||(a=='R'))
				{
					goto back;
				}
				else if((a=='y')||(a=='Y'))
				{
					input_password();
					printf("请再次输入以用于确认！\n");
					unsigned long number2;
					scanf("%d",&number2);
					if(number1==number2)
					{
						employee[iNo].number=number2;
					}
					else
					{
						printf("两次输入不符合！系统自动退出\n");
						exit(0);
					}

				}
			}		
		}
	}
}
extern void change_cell_phone_number(struct workers_and_staff_members employee[],unsigned int iNo)
{
	back:
	char choice;
	int count = iNo;
	char number1[12];
	printf("现在请输入11位手机号：\n->");
	scanf("%s",number1);
	while((strlen(number1)-11)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的手机号以此来确认：");
	scanf("%s",employee[iNo].cell_phone_number);
	if((strlen(number1)-strlen(employee[iNo].cell_phone_number))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		goto back;
	}
}
extern void change_identity_card_number(struct workers_and_staff_members employee[],unsigned int iNo)
{
back:
	char choice;
	int count = iNo;
	char number1[19];
	printf("现在请输入18位身份证号：\n->");
	scanf("%s",number1);
	while((strlen(number1)-18)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的身份证号以此来确认：");
	scanf("%s",employee[iNo].identity_card_number);
	if((strlen(number1)-strlen(employee[iNo].identity_card_number))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		goto back;
	}
}
extern void change_name(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("姓名->");
	scanf("%s",employee[iNo].name);

}
extern void change_sex(struct workers_and_staff_members employee[],unsigned int iNo)
{
	while(1)
	{
		printf("输入性别（男为0/女1）\n->");
		if(scanf("%u",&employee[iNo].sex)<=0)
		{
			while(getchar()!='\n');
			printf("输入错误！\n请重新输入！");
			continue;
		}
		if(!(employee[iNo].sex==0||employee[iNo].sex==1))
		{
			printf("输入错误！\n请重新输入！");
			continue;
		}
		break;
	}
}
extern void change_birthday(struct workers_and_staff_members employee[],unsigned int iNo)
{
	while(1)
	{
	    printf("输入职工的出生日期(年/月/日)。\n");
        printf("年（1950-%d）->",This_year);
        scanf("%u",&employee[iNo].birthday.year);
		printf("月（1-12）->");
	    scanf("%u",&employee[iNo].birthday.mounth);
		printf("日（1-31）->");
	    scanf("%u",&employee[iNo].birthday.day);
	    if((employee[iNo].birthday.year<1950)||(employee[iNo].birthday.year)>(This_year-18)||((employee[iNo].birthday.mounth)>12)||((employee[iNo].birthday.mounth)<1)||((employee[iNo].birthday.day)>31))
		{
		    printf("日期输入错误！\n请重新输入！");
		    continue;
		}
		break;
	}	
}
extern void change_position(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("输入职工的职位\n->");
	scanf("%s",employee[iNo].position);

}
extern void change_obtain_employmen_time(struct workers_and_staff_members employee[],unsigned int iNo)
{
	while(1)
	{
		printf("输入职工的入职日期(年/月/日)。\n");
		printf("年（1950-%d）->",This_year);
		scanf("%d",&employee[iNo].obtain_employmen_time.year);
		printf("月（1-12）->");
		scanf("%d",&employee[iNo].obtain_employmen_time.mounth);
		printf("日（1-31）->");
		scanf("%d",&employee[iNo].obtain_employmen_time.day);
		if((employee[iNo].obtain_employmen_time.year<1950)||(employee[iNo].obtain_employmen_time.year)>(This_year-18)||((employee[iNo].obtain_employmen_time.mounth)>12)||((employee[iNo].obtain_employmen_time.mounth)<1)||((employee[iNo].obtain_employmen_time.day)>31))
		{
			printf("日期输入错误！\n请重新输入！");
			continue;
		}
		break;
	}
	

}
extern void change_Contract_expiration_time(struct workers_and_staff_members employee[],unsigned int iNo)
{
	while(1)
	{
		printf("输入职工的公司劳动合同年限(年/月/日)。\n输入年之后摁Enter键再输入月，\n输入日同上)->");
		scanf("%d",&employee[iNo].Contract_expiration_time.year);
		scanf("%d",&employee[iNo].Contract_expiration_time.mounth);
		scanf("%d",&employee[iNo].Contract_expiration_time.day);
		if((employee[iNo].Contract_expiration_time.year+(employee[iNo].Contract_expiration_time.mounth+employee[iNo].Contract_expiration_time.year/30)/12)>MAX_Contract_expiration_time)
		{
			printf("超过最大合同年限！\n请重新输入！");
			continue;
		}
		break;
	}

}
extern void change_Now_lives_in(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("现在输入职工的居住地址：");
	printf("现在输入所在省或省级市(要在最后加‘省\\市')\n->");
	scanf("%s",employee[iNo].Now_lives_in.province);
	printf("现在输入所在市或区(要在最后加‘市\\区')\n->");
	scanf("%s",employee[iNo].Now_lives_in.city_or_zone);
	printf("现在输入该职工的详细地址\n->");
	scanf("%s",employee[iNo].Now_lives_in.detailed_address);

}
extern void change_Other_information_structures(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("输入职工的其他信息。\n->");
	scanf("%s",employee[iNo].Other_information_structures);

}
//////////////////////////////////////////////////////////////////////////
//下面是函数Ways_of_Search的二级子函数
//////////////////////////////////////////////////////////////////////////
extern void Search_By_name(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	printf("请输入员工的名字：\n->");
	char name[20];
	scanf("%s",name);
	char choice;
	unsigned int i;
	int isFind = 0;
	int change = 0;
	for(i=0; i<iNo; i++)
	{
		if(strcmp(employee[i].name,name)==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
		back:
		printf("你想要修改该员工的数据吗？Y/N?\n");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if((choice=='y')||(choice=='Y'))
		{
			Modify_information(employee,iNo);
			change++;

		}
		else if((choice=='n')||(choice=='N'))
		{
			continue;
		}
		else
		{
			printf("输入了无效字符！\n");
			printf("系统将自动返回！\n");
			system("cls");
			goto back;
		}

	}
	if(isFind==0)
	{
		printf("没有找到姓名为%s的职工！",name);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到姓名为%s的职工%d个，您一共修改了其中的%d个！",name,isFind,change);
		system("PAUSE");
	}
}
extern void Search_By_number(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	printf("请输入员工的员工编号：\n->");
	unsigned long number;
    back1:
	scanf("%d",&number);
	if((number/Employee_Number)<1||((number/Employee_Number)>=10))
	{
		printf("编号输入错误！\n请重新输入！");
		goto back1;
	}
	char choice;
	unsigned int i;
	int isFind=0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].number)-number)==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			int isFind=1;
		}
		back:
		printf("你想要修改该员工的数据吗？Y/N?\n");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if((choice=='y')||(choice=='Y'))
		{
			Modify_information(employee,iNo);
		}
		else if((choice=='n')||(choice=='N'))
		{
			continue;
		}
		else
		{
			printf("输入了无效字符！\n");
			printf("系统将自动返回！\n");
			system("cls");
			goto back;
		}
	}
	if(isFind==0)
	{
		printf("没有找到编号为%d的职工！\n",number);
		system("PAUSE");
	}
}
extern void Search_By_cell_phone_number(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	back1:
	char choice;
	char number1[12];
	char number2[12];
	printf("现在请输入11位手机号：\n->");
	scanf("%s",number1);
	while ((strlen(number1)-11)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的手机号以此来确认：");
	scanf("%s",number2);
	if((strlen(number1)-strlen(number1))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		scanf("%s",number2);
		goto back1;
	}
	unsigned int i;
	int isFind = 0;
	int change = 0;
	for(i=0;i<iNo;i++)
	{
		if((strlen(number1)-strlen(employee[iNo].cell_phone_number))==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
back:
		printf("你想要修改该员工的数据吗？Y/N?\n");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if((choice=='y')||(choice=='Y'))
		{
			Modify_information(employee,iNo);
			change++;
		}
		else if((choice=='n')||(choice=='N'))
		{
			continue;
		}
		else
		{
			printf("输入了无效字符！\n");
			printf("系统将自动返回！\n");
			system("cls");
			goto back;
		}

	}
	if(isFind==0)
	{
		printf("没有找到手机号为%s的职工！\n",number1);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到手机号码为%s的职工%d个，您一共修改了其中的%d个！\n",number1,isFind,change);
		system("PAUSE");
	}
}
extern void Search_By_identity_card_number(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
back1:
	char choice;
	char number1[19];
	char number2[19];
	printf("现在请输入18位身份证号：\n->");
	scanf("%s",number1);
	while ((strlen(number1)-18)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的身份证号以此来确认：");
	scanf("%s",number2);
	if((strlen(number1)-strlen(number1))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		scanf("%s",number2);
		goto back1;
	}
	unsigned int i;
	int isFind = 0;
	int change = 0;
	for(i=0;i<iNo;i++)
	{
		if((strlen(number1)-strlen(employee[iNo].identity_card_number))==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
back:
		printf("你想要修改该员工的数据吗？Y/N?\n");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if((choice=='y')||(choice=='Y'))
		{
			Modify_information(employee,iNo);
			change++;
		}
		else if((choice=='n')||(choice=='N'))
		{
			continue;
		}
		else
		{
			printf("输入了无效字符！\n");
			printf("系统将自动返回！\n");
			system("cls");
			goto back;
		}

	}
	if(isFind==0)
	{
		printf("没有找到身份证号为%s的职工！\n",number1);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到身份证号为%s的职工%d个，您一共修改了其中的%d个！\n",number1,isFind,change);
		system("PAUSE");
	}
}
extern void Search_By_position(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	printf("请输入员工的职位：\n->");
	char position[40];
	scanf("%s",position);
	char choice;
	unsigned int i;
	int isFind = 0;
	int change = 0;
	for(i=0; i<iNo; i++)
	{
		if(strcmp(employee[i].position,position)==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
		back:
		printf("你想要修改该员工的数据吗？Y/N?\n");
		scanf("%c",&choice);
		while(choice=='\n')
		{
			scanf("%c",&choice);
		}
		if((choice=='y')||(choice=='Y'))
		{
			Modify_information(employee,iNo);
			change++;
		}
		else if((choice=='n')||(choice=='N'))
		{
			continue;
		}
		else
		{
			printf("输入了无效字符！\n");
			printf("系统将自动返回！\n");
			system("cls");
			goto back;
		}

	}
	if(isFind==0)
	{
		printf("没有找到职位为%s的职工！\n",position);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到职位为%s的职工%d个，您一共修改了其中的%d个\n！",position,isFind,change);
		system("PAUSE");
	}
}
extern void Search_By_birthay(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	int year;
	int mounth;
	int day;
	printf("请输入员工的出生日期：\n");
	printf("按照XXXX(年)XX(月)/XX(日)的格式：\n->");
	scanf("%d //%d//%d",&year,&mounth,&day);
	char choice;
	unsigned int i;
	int isFind = 0;
	int change = 0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].birthday.year)-year)==0)
		{
			if(((employee[i].birthday.mounth)-mounth)==0)
			{
				if(((employee[i].birthday.day)-day)==0)
				{
					back:
					show_employee_information(employee,i);
					printf("******************************************\n");
					isFind++;
					printf("你想要修改该员工的数据吗？Y/N?\n");
					scanf("%c",&choice);
					while(choice=='\n')
					{
						scanf("%c",&choice);
					}
					if((choice=='y')||(choice=='Y'))
					{
						Modify_information(employee,iNo);
						change++;
					}
					else if((choice=='n')||(choice=='N'))
					{
						continue;
					}
					else
					{
						printf("输入了无效字符！\n");
						printf("系统将自动返回！\n");
						system("cls");
						goto back;
					}
				}
			}
		}
	}
	if(isFind==0)
	{
		printf("没有找到出生日期为%d %d %d的职工！\n",year,mounth,day);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到出生日期为%d %d %d的职工%d个，您一共修改了其中的%d个！\n",year,mounth,day,isFind,change);
		system("PAUSE");
	}
}
extern void Search_By_obtain_employmen_time(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	int year;
	int mounth;
	int day;
	printf("请输入员工的就职日期：\n");
	printf("按照XXXX(年)XX(月)/XX(日)的格式：\n->");
	scanf("%d //%d//%d",&year,&mounth,&day);
	char choice;
	unsigned int i;
	int isFind = 0;
	int change = 0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].obtain_employmen_time.year)-year)==0)
		{
			if(((employee[i].obtain_employmen_time.mounth)-mounth)==0)
			{
				if(((employee[i].obtain_employmen_time.day)-day)==0)
				{
					back:
					show_employee_information(employee,i);
					printf("******************************************\n");
					isFind++;
					printf("你想要修改该员工的数据吗？Y/N?\n");
					scanf("%c",&choice);
					while(choice=='\n')
					{
						scanf("%c",&choice);
					}
					if((choice=='y')||(choice=='Y'))
					{
						Modify_information(employee,iNo);
						change++;
					}
					else if((choice=='n')||(choice=='N'))
					{
						continue;
					}
					else
					{
						printf("输入了无效字符！\n");
						printf("系统将自动返回！\n");
						system("cls");
						goto back;
					}

				}
			}
		}
	}
	if(isFind==0)
	{
		printf("没有找到就职日期为%d %d %d的职工！\n",year,mounth,day);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到就职日期为%d %d %d的职工%d个，您一共修改了其中的%d个！\n",year,mounth,day,isFind,change);
		system("PAUSE");
	}
}
extern void Search_By_Contract_expiration_time(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	int year;
	int mounth;
	int day;
	printf("请输入员工的合同时长：\n");
	printf("按照XXXX(年)XX(月)/XX(日)的格式：\n->");
	scanf("%d //%d//%d",&year,&mounth,&day);
	char choice;
	unsigned int i;
	int isFind = 0;
	int change = 0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].Contract_expiration_time.year)-year)==0)
		{
			if(((employee[i].Contract_expiration_time.mounth)-mounth)==0)
			{
				if(((employee[i].Contract_expiration_time.day)-day)==0)
				{
					back:
					change++;
					show_employee_information(employee,i);
					printf("******************************************\n");
					isFind++;
					printf("你想要修改该员工的数据吗？Y/N?\n");
					scanf("%c",&choice);
					while(choice=='\n')
					{
						scanf("%c",&choice);
					}
					if((choice=='y')||(choice=='Y'))
					{
						int Modify_information(workers_and_staff_members employee[],unsigned int iNo,int choice);
						change++;
					}
					else if((choice=='n')||(choice=='N'))
					{
						continue;
					}
					else
					{
						printf("输入了无效字符！\n");
						printf("系统将自动返回！\n");
						system("cls");
						goto back;
					}
				}
			}
		}
	}
	if(isFind==0)
	{
		printf("没有找到合同时长为%d %d %d的职工！\n",year,mounth,day);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到合同时长为%d %d %d的职工%d个，您一共修改了其中的%d个！\n",year,mounth,day,isFind,change);
		system("PAUSE");
	}
}
//////////////////////////////////////////////////////////////////////////
//下面是函数Ways_of_Search_without_change的二级字函数
//////////////////////////////////////////////////////////////////////////
extern void Search_By_name_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	printf("请输入员工的名字：\n->");
	char name[20];
	scanf("%s",name);
	unsigned int i;
	int isFind = 0;
	for(i=0; i<iNo; i++)
	{
		if(strcmp(employee[i].name,name)==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
	}
	if(isFind==0)
	{
		printf("没有找到姓名为%s的职工！\n",name);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到姓名为%s的职工%d个！\n",name,isFind);
		system("PAUSE");
	}
}
extern void Search_By_number_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	printf("请输入员工的员工编号：\n->");
	unsigned long number;
    back:
	scanf("%d",&number);
	if((number/Employee_Number)<1||((number/Employee_Number)>=10))
	{
		printf("编号输入错误！\n请重新输入！");
		goto back;
	}
    unsigned 	int i;
	int isFind = 0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].number)-number)==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind=1;
		}
	}
	if(isFind==0)
	{
		printf("没有找到编号为%d的职工！\n",number);
		system("PAUSE");
	}
}
extern void Search_By_cell_phone_number_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
    back1:
	char choice;
	char number1[12];
	char number2[12];
	printf("现在请输入11位手机号：\n->");
	scanf("%s",number1);
	while ((strlen(number1)-11)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的手机号以此来确认：");
	scanf("%s",number2);
	if((strlen(number1)-strlen(number1))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		scanf("%s",number2);
		goto back1;
	}
	unsigned int i;
	int isFind = 0;
	for(i=0;i<iNo;i++)
	{
		if((strlen(number1)-strlen(employee[iNo].cell_phone_number))==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
	}
	if(isFind==0)
	{
		printf("没有找到手机号为%s的职工！\n",number2);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到手机号为%s的职工为%d个！\n",number2,isFind);
		system("PAUSE");
	}
}
extern void Search_By_identity_card_number_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
back1:
	char choice;
	char number1[19];
	char number2[19];
	printf("现在请输入18位身份证号：\n->");
	scanf("%s",number1);
	while ((strlen(number1)-18)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的18位身份证号以此来确认：");
	scanf("%s",number2);
	if((strlen(number1)-strlen(number1))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		scanf("%s",number2);
		goto back1;
	}
	unsigned int i;
	int isFind = 0;
	for(i=0;i<iNo;i++)
	{
		if((strlen(number1)-strlen(employee[iNo].identity_card_number))==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
	}
	if(isFind==0)
	{
		printf("没有找到身份证号为%s的职工！\n",number2);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到身份证号为%s的职工为%d个！\n",number2,isFind);
		system("PAUSE");
	}
}
extern void Search_By_position_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	printf("请输入员工的职位：\n->");
	char position[40];
	scanf("%s",position);
	unsigned int i;
	int isFind = 0;
	for(i=0; i<iNo; i++)
	{
		if(strcmp(employee[i].position,position)==0)
		{
			show_employee_information(employee,i);
			printf("******************************************\n");
			isFind++;
		}
	}
	if(isFind==0)
	{
		printf("没有找到职位为%s的职工！\n",position);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到职位为%s的职工%d个\n！",position,isFind);
		system("PAUSE");
	}
}
extern void Search_By_birthay_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	int year;
	int mounth;
	int day;
	printf("请输入员工的出生日期：\n");
	printf("按照XXXX(年)XX(月)/XX(日)的格式：\n->");
	scanf("%d //%d//%d",&year,&mounth,&day);
	unsigned int i;
	int isFind = 0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].birthday.year)-year)==0)
		{
			if(((employee[i].birthday.mounth)-mounth)==0)
			{
				if(((employee[i].birthday.day)-day)==0)
				{
					show_employee_information(employee,i);
					printf("******************************************\n");
					isFind++;
				}
			}
		}
	}
	if(isFind==0)
	{
		printf("没有找到出生日期为%d %d %d的职工！\n",year,mounth,day);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到出生日期为%d %d %d的职工%d个！\n",year,mounth,day,isFind);
		system("PAUSE");
	}
}
extern void Search_By_obtain_employmen_time_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	int year;
	int mounth;
	int day;
	printf("请输入员工的就职日期：\n");
	printf("按照XXXX(年)XX(月)/XX(日)的格式：\n->");
	scanf("%d //%d//%d",&year,&mounth,&day);
	unsigned int i;
	int isFind = 0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].obtain_employmen_time.year)-year)==0)
		{
			if(((employee[i].obtain_employmen_time.mounth)-mounth)==0)
			{
				if(((employee[i].obtain_employmen_time.day)-day)==0)
				{
					show_employee_information(employee,i);
					printf("******************************************\n");
					isFind++;
				}
			}
		}
	}
	if(isFind==0)
	{
		printf("没有找到就职日期为%d %d %d的职工！\n",year,mounth,day);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到就职日期为%d %d %d的职工%d个！n",year,mounth,day,isFind);
		system("PAUSE");
	}
}
extern void Search_By_Contract_expiration_time_without_change(workers_and_staff_members employee[],unsigned int iNo)//在这个地方用iNo，是因为我准备用一个函数来动态的从文件中发现有iNo个员工数据
{
	int year;
	int mounth;
	int day;
	printf("请输入员工的合同时长：\n");
	printf("按照XXXX(年)XX(月)/XX(日)的格式：\n->");
	scanf("%d //%d//%d",&year,&mounth,&day);
	unsigned int i;
	int isFind = 0;
	for(i=0; i<iNo; i++)
	{
		if(((employee[i].Contract_expiration_time.year)-year)==0)
		{
			if(((employee[i].Contract_expiration_time.mounth)-mounth)==0)
			{
				if(((employee[i].Contract_expiration_time.day)-day)==0)
				{
					show_employee_information(employee,i);
					printf("******************************************\n");
					isFind++;
				}
			}
		}
	}
	if(isFind==0)
	{
		printf("没有找到合同时长为%d %d %d的职工！\n",year,mounth,day);
		system("PAUSE");
	}
	else if(isFind)
	{
		printf("共找到合同时长为%d %d %d的职工%d个！\n",year,mounth,day,isFind);
		system("PAUSE");
	}
}
//////////////////////////////////////////////////////////////////////////
//下面是函数change_information的二级字函数
//////////////////////////////////////////////////////////////////////////
extern void add_new_number(struct workers_and_staff_members employee[],unsigned int iNo)
{
	int count = iNo;
	while(1)
	{
back:
		printf("10位职工号->");
		unsigned long number;
		scanf("%d",&number);
		if((number/Employee_Number)<1||(number/Employee_Number)>=10)
		{
			printf("输入错误！\n重新输入请按R，退出请按Q！");
			char a;
			scanf("%c",&a);
				if(a=='q'||a=='Q')
				{
					exit(0);
				}
				else
				{
					goto back;
				}
		}
		else
		{
			for(int i=0;i<=count;i++)
			{
				if((employee[i].number-number)==0)
				{
					printf("已有相同编号的职工！无法进行操作！\n重新输入请按R，退出请按Q！\n");	
					char b;
					scanf("%c",&b);
						if(b=='q'||b=='Q')
						{
							exit(0);
						}
						else
						{
							goto back;
						}
				}		
			}
			employee[iNo].number=number;
			break;
		}
	}
}
extern void add_new_name(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("姓名->");
	scanf("%s",employee[iNo].name);

}
extern void add_new_sex(struct workers_and_staff_members employee[],unsigned int iNo)
{
	while(1)
	{
		printf("输入性别（男为0/女1）\n->");
		if(scanf("%u",&employee[iNo].sex)<=0)
		{
			while(getchar()!='\n');
			printf("输入错误！\n请重新输入！");
			continue;
		}
		if(!(employee[iNo].sex==0||employee[iNo].sex==1))
		{
			printf("输入错误！\n请重新输入！");
			continue;
		}
		break;
	}
}
extern void add_new_cell_phone_number(struct workers_and_staff_members employee[],unsigned int iNo)
{
	back:
	char choice;
	char number1[12];
	char number2[12];
	printf("现在请输入11位手机号：\n->");
	scanf("%s",number1);
	while ((strlen(number1)-11)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的手机号以此来确认：");
	scanf("%s",employee[iNo].cell_phone_number);
	if((strlen(number1)-strlen(employee[iNo].cell_phone_number))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		goto back;
	}
	
}
extern void add_new_identity_card_number(struct workers_and_staff_members employee[],unsigned int iNo)
{
back:
	char choice;
	char number1[19];
	printf("现在请输入18位身份证号：\n->");
	scanf("%s",number1);
	while ((strlen(number1)-18)!=0)
	{
		printf("输入错误！\n请重新输入！\n->");
		scanf("%s",number1);
	}
	printf("现在请再次输入该员工的18位身份证号以此来确认：");
	scanf("%s",employee[iNo].identity_card_number);
	if((strlen(number1)-strlen(employee[iNo].identity_card_number))!=0)
	{
		printf("两次输入的数据不符合，请重新输入！");
		goto back;
	}

}
extern void add_new_birthday(struct workers_and_staff_members employee[],unsigned int iNo)
{
	while(1)
	{
		printf("输入职工的出生日期(年/月/日)。\n");
		printf("年（1950-%d）->",This_year);
		scanf("%u",&employee[iNo].birthday.year);
		printf("月（1-12）->");
		scanf("%u",&employee[iNo].birthday.mounth);
		printf("日（1-31）->");
		scanf("%u",&employee[iNo].birthday.day);
		if((employee[iNo].birthday.year<1950)||(employee[iNo].birthday.year)>(This_year-18)||((employee[iNo].birthday.mounth)>12)||((employee[iNo].birthday.mounth)<1)||((employee[iNo].birthday.day)>31))
		{
			printf("日期输入错误！\n请重新输入！");
			continue;
		}
		break;
	}	
}
extern void add_new_position(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("输入职工的职位\n->");
	scanf("%s",employee[iNo].position);

}
extern void add_Now_lives_in(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("现在输入职工的居住地址：");
	printf("现在输入所在省或省级市(要在最后加‘省\\市’)\n->");
	scanf("%s",employee[iNo].Now_lives_in.province);
	printf("现在输入所在市或区(要在最后加‘市\\区')\n->");
	scanf("%s",employee[iNo].Now_lives_in.city_or_zone);
	printf("现在输入该职工的详细地址\n->");
	scanf("%s",employee[iNo].Now_lives_in.detailed_address);

}
extern void add_new_obtain_employmen_time(struct workers_and_staff_members employee[],unsigned int iNo)
{
	back:
	printf("输入职工的入职日期(年/月/日)。\n");
	printf("年（1950-%d）->",This_year);
	scanf("%d",&employee[iNo].obtain_employmen_time.year);
	printf("月（1-12）->");
	scanf("%d",&employee[iNo].obtain_employmen_time.mounth);
	printf("日（1-31）->");
	scanf("%d",&employee[iNo].obtain_employmen_time.day);
	if((employee[iNo].obtain_employmen_time.year<1950)||(employee[iNo].obtain_employmen_time.year)>(This_year-18)||((employee[iNo].obtain_employmen_time.mounth)>12)||((employee[iNo].obtain_employmen_time.mounth)<1)||((employee[iNo].obtain_employmen_time.day)>31))
	{
		printf("日期输入错误！\n请重新输入！");
		goto back;
	}
}
extern void add_new_Contract_expiration_time(struct workers_and_staff_members employee[],unsigned int iNo)
{
	while(1)
	{
		printf("输入职工的公司劳动合同年限(年/月/日)。\n输入年之后摁Enter键再输入月，\n输入日同上)->");
		scanf("%d",&employee[iNo].Contract_expiration_time.year);
		scanf("%d",&employee[iNo].Contract_expiration_time.mounth);
		scanf("%d",&employee[iNo].Contract_expiration_time.day);
		if((employee[iNo].Contract_expiration_time.year+(employee[iNo].Contract_expiration_time.mounth+employee[iNo].Contract_expiration_time.year/30)/12)>MAX_Contract_expiration_time)
		{
			printf("超过最大合同年限！\n请重新输入！");
			continue;
		}
		break;
	}

}
extern void add_new_Other_information_structures(struct workers_and_staff_members employee[],unsigned int iNo)
{
	printf("输入职工的其他信息。\n->");
	scanf("%s",employee[iNo].Other_information_structures);

}