// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//
//在此处引用程序需要的其他头文件
#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//
//在此处定义
#define MAX_INFO_COUNT 5000//定义该程序所能容纳的最大数据量
#define MAX_Contract_expiration_time 10//定义该公司所签合同的最大年限
#define This_year 2012
#define Employee_Number 1000000000//用员工的编号除以改数据，只有大于1，小于10的符合要求
//                      1209040122
#define Cell_phone_number 10000000000//用于确认手机号码
//                        18652680086
#define PassWord 123456//用于密码认证，防止随意的修改
////////////////////
//
//在此处引用结构体
struct Time
{
	unsigned int year;
	unsigned int mounth;
	unsigned int day;

};
struct Location
{
	char province[16];//省或省级市
	char city_or_zone[20];//市或区
	char detailed_address[100];//详细住址
};
struct  workers_and_staff_members//定义劳工这个结构体变量
{
	unsigned long number;//是指员工编号
	char name[20];
	unsigned int sex;
	unsigned int age;
	char cell_phone_number[12];
	char identity_card_number[19];
	char position[40];//postition:职位。一般不会超过20个字。
	struct Time obtain_employmen_time;//开始工作的日期
	struct Time Contract_expiration_time;//公司劳动合同年限;
	struct Location Now_lives_in;
	struct Time birthday;
	char Other_information_structures[1000];//用来说明该职工的其他信息
};
//
//
//
//在此处声明函数
extern int laod_informaion(struct workers_and_staff_members employee[],int MaxCount);
extern int Save(workers_and_staff_members employee[],unsigned int iNo);
extern int Modify_information(workers_and_staff_members employee[],unsigned int iNo);
extern void welcome_to_use();
extern void Thankyou_to_use();
extern void showtime();
extern void input_password();
extern void change_information(struct workers_and_staff_members employee[],unsigned int iNo);
extern void show_age(struct workers_and_staff_members employee[],unsigned int iNo);
extern void show_employee_information(workers_and_staff_members employee[],unsigned int iNo);
extern void input_information(struct workers_and_staff_members employee[],unsigned int iNo);
extern void Ways_of_Search(workers_and_staff_members employee[],unsigned int iNo);
extern void Ways_of_Search_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Ways_of_Delete(workers_and_staff_members employee[],unsigned int *count);
//////////////////////////////////////////////////////////////////////////
extern void change_number(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_name(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_sex(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_cell_phone_number(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_birthday(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_position(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_obtain_employmen_time(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_Now_lives_in(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_Contract_expiration_time(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_Other_information_structures(struct workers_and_staff_members employee[],unsigned int iNo);
extern void change_identity_card_number(struct workers_and_staff_members employee[],unsigned int iNo);
//////////////////////////////////////////////////////////////////////////
extern void Search_By_name(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_number(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_position(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_cell_phone_number(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_identity_card_number(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_birthay(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_obtain_employmen_time(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_Contract_expiration_time(workers_and_staff_members employee[],unsigned int iNo);
//////////////////////////////////////////////////////////////////////////
extern void Search_By_name_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_number_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_position_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_cell_phone_number_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_identity_card_number_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_birthay_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_obtain_employmen_time_without_change(workers_and_staff_members employee[],unsigned int iNo);
extern void Search_By_Contract_expiration_time_without_change(workers_and_staff_members employee[],unsigned int iNo);
//////////////////////////////////////////////////////////////////////////
extern void Delete_employee_information_by_position(workers_and_staff_members employee[],unsigned int *count);
extern void Delete_employee_information_by_name(workers_and_staff_members employee[],unsigned int *count);
extern void Delete_employee_information_by_number(workers_and_staff_members employee[],unsigned int *count);
extern void Delete_employee_information_by_birthday(workers_and_staff_members employee[],unsigned int *count);
extern void Delete_employee_information_by_cell_phone_number(workers_and_staff_members employee[],unsigned int *iNo);
extern void Delete_employee_information_by_identity_card_number(workers_and_staff_members employee[],unsigned int *iNo);
//////////////////////////////////////////////////////////////////////////
extern void add_new_number(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_name(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_sex(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_cell_phone_number(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_identity_card_number(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_birthday(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_position(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_obtain_employmen_time(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_Contract_expiration_time(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_Now_lives_in(struct workers_and_staff_members employee[],unsigned int iNo);
extern void add_new_Other_information_structures(struct workers_and_staff_members employee[],unsigned int iNo);
