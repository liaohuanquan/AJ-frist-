/*
                   _ooOoo_
                  o8888888o
                  88" . "88          ***********
                  (| -_- |)          *老师捞捞 *
                  O\  =  /O          *********** 
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
              
              
            C语言学生信息管理系统设计
			 220746廖焕权3122002455 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h> //清屏头文件 
#include <unistd.h> // 添加用于 usleep 的头文件
typedef struct Student
{
    char num[20];
    char name[20];
    char sex;
    int age;
    int score;
} Student_t;
typedef struct class
{
    Student_t stu_arr[50]; // 这个班级最多有50个学生
    unsigned int index;    // 当前班级学生的个数
} class_t;                 // 班级的类

void show();
int student_one(class_t *class);
int student_interp(class_t *class);
int student_delete(class_t *class);
int student_changed(class_t *class);
int student_inquire(class_t *class);
int student_print(class_t *class);
int student_score(class_t *class);
int student_sort(class_t *class);
int student_sort_num(class_t *class);
float student_score_avg(class_t *class);
void readStu(class_t *class);
int saveStu(class_t *class);
//主函数部分 
int main(int argc, char const *argv[])
{
	
	int progress;
for (progress = 0; progress <= 100; progress++) {
    system("cls");
    printf("Loading: [%-50s] %d%%\n", "================================================", progress);
    // 延迟一段时间，模拟加载过程
    usleep(30000); 
    printf("\r");
}

// 清空屏幕
system("cls");


    int id = 0;
    int code = 0;
    int chose = 0;
    class_t *class = (class_t *)malloc(sizeof(class_t));
    if (class == NULL)
    {
        printf("malloc memory failed!\n");
        return -1;
    }
    class->index = 0;
    while (1)
    {
        printf("*********|五口巴学生管理系统|*********\n");//登陆界面部分 
        printf("请输入登录账号->（初始账号为10086）\n");
        scanf("%d", &id);
        printf("请输入登录密码->（初始密码为10086）\n");
        scanf("%d", &code);
        
        
        
        
        ////////////////////////////////////////////////////////////////////////////////
        if (id == 10086 && code == 10086)//这里修改账号密码 //////////////////////////// 
        //////////////////////////////////////////////////////////////////////////////// 
        
        
        
        
        
        
        
        {
            printf("*************|登录成功|*************\n");
            while (1)
            {
                printf("请选择所需要的功能(输入0进入功能菜单)：\n");
                scanf("%d", &chose);
                system ("cls");//清屏 
                switch (chose)
                {
                case 0:
                    show();
                    break;
                case 1:
                    student_interp(class);
                    break;
                case 2:
                    student_delete(class);
                    break;
                case 3:
                    student_changed(class);
                    break;
                case 4:
                    student_inquire(class);
                    break;
                case 5:
                    student_print(class);
                    break;
                case 6:
                    student_score(class);
                    break;
                case 7:
                    student_sort(class);
                    student_score(class);
                    break;
                case 8:
                    student_one(class);
                    break;
                case 9:
                    readStu(class);
                    student_print(class);
                    break;
                case 10:
                    saveStu(class);
                    break;
                case 11:
                    student_sort_num(class);
                    student_print(class);
                    break;
                case 12:
                    printf("班级平均分为：%.2f\n",student_score_avg(class));
                    break;
                case 13:
                    goto END;
                default:
                    break;
                }
            }
            
        }
        else
        {
            printf("账号或密码错误\n");
        }
    }
    END :
    return 0;
}


//菜单
void show()
{
                printf("=====================|五口巴学生信息管理系统|======================\n");
                printf("|---------------------------|功能菜单|----------------------------|\n");
                printf("|                                                                 |\n");
                printf("|                        1.录入学生信息                           |\n");
                printf("|                        2.删除学生信息                           |\n");
                printf("|                        3.修改学生成绩                           |\n");
                printf("|                        4.查询学生成绩                           |\n");
                printf("|                        5.查询所有学生的信息                     |\n");
                printf("|                        6.查询所有学生成绩                       |\n");
                printf("|                        7.学生成绩排序                           |\n");
                printf("|                        8.查询单个学生                           |\n");
                printf("|                        9.导入学生信息                           |\n");
                printf("|                        10.保存学生信息                          |\n");
                printf("|                        11.根据学号排序                          |\n");
                printf("|                        12.查看班级平均分                        |\n");
                printf("|                        13.退出系统                              |\n");
                printf("|                                                                 |\n");
                printf("-------------------------------------------------------------------\n");
                
}
//插入一个学生 (姓名, 性别, 年龄，成绩)
int student_interp(class_t *class)
{
    int i;
    Student_t stu;
    printf("请输入学生的 学号、姓名、性别（男M,女W）、年龄、成绩：\n");
    BEGIN:
    scanf("%s %s %c %d %d", stu.num, stu.name, &stu.sex, &stu.age, &stu.score);
    if(stu.sex!='M'&&stu.sex!='W') 
    {
        printf("输入的性别有误，请重新输入：\n");
        goto BEGIN;
    }
    if(stu.score>100)
    {
        printf("输入成绩有误，请重新输入：\n");
        goto BEGIN;
    }
    for (i = 0; i < class->index; i++)
    {
        if (strcmp(class->stu_arr[i].num, stu.num) == 0)
        {
            printf("该学生已经存在，请重新输入：\n");
            goto BEGIN;
        }
    }
    class->stu_arr[class->index] = stu;
    class->index++;
    printf("插入成功！\n");
    return 0;
}
//删除一个学生 (根据姓名删除一个学生)
int student_delete(class_t *class)
{
    int i = 0;
    int j = 0;
    char name[20];
    if (class->index == 0)
    {
        printf("还没有学生，请输入\n");
        return -1;
    }
    printf("请输入要删除学生的姓名：");
    scanf("%s", name);
    for (i = 0; i < class->index; i++)
    {
        if (strcmp(name, class->stu_arr[i].name) == 0)
        {
            
            for (j = i; j < class->index - 1; j++)
            {
                class->stu_arr[j] = class->stu_arr[j + 1];
            }
            class->index--;
            printf("删除成功!!!\n");
            break;
        }
        if (i == class->index)
        {
            printf("班级没有这个学员!\n");
            return -1;
        }
    }

    return 0;
}
//修改学生成绩 (根据姓名修改成绩)
int student_changed(class_t *class)
{
    char name[20];
    int score = 0;
    int i = 0;
    if(class->index == 0){
        printf("还没有学生，请输入\n");
        return -1;
    }
    printf("请输入要修改学生的姓名：");
    scanf("%s",name);
    for(i = 0; i < class->index; i++){
        if(strcmp(name,class->stu_arr[i].name) == 0){
            printf("请输入要修改的成绩：");
            scanf("%d",&score); 
            class->stu_arr[i].score = score;            
            printf("修改成功\n");
            break;     
        }
    }
    if(i == class->index){
        printf("没有该学员!\n");
    }
    return 0;
}
//查询学生成绩 (根据姓名查询成绩)
int student_inquire(class_t *class)
{
    char name[20];
    int i;
    if(class->index==0)
    {
        printf("还没有学生，请输入：\n");
        return -1;
    }
    printf("请输入要查询的学生：");
    scanf("%s",name);
    for(i = 0; i < class->index; i++){
        if(strcmp(name,class->stu_arr[i].name) == 0){
            printf("姓名：%-10s 成绩：%-5d\n",name,class->stu_arr[i].score);
            break;     
        }
    }
    if(i==class->index){
        printf("没有该学员！");
    }
    return 0;
}
//查询所有学生的信息
int student_print(class_t *class)
{
    int i;
    if(class->index == 0){
        printf("还没有学生，请输入\n");
        return -1;
    }
    for (i = 0; i < class->index; i++)
    {

        printf("所有学生信息：学号：%-10s 姓名：%-10s 性别：%-5c 年龄：%-5d 成绩：%-5d\n", class->stu_arr[i].num, class->stu_arr[i].name, class->stu_arr[i].sex, class->stu_arr[i].age, class->stu_arr[i].score);
    }
    return 0;
}
//查询所有学生成绩
int student_score(class_t *class)
{
    if(class->index == 0){
        printf("还没有学生，请输入\n");
        return -1;
    }
    int i;
    for (i = 0; i < class->index; i++)
    {

        printf("姓名：%-10s 成绩：%-5d\n", class->stu_arr[i].name, class->stu_arr[i].score);
    }
    return 0;
}
//根据成绩进行排序(从高到低， 冒泡排序) 还有很多排序但是我不会哈哈,冒泡YYDS 
int student_sort(class_t *class)
{
    int i,j;
    Student_t temp;
     if(class->index==0)
    {
        printf("还没有学生，请输入：\n");
        return -1;
    }
    for(i=0;i<class->index-1;i++)
    {
        for(j=0;j<class->index-1-i;j++)
        {
            if(class->stu_arr[j].score<class->stu_arr[j+1].score)
            {
                temp=class->stu_arr[j];
                class->stu_arr[j]=class->stu_arr[j+1];
                class->stu_arr[j+1]=temp;
            }
           
        }
    }
    printf("成绩由高到低排序为：\n");
    return 0;
}
//根据学号查询学生信息
int student_one(class_t *class)
{
    char num[20];
    int i;
    if(class->index==0)
    {
        printf("还没有学生，请输入：\n");
        return -1;
    }
    printf("请输入要查询的学生学号：\n");
    scanf("%s",num);
    for(i = 0; i < class->index; i++){
        if(strcmp(num,class->stu_arr[i].num) == 0){
            printf("学号：%-10s 姓名：%-10s 性别：%-5c 年龄：%-5d 成绩：%-5d\n", class->stu_arr[i].num, class->stu_arr[i].name, class->stu_arr[i].sex, class->stu_arr[i].age, class->stu_arr[i].score);
            break;     
        }
    }
    if(i==class->index){
        printf("没有该学生！\n");
    }
    return 0;
}
//读取学生信息
void readStu(class_t *class){
    int i = 0;
    FILE * fp;
    fp = fopen("students.txt","a+");
    if(fp == NULL){
        printf("文件打开失败!\n");
        exit(0);
    }
 
    fscanf(fp,"%d",&class->index);
    for(i = 0;i < class->index;i++){
        fscanf(fp,"%s %s %c %d %d",class->stu_arr[i].num,class->stu_arr[i].name,&class->stu_arr[i].sex,&class->stu_arr[i].age,&class->stu_arr[i].score);
    }
    fclose(fp);
    printf("导入学生信息成功!\n");
}
//保存学生信息
int saveStu(class_t *class){
    int i = 0;
    if(class->index == 0){
        printf("还没有学生，请输入\n");
        return -1;
    }
    FILE * fp;
    fp = fopen("students.txt","w");
    if(fp == NULL){
        printf("文件打开失败!\n");
        exit(0);
    }
 
    fprintf(fp,"%d\n",class->index); 
    for(i = 0;i < class->index;i++){
        fprintf(fp,"%s %s %c %d %d\n",class->stu_arr[i].num,class->stu_arr[i].name,class->stu_arr[i].sex,class->stu_arr[i].age,class->stu_arr[i].score);
    }
    fclose(fp);
    printf("写入成功!\n");
}
//按学号排序
int student_sort_num(class_t *class)
{
    int i,j;
    Student_t temp;
     if(class->index==0)
    {
        printf("还没有学生，请输入：\n");
        return -1;
    }
    for(i=0;i<class->index-1;i++)
    {
        for(j=0;j<class->index-1-i;j++)
        {
            if(strcmp(class->stu_arr[j].num,class->stu_arr[j+1].num)>0)
            {
                temp=class->stu_arr[j];
                class->stu_arr[j]=class->stu_arr[j+1];
                class->stu_arr[j+1]=temp;
            }
           
        }
    }
    printf("学号由低到高排序：\n");
    return 0;
}
//统计班级平均成绩
float student_score_avg(class_t *class)
{
    int i;
    float avg=0,sum=0;
    for(i=0;i<class->index;i++)
    {
        sum=sum+class->stu_arr[i].score;
    }
    avg=sum/class->index;
    return avg;
}

