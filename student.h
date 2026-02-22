//头文件 
//防止头文件重复包含操作 

#ifndef STUDENT_H
#define STUDENT_H //必须是大写 
#define MAX 100

//结构体Student存放学生的信息 
typedef struct{
	int id;
	char name[20];
	float china;
	float math;
	float english;
	float total;
}Student;

//函数声明 be like

void showMenu();//显示功能菜单 
void addStudent(Student stu[], int *n);//添加学生 
void showAll(Student stu[], int n);//显示所有学生 
void searchById(Student stu[], int n);//学号查找学生 
void modifyStudent(Student stu[], int n);//修改学生成绩 
void deleteStudent(Student stu[], int *n);//删除学生 
void sortByTotal(Student stu[], int n);//按总分 排序 
void saveFile(Student stu[], int n);//保存 
int loadFile(Student stu[]);//文件加载 

#endif
 

