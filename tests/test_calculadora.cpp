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
TEST (test_calculadora, gral2){
    Programa p;
    Calculadora c(p);
    c.asignarVariable("x", 12);
    c.asignarVariable("y", 5);
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(READ, "y"));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "z"));
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("z"), 17);
    p.agregarInstruccion("MAIN", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAIN", Instruccion(MUL));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"), 10);
}
TEST (test_calculadora, vacio){
    Programa p;
    Calculadora c(p);
    c.asignarVariable("x", 12);
    c.asignarVariable("y", 5);
    c.asignarVariable("z", 4);
    c.asignarVariable("w", 5);
    p.agregarInstruccion("main", Instruccion(WRITE, "x"));
    EXPECT_EQ(c.valorVariable("x"), 0);
    p.agregarInstruccion("main", Instruccion(ADD));
    p.agregarInstruccion("main", Instruccion(WRITE, "y"));
    EXPECT_EQ(c.valorVariable("y"), 0);
    p.agregarInstruccion("main", Instruccion(MUL));
    p.agregarInstruccion("main", Instruccion(WRITE, "z"));
    EXPECT_EQ(c.valorVariable("z"), 0);
    p.agregarInstruccion("main", Instruccion(SUB));
    p.agregarInstruccion("main", Instruccion(WRITE, "w"));
    EXPECT_EQ(c.valorVariable("w"), 0);
}
TEST(test_calculadora, jumps){
    Programa p;
    Calculadora c(p);
    c.asignarVariable("x", 3);
    p.agregarInstruccion("main", Instruccion(PUSH, 1));
    p.agregarInstruccion("main", Instruccion(SUB));
    p.agregarInstruccion("main", Instruccion(WRITE, "x"));
    p.agregarInstruccion("main", Instruccion(READ, "x"));
    EXPECT_EQ(c.valorVariable("x"), 2);
    p.agregarInstruccion("main", Instruccion(JUMPZ, 0));
    p.agregarInstruccion("main", Instruccion(JUMP, "main"));
    EXPECT_EQ(c.valorVariable("x"), 0);
}