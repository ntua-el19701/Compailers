#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "../symbol.hpp"


using namespace std;



class AST {
 public:
  virtual void printAST(std::ostream &out) const = 0;
  virtual void sem() {}
    void type_check(Typos t) {
    sem();
    if (type != t) {
      std::cerr << "Type mismatch" << std::endl;
      exit(1);
    }
  } 
public:
  Typos type;
};

inline std::ostream &operator<<(std::ostream &out, const AST &ast) {
  ast.printAST(out);
  return out;
}

class Expr : public AST {};

class Stmt : public AST {};



class Local_def;


class Const_char : public Expr {
public:
  Const_char(char *n): str(n) {}
  virtual void printAST(std::ostream &out) const override;
  virtual void sem() override;
  int eval() const  {
    return *str;
  }
 private:
  char *str;
};

class StringConst : public Expr {
public:
  StringConst(char *n): str(n) {}
  virtual void printAST(std::ostream &out) const override;
  virtual void sem() override;
  int eval() const  {
    return *str;
  }
 private:
  char *str;
};

class Id : public Expr {
public: 
    Id(char *s) : name(s) {}
    virtual void printAST(std::ostream &out) const override;
    virtual void sem() override;
    char* getName(){
        return name;
    }
protected:
    char *name;
};

class IntConst : public Expr {
 public:
  IntConst(int n): num(n) {}
  virtual void printAST(std::ostream &out) const override;
  virtual void sem() override;
  int eval() const  {
    return num;
  }
 private:
  int num;
};

class Cond : public Stmt {
public:
    Cond(Cond *c1, const char *o, Cond *c2):  op(o), cond1(c1), cond2(c2){}
    virtual void printAST(std::ostream &out) const override;
private:
    const char *op;
    Cond *cond1;
    Cond *cond2;
};

class Comma_expr_gen : public Stmt{
public:
    Comma_expr_gen(Expr *e, Comma_expr_gen *c) : expr(e), comma_expr_gen(c){}
    void printAST(std::ostream &out) const override;
private:
    Expr *expr;
    Comma_expr_gen *comma_expr_gen;
};


class Func_call_stmt : public  Stmt{
public:
    Func_call_stmt(Id i, Expr *e = nullptr, Comma_expr_gen *c = nullptr) : id(i), expr(e), comma_expr_gen(c){}
    virtual void printAST(std::ostream &out) const override;
private:
    Id id;
    Expr *expr;
    Comma_expr_gen *comma_expr_gen;
};

class Func_call_expr : public  Expr{
public:
    Func_call_expr(Id i, Expr *e = nullptr, Comma_expr_gen *c = nullptr) : id(i), expr(e), comma_expr_gen(c){}
    virtual void printAST(std::ostream &out) const override;
private:
    Id id;
    Expr *expr;
    Comma_expr_gen *comma_expr_gen;
};

class Block : public Stmt {
public:
    Block() : stmt_list(), size(0) {}
   /* ~Block() {
    for (Stmt *s : stmt_list) delete s;
  }*/
    void append_stmt(Stmt *s) { stmt_list.push_back(s); size = size+1; }
    virtual void printAST(std::ostream &out) const override;
    virtual void sem() override;
protected:
    std::vector<Stmt *> stmt_list;
    int size;
};

class Ret_type : public AST {
public:
    Ret_type(Typos t): typos(t){}
    virtual void printAST(std::ostream &out) const override;
    virtual void sem() override;
    Typos getTypos(){
        return typos;
    }
private:
    Typos typos;
};

class Comma_id_gen : public AST{
public:
    Comma_id_gen(Id i, Comma_id_gen *c) : name(i), comma_id_gen(c) {}
    virtual void printAST(std::ostream &out) const override;
private:
    Id name;
    Comma_id_gen *comma_id_gen;    
};

class Type_gen : public AST{
public:
    Type_gen(int a, Type_gen *tg = nullptr) : size(a), type_gen(tg){}
    virtual void printAST(std::ostream &out) const override;
private:
    int size;
    Type_gen *type_gen;

};

class Fpar_type : public AST {
public:
    Fpar_type(Typos t, Type_gen *tg, int i) : typos(t), type_gen(tg), array(i){}
    virtual void printAST(std::ostream &out) const override;
private:
    Typos typos;
    Type_gen *type_gen;
    int array;

};

class Fpar_def : public AST {
public:
    Fpar_def(bool flag, Id i, Comma_id_gen *c , Fpar_type *fpt ) : ref(flag), name(i), comma_id_gen(c), fpar_type(fpt) {}
    virtual void printAST(std::ostream &out) const override;
private:
    bool ref;
    Id name;
    Comma_id_gen *comma_id_gen;
    Fpar_type *fpar_type;
};

class Fpar_def_gen : public AST {
public:
     Fpar_def_gen(Fpar_def *fp, Fpar_def_gen *fpg) : fpar_def(fp), fpar_def_gen(fpg) {}
    virtual void printAST(std::ostream &out) const override;
private :
    Fpar_def *fpar_def;
    Fpar_def_gen *fpar_def_gen;     
};

class Header : public  AST {
public: 
    Header(Id i, Fpar_def *fp  , Fpar_def_gen *fpg  , Ret_type *r  ) : nam(i), fpar_def(fp), fpar_def_gen(fpg), ret_type(r) {}
    virtual void printAST(std::ostream &out) const override;
    virtual void sem() override;
private:
    Id nam;
    Fpar_def *fpar_def;
    Fpar_def_gen *fpar_def_gen;
    Ret_type *ret_type;
};

class Func_decl : public  AST {
public:
    Func_decl(Header *h) : header(h){}
    virtual void printAST(std::ostream &out) const override;
    Header *header;
};

class Local_def_gen : public AST {
public:
    Local_def_gen( Local_def *ld, Local_def_gen *ldg) : local_def(ld), local_def_gen(ldg){ }
    virtual void printAST(std::ostream &out) const override;
private: 
    Local_def *local_def;   
    Local_def_gen *local_def_gen; 
};

class Func_def : public AST {
public:
    Func_def(Header *h, Local_def_gen *ldg , Block *blk ) : header(h), local_def_gen(ldg), block(blk) {}
    virtual void printAST(std::ostream &out) const override;
    virtual void sem() override;
private:
    Header *header;
    Local_def_gen *local_def_gen;
    Block *block;    
};

class Type : public AST {
public:
    Type(Typos t, Type_gen *tg) : typos(t),  type_gen(tg){}
    virtual void printAST(std::ostream &out) const override;
private:
    Typos typos;
    Type_gen *type_gen;
};

class Var_def : public AST {
public:
    Var_def(Id i, Comma_id_gen *c, Type *t) : id(i), comma_id_gen(c), type(t){}
    virtual void printAST(std::ostream &out) const override;
   // virtual void sem() override;
private:
    Id id;
    Comma_id_gen *comma_id_gen;
    Type *type;
    
};

class Local_def : public AST {
public:
    Local_def(Func_def *fdf, Func_decl *fdc, Var_def *vd) : func_def(fdf), func_decl(fdc), var_def(vd){}
    virtual void printAST(std::ostream &out) const override;
private:
    Func_def *func_def;
    Func_decl *func_decl; 
    Var_def *var_def;  
};

class L_value : public  Expr {
public:
    L_value(L_value *l, Expr *e, Id i, StringConst s,int x) : l_value(l), expr(e), id(i), const_string(s),flag(x){}
    virtual void printAST(std::ostream &out) const override ;
private:
    L_value *l_value;
    Expr *expr;
    Id id;
    StringConst const_string;
    int flag;
};


class Assign : public Stmt {
public:
    Assign(L_value *lv, Expr *e) : l_value(lv), expr(e){}
    virtual void printAST(std::ostream &out) const override;
private:
    L_value *l_value;
    Expr *expr;

};

class If : public Stmt {
public:
    If(Cond *c, Stmt *s1, Stmt *s2 = nullptr) : condition(c), stmt1(s1), stmt2(s2){}
    virtual void printAST(std::ostream &out) const override ;
private: 
    Cond *condition;
    Stmt *stmt1;
    Stmt *stmt2;

};

class While : public Stmt {
public:
    While(Cond *c, Stmt *s) :  condition(c), stmt(s){}
    virtual void printAST(std::ostream &out) const override;
private:
    Cond *condition;
    Stmt *stmt;
};

class Return : public Stmt {
public: 
    Return(Expr *e = nullptr) : expr(e) {}
    virtual void printAST(std::ostream &out) const override;
private:
    Expr *expr;
};

class BinOp : public Expr{
public:
    BinOp(Expr *e1, const char *o, Expr *e2) : expr1(e1), op(o), expr2(e2) {}
    void printAST(std::ostream &out) const override ;
private:
    Expr *expr1;
    const char *op;
    Expr *expr2;
}; 

class Compare : public Cond{
public:
    Compare(Expr *e1, const char *o, Expr *e2) :  Cond(nullptr, o, nullptr),  expr1(e1), op(o), expr2(e2) {}
    void printAST(std::ostream &out) const override ;
    virtual void sem() override ; 
private:
    Expr *expr1;
    const char *op;
    Expr *expr2;
};

class UnOp : public  Expr {
public : 
    UnOp(char o, Expr *e) : op(o), expr(e) {}
    void printAST(std::ostream &out) const override;
private:
    char op;
    Expr *expr;
};

class Not_cond : public Stmt {
public: 
    Not_cond(Cond *c1) : cond(c1) {}
    void printAST(std::ostream &out) const override;
private:
    Cond *cond;
};

class Write_Integer : public Stmt {
public:
    Write_Integer(Id d, int i) : id(d), n(i){}
    void printAST(std::ostream &out) const override;
   
private:
    Id id;
    int n;
   
};

class Write_Char : public Stmt {
public:
    Write_Char(Id d) : id(d){}
    void printAST(std::ostream &out) const override;
private:
    Id id;

};

class Write_String : public Stmt {
public:
    Write_String(Id d,char *i,int m) : id(d), x(i), flag(m) {}
    void printAST(std::ostream &out) const override;
   
private:
    Id id;
    char *x;
    int flag;
    
};
#endif