/*
x power y can be calculated by multiplying x for y times. Complexity of the algorithm with this method is in terms of O(y).
Other method is to use binary representation of y to determine multiplication stratergy.Algorithm using this method will have it's complexity O(log y) to base 2.

Given two positive integers x and y, Calculate x power y and compare number of multiplication operations required in each (Complexity).
a)Multiplying x for y times
b)Using binary representation of y
c)Using base 3 representation of y

INPUT FORMAT
<X><Y>
	X,Y are two posotive integers

OUTPUT FORMAT
<RESULTa><Na>
<RESULTb><Nb>
<RESULTc><Nc>

	<RESULTx> result obtained when method x is used
	<Nx> Number of multiplication operations for method x

Test Cases:
------------------------------------
Input:
2 23

Output:
8388608 23
8388608 5
8388608 6
-------------------------------------

Input:
6 13

Output:
175792128 13
175792128 4
175792128 6
-------------------------------------
Input:
10 0

Output:
1 0
1 0
1 0
-------------------------------------

*/
#include<stdio.h>
int main(void)
{
	//final result stored in result and count for multiplication operation stored in mul

	int x,y,i,mul=0,result=1;
	//taking input from the input.in 
	scanf("%d",&x);
	scanf("%d",&y);	
	
	//Part a
	for(i=1;i<=y;i++)
	{
		mul++;
		result=result*x;
	}
	//printing reesult for part a
	printf("%d %d",mul,result);

	//Partb
	result=power_xy(x,y,&mul);
	printf("\n%d %d",mul,result);

	//Partc
	result=power_3xy(x,y,&mul);
	printf("\n%d %d",mul,result);
}

//This function calculates x power y by representing y in base 2
int power_xy(int x,int y,int *m)
{
	int result,sequence,lsb;
	result=1;
	sequence=x;
	*m=0;
	while(y>0)
	{
		lsb=y%2;
		if(lsb==1)
			result=result*sequence;
		sequence*=sequence;
		(*m)++;	
		y=y/2;
	}
	return result;
}

//This function calculates x power y by representing y in base 3
int power_3xy(int x,int y,int *m)
{
	int result,sequence,lsb;
	result=1;
	sequence=x;
	*m=0;
	while(y>0)
	{
		lsb=y%3;
		if(lsb==1)
			result=result*sequence;
		else if(lsb==2)
			result=result*sequence*sequence;
		sequence=sequence*sequence*sequence;
		*m=*m+2;	
		y=y/3;
	}
	return result;
}
