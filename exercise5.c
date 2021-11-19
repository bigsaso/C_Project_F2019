#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//declare and define average temperature function
double summer(double a[365]){
	int row;
	double sum = 0, avg;
	for(row=171;row<265;row++){
		sum = sum+a[row];
	}
	avg = sum/93;
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
	avg1 = summer(superior);
	avg2 = summer(michigan);
	avg3 = summer(huron);
	avg4 = summer(erie);;
	avg5 = summer(ontario);
	avg6 = summer(stclaire);
	
	//First we displayed the averages
	printf("\nThe summer average temperature of Lake Superior is %0.3lf\n", avg1);
	printf("The summer average temperature of Lake Michigan is %0.3lf\n", avg2);
	printf("The summer average temperature of Lake Huron is %0.3lf\n", avg3);
	printf("The summer average temperature of Lake Erie is %0.3lf\n", avg4);
	printf("The summer average temperature of Lake Ontario is %0.3lf\n", avg5);
	printf("The summer average temperature of Lake St. Claire is %0.3lf\n", avg6);
	
	//After seeing the result of the averages, we compiled the list in order
	printf("\nThe lakes' temperature in order from warmest to coldest is:\n");
	printf("Erie with an average summer temperature of %0.3lf\n", avg4);
	printf("St. Claire with an average summer temperature of %0.3lf\n", avg6);
	printf("Ontario with an average summer temperature of %0.3lf\n", avg5);
	printf("Michigan with an average summer temperature of %0.3lf\n", avg2);
	printf("Huron with an average summer temperature of %0.3lf\n", avg3);
	printf("Superior with an average summer temperature of %0.3lf\n", avg1);
	
	return(0);
}
