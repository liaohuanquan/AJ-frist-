/*
                   _ooOoo_
                  o8888888o
                  88" . "88          ***********
                  (| -_- |)          *��ʦ���� *
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
              
              
            C����ѧ����Ϣ����ϵͳ���
			 220746�λ�Ȩ3122002455 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h> //����ͷ�ļ� 
#include <unistd.h> // ������� usleep ��ͷ�ļ�
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
    Student_t stu_arr[50]; // ����༶�����50��ѧ��
    unsigned int index;    // ��ǰ�༶ѧ���ĸ���
} class_t;                 // �༶����

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
//���������� 
int main(int argc, char const *argv[])
{
	
	int progress;
for (progress = 0; progress <= 100; progress++) {
    system("cls");
    printf("Loading: [%-50s] %d%%\n", "================================================", progress);
    // �ӳ�һ��ʱ�䣬ģ����ع���
    usleep(30000); 
    printf("\r");
}

// �����Ļ
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
        printf("*********|��ڰ�ѧ������ϵͳ|*********\n");//��½���沿�� 
        printf("�������¼�˺�->����ʼ�˺�Ϊ10086��\n");
        scanf("%d", &id);
        printf("�������¼����->����ʼ����Ϊ10086��\n");
        scanf("%d", &code);
        
        
        
        
        ////////////////////////////////////////////////////////////////////////////////
        if (id == 10086 && code == 10086)//�����޸��˺����� //////////////////////////// 
        //////////////////////////////////////////////////////////////////////////////// 
        
        
        
        
        
        
        
        {
            printf("*************|��¼�ɹ�|*************\n");
            while (1)
            {
                printf("��ѡ������Ҫ�Ĺ���(����0���빦�ܲ˵�)��\n");
                scanf("%d", &chose);
                system ("cls");//���� 
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
                    printf("�༶ƽ����Ϊ��%.2f\n",student_score_avg(class));
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
            printf("�˺Ż��������\n");
        }
    }
    END :
    return 0;
}


//�˵�
void show()
{
                printf("=====================|��ڰ�ѧ����Ϣ����ϵͳ|======================\n");
                printf("|---------------------------|���ܲ˵�|----------------------------|\n");
                printf("|                                                                 |\n");
                printf("|                        1.¼��ѧ����Ϣ                           |\n");
                printf("|                        2.ɾ��ѧ����Ϣ                           |\n");
                printf("|                        3.�޸�ѧ���ɼ�                           |\n");
                printf("|                        4.��ѯѧ���ɼ�                           |\n");
                printf("|                        5.��ѯ����ѧ������Ϣ                     |\n");
                printf("|                        6.��ѯ����ѧ���ɼ�                       |\n");
                printf("|                        7.ѧ���ɼ�����                           |\n");
                printf("|                        8.��ѯ����ѧ��                           |\n");
                printf("|                        9.����ѧ����Ϣ                           |\n");
                printf("|                        10.����ѧ����Ϣ                          |\n");
                printf("|                        11.����ѧ������                          |\n");
                printf("|                        12.�鿴�༶ƽ����                        |\n");
                printf("|                        13.�˳�ϵͳ                              |\n");
                printf("|                                                                 |\n");
                printf("-------------------------------------------------------------------\n");
                
}
//����һ��ѧ�� (����, �Ա�, ���䣬�ɼ�)
int student_interp(class_t *class)
{
    int i;
    Student_t stu;
    printf("������ѧ���� ѧ�š��������Ա���M,ŮW�������䡢�ɼ���\n");
    BEGIN:
    scanf("%s %s %c %d %d", stu.num, stu.name, &stu.sex, &stu.age, &stu.score);
    if(stu.sex!='M'&&stu.sex!='W') 
    {
        printf("������Ա��������������룺\n");
        goto BEGIN;
    }
    if(stu.score>100)
    {
        printf("����ɼ��������������룺\n");
        goto BEGIN;
    }
    for (i = 0; i < class->index; i++)
    {
        if (strcmp(class->stu_arr[i].num, stu.num) == 0)
        {
            printf("��ѧ���Ѿ����ڣ����������룺\n");
            goto BEGIN;
        }
    }
    class->stu_arr[class->index] = stu;
    class->index++;
    printf("����ɹ���\n");
    return 0;
}
//ɾ��һ��ѧ�� (��������ɾ��һ��ѧ��)
int student_delete(class_t *class)
{
    int i = 0;
    int j = 0;
    char name[20];
    if (class->index == 0)
    {
        printf("��û��ѧ����������\n");
        return -1;
    }
    printf("������Ҫɾ��ѧ����������");
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
            printf("ɾ���ɹ�!!!\n");
            break;
        }
        if (i == class->index)
        {
            printf("�༶û�����ѧԱ!\n");
            return -1;
        }
    }

    return 0;
}
//�޸�ѧ���ɼ� (���������޸ĳɼ�)
int student_changed(class_t *class)
{
    char name[20];
    int score = 0;
    int i = 0;
    if(class->index == 0){
        printf("��û��ѧ����������\n");
        return -1;
    }
    printf("������Ҫ�޸�ѧ����������");
    scanf("%s",name);
    for(i = 0; i < class->index; i++){
        if(strcmp(name,class->stu_arr[i].name) == 0){
            printf("������Ҫ�޸ĵĳɼ���");
            scanf("%d",&score); 
            class->stu_arr[i].score = score;            
            printf("�޸ĳɹ�\n");
            break;     
        }
    }
    if(i == class->index){
        printf("û�и�ѧԱ!\n");
    }
    return 0;
}
//��ѯѧ���ɼ� (����������ѯ�ɼ�)
int student_inquire(class_t *class)
{
    char name[20];
    int i;
    if(class->index==0)
    {
        printf("��û��ѧ���������룺\n");
        return -1;
    }
    printf("������Ҫ��ѯ��ѧ����");
    scanf("%s",name);
    for(i = 0; i < class->index; i++){
        if(strcmp(name,class->stu_arr[i].name) == 0){
            printf("������%-10s �ɼ���%-5d\n",name,class->stu_arr[i].score);
            break;     
        }
    }
    if(i==class->index){
        printf("û�и�ѧԱ��");
    }
    return 0;
}
//��ѯ����ѧ������Ϣ
int student_print(class_t *class)
{
    int i;
    if(class->index == 0){
        printf("��û��ѧ����������\n");
        return -1;
    }
    for (i = 0; i < class->index; i++)
    {

        printf("����ѧ����Ϣ��ѧ�ţ�%-10s ������%-10s �Ա�%-5c ���䣺%-5d �ɼ���%-5d\n", class->stu_arr[i].num, class->stu_arr[i].name, class->stu_arr[i].sex, class->stu_arr[i].age, class->stu_arr[i].score);
    }
    return 0;
}
//��ѯ����ѧ���ɼ�
int student_score(class_t *class)
{
    if(class->index == 0){
        printf("��û��ѧ����������\n");
        return -1;
    }
    int i;
    for (i = 0; i < class->index; i++)
    {

        printf("������%-10s �ɼ���%-5d\n", class->stu_arr[i].name, class->stu_arr[i].score);
    }
    return 0;
}
//���ݳɼ���������(�Ӹߵ��ͣ� ð������) ���кܶ��������Ҳ������,ð��YYDS 
int student_sort(class_t *class)
{
    int i,j;
    Student_t temp;
     if(class->index==0)
    {
        printf("��û��ѧ���������룺\n");
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
    printf("�ɼ��ɸߵ�������Ϊ��\n");
    return 0;
}
//����ѧ�Ų�ѯѧ����Ϣ
int student_one(class_t *class)
{
    char num[20];
    int i;
    if(class->index==0)
    {
        printf("��û��ѧ���������룺\n");
        return -1;
    }
    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
    scanf("%s",num);
    for(i = 0; i < class->index; i++){
        if(strcmp(num,class->stu_arr[i].num) == 0){
            printf("ѧ�ţ�%-10s ������%-10s �Ա�%-5c ���䣺%-5d �ɼ���%-5d\n", class->stu_arr[i].num, class->stu_arr[i].name, class->stu_arr[i].sex, class->stu_arr[i].age, class->stu_arr[i].score);
            break;     
        }
    }
    if(i==class->index){
        printf("û�и�ѧ����\n");
    }
    return 0;
}
//��ȡѧ����Ϣ
void readStu(class_t *class){
    int i = 0;
    FILE * fp;
    fp = fopen("students.txt","a+");
    if(fp == NULL){
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
 
    fscanf(fp,"%d",&class->index);
    for(i = 0;i < class->index;i++){
        fscanf(fp,"%s %s %c %d %d",class->stu_arr[i].num,class->stu_arr[i].name,&class->stu_arr[i].sex,&class->stu_arr[i].age,&class->stu_arr[i].score);
    }
    fclose(fp);
    printf("����ѧ����Ϣ�ɹ�!\n");
}
//����ѧ����Ϣ
int saveStu(class_t *class){
    int i = 0;
    if(class->index == 0){
        printf("��û��ѧ����������\n");
        return -1;
    }
    FILE * fp;
    fp = fopen("students.txt","w");
    if(fp == NULL){
        printf("�ļ���ʧ��!\n");
        exit(0);
    }
 
    fprintf(fp,"%d\n",class->index); 
    for(i = 0;i < class->index;i++){
        fprintf(fp,"%s %s %c %d %d\n",class->stu_arr[i].num,class->stu_arr[i].name,class->stu_arr[i].sex,class->stu_arr[i].age,class->stu_arr[i].score);
    }
    fclose(fp);
    printf("д��ɹ�!\n");
}
//��ѧ������
int student_sort_num(class_t *class)
{
    int i,j;
    Student_t temp;
     if(class->index==0)
    {
        printf("��û��ѧ���������룺\n");
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
    printf("ѧ���ɵ͵�������\n");
    return 0;
}
//ͳ�ư༶ƽ���ɼ�
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

