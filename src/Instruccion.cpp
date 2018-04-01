#include "Instruccion.h"

Instruccion::Instruccion(Operacion op, int valor){
    _op = op;
    _value = valor;
}

Instruccion::Instruccion(Operacion op){
    _op = op;
}

Instruccion::Instruccion(Operacion op, Id id){
    _op = op;
    _id = id;
}

Operacion Instruccion::operacion() const{
    return _op;
}

int Instruccion::valor() const{
    return _value;
}

Id Instruccion::nombre() const{
    return _id;
}