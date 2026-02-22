//功能实现部分 

#include<stdio.h>
#include<stdlib.h>
#include"student.h"

//----------显示菜单选项部分----------
void showMenu() 
{
	printf("---------学生成绩管理系统--------\n");
	
	printf("1.添加学生\n");
	printf("2.查看全部\n");
	printf("3.按学号查询\n");
	printf("4.修改成绩\n");
	printf("5.删除学生\n");
	printf("6.按总分排序\n");
	printf("7.保存到文件\n");
	printf("0.退出\n");
	printf("------------------");	
}
   //具体功能 
   //-----------------------------------添加学生 ------------------------
void addStudent(Student stu[],int *n) 
//传输地址  
{
	//如果学生已满 则不再添加
	if(*n>=MAX) 
	{
		printf("已满，不再添加\n");
		return;
	}
	//****
	Student *s=&stu[*n];
	printf("请输入学号:");
	scanf("%d",&s->id);
	printf("请输入姓名:");
    scanf("%s",s->name);
	printf("请输入语文成绩:");
	scanf("%f",&s->china);
	printf("请输入数学成绩:");
	scanf("%f",&s->math);
	printf("请输入英语成绩:");
	scanf("%f",&s->english);
	//计算总分
	s->total=s->china+s->math+s->english;
	
    //学生数量加一	
	(*n)++;
	
	printf("添加学生成功\n");		
}


  //-------------------------------显示所有学生-------------------------
void showAll(Student stu[],int n) 
{
	if(n==0)
	{
		printf("无学生\n");
		return;
	}
	
	//打印表头
	 
	printf("学号\t姓名\t语文\t数学\t英语\t总分\n");
	
	//遍历学生的信息并逐个打印 
	for(int i=0;i<n;i++){
		printf("%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",
		stu[i].id,
		stu[i].name,
		stu[i].china,
		stu[i].math,
		stu[i].english,
		stu[i].total);		
	}
}
//------------------------按学号查询学生----------
void searchById(Student stu[],int n) 
{
	int id,i;
	printf("输入要查询的学号：");
	scanf("%d",&id);
	
	//比对学号 
	for(i=0;i<n;i++)
	{
		if(stu[i].id==id)
		{
		printf("学生姓名：%s,总分为：%.1f\n",stu[i].name,stu[i].total);
		return;
		}
	}
	printf("未找到该学号对应的学生\n");
}

//------------------------修改学生成绩--------------
void modifyStudent(Student stu[],int n) 
{
	int id,i;
	printf("请输入要修改的学生学号：");
	scanf("%d",&id);
	
	//找学生
	for(i=0;i<n;i++) 
	{ if(stu[i].id==id)
	  {
	  	printf("输入新的语文成绩：");
		scanf("%f",&stu[i].china);
		
		printf("输入新的数学成绩：");
		scanf("%f",&stu[i].math);
		
		printf("输入新的英语成绩：");
		scanf("%f",&stu[i].english);
		
		stu[i].total=stu[i].china+stu[i].math+stu[i].english;
		
		printf("成绩修改成功\n");
		return;
	  }		
	}
	printf("未找到此学生 \n");
}
//--------------------删除学生--------------------------
 void deleteStudent(Student stu[],int *n)
 {
 	int id,i,j;
 	printf("请输入要删除的学号：");
 	scanf("%d",&id);
 	
 	//找学生
	 for(i=0;i<*n;i++) 
	  if(stu[i].id==id)
	  {
	  	for(j=i;j<*n-1;j++)
	  	{
	  		stu[j]=stu[j+1];
		  }
		  (*n)--;
		  printf("删除学生成功\n");
    	  return;
	  }
}

	  
 
 
 
 //------------------按照总分排序（冒泡排序）---------- 
 void sortByTotal(Student stu[],int n)
 {
 	int i,j;
 	Student temp;//交换变量
	 
	 for(i=0;i<n-1;i++) 
	 {
	 	for(j=0;j<n-1-i;j++)
	 	{
	 		if(stu[j].total>stu[j+1].total)
	 		{
	 			temp=stu[j];
	 			stu[j]=stu[j+1];
	 			stu[j+1]=temp;
			 }
		 }
	 }	 
 	
 }
 
 
 
 
 //----------------保存数据到文件---------------
 void saveFile(Student stu[],int n)
 {  
 	FILE*fp=fopen("data.txt","w");
 	
 	
	 if(fp==NULL) 
	 {
	 	printf("文件保存失败\n");
	 	return;
	 }
	 
	 fprintf(fp,"学号 姓名 语文 数学 英语\n");
	 //把每个学生的数据写入文件
	 for(int i=0;i<n;i++) 
	 {
	 	fprintf(fp,"%d %s %.2f %.2f %.2f %.2f\n",
		 stu[i].id,
		 stu[i].name,
		 stu[i].china,
		 stu[i].math,
		 stu[i].english,
		 stu[i].total);
	 }
 	fclose(fp);
 	
 }
//------------------加载学生个数---------------- 
 int loadFile(Student stu[]) 
 {
 	FILE*fp=fopen("data.txt","r");
 	int n=0;
 	char buffer[100];/////用来读表头的临时数组 
 	
 	if(fp==NULL)
 	{
 		return 0;
	 }
	 //跳过表头 
     fgets(buffer,sizeof(buffer),fp);
	 while (fscanf(fp, "%d %s %f %f %f %f",
	                   &stu[n].id,
					   stu[n].name,
					   &stu[n].china,
					   &stu[n].math,
					   &stu[n].english,
					   &stu[n].total)!=EOF)//只要没读到文件末尾，就继续读 
					   {
					   	n++;
					   }
		fclose(fp);
		return n;
 }
 
  
 
 
 







