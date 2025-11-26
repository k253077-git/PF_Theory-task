#include <stdio.h>
#include <string.h>


double calculateRepayment(double loan, double interestRate, int years, double installment) {
      if(loan<=0 || years==0){
      	return 0;
	  }
	  
    loan = loan + (loan * interestRate / 100);
    loan = loan - installment;
    if(loan<0){
    	loan =0;
	}
    
    printf("Year %d: Remaining loan = %.2f\n", years, loan);
    return installment + calculateRepayment(loan, interestRate, years - 1, installment);
}

int main() {
    double loan = 100000;  
    double interestRate = 5;   
    int years = 3;             
    double installment = 40000; 

    printf("Loan Repayment Schedule:\n");

    double total = calculateRepayment(loan, interestRate, years, installment);

    printf("\nTotal repayment over %d years = %.2f\n", years, total);

    return 0;
}

