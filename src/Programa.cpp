#include "Programa.h"

Programa::Programa(){}

void Programa::agregarInstruccion(Id idRutina, Instruccion instruccion){
    if(_rutinas.count(idRutina) == 0){
        vector<Instruccion> is;
        is.push_back(instruccion);
        _rutinas.insert(pair<Id, vector<Instruccion>>(idRutina, is));
    }
    else{
        _rutinas[idRutina].push_back(instruccion);
    }
}

bool Programa::esRutinaExistente(Id idRutina) const{
    if(_rutinas.find(idRutina) == _rutinas.end())
       return false;
    return true;
}

int Programa::longitud(Id idRutina) const {
    //uso un iterador const porque el operador de acceso [] no se puede usar en funcion const
    //e.g _rutinas[idRutina] no se puede hacer en esta funcion
    map<Id, vector<Instruccion>>::const_iterator ubicacion = _rutinas.find(idRutina);
    int longitud = ubicacion->second.size();
    return longitud;
}

Instruccion Programa::instruccion(Id idRutina, int i) const{
    map<Id, vector<Instruccion>>::const_iterator ubicacion = _rutinas.find(idRutina);
    return ubicacion->second[i];
}