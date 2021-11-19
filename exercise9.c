#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//declare and define average temperature function
double avgtemp(double a[365]){
	int row;
	double sum = 0, avg;
	for(row=0;row<365;row++){
		sum = sum+a[row];
	}
	avg = sum/365;
	return(avg);
}

int main(void){
	
	//This part finds averages in 2018
	//Note: file name may vary on each machine
	FILE *f1 = fopen("2018.txt","r");
	//Start by creating the arrays first
	double year1[365], day1[365], superior1[365], michigan1[365], huron1[365], erie1[365], ontario1[365], stclaire1[365];
	int row1;
	double avg7, avg8, avg9, avg10, avg11, avg12, totavg2;
	for(row1=0;row1<365;row1++){
		fscanf(f1, "%lf%lf%lf%lf%lf%lf%lf%lf", &year1[row1], &day1[row1], &superior1[row1], &michigan1[row1], &huron1[row1], &erie1[row1], &ontario1[row1], &stclaire1[row1]);
		//Print the arrays just to check their exactness
		printf("%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\n", year1[row1], day1[row1], superior1[row1], michigan1[row1], huron1[row1], erie1[row1], ontario1[row1], stclaire1[row1]);
	}
	fclose(f1);
	//Call the function to find yearly average
	avg7 = avgtemp(superior1);
	avg8 = avgtemp(michigan1);
	avg9 = avgtemp(huron1);
	avg10 = avgtemp(erie1);;
	avg11 = avgtemp(ontario1);
	avg12 = avgtemp(stclaire1);
	totavg2 = (avg7+avg8+avg9+avg10+avg11+avg12)/6;
	
	//This part finds averages in 2019
	//Note: file name may vary on each machine
	FILE *f2 = fopen("2019.txt","r");
	//Start by creating the arrays first
	double year[365], day[365], superior[365], michigan[365], huron[365], erie[365], ontario[365], stclaire[365];
	int row;
	double avg1, avg2, avg3, avg4, avg5, avg6, totavg1;
	for(row=0;row<365;row++){
		fscanf(f1, "%lf%lf%lf%lf%lf%lf%lf%lf", &year[row], &day[row], &superior[row], &michigan[row], &huron[row], &erie[row], &ontario[row], &stclaire[row]);
		//Print the arrays just to check their exactness
		printf("%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\n", year[row], day[row], superior[row], michigan[row], huron[row], erie[row], ontario[row], stclaire[row]);
	}
	fclose(f2);
	//Call the function to find yearly average
	avg1 = avgtemp(superior);
	avg2 = avgtemp(michigan);
	avg3 = avgtemp(huron);
	avg4 = avgtemp(erie);;
	avg5 = avgtemp(ontario);
	avg6 = avgtemp(stclaire);
	//Use simple average calculation to find total yearly average
	totavg1 = (avg1+avg2+avg3+avg4+avg5+avg6)/6;
	//Here is the list of printf statements for the comparison table
	printf("\nYear:\t\t2018\t\t2019\n\n");
	printf("Superior:\t%0.3lf\t\t%0.3lf\n", avg7, avg1);
	printf("Michigan:\t%0.3lf\t\t%0.3lf\n", avg8, avg2);
	printf("Huron:\t\t%0.3lf\t\t%0.3lf\n", avg9, avg3);
	printf("Erie:\t\t%0.3lf\t\t%0.3lf\n", avg10, avg4);
	printf("Ontario:\t%0.3lf\t\t%0.3lf\n", avg11, avg5);
	printf("St. Claire:\t%0.3lf\t\t%0.3lf\n\n", avg12, avg6);
	printf("Total:\t\t%0.3lf\t\t%0.3lf\n", totavg2, totavg1);
	return(0);
}

