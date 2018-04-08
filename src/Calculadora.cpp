#include "Calculadora.h"

Calculadora::Calculadora(Programa p){
    Calculadora = ;

}

void Calculadora::asignarVariable(Id idVariable, int valor){
    _id = idVariable;
    _value = valor;

}

void Calculadora::ejecutar(Id idRutina){
    _id = idRutina;

}

int Calculadora::valorVariable(Id idVariable) const{
    return _value;
}