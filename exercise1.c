#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//declare and define average temperature function (for Exercise 1)
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
	//Note: file name may vary on each machine
	FILE *f1 = fopen("2019.txt","r");
	//Start by creating the arrays first
	double year[365], day[365], superior[365], michigan[365], huron[365], erie[365], ontario[365], stclaire[365];
	int row;
	double avg1, avg2, avg3, avg4, avg5, avg6, totavg;
	for(row=0;row<365;row++){
		fscanf(f1, "%lf%lf%lf%lf%lf%lf%lf%lf", &year[row], &day[row], &superior[row], &michigan[row], &huron[row], &erie[row], &ontario[row], &stclaire[row]);
		//Print the arrays just to check their exactness
		printf("%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\n", year[row], day[row], superior[row], michigan[row], huron[row], erie[row], ontario[row], stclaire[row]);
	}
	fclose(f1);
	//Call the function to find yearly average
	avg1 = avgtemp(superior);
	avg2 = avgtemp(michigan);
	avg3 = avgtemp(huron);
	avg4 = avgtemp(erie);;
	avg5 = avgtemp(ontario);
	avg6 = avgtemp(stclaire);
	//Use simple average calculation to find total yearly average
	totavg = (avg1+avg2+avg3+avg4+avg5+avg6)/6;
	printf("The yearly average temperature of Lake Superior is %0.3lf\n", avg1);
	printf("The yearly average temperature of Lake Michigan is %0.3lf\n", avg2);
	printf("The yearly average temperature of Lake Huron is %0.3lf\n", avg3);
	printf("The yearly average temperature of Lake Erie is %0.3lf\n", avg4);
	printf("The yearly average temperature of Lake Ontario is %0.3lf\n", avg5);
	printf("The yearly average temperature of Lake St. Claire is %0.3lf\n", avg6);
	printf("The yearly average temperature of all six lakes put together is %0.3lf\n", totavg);
	return(0);
}
