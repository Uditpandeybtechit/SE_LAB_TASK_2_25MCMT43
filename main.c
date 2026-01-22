#include <stdio.h>
#include "student.h"

int main()
{
    FILE *fp;
    struct Student students[MAX];
    int totalStudents, i, j;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File is not found ! Some error\n");
        return 1;
    }

    fscanf(fp, "%d", &totalStudents);

    for (i = 0; i < totalStudents; i++)
    {
        fscanf(fp, "%s %s", students[i].rollnumber, students[i].name);

        if (!checkRollnumber(students[i].rollnumber, students, i))
        {
            printf("Invalid rollnumber\n");
            return 1;
        }

        if (!checkName(students[i].name))
        {
            printf("Invalid name\n");
            return 1;
        }

        students[i].isPass = 1;

        for (j = 0; j < SUB; j++)
        {
            fscanf(fp, "%d", &students[i].marks[j]);

            if (students[i].marks[j] < 0 || students[i].marks[j] > 100)
            {
                printf("Invalid marks\n");
                return 1;
            }

            if (students[i].marks[j] < 50)
            {
                students[i].isPass = 0;
            }
        }

        calculate(&students[i]);
    }

    fclose(fp);

    display(students, totalStudents);
    statistics(students, totalStudents);

    printf("\n--- End of Result ---\n");
    return 0;
}
