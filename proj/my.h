#ifndef MY__H__
#define MY__H__

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <any>

using namespace std;
struct Arguments;

struct Atom_smal {
    string name;
    Arguments *args;

    Atom_smal(string s = "", Arguments *arg = nullptr);
    void print();
};

struct Arguments {
    vector<any> args; // name/Atom_smal
    void add_name(string &s);
    void add_a_s(Atom_smal &a_s);
    void print();
};

struct Func;

struct Arg_list {
    vector<any> args; // name/*FUNC
    void add_name(string &s);
    void add_func(Func *);
    void print();
};

struct Atom;

struct Func {
    vector<pair<bool, Func *>> vec;
    Arg_list *arg_l;
    string name;
    Func(string *s, Arg_list *);

    void add_and_func(Func *);
    void add_or_func(Func *);
    void print();
};

struct Atom {
    Atom_smal *a_s;
    Func *func = nullptr;
    Atom(Atom_smal *);
    Atom(Atom_smal *, Func *);
    void print();
};

void result(vector<Atom *> &atoms, Func f);

#endif
