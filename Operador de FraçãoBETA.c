#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct fracao{
    int Nume,Deno;
    
};


struct fracao Mult (struct fracao A, struct fracao B,struct fracao *Res){
	Res->Nume = (A.Nume)*(B.Nume);
	Res->Deno = (A.Deno)*(B.Deno);

    

}
struct fracao Div (struct fracao A, struct fracao B,struct fracao *Res){
	Res->Nume = (A.Nume)*(B.Deno);
	Res->Deno = (A.Deno)*(B.Nume);
    

}
struct fracao Soma (struct fracao A, struct fracao B,struct fracao *Res){
	int ParaA,ParaB;
	Res->Deno = (A.Deno)*(B.Deno);
	ParaA = ((Res->Deno)/A.Deno);
	ParaB = ((Res->Deno)/B.Deno);
	Res->Nume = (ParaA*A.Nume)+(ParaB*B.Nume);
    

}
struct fracao Sub(struct fracao A, struct fracao B,struct fracao *Res){
	int ParaA,ParaB;
	Res->Deno = (A.Deno)*(B.Deno);
	ParaA = ((Res->Deno)/A.Deno);
	ParaB = ((Res->Deno)/B.Deno);
	Res->Nume = (ParaA*A.Nume)-(ParaB*B.Nume);
    
}
struct fracao Expo(int A,struct fracao *Res){
	Res->Deno = pow(Res->Deno,A);
	Res->Nume = pow(Res->Nume,A);
    
}
struct fracao Reduz (struct fracao *Res){
	int Primos[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int i=0;
	while(i<25){
		if ((Res->Nume%Primos[i]==0)&&(Res->Deno%Primos[i]==0)){
		Res->Nume=Res->Nume/Primos[i];
		Res->Deno=Res->Deno/Primos[i];
		Reduz(Res);
		}
	i++;
	}

	Res->Nume=Res->Nume;
	Res->Deno=Res->Deno;
}

int main (){
    int Para;
    struct fracao fracaoA;
    struct fracao fracaoB;
    struct fracao Resultado;
    int L = 0, T = 0, K;
    int Expoe;
	while (L == 0){
    	printf("Escolha a operacao desejada\n 1- Mult 2- Div \n 3- Soma 4- Subtracao\n 5- reduzir 6- Expoente \n");
    	scanf("%d",&Para);
    	if((Para == 5)||(Para == 6)){
    		printf("Digite o Numerado e Denominador da 1\n");
   			scanf("%d %d",&fracaoA.Nume,&fracaoA.Deno);
			   if(Para == 6){
			   	printf("Digite o expoente\n");
   				scanf("%d",&Expoe);
			   }		
		}
		else{
			printf("Digite o Numerado e Denominador da 1\n");
   			scanf("%d %d",&fracaoA.Nume,&fracaoA.Deno);
    		printf("Digite o Numerado e Denominador da 2\n");
    		scanf("%d %d",&fracaoB.Nume,&fracaoB.Deno);
			}
		T = 0;
		while(T == 0){
    		if(Para == 1){
            	Mult(fracaoA,fracaoB,&fracaoA);
            	printf("Resultado\n");
				printf("%d/",fracaoA.Nume);
				printf("%d\n",fracaoA.Deno);
				Para = 5;
			}
    		else if(Para == 2){
   				Div(fracaoA,fracaoB,&fracaoA);
   				printf("Resultado\n");
   				printf("%d/",fracaoA.Nume);
				printf("%d\n",fracaoA.Deno);
				Para = 5;
			}
    		else if(Para == 3){
        		Soma(fracaoA,fracaoB,&fracaoA);
        		printf("Resultado\n");
        		printf("%d/",fracaoA.Nume);
				printf("%d\n",fracaoA.Deno);
				Para = 5;
    		}
			else if(Para == 4){
        		Sub(fracaoA,fracaoB,&fracaoA);
        		printf("Resultado\n");
        		printf("%d/",fracaoA.Nume);
				printf("%d\n",fracaoA.Deno);
				Para = 5;
			}
			else if(Para == 6){
        		Expo(Expoe,&fracaoA);
        		printf("Resultado\n");
        		printf("%d/",fracaoA.Nume);
				printf("%d\n",fracaoA.Deno);
				Para = 5;
		
			}
    		else if(Para == 5){
    				Reduz(&fracaoA);
    				printf("Forma Reduzida\n");
				if(fracaoA.Deno == 1){
					printf("%d\n",fracaoA.Nume);
		 		}
				else{
					printf("%d/",fracaoA.Nume);
					printf("%d\n",fracaoA.Deno);
				}
				T = 1;
			}
		}
		printf("1 p/reiniciar 2 p/parar\n");
		scanf("%d",&K);
		if(K == 2){
			L = 1;
		}
		else{
			L = 0;
		}
 	}
	return 0;
}
