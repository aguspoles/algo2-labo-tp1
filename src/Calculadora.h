#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__
#include "Programa.h"
#include <stack>

class Calculadora
{
  public:
    //Calcu con programa cargado
    Calculadora(Programa p);

    //Establece el valor de la variable indicada en la memoria de la calculadora
    void asignarVariable(Id idVariable, int valor);

    //Ejecuta el programa hasta alcanzar alguna condicion de finalizacion. La ejecucion comienza en la primera
    //instruccion de la rutina especificada. Si la rutina no es existente, la ejecucion finaliza de manera inmediata.
    void ejecutar(Id idRutina);

    //Devuelve que tiene la variable en la memoria.
    //Si nunca se le dio valor a dicha variable, se asume que es 0;
    int valorVariable(Id idVariable) const;

  private:
    Programa _programa;
    vector<std::pair<Id, int>> _memoria;
    stack<int> _pila;
    Id _rutinaActual;
    int _indiceDeInstruccionActual;
};

#endif