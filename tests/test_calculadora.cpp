#include "gtest/gtest.h"
#include "../src/Calculadora.h"

TEST(test_calculadora, push) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(PUSH, 2));
    p.agregarInstruccion("M", Instruccion (WRITE, "x"));
    Calculadora c(p);
    c.asignarVariable("x", 1);
    c.ejecutar("M");
    EXPECT_EQ(c.valorVariable("x"), 2);
}
TEST(test_calculadora, add) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(ADD));
    p.agregarInstruccion("M", Instruccion(WRITE, "X"));
    Calculadora c(p);
    c.asignarVariable("X", 2);
    c.ejecutar("M");
    EXPECT_EQ(c.valorVariable("X"), 0);
}
TEST(test_calculadora, mul) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(PUSH, 2));
    p.agregarInstruccion("M", Instruccion(MUL));
    p.agregarInstruccion("M", Instruccion(WRITE, "X"));
    Calculadora c(p);
    c.asignarVariable("X", 5);
    c.ejecutar("M");
    EXPECT_EQ(c.valorVariable("X"), 0);
}
TEST(test_calculadora, mul2) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(PUSH, 2));
    p.agregarInstruccion("M", Instruccion(PUSH, 10));
    p.agregarInstruccion("M", Instruccion(MUL));
    p.agregarInstruccion("M", Instruccion(WRITE, "X"));
    Calculadora c(p);
    c.asignarVariable("X", 5);
    c.ejecutar("M");
    EXPECT_EQ(c.valorVariable("X"), 20);
}
TEST(test_calculadora, sub) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(PUSH, 2));
    p.agregarInstruccion("M", Instruccion(SUB));
    p.agregarInstruccion("M", Instruccion(WRITE, "X"));
    Calculadora c(p);
    c.asignarVariable("X", 5);
    c.ejecutar("M");
    EXPECT_EQ(c.valorVariable("X"), -2);
}
TEST(test_calculadora, sub2) {
    Programa p;
    p.agregarInstruccion("M", Instruccion(PUSH, 28));
    p.agregarInstruccion("M", Instruccion(PUSH, 20));
    p.agregarInstruccion("M", Instruccion(SUB));
    p.agregarInstruccion("M", Instruccion(WRITE, "X"));
    Calculadora c(p);
    c.asignarVariable("X", 5);
    c.ejecutar("M");
    EXPECT_EQ(c.valorVariable("X"), 8);
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
    c.ejecutar("MAIN");
    EXPECT_EQ(c.valorVariable("z"), 17);
}
TEST (test_calculadora, vacio){
    Programa p;
    p.agregarInstruccion("main", Instruccion(READ, "x"));
    p.agregarInstruccion("main", Instruccion(READ, "y"));
    p.agregarInstruccion("main", Instruccion(ADD));
    p.agregarInstruccion("main", Instruccion(MUL));
    p.agregarInstruccion("main", Instruccion(WRITE, "z"));
    p.agregarInstruccion("main", Instruccion(SUB));
    p.agregarInstruccion("main", Instruccion(WRITE, "w"));
    Calculadora c(p);
    c.asignarVariable("x", 12);
    c.ejecutar("main");
    EXPECT_EQ(c.valorVariable("x"), 12);
    c.asignarVariable("y", 5);
    c.ejecutar("main");
    EXPECT_EQ(c.valorVariable("y"), 5);
    c.asignarVariable("z", 4);
    c.ejecutar("main");
    EXPECT_EQ(c.valorVariable("z"), 0);
    c.asignarVariable("w", 5);
    c.ejecutar("main");
    EXPECT_EQ(c.valorVariable("w"), 0);
}
TEST(test_calculadora, jumps){
    Programa p;
    p.agregarInstruccion("main", Instruccion(PUSH, 1));
    p.agregarInstruccion("main", Instruccion(SUB));
    p.agregarInstruccion("main", Instruccion(WRITE, "x"));
    p.agregarInstruccion("m", Instruccion(READ, "x"));
    p.agregarInstruccion("main", Instruccion(JUMP, "m"));
    Calculadora c(p);
    c.asignarVariable("x", 3);
    c.ejecutar("main");
    EXPECT_EQ(c.valorVariable("x"), -1);
}
TEST(test_calculadora, jump2) {
    Programa p;
    p.agregarInstruccion("main", Instruccion(PUSH, 1));
    p.agregarInstruccion("main", Instruccion(READ, "x"));
    p.agregarInstruccion("main", Instruccion(SUB));
    p.agregarInstruccion("main", Instruccion(WRITE, "x"));
    p.agregarInstruccion("m", Instruccion(READ, "x"));
    p.agregarInstruccion("main", Instruccion(JUMPZ, "m"));
    Calculadora c(p);
    c.asignarVariable("x", 1);
    c.ejecutar("main");
    EXPECT_EQ(c.valorVariable("x"), 0);
}
TEST(test_calculadora, varrep){
    Programa p;
    p.agregarInstruccion("main", Instruccion(PUSH, 1));
    Calculadora c(p);
    c.asignarVariable("x", 5);
    c.asignarVariable("x", 2);
    EXPECT_EQ(c.valorVariable("x"), 2);
}