#enconding=utf-8
Cidades = open("cidades.txt", "r")
Linha = Cidades.readlines()
lista = []
for y in Linha :
	x=y.split("\n")[0]
	num = len(x)
	if num != 1 and num != 0 :
		x=x.replace("20px","")
		x=x.replace("\n","").strip()
print x
#-------------------------------------------------
#encoding=utf-8

x=int(raw_input("Digite o valor em que você deseja clarear a imagem."))

arq1=open("small_einstein.pgm","r")
entrada=arq1.read()

arq1.close()

listas=entrada.split("\n")

saida="P2\n256 256\n255\n"

for i in listas[3:]:
    ln=i.split(" ")
    for j in ln:
        if j != (""):
            j=int(j)
            j=j+x
            j=str(j)
            saida=saida+j+" "
    saida=saida+"\n"

arq2=open("clone.pgm", "w")
arq2.write(saida)
arq2.close()
#-------------------------------------------------------------
