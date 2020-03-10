/*Dados 2 vetores, calcular a soma deles;*/

#include <omp.h>
#include <stdio.h>

int tamanho = 5;
int i;
        
void main(){
    int vetor1[] = {1,2,3,4,5};
    int vetor2[] = {6,7,8,9,0};
    int vetorResultado[tamanho];   
    
    #pragma omp parallel num_threads(6)
    {  
        
        #pragma omp for
            for(i=0 ; i<tamanho ; i++){
                vetorResultado[i] = vetor1[i] + vetor2[i];
                printf("%i ", vetorResultado[i]);
            }
    }
    printf("\n");
}