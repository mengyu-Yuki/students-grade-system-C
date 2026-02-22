//主函数部分 

#include<stdio.h>
#include<stdlib.h>
//调用“清屏” 需要用到 
#include"student.h"


int main()
{   Student stu[MAX];
     
    int n=loadFile(stu);//从文件中读取学生的个数 
    
	int choice;
	
	while(1)
	
	{    //死循环显示菜单 
	
		showMenu();
		scanf("%d",&choice);
		
		//区分switch和while里面的break跳出循环 
		
		switch(choice)
		{
			case 1:
				addStudent(stu,&n);
	//为什么addstudent和deletestudent都是传输地址
	//答： 需要在函数内部修改外面的整数变量，就把参数写成int *n 
				break;
			case 2:
			    showAll(stu,n);
			    break;
			case 3:
				searchById(stu, n);
				break;
			case 4:
				modifyStudent(stu,n);
				break;
			case 5:
				deleteStudent(stu,&n);
				break;
			case 6:
				sortByTotal(stu, n);
				break;
			case 7:
				saveFile(stu,n);
				printf("已保存\n");
			case 0:
				
				//退出显示菜单 
				 
				printf("退出系统\n");
				return 0;
			default:
				printf("输入错误，请重新输入\n");
			
			 
		}
		printf("按回车继续");
		getchar();//吃掉上一次输入数字残留的回车\r
		getchar();//接受用户的回车 
		
		system("cls"); //windows清屏  
	}
}
