#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Info{
	int Code;
	double Price;
	char Description[255];

};


struct Register{
	char Product[255];
	struct Info Specification;
};
	
int main(){
	struct Register List[6];
	int CodeParameter, Amount,Cont;
	double  Value,Money;
	char Sales[300][300];
	for(int t=0;t<5;t++){
		printf("Digite o nome do produto\n");
		scanf("%[a-z A-Z]s",List[t].Product);
		printf("Digite o código do produto\n");
		scanf("%d",&List[t].Specification.Code);
		printf("Digite o preco do produto\n");
		scanf("%lf",&List[t].Specification.Price);
		printf("Digite uma descrição\n");
		scanf("%[a-z A-Z]s",List[t].Specification.Description);		
	}
	while(1){
		printf("Digite o código para realização da venda\n");
		scanf("%d",&CodeParameter);
		printf("Digite a Quantidade\n");
		scanf("%d",&Amount);
		int j=0;
		while (j<5){
			if (CodeParameter == List[j].Specification.Code){
				Value = Amount*List[j].Specification.Price;
				strcpy(Sales[Cont],List[j].Product);
				Money = Money+Value;
				printf("O item a ser vendida : %s\n",List[j].Product);
				printf("Código : %d\n",List[j].Specification.Code);
				printf("Preço unitario : %lf R$\n",List[j].Specification.Price);
				printf("Descrição :%s\n",List[j].Specification.Description);
				printf("Relatorio da venda\nSaldo : %lf R$\n",Value);
				printf("Saldo Atual : %lf\n",Money);
				printf("Itens Vendidos :\n");
				for(int i = 0; i<(Cont+1); i++){
					printf("%s, ",Sales[i]);
				}
				printf("\n");
				j = 15;			
			}	
			j++;	
		}
		Value = 0;
		Cont ++;
	}	





	return 0;
}


