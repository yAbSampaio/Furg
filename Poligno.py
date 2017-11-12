from graphics import *
import time
import math

#-------------Functions-------------------------#
def Vertices (Vertice):
	V = 360/Vertice
	return V
	
def angulo (Ang):	
	Rad = math.radians(Ang)
	return Rad

def AcharPx (Ang, raio):
	cos = math.cos(Ang)
	X = raio*cos
	return X
def AcharPy (Ang, raio):
	Sen = math.sin(Ang)
	Y = raio*Sen
	return Y 



#------------------------Criation-----------------#
raio = 100
V = 3
cont = 0
A = 0
Lista = []

Moldura = GraphWin("Triangulo",800,800)
Moldura.setBackground(color_rgb(0,255,0))
Moldura.setCoords(-400,-400,400,400)
Circulo = Circle(Point(0,0),raio)
Circulo.setWidth(3)
Circulo.draw(Moldura)
while (cont != V):
	A += 120
	AngR = angulo(A)
	X = AcharPx(AngR, raio)
	Y = AcharPy(AngR, raio)
	Ponto = Point(X,Y)
	Lista.append(Ponto)
	cont += 1
Poligno = Polygon(Lista)
Poligno.setWidth(3)
Poligno.draw(Moldura)
con = 0
#-----------------------------------------#

while (True):
	Acao = Moldura.checkKey()	
	if (Acao == "Up"):
		Poligno.undraw()
		cont = 0
		V += 1
		Lista = []
		Angulo = Vertices(V)
		while (cont != V):
			A += Angulo
			AngR = angulo(A)
			X = AcharPx(AngR, raio)
			Y = AcharPy(AngR, raio)
			Ponto = Point(X,Y)
			Lista.append(Ponto)
			cont += 1
		Poligno = Polygon(Lista)
		Poligno.setWidth(3)
		Poligno.draw(Moldura)
	elif (Acao == "Down"):
		Poligno.undraw()
		cont = 0
		V -= 1
		Lista = []
		Angulo = Vertices(V)
		while (cont != V):
			A += Angulo
			AngR = angulo(A)
			X = AcharPx(AngR, raio)
			Y = AcharPy(AngR, raio)
			Ponto = Point(X,Y)
			Lista.append(Ponto)
			cont += 1
		Poligno = Polygon(Lista)
		Poligno.setWidth(3)
		Poligno.draw(Moldura)
	elif (Acao == "space"):
		Circulo.undraw()
		con += 1
		if con ==2:
			Circulo = Circle(Point(0,0),raio)
			Circulo.setWidth(3)
			Circulo.draw(Moldura)
			con = 0
	elif (Acao == "j"):
		Poligno.undraw()
		cont = 0
		raio = (9+raio)
		Lista = []
		Angulo = Vertices(V)
		while (cont != V):
			A += Angulo
			AngR = angulo(A)
			X = AcharPx(AngR, raio)
			Y = AcharPy(AngR, raio)
			Ponto = Point(X,Y)
			Lista.append(Ponto)
			cont += 1
		Poligno = Polygon(Lista)
		Poligno.setWidth(3)
		Poligno.draw(Moldura)
	elif(Acao == "m"):
		Poligno.undraw()
		cont = 0
		raio = (raio-7)
		Lista = []
		Angulo = Vertices(V)
		while (cont != V):
			A += Angulo
			AngR = angulo(A)
			X = AcharPx(AngR, raio)
			Y = AcharPy(AngR, raio)
			Ponto = Point(X,Y)
			Lista.append(Ponto)
			cont += 1
		Poligno = Polygon(Lista)
		Poligno.setWidth(3)
		Poligno.draw(Moldura)

	elif (Acao == "Right"):
		Poligno.undraw()
		cont = 0
		A += 10
		Lista = []
		Angulo = Vertices(V)
		while (cont != V):
			A += Angulo 
			AngR = angulo(A)
			X = AcharPx(AngR, raio)
			Y = AcharPy(AngR, raio)
			Ponto = Point(X,Y)
			Lista.append(Ponto)
			cont += 1
		Poligno = Polygon(Lista)
		Poligno.setWidth(3)
		Poligno.draw(Moldura)

	elif (Acao == "Left"):
		Poligno.undraw()
		cont = 0
		A -= 10
		Lista = []
		Angulo = Vertices(V)
		while (cont != V):
			A += Angulo 
			AngR = angulo(A)
			X = AcharPx(AngR, raio)
			Y = AcharPy(AngR, raio)
			Ponto = Point(X,Y)
			Lista.append(Ponto)
			cont += 1
		Poligno = Polygon(Lista)
		Poligno.setWidth(3)
    Poligno.draw(Moldura)
