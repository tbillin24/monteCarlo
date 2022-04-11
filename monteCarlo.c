#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265


double boxMuller (double mean, double stdDev) {

	float u = 0.0, r, theta; 
	double x;
	double norm_rv;	

		
	u = rand() / ((float)RAND_MAX+1);

	r = sqrt(-2.0*log(u));

	theta = 2.0*PI*(rand() / ((double)RAND_MAX+1));

	x = r*cos(theta);

	norm_rv = (x*stdDev)+mean;

	return(norm_rv);
}

int *coefGenerator(double coef[], double stdDev[]) {
	
	int len = sizeof(coef)/sizeof(coef[0]);
	
	double randCoef[len];

	for (int i=0; i<len; i++) {
		randCoef[i] = boxMuller(coef[i],stdDev[i]);
	}
	
	return randCoef;
}



int main() {
	
	printf("%f",boxMuller(0.0,1.0));


	double array[50];

	unsigned int len = sizeof(array)/sizeof(array[0]);

	for (int i=0;i<len;i++){
		array[i] = boxMuller(0.0,1.0);
		printf("%f\n", array[i]);
	}

	return 0;
}
