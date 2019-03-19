#include<stdio.h>
#include<stdlib.h>

int main(){
	int *v; 
	int i,j,n,aux,y,p,w;
 	int primo=0;



  	scanf ("%d", &n);
  	if(n>1 && n<5){
  		v = malloc (n * sizeof (int));
  		i=0;
  	//PEGA O VALOR
  		while(i<n){
        scanf("%i",&v[i]);

        //VERIFICA SE O NUMERO É MENOR QUE ZERO e fica em loop até o numero ser maior
        while(v[i]<= 0){
          printf("esse numero é menor ou igual a zero tente outro\n");
          scanf("%i",&v[i]);
        }
  			
        /*CASO SEJA SO COM NUMEROS PRIMOS
  				for(j=1;j<=v[i];j++){
  					if (v[i]%j==0){ 
  						primo++;
   					 }
  				}
  				if(primo == 2){
  					primo = 0;
  					i++;
  				}else{
  					primo =0;
  					printf("esse numero não é primo tente outro\n");
  				}*/


        //incrementa o vetor
        i++;
  			
  		}

  		// Faz a ordenação do vetor
  		for ( i = 0; i <n; i++){
            for ( j = 0; j < n; j++){
                if (v[i] < v[j]){
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }
         //FIm DA ORDENAÇÃO


        //pegando os dois numeros para realizar o mdc //
        if(n == 2){
        	y = fazmdc(v[1],v[0]);
        	printf("%i\n",y);
        }else if(n==3){//ṕegando 3 numeros para o mdc //
        	p = fazmdc(v[1],v[0]);
        	if(p>v[2]){
        		y = fazmdc(p,v[2]);
        	}else{
        		y = fazmdc(v[2],p);
        	}
        	printf("%i\n",y);
        }else if(n == 4){// pegando 4 numeros para o mdc //
        	p = fazmdc(v[1],v[0]);
        	w = fazmdc(v[3],v[2]);

        	if(p>w){
        		y = fazmdc(p,w);
        	}else{
        		y = fazmdc(w,p);
        	}
        	printf("%i\n",y);
        }

  	}else{
  		printf("Numero invalido");	
  	}

   return 0;
}


int fazmdc(int maior, int menor){
	int resto;
	while(menor !=0){
		resto = maior % menor;
		maior = menor;
		menor = resto;
	}
	return maior;
}
