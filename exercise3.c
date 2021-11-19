#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int daypermonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *lake[6] = {“Superior”, “Michigan”, “Huron”, “Erie”, “Ontario”, “Stclair”};
double temperature[6][365], index[6][3], avgtemperature;
void numtodate(int num)
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
			printf(“ %d/%d \n”, num, i+1);
		}
	}
}
void warmesttemp()
{
	int i
	for(i=0; i<6; i++)
	{
		printf(“Lake %s is warmest with a temperature of .2%lf on “, temperature[i][(int)index[i][2]],lake[i]);
		numtodate(index[i][2]);
	}
}
void coldesttemp()
{
	int j
	for(j=0; j<6; j++)
	{
		printf(“Lake %s is warmest with a temperature of .2%lf on “, temperature[j][(int)index[j][0]],lake[j]);
		numtodate(index[j][0]);
	}
}
int main()
{
	warmesttemp();
	coldesttemp();
}

