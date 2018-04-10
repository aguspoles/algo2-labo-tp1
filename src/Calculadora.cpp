#include "Calculadora.h"

Calculadora::Calculadora(Programa p){
    _programa = p;

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