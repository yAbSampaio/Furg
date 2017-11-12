#------------Inicio---------------------#
            #LIBRARY#
from graphics import *
import time
import math

#-------------Functions-------------------------#

def angulo (Ang):
    Rad = math.radians(Ang)
    return Rad

def PosicaoX(AngRad):
    Cos = math.cos(AngRad)
    Pos = 300+(300*Cos)
    return Pos

def PosicaoY(AngRad):
    sen = math.sin(AngRad)
    Pos = 300+(300*sen)
    return Pos

#------------Criation-----------------#

Moldura = GraphWin("Relogio",600,600)
Moldura.setBackground("black")
Moldura.setCoords(0,0,600,600)
Relogio = Circle(Point(300,300),300)
Relogio.setFill("pink")
Relogio.draw(Moldura)
Parafuso = Circle(Point(300,300),5)
Parafuso.setFill("black")
Parafuso.draw(Moldura)
Poi0 = Point(300,300)
PoiS = Point(300,0)
PoiM = Point(268.64146102,598.35656861)
PoiH = Point(600,300)
PonSec = Line(Poi0,PoiS)
PonMin = Line(Poi0,PoiM)
PonHo = Line(Poi0,PoiH)
PonSec.setWidth(1)
PonMin.setWidth(2)
PonHo.setWidth(3)
PonSec.draw(Moldura)
PonMin.draw(Moldura)
PonHo.draw(Moldura)

#------------Numbers-------------------#
Doze = Text(Point(300,580),"XII")
Doze.setTextColor("white")
Doze.setSize(25)
Doze.draw(Moldura)
Onze = Text(Point(140,540),"XI")
Onze.setTextColor("white")
Onze.setSize(25)
Onze.draw(Moldura)
Dez = Text(Point(51,440),"X")
Dez.setTextColor("white")
Dez.setSize(25)
Dez.draw(Moldura)
Nove = Text(Point(20,300),"IX")
Nove.setTextColor("white")
Nove.setSize(25)
Nove.draw(Moldura)
Oito = Text(Point(71,135),"VIII")
Oito.setTextColor("white")
Oito.setSize(25)
Oito.draw(Moldura)
Sete = Text(Point(150,59),"VII")
Sete.setTextColor("white")
Sete.setSize(25)
Sete.draw(Moldura)
Seis = Text(Point(290,30),"VI")
Seis.setTextColor("white")
Seis.setSize(25)
Seis.draw(Moldura)
Cinco =Text(Point(440,50),"V")
Cinco.setTextColor("white")
Cinco.setSize(25)
Cinco.draw(Moldura)
Quatro = Text(Point(540,145),"IV")
Quatro.setTextColor("white")
Quatro.setSize(25)
Quatro.draw(Moldura)
Tres = Text(Point(580,300),"III")
Tres.setTextColor("white")
Tres.setSize(25)
Tres.draw(Moldura)
Dois = Text(Point(540,445),"II")
Dois.setTextColor("white")
Dois.setSize(25)
Dois.draw(Moldura)
Um = Text(Point(445,540),"I")
Um.setTextColor("white")
Um.setSize(25)
Um.draw(Moldura)

#----------contadores----------------------#
CHours = 0
CMin = 0
CSec = 0

#------------Program-------------------#
while (True):

    if (CSec <= 360):
        Secondos = angulo(360-CSec)
        X = PosicaoX(Secondos)
        Y = PosicaoY(Secondos)
        PoiS = Point(X, Y)
        PonSec.undraw()
        PonSec = Line(Poi0,PoiS)
        PonSec.setWidth(2)
        PonSec.draw(Moldura)
        if (CSec == 270):
            CMin += 6
            Minutos = angulo(360-CMin)
            Xm = PosicaoX(Minutos)
            Ym = PosicaoY(Minutos)
            PoiM = Point(Xm, Ym)
            PonMin.undraw()
            PonMin = Line(Poi0, PoiM)
            PonMin.setWidth(3)
            PonMin.draw(Moldura)

        elif (CSec == 360):
            CSec = 0
        elif (CMin == 270):
            CHours += 30
            CMin += 0.000000000001
            Horas = angulo(360-CHours)
            Xh = PosicaoX(Horas)
            Yh = PosicaoY(Horas)
            PoiH = Point(Xh, Yh)
            PonHo.undraw()
            PonHo = Line(Poi0, PoiH)
            PonHo.setWidth(4)
            PonHo.draw(Moldura)

        elif (CMin == 360):
            CMin = 0
        elif (CHours > 330):
            CHours = 0
    	CSec += 6
      time.sleep(1)
