#include <string.h>
#include "student.h"

/* calculate total, percentage, grade and cgpa */
void calculate(struct Student *s)
{
    int i;
    s->sum = 0;

    for (i = 0; i < SUB; i++)
    {
        s->sum += s->marks[i];
    }

    s->percent = s->sum / (float)SUB;
    getGrade(s->percent, s->isPass, s->Grade);
    s->cgpa = getCGPA(s->Grade);
}

/* grade as per PDF */
void getGrade(float p, int pass, char Grade[])
{
    if (!pass)
    {
        strcpy(Grade, "F");
        return;
    }

    if (p >= 90) strcpy(Grade, "O");
    else if (p >= 85) strcpy(Grade, "A+");
    else if (p >= 75) strcpy(Grade, "A");
    else if (p >= 65) strcpy(Grade, "B+");
    else if (p >= 60) strcpy(Grade, "B");
    else if (p >= 55) strcpy(Grade, "C");
    else if (p >= 50) strcpy(Grade, "D");
    else strcpy(Grade, "F");
}

/* CGPA mapping */
float getCGPA(char Grade[])
{
    if (strcmp(Grade, "O") == 0) return 10.0;
    if (strcmp(Grade, "A+") == 0) return 9.0;
    if (strcmp(Grade, "A") == 0) return 8.0;
    if (strcmp(Grade, "B+") == 0) return 7.0;
    if (strcmp(Grade, "B") == 0) return 6.0;
    if (strcmp(Grade, "C") == 0) return 5.0;
    if (strcmp(Grade, "D") == 0) return 4.0;
    return 0.0;
}
