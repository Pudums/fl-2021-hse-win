#include "my.h"
#include <sstream>

namespace {

int color = 30;
int bg = 41;

vector<Atom *> atoms;

void set_next() {
    cout << "\033[" << color << ";" << bg << ";1" << 'm';
    if (color == 37) {
        color = 30;
        bg++;
    } else {
        if(10 + (++color) == bg) {
            color++;
        }
    }
}

void set_prev() {
    cout << "\033[" << color << ";" << bg << ";1" << 'm';
    if (color == 30) {
        color = 37;
        bg--;
    } else {
        if(10 + (--color) == bg) {
            color--;
        }
    }
}
}

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

Func *check(Func f, Atom *a) {
    if(f.name != a->a_s->name) return nullptr;
    Arg_list *args = new Arg_list();
    for(int i = 0; i < a->func->arg_l->args.size();i++) {
        any an = a->func->arg_l->args[i];
        Func *f1;
        string s;
        bool flag;
        try {
            f1 = any_cast<Func *> (an);
            flag = true;
        } catch (...) {
            flag = false;
        }
        if(!flag) {
            s = any_cast<string> (an);
            continue;
        }
    }
    return new Func(new string("s"), NULL);
}

void evaluate(Func f) {
    for(Atom *a: atoms) {
        if(check(f, a)) {
            set_next();
            cout << "Yes\n";
        }
    }
}

string get_str(any a) {
    try{
        return any_cast<string> (a);
    }catch(...) {
        cerr << "CAST ERROR\n";
        return "";
    }
}

Func *get_func(any a) {
    try {
        return any_cast<Func *> (a);
    }catch (...) {
        return nullptr;
    }
}

Func *Func::complete(Atom *a) {
    if(name != a->a_s->name || a->a_s->args->args.size() != arg_l->args.size()) return nullptr;

    map<any, any> mp;
    for(int i = 0;i<a->a_s->args->args.size();i++){
        any an = a->a_s->args->args[i];
        any myan = arg_l->args[i];
        if(Func *f = get_func(an)) {
        } else {
            string nm = get_str(an);
            mp[any(nm)] = myan;
        }
    }

    Arg_list *args = new Arg_list();
    for(int i = 0; i < a->func->arg_l->args.size();i++) {
        any an = a->func->arg_l->args[i];
        string s;
        if(Func *f = get_func(an)) {
        } else {
            string s = get_str(an);
        }
    }
    return new Func(new string("s"), NULL);
}

void result(vector<Atom *> &atoms_, Func f) {
    cout << "Start:\n";
    atoms = atoms_;
    evaluate(f);
}
