#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll_no;
    char name[20];
    float marks;
} Student;

int main() {
    int n, i;
    float sum = 0.0;
    char choice;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;

    Student *students = malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter roll, name, marks: ");
        scanf("%d %19s %f",
              &students[i].roll_no,
              students[i].name,
              &students[i].marks);
    }

    Student *topper = &students[0];

    for (i = 0; i < n; i++) {
        sum += students[i].marks;

        if (students[i].marks > topper->marks)
            topper = &students[i];
    }

    printf("\nAverage marks: %.2f\n", sum / n);
    printf("Topper: %s (Roll %d, Marks %.2f)\n",
           topper->name, topper->roll_no, topper->marks);

    printf("\nAdd 2 more students? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        Student *temp = realloc(students, (n + 2) * sizeof(Student));

        if (temp == NULL) {
            printf("Reallocation failed!\n");
            free(students);
            return 1;
        }

        students = temp;

        for (i = n; i < n + 2; i++) {
            printf("Enter roll, name, marks: ");
            scanf("%d %19s %f",
                  &students[i].roll_no,
                  students[i].name,
                  &students[i].marks);
        }

        n += 2;
        sum = 0.0;

        for (i = 0; i < n; i++)
            sum += students[i].marks;

        printf("Updated average marks: %.2f\n", sum / n);
    }

    free(students);

    return 0;
}
