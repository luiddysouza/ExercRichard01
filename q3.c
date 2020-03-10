/*Calcular a média harmônica de um vetor*/

#include <omp.h>
#include <stdio.h>
#include <math.h>

int tamanho = 5;
int i;
        
void main(){
    float v[tamanho];
    float mediaHarmonica = 0, somatorio = 0;
    
    for(i=0 ; i<tamanho ; i++)
        v[i] = i+1;

    #pragma omp parallel
    {  
        #pragma omp for reduction(+: somatorio)
            for(i=0 ; i<tamanho ; i++){
                somatorio += 1 / v[i];
            }
    }

    mediaHarmonica = tamanho/somatorio;
    
    printf("Media Harmonica: %.2f ", mediaHarmonica);
}