//
// Created by tomyo_000 on 4/4/2018.
//
#include "gtest/gtest.h"

#include "../src/Calculadora.h"


TEST(test_calculadora, gral){
    Programa p;
    Calculadora c(p);
    c.asignarVariable("x", 38);
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"), 40);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"), 42);
}
//TEST (test_calculadora, ){
