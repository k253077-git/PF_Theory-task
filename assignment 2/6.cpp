#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    char batch[20];
    char membership[10];
    char regDate[11];
    char dob[11];
    char interest[10];
};

struct Student *students = NULL;
int count = 0;

void loadDatabase(const char *file) {
    FILE *fp = fopen(file, "rb");
    if (!fp) return;
    struct Student temp;
    while (fread(&temp, sizeof(struct Student), 1, fp) == 1) {
        students =(struct Student*) realloc(students, (count + 1) * sizeof(struct Student));
        students[count++] = temp;
    }
    fclose(fp);
}

void saveDatabase(const char *file) {
    FILE *fp = fopen(file, "wb");
    if (!fp) return;
    fwrite(students, sizeof(struct Student), count, fp);
    fclose(fp);
}

int idExists(int id) {
    for (int i = 0; i < count; i++)
        if (students[i].id == id) return 1;
    return 0;
}

void addStudent() {
    struct Student s;

    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    if (idExists(s.id)) {
        printf("ID already exists\n");
        return;
    }

    getchar();
    printf("Enter Full Name: ");
    fgets(s.name, 100, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Batch: ");
    scanf("%s", s.batch);

    printf("Membership (IEEE/ACM): ");
    scanf("%s", s.membership);

    printf("Registration Date (YYYY-MM-DD): ");
    scanf("%s", s.regDate);

    printf("Date of Birth (YYYY-MM-DD): ");
    scanf("%s", s.dob);

    printf("Interest (IEEE/ACM/Both): ");
    scanf("%s", s.interest);

    students = (struct Student*)realloc(students, (count + 1) * sizeof(struct Student));
    students[count++] = s;

    printf("Student added\n");
}

void updateStudent() {
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("New Batch: ");
            scanf("%s", students[i].batch);
            printf("New Membership: ");
            scanf("%s", students[i].membership);
            printf("Updated\n");
            return;
        }
    }
    printf("ID not found\n");
}

void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            students = (struct Student*)realloc(students, count * sizeof(struct Student));
            printf("Deleted\n");
            return;
        }
    }
    printf("ID not found\n");
}

void displayAll() {
    if (count == 0) {
        printf("No records\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nBatch: %s\nMembership: %s\nReg: %s\nDOB: %s\nInterest: %s\n",
               students[i].id, students[i].name, students[i].batch,
               students[i].membership, students[i].regDate,
               students[i].dob, students[i].interest);
    }
}

void batchReport() {
    char batchName[20];
    printf("Enter batch: ");
    scanf("%s", batchName);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].batch, batchName) == 0) {
            printf("ID %d - %s (%s)\n",
                   students[i].id, students[i].name, students[i].membership);
            found = 1;
        }
    }
    if (!found) printf("No students\n");
}

int main() {
    loadDatabase("members.dat");
printf("===Membership system===\n");
    int choice;
    while (choice!=7) {
        printf("1.Add\n2.Update\n3.Delete\n4.View All\n5.Batch Report\n6.Save\n7.Exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1:
        		addStudent();
        		break;
        	case 2:
        		updateStudent();
        		break;
        	case 3:
        		deleteStudent();
        		break;
        	case 4:
        		displayAll();
        		break;
        	case 5:
        		batchReport();
        		break;
        	case 6:
        		saveDatabase("members.dat");
                free(students);
            case 7:
            	printf("Thankyou");
		};
}
}
