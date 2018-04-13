#include "Calculadora.h"
#include <iostream>

using namespace std;

Calculadora::Calculadora(Programa p) : _programa(p)
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

    for (int i = 0; i < _programa.longitud(idRutina); i++)
    {
        Instruccion instruccion = _programa.instruccion(idRutina, i);
        ejecutarInstruccion(instruccion.operacion(), instruccion.nombre(), instruccion.valor());
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

void Calculadora::ejecutarInstruccion(Operacion Op, Id Nombre, int Valor)
{
    switch (Op)
    {
    case PUSH:
        _pila.push(Valor);
        break;

    case ADD:
    {
        if (_pila.empty())
            _pila.push(0);
        else
        {
            int a = _pila.top();
            _pila.pop();
            if (_pila.empty())
                _pila.push(0);
            int b = _pila.top();
            _pila.pop();
            _pila.push(a + b);
        }
        break;
    }

    case SUB:
    {
        if (_pila.empty())
            _pila.push(0);
        else
        {
            int a = _pila.top();
            _pila.pop();
            if (_pila.empty())
                _pila.push(0);
            int b = _pila.top();
            _pila.pop();
            _pila.push(a - b);
        }
        break;
    }

    case MUL:
    {
        if (_pila.empty())
            _pila.push(0);
        else
        {
            int a = _pila.top();
            _pila.pop();
            if (_pila.empty())
                _pila.push(1);
            int b = _pila.top();
            _pila.pop();
            _pila.push(a * b);
        }
        break;
    }

    case WRITE:
    {
        int valor = _pila.top();
        _pila.pop();
        for (int i = 0; i < _memoria.size(); i++)
        {
            if (_memoria[i].first == Nombre)
                _memoria[i].second = valor;
        }
        break;
    }

    case READ:
    {
        for (int i = 0; i < _memoria.size(); i++)
        {
            if (_memoria[i].first == Nombre)
                _pila.push(_memoria[i].second);
        }
        break;
    }

    case JUMP:
    {
        Id rutina = _rutinaActual;
        ejecutar(Nombre);
        _rutinaActual = rutina;
        break;
    }

    case JUMPZ:
    {
        if (_pila.empty() || _pila.top() == 0)
        {
            Id rutina = _rutinaActual;
            ejecutar(Nombre);
            _rutinaActual = rutina;
        }
        break;
    }
    default:
        break;
    }
}