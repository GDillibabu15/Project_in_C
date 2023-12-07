#include<stdio.h>


float Total_Mounthly_Income;
float Total_Essential_Expenses;
float Total_Lifestyle_Expenses;
float Total_EMIs;
float Total_Investments;
float Leftout_For_The_Mounth;
float Total_Outflows;
float Mounthly_Income;
float Additional_Income;
float Rentel_Income;
float Spouse_Income;


float _Mounthly_Income()
{

	printf("Enter your Mounthly Salary :\n");
	scanf("%f",&Mounthly_Income);
	printf("Enter your Additional Income if you have othewise enter \"0\" :\n");
	scanf("%f",&Additional_Income);
	printf("Enter your Rentel Income if you have, otherwise enter \"0\" : \n");
	scanf("%f",&Rentel_Income);
	printf("Enter your Spouse's income if your wife earns otherwise enter \"0\" :\n");
	scanf("%f",&Spouse_Income);
	
	float Total;
	Total = Mounthly_Income + Additional_Income + Rentel_Income + Spouse_Income;
	return Total;
}


float Essential_Expenses()
{
	float House_Rent, Children_Fee, Property_tax, Utilities, Groceries, Transportation, Medical_Expenses, Insurence_Premiums;
	
	printf("Enter your house rent :\n");
	scanf("%f",&House_Rent);
	printf("Enter your Children_Fees :\n");
	scanf("%f",&Children_Fee);
	printf("Enter your Property_tax :\n");
	scanf("%f",&Property_tax);
	printf("Enter your Utilities Expenses :\n");
	scanf("%f",&Utilities);
	printf("Enter your Groceries Expenses :\n");
	scanf("%f",&Groceries);
	printf("Enter your Transportation Expenses :\n");
	scanf("%f",&Transportation);
	printf("Enter your Medical Expenses :\n");
	scanf("%f",&Medical_Expenses);
	printf("Enter your Insurence Premiums :\n");
	scanf("%f",&Insurence_Premiums);

	float total = House_Rent + Children_Fee + Property_tax + Utilities + Groceries + Transportation + Medical_Expenses + Insurence_Premiums;
	return total;
}


float Lifestyle_Expenses()
{
	float Shopping, Travel, Dine_and_Entertainment;
	printf("Enter how much would you like to spend on \"Shopping\":\n");
	scanf("%f",&Shopping);
	printf("Enter how much would you like to spend on \"Traveling\":\n");
	scanf("%f",&Travel);
	printf("Enter how much would you like to spend on \"Dinner and Entertainment\":\n");
	scanf("%f",&Dine_and_Entertainment);
	
	float total= Shopping + Travel + Dine_and_Entertainment;
	
	return total;
}

float EMIs()
{
	float Home_Loan_EMI, Car_Loan_EMI, Personal_Loan_EMI, Other_EMIs;
	printf("Enter your Home loan EMI :\n");
	scanf("%f",&Home_Loan_EMI);
	printf("Enter your Car Loan EMI :\n");
	scanf("%f",&Car_Loan_EMI);
	printf("Enter your Personal Loan EMI :\n");
	scanf("%f",&Personal_Loan_EMI);
	printf("Enter if any other EMIs :");
	scanf("%f",&Other_EMIs);

	float total= Home_Loan_EMI + Car_Loan_EMI + Personal_Loan_EMI + Other_EMIs;
	
	return total;
}

	
float Investments()
{
	float Mutual_Funds, Stocks;
	printf("Enter how much would you invested on Mutual Funds :\n");
	scanf("%f",&Mutual_Funds);
	printf("Enter how much would you invested on stocks :\n");
	scanf("%f",&Stocks);
	
	float Total; 
	Total= Mutual_Funds + Stocks ;
	
	return Total;
}


float Mounthly_Outflow()
{
	float Total;
	Total = Total_Essential_Expenses + Total_Lifestyle_Expenses + Total_EMIs + Total_Investments ;
	return Total;

}


float Savings()
{
	float savings;
	savings = Total_Mounthly_Income - Total_Outflows;
	return savings;
}


int main()
{

		
	Total_Mounthly_Income = _Mounthly_Income();
	Total_Essential_Expenses = Essential_Expenses();
	Total_Lifestyle_Expenses = Lifestyle_Expenses();
	Total_EMIs = EMIs();
	Total_Investments = Investments();
	Total_Outflows = Mounthly_Outflow();
	Leftout_For_The_Mounth = Savings();
	
	float Ten_Percent_of_Income = Total_Mounthly_Income / 10 ;
	//printf("%f\n",Ten_Percent_of_Income);


	printf("\n\n      Mounthly Budget Planning        \n\n");


	printf("    Expenses	     	Amount\n");
	printf("Essential Expenses	%.2f\n",Total_Essential_Expenses);
	printf("Lifestyle Expenses	%.2f\n",Total_Lifestyle_Expenses);
	printf("EMIs			%.2f\n",Total_EMIs);
	printf("Investments		%.2f\n",Total_Investments);
	printf("Savings			%.2f\n",Leftout_For_The_Mounth);
	


	printf("Amount		Statement\n");
	printf("\n");


	if(Total_Essential_Expenses < 4*Ten_Percent_of_Income)
	{
		printf("%.2f	The Essential Expenses are with in line with income \n",Total_Essential_Expenses);
	}
	else
	{
		printf("%.2f	The Essential Expenses are not with in line with income\n",Total_Essential_Expenses);
		printf("  		Reduce the Expenses to be with in line with income\n");
	}

	if(Total_Lifestyle_Expenses < 2*Ten_Percent_of_Income)
	{
		printf("%.2f	The Lifestyle Expenses are with in line with income \n",Total_Lifestyle_Expenses);
	}
  	else
	{
		printf("%.2f	The Lifestyle Expenses are not with in line with income\n",Total_Lifestyle_Expenses);
		printf("		Reduce the Expenses to be with in line with income\n");
	}

	if(Total_EMIs < 3*Ten_Percent_of_Income)
	{
		printf("%.2f	The EMI level range Utilization is good \n",Total_EMIs);
	}
  	else
	{
		printf("%.2f	The level range utilization is verybad\n",Total_EMIs);
		printf("  		To be in good finacail condition first clear high paying interest rate EMIs\n");
	}


	if(Total_Investments > 4*Ten_Percent_of_Income)
	{
		printf("%.2f	Your Investments are Extedronary \n",Total_Investments);
	}
  	else if((Total_Investments > 2*Ten_Percent_of_Income) && (Total_Investments < 4*Ten_Percent_of_Income))
	{
		
		printf("%.2f	Increase the Investments \n",Total_Investments);
	}
	else
	{
		printf("%.2f	Your are Poor at Investments\n",Total_Investments);
	}

	if(Leftout_For_The_Mounth > 2*Ten_Percent_of_Income)
	{
		printf("%.2f	Move sum funds to Investments\n",Leftout_For_The_Mounth);
 	}

	
	return 0;
}
	
