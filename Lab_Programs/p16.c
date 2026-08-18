#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee emp;
    int choice, pos;

    fp = fopen("employee.dat", "rb+");

    if (fp == NULL)
        fp = fopen("employee.dat", "wb+");

    while (1)
    {
        printf("\n--- RANDOM ACCESS FILE ---");
        printf("\n1. Add Employee");
        printf("\n2. Read Employee by Position");
        printf("\n3. Update Employee");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp.id);

                printf("Enter Name: ");
                scanf("%s", emp.name);

                printf("Enter Salary: ");
                scanf("%f", &emp.salary);

                fseek(fp, 0, SEEK_END);
                fwrite(&emp, sizeof(struct Employee), 1, fp);

                printf("Employee added successfully\n");
                break;

            case 2:
                printf("Enter employee position (starting from 1): ");
                scanf("%d", &pos);

                fseek(fp, (pos - 1) * sizeof(struct Employee), SEEK_SET);

                if (fread(&emp, sizeof(struct Employee), 1, fp) == 1)
                {
                    printf("\nID     : %d", emp.id);
                    printf("\nName   : %s", emp.name);
                    printf("\nSalary : %.2f\n", emp.salary);
                }
                else
                {
                    printf("Employee not found\n");
                }
                break;

            case 3:
                printf("Enter employee position to update: ");
                scanf("%d", &pos);

                fseek(fp, (pos - 1) * sizeof(struct Employee), SEEK_SET);

                if (fread(&emp, sizeof(struct Employee), 1, fp) == 1)
                {
                    printf("Enter New ID: ");
                    scanf("%d", &emp.id);

                    printf("Enter New Name: ");
                    scanf("%s", emp.name);

                    printf("Enter New Salary: ");
                    scanf("%f", &emp.salary);

                    fseek(fp, (pos - 1) * sizeof(struct Employee), SEEK_SET);
                    fwrite(&emp, sizeof(struct Employee), 1, fp);

                    printf("Employee updated successfully\n");
                }
                else
                {
                    printf("Employee not found\n");
                }
                break;

            case 4:
                fclose(fp);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}