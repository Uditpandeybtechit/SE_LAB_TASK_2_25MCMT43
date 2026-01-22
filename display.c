#include <stdio.h>
#include "student.h"

/* display output */
void display(struct Student s[], int totalStudents)
{
    int i, j;

    printf("\nRoll No\tName\tMarks\t\t\tTotal\t%%\tGrade\tCGPA\n");
    printf("-----------------------------------------------------------------------------\n");

    for (i = 0; i < totalStudents; i++)
    {
        printf("%s\t%s\t", s[i].rollnumber, s[i].name);

        for (j = 0; j < SUB; j++)
        {
            printf("%d ", s[i].marks[j]);
        }

        printf("\t%d\t%.2f\t%s\t%.1f\n",
               s[i].sum, s[i].percent, s[i].Grade, s[i].cgpa);
    }
}
