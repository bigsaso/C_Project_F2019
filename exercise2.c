#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int daypermonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *lake[6] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "Stclair"};
double temperature[6][365], index[6][3], avgtemperature;

double avgtemp(double a[365]){
          	int row;
          	double sum = 0, avg;
          	for(row=0;row<365;row++){
                       	sum = sum+a[row];
          	}
          	avg = sum/365;
          	return(avg);
}
void warmestavg() //Question 2
{
	int i, a = 0;
	for(i=1; i<6; i++)
	{
		if(index[i][1] > index[a][1])
		{
			a = i;
		}
	}
	printf("Warmest Lake is lake %s\n", lake[a]);
	for(i=0; i<6; i++)
	{
		if(index[i][1] > avgtemperature)
		{
			printf("Lakes above the average temperature: %s\n", lake[i]);
		}
	}
}
void coldestavg()
{
	int j, b = 0;
	for(j=1; j<6; j++)
	{
		if(index[j][1] > index[b][1])
		{
			b = j;
		}
	}
	printf("Coldest Lake is lake %s\n", lake[b]);
	for(j=0; j<6; j++)
	{
		if(index[j][1] > avgtemperature)
		{
			printf("Lakes below the average temperature: %s\n", lake[j]);
		}
	}
}
void numtodate(int num) //tool for q3 & a4
{
	int i;
	for(i = 0; i < 12; i++)
	{
		if(num > daypermonth[i])
		{
			num -= daypermonth[i];
		}
		else
		{
			printf("%d/%d \n", num, i+1);
		}
		break;
	}
}
void warmesttemp() //Question 3
{
	int i;
	for(i=0; i<6; i++)
	{
		printf("Lake %s is warmest on ", lake[i]);
		numtodate(index[i][2]);
		printf(" with a temperature of .2%lf\n", temperature[i][(int)index[i][2]]);
	}
}
void coldesttemp()
{
	int j;
	for(j=0; j<6; j++)
	{
		printf("Lake %s is coldest on ", lake[j]);
		numtodate(index[j][0]);
		printf(" with a temperature of .2%lf\n", temperature[j][(int)index[j][0]]);
	}
}
void thewarmesttemp() //Question 4
{
	int i, a = 0;
	for(i=1; i<6; i++)
	{
		if(index[i][1] > index[a][1])
		{
			a = i;
		}
	}
	printf("Warmest Lake is lake %s on ", lake[a]);
	numtodate(index[i][2]);
	printf(" with a temperature of .2%lf\n", temperature[i][(int)index[i][2]]);
	
}
void thecoldesttemp()
{
	int j, b = 0;
	for(j=1; j<6; j++)
	{
		if(index[j][1] > index[b][1])
		{
			b = j;
		}
	}
	printf("Warmest Lake is lake %s on ", lake[b]);
	numtodate(index[j][0]);
	printf(" with a temperature of .2%lf\n", temperature[j][(int)index[j][0]]);
}
 
int main(void){
          	//Note: file name may vary on each machine
          	FILE *f1 = fopen("2019.txt","r");
          	//Start by creating the arrays first
          	double year[365], day[365], superior[365], michigan[365], huron[365], erie[365], ontario[365], stclair[365];
          	int row;
          	double avg1, avg2, avg3, avg4, avg5, avg6, totavg;
          	for(row=0;row<365;row++){
                       	fscanf(f1, "%lf%lf%lf%lf%lf%lf%lf%lf", &year[row], &day[row], &superior[row], &michigan[row], &huron[row], &erie[row], &ontario[row], &stclair[row]);
                       	//Print the arrays just to check their exactness
                       	printf("%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\n", year[row], day[row], superior[row], michigan[row], huron[row], erie[row], ontario[row], stclair[row]);
          	}
          	fclose(f1);
          	//Call the function to find yearly average
          	avg1 = avgtemp(superior);
          	avg2 = avgtemp(michigan);
          	avg3 = avgtemp(huron);
          	avg4 = avgtemp(erie);;
          	avg5 = avgtemp(ontario);
          	avg6 = avgtemp(stclair);
          	//Use simple average calculation to find total yearly average
          	totavg = (avg1+avg2+avg3+avg4+avg5+avg6)/6;
          	printf("The yearly average temperature of Lake Superior is %0.3lf\n", avg1);
          	printf("The yearly average temperature of Lake Michigan is %0.3lf\n", avg2);
          	printf("The yearly average temperature of Lake Huron is %0.3lf\n", avg3);
          	printf("The yearly average temperature of Lake Erie is %0.3lf\n", avg4);
          	printf("The yearly average temperature of Lake Ontario is %0.3lf\n", avg5);
          	printf("The yearly average temperature of Lake St. Clair is %0.3lf\n", avg6);
          	printf("The yearly average temperature of all six lakes put together is %0.3lf\n", totavg);
          	warmestavg();
			coldestavg();
          	warmesttemp();
			coldesttemp();
          	thewarmesttemp();
			thecoldesttemp();

          	return(0);
}
