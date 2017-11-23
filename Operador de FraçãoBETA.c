#include <stdio.h>
#include <stdlib.h>

struct fracao{
    int Nume,Deno;
    
};


struct fracao Mult (struct fracao A, struct fracao B){
	struct fracao Res;
	Res.Nume = (A.Nume)*(B.Nume);
	Res.Deno = (A.Deno)*(B.Deno);
	return Res;
    

}
struct fracao Div (struct fracao A, struct fracao B){
	struct fracao Res;
	Res.Nume = (A.Nume)*(B.Deno);
	Res.Deno = (A.Deno)*(B.Nume);
	return Res;
    

}
struct fracao Soma (struct fracao A, struct fracao B){
	struct fracao Res;
	int ParaA,ParaB;
	Res.Deno = (A.Deno)*(B.Deno);
	ParaA = ((Res.Deno)/A.Deno);
	ParaB = ((Res.Deno)/B.Deno);
	Res.Nume = (ParaA*A.Nume)+(ParaB*B.Nume);
	return Res;
    

}
struct fracao Sub(struct fracao A, struct fracao B){
	struct fracao Res;
	int ParaA,ParaB;
	Res.Deno = (A.Deno)*(B.Deno);
	ParaA = ((Res.Deno)/A.Deno);
	ParaB = ((Res.Deno)/B.Deno);
	Res.Nume = (ParaA*A.Nume)-(ParaB*B.Nume);
	return Res;
    

}
struct fracao Reduz (struct fracao A){
	struct fracao Res;
	if ((A.Nume%2==0)&&(A.Deno%2==0)){
		Res.Nume=A.Nume/2;
		Res.Deno=A.Deno/2;
		Res = Reduz(Res);
	}
	else if ((A.Nume%3==0)&&(A.Deno%3==0)){
		Res.Nume=A.Nume/3;
		Res.Deno=A.Deno/3;
		Res = Reduz(Res);
	}
	else if ((A.Nume%5==0)&&(A.Deno%5==0)){
		Res.Nume=A.Nume/5;
		Res.Deno=A.Deno/5;
		Res = Reduz(Res);
	}
	else if ((A.Nume%7==0)&&(A.Deno%7==0)){
		Res.Nume=A.Nume/7;
		Res.Deno=A.Deno/7;
		Res =  Reduz(Res);
	}
	else if ((A.Nume%11==0)&&(A.Deno%11==0)){
		Res.Nume=A.Nume/11;
		Res.Deno=A.Deno/11;
		Res =  Reduz(Res);
	}
	else if ((A.Nume%13==0)&&(A.Deno%13==0)){
		Res.Nume=A.Nume/13;
		Res.Deno=A.Deno/13;
		Res =  Reduz(Res);
		
	}
	else {
		Res.Nume=A.Nume;
		Res.Deno=A.Deno;
		return Res;
	}
}

int main (){
    int Para;
    struct fracao fracaoA;
    struct fracao fracaoB;
    struct fracao Resultado;
    int L = 0, A, T = 0, K;
    int Cont;
	while (L == 0){
    	printf("Escolha a operacao desejada\n 1 - Mult 2 - Div \n 3- Soma 4 - Subtracao 5 - reduzir\n");
    	scanf("%d",&Para);
    	if(Para == 5){
    		printf("Digite o Numerado e Denominador da 1\n");
   			scanf("%d %d",&fracaoA.Nume,&fracaoA.Deno);		
		}
		else{
			printf("Digite o Numerado e Denominador da 1\n");
   			scanf("%d %d",&fracaoA.Nume,&fracaoA.Deno);
    		printf("Digite o Numerado e Denominador da 2\n");
    		scanf("%d %d",&fracaoB.Nume,&fracaoB.Deno);
		}
		T = 0;
		Cont = 0;
		while(T == 0){
    		if(Para == 1){
            	Resultado = Mult(fracaoA,fracaoB);
            	printf("Resultado\n");
				printf("%d/",Resultado.Nume);
				printf("%d\n",Resultado.Deno);
				Para = 5;
				Cont ++;
			}
    		else if(Para == 2){
   				Resultado = Div(fracaoA,fracaoB);
   				printf("Resultado\n");
   				printf("%d/",Resultado.Nume);
				printf("%d\n",Resultado.Deno);
				Para = 5;
				Cont ++;
			}
    		else if(Para == 3){
        		Resultado = Soma(fracaoA,fracaoB);
        		printf("Resultado\n");
        		printf("%d/",Resultado.Nume);
				printf("%d\n",Resultado.Deno);
				Para = 5;
				Cont ++;
    		}
			else if(Para == 4){
        		Resultado = Sub(fracaoA,fracaoB);
        		printf("Resultado\n");
        		printf("%d/",Resultado.Nume);
				printf("%d\n",Resultado.Deno);
				Para = 5;
				Cont ++;
			}
    		else if(Para == 5){
    			if (Cont == 0){
    				Resultado = Reduz(fracaoA);
    				printf("Forma Reduzida\n");
					if(Resultado.Deno == 1){
						printf("%d\n",Resultado.Nume);
		 			}
					else{
						printf("%d/",Resultado.Nume);
						printf("%d\n",Resultado.Deno);
					}
				}
				else{
					Resultado = Reduz(Resultado);
					printf("Forma Reduzida\n");
					if(Resultado.Deno == 1){
						printf("%d\n",Resultado.Nume);
		 			}
					else{
						printf("%d/",Resultado.Nume);
						printf("%d\n",Resultado.Deno);
					}
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
