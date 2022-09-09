#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "dataType.h"

studentDB *head =NULL;
uint32_type count=0,countl=0,index,usedSize;
uint8_type countz=0;
void mainMenu()
{
    uint32_type x ;
    bool isExist;
    uint32_type Addentry,readEntry;
    uint32_type stID ,yearr ,stSubject[sizeArr],suGrade[sizeArr];
    uint32_type *ptr_year =&yearr;
    uint32_type *ptr_subject =&stSubject;
    uint32_type *ptr_grade = &suGrade;

    do
    {
        printf("\t\t\t Welcome In DataBase\n");
        printf("\t\t\t****************\n");
        printf("\t\t1. Add Student\n");
        printf("\t\t2. Delete Student\n");
        printf("\t\t3. Check If ID Exist\n");
        printf("\t\t4. Read All Data\n");
        printf("\t\t5. The Used Size\n");
        printf("\t\t6. Get IDs List\n");
        printf("\t\t7. Exit\n");
        scanf("%d",&x);
    switch(x)
        {
            case 1:


                printf("Please enter student ID : \n");
                scanf("%d",&stID);

                printf("Please enter Year : \n");
                scanf("%d",&yearr);
                printf("Please Enter Subjects\n");
                for(index=0;index<sizeArr;index++)
                {

                    printf("Please Enter Subject NO. %d \n",index+1);
                    scanf("%d",&stSubject[index]);
                }
                for(index=0;index<sizeArr;index++)
                {
                    printf("Please Enter Grade %d \n",index+1);
                    scanf("%d",&suGrade[index]);
                    if (suGrade[index] < 0 || suGrade[index] > 100) {
                        printf("Number '%d' is out of range of grade, try again: \n", suGrade[index]);
                        --index;
                    }
                }
                Addentry =SDB_ADDEntry(stID,yearr,stSubject,suGrade);
                printf("%i",Addentry);
                count++;
                break;
            case 2:
                printf("Enter The Student ID you Want to Delete : \n");
                scanf("%d", &stID);
                SDB_DeleteEntry(stID);
                printf("This id data is deleted\n");

                break;
            case 3:
                printf("Enter The Student ID you Want to check Is Exist: \n");
                scanf("%d", &stID);
                isExist = SDB_IsIdExist(stID);
                //printf("%d\n",isExist);
                if(isExist == true)
                {
                    printf("This ID is Exist \n");
                }else{
                    printf("This ID is  Not Exist \n");
                }
                break;
            case 4:
                    readEntry = SDB_ReadEntry(stID,ptr_year,ptr_subject,ptr_grade);
                    printf("%i",readEntry);
                    break;
            case 5:
                usedSize =SDB_GetUsedSize();
                printf("%d",usedSize);
                break;
            case 6:
                SDB_GetID(usedSize,stID);
                break;
            case 7:
                exit(0);
                break;
        }
    }while(count <=10);
}

bool SDB_Isfull(void)
{
    if(count <= 10)
        return true;
    else
        return false;
}

uint8_type SDB_GetUsedSize(void)
{
    studentDB *temp;
    uint8_type countz =0;
    if(head != NULL)
    {
        temp=head;
        while(temp != NULL)
        {
        countz++;
        temp = temp->next;
        }
    }
    else
        printf("the database is empty");
    return countz;
}



bool SDB_ADDEntry(uint32_type id,uint32_type year,uint32_type *subjectt,uint32_type *grades)
{
            studentDB *new_node , *temp;
            new_node =(studentDB*)malloc(sizeof(studentDB));
            if(new_node==NULL)
            {
                printf("out of memory");

            }
            new_node->studentId = id;
            new_node->year = year;
            for(index = 0 ;index < sizeArr; index++)
            {
                new_node->subject[index]= subjectt[index];
            }
            for(index = 0 ;index < sizeArr; index++)
            {
                new_node->grade[index]=grades[index];
            }
            new_node->next=NULL;
            if(head==NULL)
           {
               head=new_node;
           }
           else
            {

                temp = head;

                    while (temp->next != NULL)
                    {
                       temp=temp->next;
                    }
                    temp->next=new_node;

            }
            count++;
            return true;
}
void SDB_DeleteEntry(uint32_type id)
{
    studentDB *temp = head,*prev;
    if (temp != NULL && temp->studentId == id) {
        head = temp->next;
        free(temp);
        return;
    }
    /*while (temp != NULL && temp->studentId != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);*/
    while(prev->studentId != id && temp->studentId != id)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next= temp->next ;
    free(temp);
}
bool SDB_ReadEntry(uint32_type id,uint32_type *year,uint32_type *subject,uint32_type *grades)
{
    studentDB *temp;
     if (head==NULL)
     {
         printf("the database is empty\n");

     }
     else
     {
         temp = head;
        while(temp!=NULL)
        {
            printf("\nthe student ID is :\t");
            printf("%d",temp->studentId);
            printf("\nthe student year is :\t");
            printf("%d",temp->year);
            for(index=0;index<sizeArr;index++)
            {
                printf("\nthe course ID is :\t");
                printf("%d",temp->subject[index]);
                printf("\nthe course grade is :\t");
                printf("%d",temp->grade[index]);
            }
            temp =temp->next;
            printf("\n===================\n");

        }
     }
     return 1;
}
void SDB_GetID(uint32_type *count,uint32_type *list)
{
    studentDB* temp = head;
    usedSize =SDB_GetUsedSize();
    printf("The Count of used In Memory %d \n", usedSize);
    printf("\t\t\t****************\n");
    printf("\t\t\t******ID********\n");
    printf("\t\t\t****************\n");
    while(temp != NULL)
    {
        printf("\t\t\t*     %d     \n", temp->studentId);
        temp=temp->next;
    }
    printf("\t\t\t****************\n");
}
bool SDB_IsIdExist(uint32_type id)
{
    studentDB *temp ;
    temp=head;
    while(temp->studentId !=id)
    {
        temp = temp->next;
        if(temp->studentId != id && temp->next == NULL)
        {
            break;
        }
    }

    if (temp->studentId == id)
        return true;
    else
        return false;

}





