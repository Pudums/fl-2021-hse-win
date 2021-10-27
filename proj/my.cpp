#include "my.h"
#include <sstream>

void Arguments::add_name(string &s) {
    args.push_back(any (s));
}

void Arguments::add_a_s(Atom_smal &a_s) {
    args.push_back(any (a_s));
}

Atom_smal::Atom_smal(string s, Arguments *arg) : name(s), args(arg) {
}

Func::Func(string *s, Arg_list *a) : arg_l(a), name(*s) {
}

void Arg_list::add_name(string &s) {
    args.push_back(any(s));
}

void Arg_list::add_func(Func *f) {
    args.push_back(any(f));
}

void Func::add_and_func(Func *f) {
    vec.push_back({false, f});
}

void Func::add_or_func(Func *f) {
    vec.push_back({true, f});
}

Atom::Atom(Atom_smal *a_s_) : a_s(a_s_) {
}

Atom::Atom(Atom_smal *a_s_, Func *f) : a_s(a_s_), func(f) {
}

void Atom_smal::print() {
    cout << "(Name: " << name << ", with this args: ";
    args->print();
    cout << ") ";
}

void Arguments::print() {
    cout << "(";
    for(any a: args) {
        try { 
            auto f = any_cast<Atom_smal> (a);
            f.print();
        } catch(...) {
            string s = any_cast<string>(a);
            cout << "(varible " << s << ")";
        }
    }
    cout << ") ";
}

void Atom::print() {
    a_s->print();
    cout << " with goal = ";
    if(func) func->print();
}

void Func::print() {
    cout << "load: " << name <<", with args: ";
    arg_l->print();
    for(auto i: vec) {
        if(i.first) cout << "and ";
        else cout << "or ";
        i.second->print();
    }
}

void Arg_list::print() {
    for(any a: args) {
        try {
            Func *f = any_cast<Func *>(a);
            if(f)
                f->print();
        } catch(...) {
            string s = any_cast<string>(a);
            cout << "(varible " << s << ") ";
        }
    }
}

void result(vector<Atom *> &atoms_, Func f) {
    for(auto i: atoms_) {
        i->print();
        cout << endl;
    }

    cout << "? ";
    f.print();
    cout << endl;
}
