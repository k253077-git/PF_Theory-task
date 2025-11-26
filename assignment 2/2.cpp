#include <stdio.h>

void calcfuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int t_planets){
	if(fuel<0){
		printf("Fuel is exhausted");
		return;
	}
	if(planet>t_planets){
		printf("All planets have been visited successfully");
		return;
	}
	fuel-=consumption;
	if(fuel<0)
	fuel=0;
	
	fuel+=recharge;
	if(planet%4==0){
		fuel+=solarBonus;
	}
	
	printf("Planet %d, fuel %d\n",planet,fuel);
	
     calcfuel(fuel, consumption, recharge, solarBonus, planet+1, t_planets);
}

int main(){
	printf("Fuel system\n");
	int f=500;
	int c=80;
	int r=20;
	int sb=100;
	int tp=10;
	
	calcfuel(f,c,r,sb,1,tp);
}
