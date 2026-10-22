#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int emp_id;
    enum { FULL_TIME, CONTRACT } type;

    union {
        float salary;
        struct {
            float hourly_rate;
            int hours_worked;
        } contract_info;
    } pay;
} Employee;

int main() {
    int n, i;
    float total_bill = 0.0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Employee *emp = malloc(n * sizeof(Employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        int type;

        printf("\nEnter name: ");
        scanf("%19s", emp[i].name);

        printf("Enter employee ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Enter type (0-Full-Time, 1-Contract): ");
        scanf("%d", &type);

        if (type != 0 && type != 1) {
            printf("Invalid employee type.\n");
            free(emp);
            return 1;
        }

        emp[i].type = (type == 0) ? FULL_TIME : CONTRACT;

        if (emp[i].type == FULL_TIME) {
            printf("Enter monthly salary: ");
            scanf("%f", &emp[i].pay.salary);
        } else {
            printf("Enter hourly rate: ");
            scanf("%f", &emp[i].pay.contract_info.hourly_rate);

            printf("Enter hours worked: ");
            scanf("%d", &emp[i].pay.contract_info.hours_worked);
        }
    }

    printf("\n========== PAYSLIPS ==========\n");

    for (i = 0; i < n; i++) {
        float total_pay;

        if (emp[i].type == FULL_TIME) {
            total_pay = emp[i].pay.salary;
            printf("ID: %d | Name: %s | Full-Time | Pay: $%.2f\n",
                   emp[i].emp_id, emp[i].name, total_pay);
        } else {
            total_pay = emp[i].pay.contract_info.hourly_rate *
                        emp[i].pay.contract_info.hours_worked;

            printf("ID: %d | Name: %s | Contract | Pay: $%.2f\n",
                   emp[i].emp_id, emp[i].name, total_pay);
        }

        total_bill += total_pay;
    }

    printf("==============================\n");
    printf("Total salary bill: $%.2f\n", total_bill);

    free(emp);

    return 0;
}
