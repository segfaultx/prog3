#include <stdio.h>

/*function to represent a math function following pattern f(x) = ... */
double f(double x){

	return x*x-25;
}

/* function to return absolute value of given value */
double absolute(double val){
	if(val<0){
		return val*-1;
	}
	return val;
}

double regula(double x1, double x2, double (*f)(double)){
	double xs;
	/* first calculation */
	xs = x1 - f(x1)*((x2-x1)/(f(x2)-f(x1)));
	while(absolute(f(xs))>(1e-6)){
		/* if x1 and xs share same sign swap them */
		if((xs<0 && x1<0) || (xs>0 && x1>0)){
			xs+=x1;
			x1=xs-x1;
			xs=xs-x1;
		}
		 /* else case, xs and x2 get swapped */
		else{	
			xs+=x2;
			x2=xs-x2;
			xs=xs-x2;
		}
		xs = x1 -f(x1)*((x2-x1)/(f(x2)-f(x1)));
	}
	return xs;
}


int main(void){
	printf("%f\n",regula(1,15,f));
	return 0;
}
