#include <stdio.h>
#include <stdlib.h>

int main(){

int m_bettor;
float n_pot;
scanf("%i %f",&m_bettor, &n_pot);
int bet [1000][60];
for(int i=0; i<m_bettor; i++){
	for(int j=0; j<60; j++){
		scanf(" %i", &bet[i][j]);
	}
}

int drawn [6];
for(int i=0; i<6; i++){
		scanf(" %i", &drawn[i]);
}

int acertos [1000];
int count_four, count_five, count_six = 0;
for(int i=0; i<m_bettor; i++){
	acertos[i] = 0;
	for (int j = 0; j < 6; ++j){
		if (bet[i][drawn[j]-1] == 1){
		acertos[i]++;
		}
	}
	if (acertos[i] == 4){
	count_four++;
	}
	else if (acertos[i] == 5){
	count_five++;
	}
	else if (acertos[i] == 6){
	count_six++;
	}
}

for(int i=0; i<m_bettor; i++){
	if (acertos[i] == 4){
		printf("%.2f\n", (n_pot * 0.19) / count_four);
	}
	else if (acertos[i] == 5){
		printf("%.2f\n", (n_pot * 0.19) / count_five);
	}
	else if (acertos[i] == 6){
		printf("%.2f\n", (n_pot * 0.62) / count_six);
	}
	else {
		printf("0.00\n");
	}
}

printf("\n");
return 0;
}