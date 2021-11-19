#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//declare and define average temperature function
double winter(double a[365]){
	int row;
	double sum1 = 0, sum2 = 0, avg;
	for(row=0;row<79;row++){
		sum1 = sum1+a[row];
	}
	for(row=354;row<365;row++){
		sum2 = sum2+a[row];
	}
	avg = (sum1+sum2)/89;
	return(avg);
}

int main(void){
	//Note: file name may vary on each machine
	FILE *f1 = fopen("2019.txt","r");
	//Start by creating the arrays first
	double year[365], day[365], superior[365], michigan[365], huron[365], erie[365], ontario[365], stclaire[365];
	int row;
	double avg1, avg2, avg3, avg4, avg5, avg6;
	for(row=0;row<365;row++){
		fscanf(f1, "%lf%lf%lf%lf%lf%lf%lf%lf", &year[row], &day[row], &superior[row], &michigan[row], &huron[row], &erie[row], &ontario[row], &stclaire[row]);
		//Print arrays just to check their exactness
		printf("%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\n", year[row], day[row], superior[row], michigan[row], huron[row], erie[row], ontario[row], stclaire[row]);
	}
	fclose(f1);
	//Call the function to find summer average
	avg1 = winter(superior);
	avg2 = winter(michigan);
	avg3 = winter(huron);
	avg4 = winter(erie);;
	avg5 = winter(ontario);
	avg6 = winter(stclaire);
	
	//First we displayed the averages
	printf("The winter average temperature of Lake Superior is %0.3lf\n", avg1);
	printf("The winter average temperature of Lake Michigan is %0.3lf\n", avg2);
	printf("The winter average temperature of Lake Huron is %0.3lf\n", avg3);
	printf("The winter average temperature of Lake Erie is %0.3lf\n", avg4);
	printf("The winter average temperature of Lake Ontario is %0.3lf\n", avg5);
	printf("The winter average temperature of Lake St. Claire is %0.3lf\n", avg6);
	
	//After seeing the result of the averages, we compiled the list in order
	printf("\nThe lakes' temperature in order from warmest to coldest is:\n");
	printf("Ontario with an average winter temperature of %0.3lf\n", avg5);
	printf("Michigan with an average winter temperature of %0.3lf\n", avg2);
	printf("Huron with an average winter temperature of %0.3lf\n", avg3);
	printf("Superior with an average winter temperature of %0.3lf\n", avg1);
	printf("Erie with an average winter temperature of %0.3lf\n", avg4);
	printf("St. Claire with an average winter temperature of %0.3lf\n", avg6);
	
	return(0);
}
