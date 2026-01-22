#include <string.h>
#include <ctype.h>
#include "student.h"

/* validate roll number */
int checkRollnumber(char rollnumber[], struct Student stu[], int totalStudents)
{
    int i;

    for (i = 0; rollnumber[i] != '\0'; i++)
    {
        if (!isalnum(rollnumber[i]))
        {
            return 0;
        }
    }

    for (i = 0; i < totalStudents; i++)
    {
        if (strcmp(rollnumber, stu[i].rollnumber) == 0)
        {
            return 0;
        }
    }

    return 1;
}

/* validate name */
int checkName(char student_name[])
{
    int i;

    for (i = 0; student_name[i] != '\0'; i++)
    {
        if (!isalpha(student_name[i]))
        {
            return 0;
        }
    }

    return 1;
}
