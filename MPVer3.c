/***************************************************************************
This is to certify that this project is my own work, based on my personal efforts
in studying and applying the concepts learned. I have constructed the
functions and their respective algorithms and corresponding code by myself.
The program was run, tested, and debugged by my own efforts. I further
certify that I have not copied in part or whole or otherwise plagiarized the
work of other students and/or persons.
Fernandez, Candice Aura T.
12207071
***************************************************************************/

/*
Description:      <This is a budgeting program that helps the 
					user budgets his/her allowance and avoid spending 
					more than the monthly allowance given.>
Programmed by:    <Fernandez, Candice Aura T.>   <S20A>
Last modified:    <December 5, 2022>
Version:          <3>
Acknowledgements: 
C - switch statement - Tutorialspoint. (2020). Tutorialspoint.com. https://www.tutorialspoint.com/cprogramming/switch_statement_in_c.htm
C Strings. (n.d.). Www.w3schools.com. Retrieved November 6, 2022, from https://www.w3schools.com/c/c_strings.php
C Switch Statement - javatpoint. (2021). Www.javatpoint.com. https://www.javatpoint.com/c-switch
*/

//<Preprocessor directives>
//<function implementation>

#include<stdio.h>

#define MONTH 30
#define FOOD_DAILY 300

/*This user defined function displays the header of the program*/
void displayHeader ()
{
	printf("%40s\n", "\t\tBudgeting Allowance Program\n");
	printf("\t\tWelcome to the Budgeting Allowance Program!\n");
	printf("\tThis program will help you balance your monthly allowance.\n");
	printf("\t\tAvoid overspending! Let's start budgeting.\n");
}

/*This user defined function gets the monthly allowance of the user.
  Pre-condition: Allowance is a non-negative value 
  @param fMAllowance is the monthly allowance*/ 
void getAllowance (float* fMAllowance)
{
	printf("Monthly Allowance: ");
	scanf("%f", fMAllowance);
}
	
/*This user defined function gets the monthly budget allocation for each category of the user.
  Pre-condition: Food and Drink Budget is a non-negative value and it should be at least 9000php
  Pre-condition: Transportation Budget is a non-negative value
  Pre-condition: Healthcare Budget is a non-negative value
  Pre-condition: Housing and Utilities Budget is a non-negative value should be at least 4000php
  Pre-condition: Leisure Budget is a non-negative value
  Pre-condition: School Budget is a non-negative value
  @param fFoodandDrink is the budget for food and drink expenses
  @param fTransportation is the budget for transportation expenses
  @param fHealthcare is the budget for healthcare expenses
  @param fHousing is the budget for housing and utilities expenses
  @param fLeisure is the budget for leisure expenses
  @param fSchool is the budget for school expenses*/  
void getBudgetAllocation (float* fFoodandDrink, float* fTransportation, float* fHealthcare, float* fHousing, float* fLeisure, float* fSchool)
{
	printf("\nMonthly Budget Allocation\n");
	
	printf("Food and Drink Budget: ");
	scanf("%f", fFoodandDrink);
        
    printf("Transportation Budget: ");
	scanf("%f", fTransportation);
        
    printf("Healthcare Budget: ");
	scanf("%f", fHealthcare);
        
    printf("Housecare and Utilities Budget: ");
	scanf("%f", fHousing);
        
    printf("Leisure Budget: ");
	scanf("%f", fLeisure);
        
    printf("School Budget: ");
	scanf("%f", fSchool);
}

/*This user defined function gets the monthly savings from the user
 Pre-condition: input should not be a negative value
 @param fSavings is the input savings of the user*/
void getSavings (float* fSavings)
{
	printf("\nSavings: ");
	scanf("%f", fSavings);
}

/*This user defined function gets the monthly savings from the user
 Pre-condition: input should not be a negative value
 @param fSpendSavings is the input of the user which will be deducted from the savings*/
void useSavings (float* fSpendSavings)
{
	printf("\nSavings that will be used: ");
	scanf("%f", fSpendSavings);
}

/* user defined function which displays the budget report of the user.
   @param fFoodandDrink is the expenses for food and drink	
   @param fTransportation is the expenses for transportation
   @param fHealthcare is the expenses for healthcare
   @param fHousing is the expenses for housing and utilities
   @param fLeisure is the expenses for leisure
   @param fSchool is the expenses for school*/
void displayBudgetReport (float fFoodandDrink, float fTransportation, float fHealthcare, float fHousing,float fLeisure, float fSchool, float fSavings, float fRemBal)
{
	printf("Food and Drink Expenses: %.2f\n", fFoodandDrink);
	printf("Transportation Expenses: %.2f\n", fTransportation);
	printf("Healthcare Expenses: %.2f\n", fHealthcare);
	printf("Household and Utilities Expenses: %.2f\n", fHousing);
	printf("Leisure Expenses: %.2f\n", fLeisure);
	printf("School Expenses: %.2f\n", fSchool);
	printf("Monthly Savings: %.2f\n", fSavings);	
	printf("Total Savings: %.2f\n", fSavings);
	printf("Balance: %.2f\n\n", fRemBal);
}

// user defined function which shows the budget report for the end of the month
/*@param fFoodandDrink is the budget for food and drink expenses
  @param fTransportation is the budget for transportation expenses
  @param fHealthcare is the budget for healthcare expenses
  @param fHousing is the budget for housing and utilities expenses
  @param fLeisure is the budget for leisure expenses
  @param fSchool is the budget for school expenses
  @param fMFoodandDrink is the expenses for food and drink	
  @param fMTransportation is the expenses for transportation
  @param fMHealthcare is the expenses for healthcare
  @param fMHousing is the expenses for housing and utilities
  @param fMLeisure is the expenses for leisure
  @param fMSchool is the expenses for school
  @param nDaysPassed is the number of days passed when ending the month
  @param fFood is the total expenses for food and drink after ending the month
  @param nDay is the number of days
  @fMAllowance is the monthly allowance of the user*/
void endMonth(float fFoodandDrink, float fTransportation, float fHealthcare, float fHousing, float fLeisure, float fSchool, float fSavings, float fRemBal, float fMFoodandDrink, float fMTransportation, float fMHealthcare, float fMHousing, float fMLeisure, float fMSchool, int nDaysPassed, float fFood, int nDay, float fMAllowance)
{
	nDaysPassed = MONTH - nDay + 1;
	fFood = FOOD_DAILY * nDaysPassed;
	fRemBal = fMAllowance - fFood - fMFoodandDrink - fMTransportation - fMHealthcare - fHousing - fMLeisure - fMSchool;
			
		printf("\nDays passed: %d\n", nDaysPassed);
		printf("Current day: %d\n", nDay + nDaysPassed - 1);
		displayBudgetReport (fFood, fMTransportation, fMHealthcare, fHousing, fMLeisure, fMSchool, fSavings, fRemBal);
			
			// PROBLEM: There are errors in some parts of these results
				if (fMFoodandDrink <= fFoodandDrink)
					{
						printf("Budget allocation for food and drink is within budget allocation.\n");
					}
				else printf("Budget allocation for food and drink is not within budget allocation.\n");
				if (fMTransportation <= fTransportation)
					{
						printf("Budget allocation for transportation is within budget allocation.\n");
					}
				else printf("Budget allocation for transportation is not within budget allocation.\n");
				if (fMHealthcare <= fHealthcare)
					{
						printf("Budget allocation for healthcare is within budget allocation.\n");
					}
				else printf("Budget allocation for healthcare is not within budget allocation.\n");
				if (fMHousing <= fHousing)
					{
						printf("Budget allocation for household and utilities is within budget allocation.\n");
					}
				else printf("Budget allocation for housing and utilities is not within budget allocation.\n");
				if (fMLeisure <= fLeisure)
					{
						printf("Budget allocation for leisure is within budget allocation.\n");
					}
				else printf("Budget allocation for leisure is not within budget allocation.\n");
				if (fMSchool <= fSchool)
					{
						printf("Budget allocation for school is within budget allocation.\n\n");
					}
				else printf("Budget allocation for school is not within budget allocation.\n\n");
				 //PROBLEM: cannot be executed since subtraction of monthly savings is not working
				if (fSavings < 0)
				{
					printf("Savings were overspent!\n");
				}		

 } 

int main()
{
	float fMAllowance;
	float fFoodandDrink, fTransportation, fHealthcare, fHousing, fLeisure, fSchool;
	float fMFoodandDrink, fMTransportation, fMHealthcare, fMHousing, fMLeisure, fMSchool;
	float fSavings, fSpendSavings;
	int nDay = 1;
	float fRemBal;
	int nChoose = 0;
	int nOptions = 0;
	int nChoice = 0;
	float fExpenses;
	int nDaysPassed = 0;
	float fFood = 0;
	float fBudget;
	char sName[20];
	
	displayHeader ();
	
	//Get user's name
    printf("\nEnter first name: ");
    scanf("%s", sName);
    printf("Welcome %s to the Budgeting Allowance Program!\n\n", sName);
    
	//BEGIN BUDGETING
	//user defined function of getting the allowance
	getAllowance (&fMAllowance);
	/*This iterative statement checks if the user's input of monthly allowance is valid 
	(13000php or above) or not. User re-enters monthly allowance if the input
	does not meet the conditions.*/
	while (fMAllowance < 13000){
		printf("The monthly allowance of %s is not enough!\n\n", sName);
		printf("Re-enter monthly allowance: ");
		scanf("%f", &fMAllowance);
	}

	//user defined function of getting budget allocation
	getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
	
	/*This iterative statement checks if the user's input for budget allocation is valid 
	(Expenses for food and drink should be at least 9000php 
	while expneses for housing and utilities should be at least 4000php) or not.
	User re-enters budget allocation if they do not meet the conditions.*/
	while (fFoodandDrink < 9000 || fHousing < 4000){
		printf("\nRe-enter budget allocation.\n");
		getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
	}
	
	//Budget allocation should not exceed monthly allowance
	fBudget = fFoodandDrink + fTransportation + fHealthcare + fHousing + fLeisure + fSchool;
		if (fBudget > fMAllowance)
		{
			printf("\nBudget allocation exceeds the monthly allowance.\n");
			printf("\nRe-enter budget allocation.\n");
			getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
			while (fFoodandDrink < 9000 || fHousing < 4000){
				printf("\nRe-enter budget allocation.\n");
				getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
				}
		}
	
	fMFoodandDrink = 0;
	fSavings = 0;
	fRemBal = fMAllowance;

	// START OF THE DAY
	do {
		if (nDay > 30)
		{
			// PROBLEM: There are errors in some parts of these results
			if (fMFoodandDrink <= fFoodandDrink)
					{
						printf("\nBudget allocation for food and drink is within budget allocation.\n");
					}
				else printf("Budget allocation for food and drink is not within budget allocation.\n");
				if (fMTransportation <= fTransportation)
					{
						printf("Budget allocation for transportation is within budget allocation.\n");
					}
				else printf("Budget allocation for transportation is not within budget allocation.\n");
				if (fMHealthcare <= fHealthcare)
					{
						printf("Budget allocation for healthcare is within budget allocation.\n");
					}
				else printf("Budget allocation for healthcare is not within budget allocation.\n");
				if (fMHousing <= fHousing)
					{
						printf("Budget allocation for household and utilities is within budget allocation.\n");
					}
				else printf("Budget allocation for housing and utilities is not within budget allocation.\n");
				if (fMLeisure <= fLeisure)
					{
						printf("Budget allocation for leisure is within budget allocation.\n");
					}
				else printf("Budget allocation for leisure is not within budget allocation.\n");
				if (fMSchool <= fSchool)
					{
						printf("Budget allocation for school is within budget allocation.\n\n");
					}
				else printf("Budget allocation for school is not within budget allocation.\n\n");
				 //PROBLEM: cannot be executed since subtraction of monthly savings is not working
				if (fSavings < 0)
				{
					printf("Savings were overspent!\n");
				}		
			nDay = 1;
			fMFoodandDrink = 0;
			fMHousing = 0;
			fSavings = 0;
			fRemBal = fMAllowance;
			
			getAllowance (&fMAllowance);
					/*This iterative statement checks if the user's input of monthly allowance is valid 
					(13000php or above) or not. User re-enters monthly allowance if the first input
					does not meet the conditions.*/
					while (fMAllowance < 13000){
						printf("Monthly allowance not enough!\n\n");
						printf("Re-enter monthly allowance: ");
						scanf("%f", &fMAllowance);
					}
				
					//user defined function of getting budget allocation
					getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
					
					/*This iterative statement checks if the user's input for budget allocation is valid 
					(Expenses for food and drink should be at least 9000php 
					while expneses for housing and utilities should be at least 4000php) or not.
					User re-enters budget allocation if they do not meet the conditions.*/
					while (fFoodandDrink < 9000 || fHousing < 4000){
						printf("\nRe-enter budget allocation.\n");
						getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
					}
					
					if (fBudget > fMAllowance)
					{
						printf("\nBudget allocation exceeds the monthly allowance.\n");
						printf("\nRe-enter budget allocation.\n");
						getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
						while (fFoodandDrink < 9000 || fHousing < 4000){
							printf("\nRe-enter budget allocation.\n");
							getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
							}
					}
		}
	printf("\nCurrent Day: %d\n", nDay++);
	displayBudgetReport (fMFoodandDrink, fMTransportation, fMHealthcare, fMHousing, fMLeisure, fMSchool, fSavings, fRemBal);
	
	//USER'S ACTIONS: The possible actions that the user can do
	/*Switch statements are used for the categories*/
	do {
	printf("%s, choose a category:\n", sName);
	printf("[1] Add expenses\n"); //Add expenses = 1
	printf("[2] Add savings\n"); //Add savings = 2
	printf("[3] Use savings\n"); //Use savings = 3
	printf("[4] End the day\n"); //End the day = 4
	printf("[5] Exit program\n"); //Exit program = 5
	//Chooser picks from the choices
	scanf("%d", &nChoose);
	//User's choice will be based on the switch case
	//PROBLEM: adding of expenses and savings; only the latest user input is recognized
	switch (nChoose)
	{
	case 1:
	printf("\n%s, choose where to add expenses: \n", sName);
	printf("[1] Food and Drink\n");
	printf("[2] Transportation\n");
	printf("[3] Healthcare\n");
	printf("[4] Housing and Utilities\n");
	printf("[5] Leisure\n");
	printf("[6] School\n");
	scanf("%d", &nOptions);
		switch (nOptions)
		{
			case 1:
				printf("\nEnter amount for Food and Drink: ");
				scanf("%f", &fMFoodandDrink);
					while (fMFoodandDrink > fRemBal){
						printf("\nEntered amount is greater than the remaining balance.\n");
						printf("Re-enter amount for food and drink: ");
						scanf("%f", &fMFoodandDrink);
					}
				break;
			case 2:
				printf("\nEnter amount for Transportation: ");
				scanf("%f", &fMTransportation);
					while (fMTransportation > fRemBal){
						printf("\nEntered amount is greater than the remaining balance.\n");
						printf("Re-enter amount for transportation: ");
						scanf("%f", &fMTransportation);
					}
				break;
			case 3:
				printf("\nEnter amount for Healthcare: ");
				scanf("%f", &fMHealthcare);
					while (fMHealthcare > fRemBal){
						printf("\nEntered amount is greater than the remaining balance.\n");
						printf("Re-enter amount for healthcare: ");
						scanf("%f", &fMHealthcare);
					}
				break;
			case 4:
				printf("\nEnter amount for Housing and Utilities: ");
				scanf("%f", &fMHousing);
					while (fMHousing > fRemBal){
						printf("\nEntered amount is greater than the remaining balance.\n");
						printf("Re-enter amount for housing and utilities: ");
						scanf("%f", &fMHousing);
					}
				break;
			case 5:
				printf("\nEnter amount for Leisure: ");
				scanf("%f", &fMLeisure);
					while (fMLeisure > fRemBal){
						printf("\nEntered amount is greater than the remaining balance.\n");
						printf("Re-enter amount for leisure: ");
						scanf("%f", &fMLeisure);
					}
				break;
			case 6:
				printf("\nEnter amount for School: ");
				scanf("%f", &fMSchool);
					while (fMSchool > fRemBal){
						printf("\nEntered amount is greater than the remaining balance.\n");
						printf("Re-enter amount for school: ");
						scanf("%f", &fMSchool);
					}
				break;
			default:
				printf("Invalid input\n");
				break;
		}
	break;
	
	case 2:
		// getting money to be saved
		getSavings (&fSavings);
		/*This iterative statement checks if the user's input for the amount for savings is valid.
		Savings for the day should be less than or equal to the balance.
		User re-enters savings for the day if they do not meet the conditions.*/
		while (fSavings > fRemBal){
		printf("Entered amount is greater than the remaining balance.\n\n");
		printf("Re-enter savings: ");
		scanf("%f", &fSavings);
		//PROBLEM: Total savings resets instead of not reseting 
		}
	break;
	
	case 3:
		//getting money that will be spent
		useSavings (&fSpendSavings);
		/*This iterative statement checks if the user's input for the amount for spending the
		savings is valid. Savings for the day should be less than or equal to the balance.
		User re-enters amount for spending the savings if they do not meet the conditions.*/
		while (fSpendSavings > fSavings){
		printf("Entered amount is greater than the total savings.\n\n");
		printf("Re-enter savings that will be used: ");
		scanf("%f", &fSpendSavings);
	}
	break;
	
	case 4:
	printf("\n[1] End the day.\n");
	printf("[2] End the month.\n");
	scanf("%d", &nChoice);
		if (nChoice == 2)
		{				
			endMonth(fFoodandDrink, fTransportation, fHealthcare, fHousing, fLeisure, fSchool, fSavings, fRemBal, fMFoodandDrink, fMTransportation, fMHealthcare, fMHousing, fMLeisure, fMSchool, nDaysPassed, fFood, nDay, fMAllowance);
		}
			switch (nChoice)
			{
				case 1:
					printf("Day ended.\n");
					break;
				case 2: 
					printf("Month ended.\n\n");
					//user defined function of getting the allowance
						getAllowance (&fMAllowance);
						/*This iterative statement checks if the user's input of monthly allowance is valid 
						(13000php or above) or not. User re-enters monthly allowance if the first input
						does not meet the conditions.*/
						while (fMAllowance < 13000){
							printf("Monthly allowance not enough!\n\n");
							printf("Re-enter monthly allowance: ");
							scanf("%f", &fMAllowance);
						}
					
						//user defined function of getting budget allocation
						getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
						
						/*This iterative statement checks if the user's input for budget allocation is valid 
						(Expenses for food and drink should be at least 9000php 
						while expneses for housing and utilities should be at least 4000php) or not.
						User re-enters budget allocation if they do not meet the conditions.*/
						while (fFoodandDrink < 9000 || fHousing < 4000){
							printf("\nRe-enter budget allocation.\n");
							getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
						}
						
						if (fBudget > fMAllowance)
						{
							printf("\nBudget allocation exceeds the monthly allowance.\n");
							printf("\nRe-enter budget allocation.\n");
							getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
							while (fFoodandDrink < 9000 || fHousing < 4000){
								printf("\nRe-enter budget allocation.\n");
								getBudgetAllocation (&fFoodandDrink, &fTransportation, &fHealthcare, &fHousing, &fLeisure, &fSchool);
								}
						}
					break;
		default:
			printf("Invalid input\n");
			break;
		}
	break;
	
	case 5: 
		printf("\nThank you for using the Budgeting Allowance Program, %s!\n", sName);
		printf("Budget wisely!\n");
		printf("Program exited.\n");
		return 0;
		
	default:
	printf("\nInvalid input\n");
	break;
	}
} while (nChoose != 4);
	
	fRemBal = fMAllowance - fHousing;
	fMFoodandDrink = fFoodandDrink / 30 * (nDay - 1);
	fRemBal = fMAllowance - fHousing - fMFoodandDrink - fMTransportation - fMHealthcare - fMLeisure - fMSchool - fSavings;
	fExpenses = fMFoodandDrink + fMTransportation + fMHealthcare + fHousing + fMLeisure + fMSchool;
		
		if (fExpenses > fMAllowance && fExpenses > fRemBal)
		{
			printf("\nNo more allowance.\n");
			return 0;
		}
	
	fMHousing = fHousing;
	//PROBLEM: Savings is trash value if there is equation for deducting savings
	//fSavings = fSavings - fSpendSavings;
	
} while (nDay <= 365);
		//PROBLEM: cannot reset day counter Update: Day counter does not reset in endMonth function
  return 0;
}
