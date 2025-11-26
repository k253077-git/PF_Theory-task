#include <stdio.h>
#include <string.h>

struct employee{
	int id;
	char name[10];
	char designation[10];
	int salary;
};

void display(employee emp[],int n){
	printf("-------Employee details-------");
  printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("---------------------------------------------------------------\n");
   for(int i=0;i<n;i++){
   	printf("%-10d %-20s %-20s %-10d\n",emp[i].id,emp[i].name,emp[i].designation,emp[i].salary);
   }
}
void highest(employee emp[], int n){
	printf("\n--Highest salary taker--\n");
	int max=0;
	for(int i=1;i<n;i++){
		if(emp[i].salary>emp[max].salary){
            max=i;
		}
	}
			printf("ID: %d \n",emp[max].id);
			printf("Name: %s \n",emp[max].name);
			printf("Designation: %s \n",emp[max].designation);
			printf("Salary: %d \n",emp[max].salary);
}

void search(employee emp[],int n){
	char search[10];
	int idx,i,ch;
	printf("\n1.search by name\n2.search by id");
	printf("enter your choice: ");
	scanf("%d",&ch);
	if(ch==1){
	printf("Enter name to search: ");
	scanf("%s",search);
	for(i=0;i<n;i++){
		if(strcmp(emp[i].name,search)==0){
			printf("ID: %d",emp[i].id);
			printf("Name: %s",emp[i].name);
			printf("Designation: %s",emp[i].designation);
			printf("Salary: %d",emp[i].salary);	
		}else{
			printf("Not found");
		}
	 } 
   }else if(ch==2){
   		printf("Enter id to search");
	    scanf("%d",&idx);
	for(i=0;i<n;i++){
	    if(emp[i].id == idx){
	        printf("ID: %d",emp[i].id);
			printf("Name: %s",emp[i].name);
			printf("Designation: %s",emp[i].designation);
			printf("Salary: %d",emp[i].salary);		
		}else {
			printf("invalid");
		}
      }
   }
}
void Bonus(employee emp[], int n, int threshold) {
    for (int i=0; i<n; i++) {
        if (emp[i].salary < threshold) {
            emp[i].salary += emp[i].salary * 0.10; 
        }
    }
}

int main(){
	printf("--Employee management system--\n");
	int n;
		struct employee emp[n];
	printf("1.Add employee details\n2.Highest salary Employee\n3.view details\n4.Search\n5.Bonus employee\n6.Exit\n\n");
	int ch;
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
	printf("Enter number of employees: ");
	scanf("%d",&n);
	printf("--Enter Emloyees Details:--\n");
	for(int i=0;i<n;i++){
		printf("Enter Id of emp %d: ",i);
		scanf("%d",&emp[i].id);
		printf("Enter name of emp %d: ",i);
		scanf("%s",emp[i].name);
		printf("Enter designation of emp %d: ",i);
		scanf("%s",emp[i].designation);
		printf("Enter Salary of emp %d: ",i);
		scanf("%d",&emp[i].salary);
	}   break;
	    case 2:
	    	highest(emp,n);
	    	break;
	    case 3:
	    	display(emp,n);
	    	break;
	    case 4:
	    	search(emp,n);
	    	break;
	    case 5:
	    	Bonus(emp,n,500);
	    	break;
	    case 6:
	    	printf("Thankyou");
}


	
}
