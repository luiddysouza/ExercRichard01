/*Encontrar o maior e o menor valor de um vetor.*/

#include <omp.h>
#include <stdio.h>
#include <math.h>

int tamanho = 5;
int i;
        
int main(){
    float v[tamanho] ;
    
    for(i=0 ; i<tamanho ; i++){
        v[i] = 10-i;
    }

    float minimo = v[0], maximo = v[0];

    #pragma omp parallel
    {  
        #pragma omp for reduction(min: minimo)
            for(i=1 ; i<tamanho ; i++){
                if (v[i] < minimo){
                    minimo = v[i];
                }
            }
        #pragma omp for reduction(max: maximo)
            for(i=1 ; i<tamanho ; i++){
                if (v[i] > maximo){
                    maximo = v[i];
                }  
            }
    }

    printf("Minimo:%.2f\n", minimo);
    printf("Maximo:%.2f\n", maximo);
}