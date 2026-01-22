#ifndef STUDENT_H
#define STUDENT_H

#define MAX 100
#define SUB 5

struct Student
{
    char rollnumber[20];
    char name[50];
    int marks[SUB];
    int sum;
    float percent;
    float cgpa;
    char Grade[3];   /* O, A+, A, B+, B, C, D, F */
    int isPass;
};

/* validation */
int checkRollnumber(char rollnumber[], struct Student stu[], int totalStudents);
int checkName(char student_name[]);

/* calculation */
void calculate(struct Student *s);
void getGrade(float p, int pass, char Grade[]);
float getCGPA(char Grade[]);

/* display */
void display(struct Student s[], int totalStudents);

/* statistics */
void statistics(struct Student s[], int totalStudents);

#endif
