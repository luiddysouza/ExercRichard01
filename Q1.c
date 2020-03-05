/*Dados 2 vetores, calcular a soma deles;*/

#include <omp.h>
#include <stdio.h>

int tamanho = 100;
int i;
        
int main(){
    double vetor1[tamanho];
    double vetor2[tamanho];
    double vetorResultado[tamanho];   
    
    #pragma omp parallel num_threads(6)
    {  
        
        #pragma omp for
            for(i=0 ; i<tamanho ; i++){
                vetorResultado[i] = vetor1[i] + vetor2[i];
            }
    }
    getchar();
}