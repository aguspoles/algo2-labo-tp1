//
// Created by tomyo_000 on 4/4/2018.
//
#include "gtest/gtest.h"

#include "../src/Calculadora.h"

/*Acordate que hay que agregar instrucciones antes de crear la calculadora con el programa,
porque que el programa pasa como copia como parametro en el constructor de la calculadora
*/
TEST (test_calculadora, idrutina){

}

TEST(test_calculadora, push) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(PUSH, 2));
    Calculadora c(p);
    c.ejecutar("M");
}

TEST(test_calculadora, add) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(ADD));
    Calculadora c(p);
    c.ejecutar("M");
}
TEST(test_calculadora, read){
    Programa p;
    p.agregarInstruccion("M", Instruccion(READ, "x"));
    p.agregarInstruccion("M", Instruccion(WRITE, "y"));
    Calculadora c(p);
    c.asignarVariable("x", 38);
    c.asignarVariable("y", 2);
    c.ejecutar("M");
    EXPECT_EQ(c.valorVariable("y"), 38);
}

TEST(test_calculadora, gral){
    Programa p;
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(PUSH, 2));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "x"));
    Calculadora c(p);
    c.asignarVariable("x", 38);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"), 40);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("x"), 42);
}
TEST (test_calculadora, gral2){
    Programa p;
    p.agregarInstruccion("MAIN", Instruccion(READ, "x"));
    p.agregarInstruccion("MAIN", Instruccion(READ, "y"));
    p.agregarInstruccion("MAIN", Instruccion(ADD));
    p.agregarInstruccion("MAIN", Instruccion(WRITE, "z"));
    Calculadora c(p);
    c.asignarVariable("x", 12);
    c.asignarVariable("y", 5);
    //en ningun momento habias creado z, por con WRIE no lo encontraba
    c.asignarVariable("z", 0);
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("z"), 17);
}
/*TEST (test_calculadora, vacio){
    Programa p;
    p.agregarInstruccion("main", Instruccion(WRITE, "x"));
    Calculadora c(p);
    c.asignarVariable("x", 12);
    c.asignarVariable("y", 5);
    c.asignarVariable("z", 4);
    c.asignarVariable("w", 5);
    c.ejecutar("main");
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
}*/
/*TEST(test_calculadora, jumps){
    Programa p;
    p.agregarInstruccion("main", Instruccion(PUSH, 1));
    p.agregarInstruccion("main", Instruccion(SUB));
    p.agregarInstruccion("main", Instruccion(WRITE, "x"));
    p.agregarInstruccion("main", Instruccion(READ, "x"));
    p.agregarInstruccion("main", Instruccion(JUMPZ, 0));
    p.agregarInstruccion("main", Instruccion(JUMP, "main"));
    Calculadora c(p);
    c.asignarVariable("x", 3);
    EXPECT_EQ(c.valorVariable("x"), 2);
    EXPECT_EQ(c.valorVariable("x"), 0);
}*/