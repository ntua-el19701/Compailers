#ifndef __SYMBOL_HPP__
#define __SYMBOL_HPP__

#include <map>
#include <string>
#include <vector>

void yyerror(const char *msg);

enum Typos { TYPE_int, TYPE_char, TYPE_nothing,  TYPE_bool, TYPE_const_char, TYPE_const_string};
enum EntryType { ENTRY_CONSTANT, ENTRY_FUNCTION, ENTRY_PARAMETER, ENTRY_VARIABLE };


struct SymbolEntry {
Typos type;
EntryType entryType;
SymbolEntry() {}
SymbolEntry(Typos t, EntryType et) : type(t), entryType(et) {}
};


class Scope {
public:
    Scope() {}
    void insert(std::string s, Typos t, EntryType et){
        if (locals.find(s) != locals.end()){ yyerror("Duplicate variable"); } 
        std::cout<<"insert in scope "<<std::endl;
        locals[s] = SymbolEntry(t, et);
    }
    SymbolEntry *lookup(std::string s){
        if (locals.find(s) == locals.end()) return nullptr;
        return &locals[s];
    }
    void reduceSize() {
        size=size-1;
    }

    void incrSize() {
        size=size+1;
    }

    int getSize(){
        return size;
    }

    void printScope(){
       for(const auto &elem : locals){
          
           std::cout<<elem.first << " " << elem.second.type << std::endl;
       }
    }
   
    

private:
    std::map<std::string, SymbolEntry> locals;
    int size;
};

class SymbolTable{
public:
    SymbolEntry *lookup(std::string s) {
        for (auto i = scopes.rbegin(); i != scopes.rend(); ++i) {
            SymbolEntry *e = i->lookup(s);
             if (e != nullptr) return e;
        }
         yyerror("Variable not found");
         return nullptr;
    }

    void insert(std::string s, Typos t, EntryType et) {
        scopes.back().insert(s , t, et);
        //std::cout<<s<<" insert"<<std::endl;
    }

    void openScope () {
        std::cout<<"opened "<<std::endl;
        size++;
        scopes.push_back(Scope());
        //std::cout<<"size of scope: "  << size;

    }

    void closeScope () {
        //std::cout<<"closed "<<std::endl;
        size--;
        scopes.pop_back();
      //  std::cout<<"size of scope: " << size;
    }

    void printST (){
          std::cout<<"Printing ST with size " << size;
          for (auto i = scopes.rbegin(); i != scopes.rend(); i++) {
          // std::cout<<"scopee"<<std::endl;

           
           i->printScope();
           std::cout<<std::endl;
        }
        
    }
private:
    std::vector<Scope> scopes;
    int size=0;

};


extern SymbolTable st;

#endif