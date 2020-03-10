/*Calcular a média e o desvio padrão dos dados de um vetor*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int tamanho = 5;
int i;

void main(){
    float v[] = {1,2,3,4,5};
    float somatorio = 0, media, desvioPadrao = 0;

    #pragma omp parallel
    { 
        #pragma omp for reduction(+:somatorio)
            for(i=0; i<tamanho; i++){
                somatorio += v[i];
            }
    }

    media = somatorio/tamanho;

    #pragma omp parallel
    {
        #pragma omp for reduction(+:somatorio)
            for(i=0 ; i<tamanho ; i++){
                desvioPadrao += pow(v[i]  - media, 2);
            }
    }

    desvioPadrao = sqrt(desvioPadrao / tamanho);
  
    printf("Media: %.2f ", media);
    printf("Desvio Padrao: %.2f\n", desvioPadrao);
}