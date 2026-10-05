/* 
copyright EKO Juste-Vie 

05/10/2026 à l'université mundiapolis de  casablanca salle M36
version en .c du fichier outils pour les régulateurs PID 

Enjoy :)

*/

// définittion des paramètres ( modifier les paramètres KP, KI, KD représenté par CoefI, CoefD et CoefP par les valeurs souhaitées)

//variables
float eError, Vmeasured;

//constantes 
float CoefP = 0, CoefI = 0, CoefD =0 ; 
float Integral = 0, Vtarget = 0, PreviousError = 0, Derivative, Consigne; 


// définition des variables. Ici je vais juste définir toutes les fonctions pour qu'ensuite on pourra faciliment les modifier à notre guise

float Detection(); //fonction qui prendra prendra les données capté pour la cyble 
void ActionCorrective(float OurConsigne); // la fonction qui effectuera les correction en fonction de la consigne. 

while(1){
    Vmeasured = Detection();
    eError = Vtarget - Vmeasured; 

    Integral += eError; 
    Derivative = eError - PreviousError;

    Consigne = (
        CoefP * eError + CoefI * Integral + CoefD * Derivative
    );

    ActionCorrective(Consigne);
    PreviousError = eError;

}