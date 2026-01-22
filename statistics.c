#include <stdio.h>
#include <string.h>
#include "student.h"

/* class statistics */
void statistics(struct Student s[], int totalStudents)
{
    int i;
    float sum = 0, high = s[0].percent, low = s[0].percent;
    int GradeCount[8] = {0};

    for (i = 0; i < totalStudents; i++)
    {
        sum += s[i].percent;

        if (s[i].percent > high)
            high = s[i].percent;

        if (s[i].percent < low)
            low = s[i].percent;

        if (strcmp(s[i].Grade, "O") == 0) GradeCount[0]++;
        else if (strcmp(s[i].Grade, "A+") == 0) GradeCount[1]++;
        else if (strcmp(s[i].Grade, "A") == 0) GradeCount[2]++;
        else if (strcmp(s[i].Grade, "B+") == 0) GradeCount[3]++;
        else if (strcmp(s[i].Grade, "B") == 0) GradeCount[4]++;
        else if (strcmp(s[i].Grade, "C") == 0) GradeCount[5]++;
        else if (strcmp(s[i].Grade, "D") == 0) GradeCount[6]++;
        else GradeCount[7]++;
    }

    printf("\nClass Average Marks : %.2f\n", sum / totalStudents);
    printf("Highest Percentage in class: %.2f\n", high);
    printf("Lowest Percentage in class : %.2f\n", low);

    printf("\nGrade Count:\n");
    printf("O : %d\nA+: %d\nA : %d\nB+: %d\nB : %d\nC : %d\nD : %d\nF : %d\n",
           GradeCount[0], GradeCount[1], GradeCount[2], GradeCount[3],
           GradeCount[4], GradeCount[5], GradeCount[6], GradeCount[7]);
}
