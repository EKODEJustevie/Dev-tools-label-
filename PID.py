"""
copyright EKO Juste-Vie 

05/10/2026 à l'université mundiapolis de  casablanca salle M36
version en .c du fichier outils pour les régulateurs PID 
Enjoy :) 

"""

#définition des coeficients KP, KI, KD représenté respectivement par CoefP, CoefI et CoefD
CoefP =0
CoefI =0
CoefD =0

#définition des variables

PreviousError = 0
eError =0
Integral = 0
Derivative = None
Target = None
XPosition = None
Consigne = None


# définition des fonctions qui capturerons les données et qui exécuterons les consignes. 
def CapteurData():
    #nothing for now 
    pass

def ActionConsigne():
    pass

while(1):
    XPosition = CapteurData()

    eError = Target - XPosition

    Integral += eError
    Derivative = eError - PreviousError 

    Consigne = ( CoefD * Derivative + CoefI * Integral + CoefP * eError)
    ActionConsigne(Consigne)

    PreviousError = eError




