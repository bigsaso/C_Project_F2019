#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Function to get warmest temp of each lake
double highesttemp(double a[365]){
	int row;
    for (row=0;row<365;row++){
        if (a[0] < a[row])
            a[0] = a[row];
    }
    return(a[0]);
}

//Function to get coldest temp of each lake
double lowesttemp(double a[365]){
	int row;
    for (row=0;row<365;row++){
        if (a[0] > a[row])
            a[0] = a[row];
    }
    return(a[0]);
}

//Function to find location of warmest temperature
double findlocation(double a[365]){
	int row, location;
    for (row=0;row<365;row++){
        if (a[0] < a[row]){
            a[0] = a[row];
            location = row;
		}
    }
    return(location);
}

//Function to find location of coldest temperature
double findlocation1(double a[365]){
	int row, location;
    for (row=0;row<365;row++){
        if (a[0] > a[row]){
            a[0] = a[row];
            location = row;
		}
    }
    return(location);
}

//Function to convert day to date
void dayToDate(int days){
	char *m[10];
	if(days<=31){
		m[10] = "January";
	}
	if(days>31&&days<=59){
		m[10] = "February";
		days = days-31;
	}
	if(days>59&&days<=90){
		m[10] = "March";
		days = days-59;
	}
	if(days>90&&days<=120){
		m[10] = "April";
		days = days-90;
	}
	if(days>120&&days<=151){
		m[10] = "May";
		days = days-120;
	}
	if(days>151&&days<=181){
		m[10] = "June";
		days = days-151;
	}
	if(days>181&&days<=212){
		m[10] = "July";
		days = days-181;
	}
	if(days>212&&days<=243){
		m[10] = "August";
		days = days-212;
	}
	if(days>243&&days<=273){
		m[10] = "September";
		days = days-243;
	}
	if(days>273&&days<=304){
		m[10] = "October";
		days = days-273;
	}
	if(days>304&&days<=334){
		m[10] = "November";
		days = days-304;
	}
	if(days>334&&days<=365){
		m[10] = "December";
		days = days-334;
	}
	
	printf("%s %d", m[10], days);
}

int main(void){
	//Note: file name may vary on each machine
	FILE *f1 = fopen("2019.txt","r");
	//Start by creating the arrays first
	double year[365], day[365], superior[365], michigan[365], huron[365], erie[365], ontario[365], stclaire[365];
	int row;
	int locw1, locw2, locw3, locw4, locw5, locw6;
	int locc1, locc2, locc3, locc4, locc5, locc6;
	double warm1, warm2, warm3, warm4, warm5, warm6, warmest1;
	double cold1, cold2, cold3, cold4, cold5, cold6, coldest1;
	for(row=0;row<365;row++){
		fscanf(f1, "%lf%lf%lf%lf%lf%lf%lf%lf", &year[row], &day[row], &superior[row], &michigan[row], &huron[row], &erie[row], &ontario[row], &stclaire[row]);
		//Print the arrays just to check their exactness
		printf("%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\t%0.3lf\n", year[row], day[row], superior[row], michigan[row], huron[row], erie[row], ontario[row], stclaire[row]);
	}
	fclose(f1);
	
	//Introduce warmest temperature of each lake
	warm1 = highesttemp(superior);
	warm2 = highesttemp(michigan);
	warm3 = highesttemp(huron);
	warm4 = highesttemp(erie);
	warm5 = highesttemp(ontario);
	warm6 = highesttemp(stclaire);
	
	//Introduce coldest temperature of each lake
	cold1 = lowesttemp(superior);
	cold2 = lowesttemp(michigan);
	cold3 = lowesttemp(huron);
	cold4 = lowesttemp(erie);
	cold5 = lowesttemp(ontario);
	cold6 = lowesttemp(stclaire);
	
	//Introduce Location of warmest temperature of each lake in the array
	locw1 = findlocation(superior);
	locw2 = findlocation(michigan);
	locw3 = findlocation(huron);
	locw4 = findlocation(erie);
	locw5 = findlocation(ontario);
	locw6 = findlocation(stclaire);
	
	//Introduce Location of coldest temperature of each lake in the array
	locc1 = findlocation1(superior);
	locc2 = findlocation1(michigan);
	locc3 = findlocation1(huron);
	locc4 = findlocation1(erie);
	locc5 = findlocation1(ontario);
	locc6 = findlocation1(stclaire);
	
	//Some locations were not used, but all of them were needed to define the address of warmest and coldest temperatures
	
	double warmest[6] = {warm1,warm2,warm3,warm4,warm5,warm6};
	double coldest[6] = {cold1,cold2,cold3,cold4,cold5,cold6};
	
	warmest1 = highesttemp(warmest);
	coldest1 = lowesttemp(coldest);
	
	printf("Warmest lake overall is St. Claire with a temperature overall of %0.3lf C on ", warmest1);
	dayToDate(day[locw6]);
	printf("\nColdest lakes overall are Superior, Huron, Erie and St. Claire with %0.3lf C respectively on ", coldest1);
	dayToDate(day[locc1]);
	printf(", ");
	dayToDate(day[locc3]);
	printf(", ");
	dayToDate(day[locc4]);
	printf(", and ");
	dayToDate(day[locc6]);
	
	return(0);
}
