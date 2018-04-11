#include "Calculadora.h"
#include <iostream>

using namespace std;

Calculadora::Calculadora(Programa p) : _programa(p), _indiceDeInstruccionActual(0)
{
}

void Calculadora::asignarVariable(Id idVariable, int valor)
{
    bool existe = false;
    for (int i = 0; i < _memoria.size(); i++)
    {
        if (_memoria[i].first == idVariable)
        {
            _memoria[i].second = valor;
            existe = true;
        }
    }
    if (!existe)
    {
        std::pair<Id, int> variable(idVariable, valor);
        _memoria.push_back(variable);
    }
}

void Calculadora::ejecutar(Id idRutina)
{
    if (!_programa.esRutinaExistente(idRutina))
        return;

    _rutinaActual = idRutina;
    _indiceDeInstruccionActual = 0;

    for (int i = 0; i < _programa.longitud(idRutina); i++)
    {
        Instruccion instruccion = _programa.instruccion(idRutina, i);
        switch (instruccion.operacion())
        {
        case PUSH:
            _pila.push(instruccion.valor()) ;
            _indiceDeInstruccionActual++;
            cout << "push" << endl;
            break;


        case ADD: {
            cout << "add" << endl;
            if (_pila.empty())
                _pila.push(0);
            else {
                int a = _pila.top();
                _pila.pop();
                if (_pila.empty())
                    _pila.push(0);
                int b = _pila.top();
                _pila.pop();
                _pila.push(a + b);
            }
            _indiceDeInstruccionActual++;
            break;
        }

        case SUB: {
            if (_pila.empty())
                _pila.push(0);
            else {
                int a = _pila.top();
                _pila.pop();
                if (_pila.empty())
                    _pila.push(0);
                int b = _pila.top();
                _pila.pop();
                _pila.push(a - b);
            }
            _indiceDeInstruccionActual++;
            break;
        }

        case MUL: {
            if (_pila.empty())
                _pila.push(0);
            else {
                int a = _pila.top();
                _pila.pop();
                if (_pila.empty())
                    _pila.push(1);
                int b = _pila.top();
                _pila.pop();
                _pila.push(a * b);
            }
            _indiceDeInstruccionActual++;
            break;
        }

        case WRITE: {
            int valor = _pila.top();
            _pila.pop();
            for (int i = 0; i < _memoria.size(); i++) {
                if (_memoria[i].first == instruccion.nombre())
                    _memoria[i].second = valor;
            }
            _indiceDeInstruccionActual++;
            break;
        }

        case READ: {
            for (int i = 0; i < _memoria.size(); i++) {
                if (_memoria[i].first == instruccion.nombre())
                    _pila.push(_memoria[i].second);
            }
            _indiceDeInstruccionActual++;
            break;
        }

        case JUMP: {
            Id rutina = _rutinaActual;
            int indice = _indiceDeInstruccionActual;
            ejecutar(instruccion.nombre());
            _rutinaActual = rutina;
            _indiceDeInstruccionActual = indice;
            _indiceDeInstruccionActual++;
            break;
        }
            
        case JUMPZ: {
            if (_pila.empty() || _pila.top() == 0) {
                Id rutina = _rutinaActual;
                int indice = _indiceDeInstruccionActual;
                ejecutar(instruccion.nombre());
                _rutinaActual = rutina;
                _indiceDeInstruccionActual = indice;
            }
            _indiceDeInstruccionActual++;
            break;
        }
        default:
            break;
        }
    }
}

int Calculadora::valorVariable(Id idVariable) const
{
    for (int i = 0; i < _memoria.size(); i++)
    {
        if (_memoria[i].first == idVariable)
            return _memoria[i].second;
    }
    return 0;
}