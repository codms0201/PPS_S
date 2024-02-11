#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int importance;
    int* subordinates;
    int subordinatesCount;
} Employee;

int getImportance(Employee* employees, int employeesSize, int id) {
    int* importanceMap = (int*)malloc((employeesSize + 1) * sizeof(int));

    for (int i = 0; i < employeesSize; i++) {
        importanceMap[employees[i].id] = employees[i].importance;
    }

    int calculateTotalImportance(int employeeId) {
        int totalImportance = importanceMap[employeeId];

        for (int i = 0; i < employees[employeeId - 1].subordinatesCount; i++) {
            totalImportance += calculateTotalImportance(employees[employeeId - 1].subordinates[i]);
        }

        return totalImportance;
    }

    int result = calculateTotalImportance(id);

    free(importanceMap);
    return result;
}

int main() {

    Employee employees[] = {
        {1, 5, (int[]){2, 3}, 2},
        {2, 3, NULL, 0},
        {3, 3, NULL, 0}
    };

    int employeesSize = sizeof(employees) / sizeof(employees[0]);

    int totalImportance = getImportance(employees, employeesSize, 1);

    printf("Total importance value: %d\n", totalImportance);

    return 0;
}
