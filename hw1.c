#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINESIZE 1024

struct student{
    
    int chours;
    float gpa;
    char *fname, *lname, *major,*degree, *ta, *advisor;


};

struct student getData(char *line){

    struct student item;

    item.fname = strdup(strtok(line, " ,"));
    item.lname = strdup(strtok(NULL, " ,"));
    item.major = strdup(strtok(NULL, " ,"));
    item.degree = strdup(strtok(NULL, " ,"));
    item.gpa = atof(strtok(NULL, " ,"));
    item.chours = atoi(strtok(NULL, " ,"));
    item.ta = strdup(strtok(NULL, " ,"));
    item.advisor = strdup(strtok(NULL, " ,"));

    return item;
}
/*
struct degree
{
    char arr[LINESIZE][50];
};
*/
//------------------------------------------------------

float creditAvg(struct student item)
{
    return item.chours;
    //avg of credit hours;
}
//------------------------------------------------------------
const char* diffDegree(struct student item)
{

return item.degree;
}
//---------------------------------------------------------------


void displayStruct(struct student item){

printf("firstname: %s || last name: %s||  major: %s ||degree: %s || GPA : %f || credit hours : %d|| TA: %s || Advisor name: %s \n",item.fname,item.lname,item.major,item.degree,item.gpa,item.chours,item.ta,item.advisor); 


printf("--------------------------------------------------------------------------------------------------\n ");

}


int main(int argc, char* args[])
{
    struct student stu_items[10000];
    char line[LINESIZE];
    int i,count;
    double temp=0;

    FILE *fptr = fopen("students_dataset.csv","r");

    if(fptr == NULL)
    {
        printf("ERROR file NULL:\n");
        exit(-1);
    }

    count =0;
    while(fgets(line, LINESIZE, fptr) != NULL)
    {
        stu_items[count++] = getData(line);
    }

    fclose(fptr);

    for(i=0;i<count;i++)
    {
        displayStruct(stu_items[i]);
    }

//--------------------------------------------------------------------------------------
    printf("count: %d\n ",count);
    
    printf("---------------------------------\n");

    for(i=0;i<count;i++)
    {
     temp = temp+ creditAvg(stu_items[i]);
    }
    printf(" Que 3 avg of credit    hours == %lf \n ",temp/count);
    printf("\n----------------------------------------------------------------------");

//-------------------------------------------------------------------------------





    return 0;
}

/*
REF: lecture documents in canvas.
"https://learnprogramo.com/array-of-strings-in-c-30/#:~:text=%20%20%201%20Array%20of%20Strings%20in,%E2%80%9C.%20Since%20an%20array%20of%20strings...%20More%20"

Submitting the .c file -> to complie the .c file -> gcc "filename.c" -o "filename.exe"  and next ./"filename.exe" in ubuntu or wsl 

*/