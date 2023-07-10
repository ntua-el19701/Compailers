#include "ast.hpp"

/*
    CONST_CHAR
*/
void Const_char::printAST(std::ostream &out) const  {
    out << "Const_Char(" << str << ")";
  }

/*
    STRINGCONST
*/
void StringConst::printAST(std::ostream &out) const  {
    out << "StringConst(" << str << ")";
  }

/*
        ID
*/
void Id::printAST(std::ostream &out) const  {
    out << "Id(" << name << ")";
  }

/*
        INTCONST
*/
void IntConst::printAST(std::ostream &out) const  {
    out << "IntConst(" << num << ")";
  }

/*
        FUNC_CALL_STMT
*/
void Func_call_stmt::printAST(std::ostream &out) const  {
        out << "Func_call_stmt(" << id;
        if(expr != nullptr) {out << ", " ; expr->printAST(out); }
        if(comma_expr_gen != nullptr){ out << ", " ; comma_expr_gen->printAST(out); }
        out << ")";
     }

/*
        FUNC_CALL_EXPR
*/
void Func_call_expr::printAST(std::ostream &out) const  {
        out << "Func_call_expr(" << id;
        if(expr != nullptr) {out << ", " ; expr->printAST(out); }
        if(comma_expr_gen != nullptr) {out << ", " ; comma_expr_gen->printAST(out);}
        out << ")";
     }

/*
        BLOCK
*/
void Block::printAST(std::ostream &out) const  {
    out << "Block(";
    bool first = true;
    for (Stmt *s : stmt_list) {
      if (!first) out << ", ";
      first = false;
      out << *s;
    }
    out << ")";
  }

/*
        RET_TYPE
*/
void Ret_type::printAST(std::ostream &out) const  {
     out<< "Ret_Type(" <<  typos << ")";
   }

/*
        COMMA_ID_GEN
*/
void Comma_id_gen::printAST(std::ostream &out) const  {
        out<< "Comma_id_gen("  << name;
        if(comma_id_gen != nullptr) { out << ", " <<  *comma_id_gen << ")"; }
    }

/*
        TYPE_GEN
*/
void Type_gen::printAST(std::ostream &out) const  {
        out<< "Type_gen("  << size;
        if(type_gen != nullptr) { out << ", " <<  *type_gen << ")"; }
    }

/*
        FPAR_TYPE
*/
void Fpar_type::printAST(std::ostream &out) const  {
        out << "Fpar_type(" << typos;
        if(array == 1) out << "[ ]";
        if(type_gen != nullptr) { out << ", " << *type_gen; }
    }

/*
        FPAR_DEF
*/
void Fpar_def::printAST(std::ostream &out) const {
        out << "Fpar_def(" << name;
        if(comma_id_gen != nullptr){ out << " ," << *comma_id_gen ;}
        out<< ", "; fpar_type->printAST(out); out << ")";
     }

/*
        FPAR_DEF_GEN
*/
void Fpar_def_gen::printAST(std::ostream &out) const  {
        if(fpar_def_gen == nullptr){
            out << "Fpar_def_gen("; fpar_def->printAST(out); out << ")";
        }
        else{
            out << "Fpar_def_gen("; fpar_def_gen->printAST(out); out << ", "; fpar_def->printAST(out); out << ")";
        }
    }

/*
        HEADER
*/
void Header::printAST(std::ostream &out) const  {
        out << "Header(" << nam;
        if(fpar_def != nullptr) { out << ", "; fpar_def->printAST(out); }
        if(fpar_def_gen != nullptr) {out << ", "; fpar_def_gen->printAST(out); }
        out << ", "; ret_type->printAST(out); out << ")";
    }

/*
        FUNC_DECL
*/
void Func_decl::printAST(std::ostream &out) const  {
      out << "Func_decl(" << *header << ")";
   }

/*
        LOCAL_DEF_GEN
*/
void Local_def_gen::printAST(std::ostream &out) const  {
        out<<"Local_Def_Gen(" ; local_def->printAST(out);
        if(local_def_gen != nullptr) {out << ", "; local_def_gen->printAST(out); }
        out <<")"; 
      }

/*
        FUNC_DEF
*/
void Func_def::printAST(std::ostream &out) const  {
        out << "Func_def(";  header->printAST(out);  
        if(local_def_gen!= nullptr){ out << ", ";  local_def_gen->printAST(out); }
        out << ", "; block->printAST(out); out << ")";
     }


/*
        TYPE
*/
 void Type::printAST(std::ostream &out) const  {
        out<< "Type("  << typos;
        if(type_gen != nullptr) { out << ", "; type_gen->printAST(out);}
        out << ")"; 
    }

/*
        VAR_DEF
*/
void Var_def::printAST(std::ostream &out) const {
        out << "Var_def(" << id;
        if(comma_id_gen != nullptr){ out << ", "; comma_id_gen->printAST(out); }
        if(type != nullptr) {out << ", "; type->printAST(out); }
        out << ")";
     }

/*
        LOCAL_DEF
*/
void Local_def::printAST(std::ostream &out) const  {

        out << "Local_def(" ;
        if(func_def!=nullptr) func_def->printAST(out);
        else if (func_decl != nullptr) func_decl->printAST(out);
        else if(var_def != nullptr ) var_def->printAST(out) ;
        out << ")";

     }

/*
        L_VALUE
*/
void L_value::printAST(std::ostream &out) const {
        out << "L_value(" ;
        if(l_value != nullptr) l_value->printAST(out); 
        if(expr != nullptr) { out << ", "; expr->printAST(out); }
        if(flag==1){out<<id;}
        if(flag==2){out<<const_string; }
        out << ")";
    }

/*
        ASSIGN
*/
void Assign::printAST(std::ostream &out) const  {
        out << "Assign("; l_value->printAST(out);  out << ", " << *expr << ")";
    }

/*
        IF
*/
void If::printAST(std::ostream &out) const  {
        out << "If(" << *condition << ", " << *stmt1;
        if(stmt2 != nullptr) out << ", " << *stmt2;
        out << ")";
    }

/*
        WHILE
*/
void While::printAST(std::ostream &out) const  {
        out << "While(" << *condition << ", " << *stmt << ")";
    }

/*
        RETURN
*/
void Return::printAST(std::ostream &out) const  {
        out << "Return(" ;
        if (expr !=nullptr) out << *expr; 
        out <<  ")";
    }

/*
      COMMA_EXPR_GEN
*/
void Comma_expr_gen::printAST(std::ostream &out) const  {
        out << "Comma_expr_gen(" << *expr;
        if(comma_expr_gen != nullptr) out << ", " << *comma_expr_gen;
        out << ")";
    }

/*
        BIN_OP
*/
void BinOp::printAST(std::ostream &out) const  {
        out << "BinOp(" << *expr1 << *op << *expr2 <<  ")";
  }

/*
      COMPARE
*/
void Compare::printAST(std::ostream &out) const  {
        out << "Compare(" << *expr1 << *op << *expr2 <<  ")";
  }

/*
        UN_OP
*/
void UnOp::printAST(std::ostream &out) const  {
        out << "UnOp(" <<  op << ", " << *expr << ")";
  }  

/*
        COND
*/
void Cond::printAST(std::ostream &out) const  {
        out << "Cond(" << *cond1 << *op << *cond2 <<  ")";
  }  
/*
        NOT_COND
*/
 void Not_cond::printAST(std::ostream &out) const  {
        out << "Not_cond(" << *cond << ")";
  }

/*
        WRITE_INTEGER
*/
 void Write_Integer::printAST(std::ostream &out) const  {
        
        out << "Write_Integer(";
        if(n == -1) {out << id;}
        else out<<n;
        out<< ")";
  }

/*
        WRITE_CHAR
*/
 void Write_Char::printAST(std::ostream &out) const  {
        out << "Write_Char(" << id;
        out<< ")";
         
  }

/*
        WRITE_STRING
*/
 void Write_String::printAST(std::ostream &out) const  {
        out << "Write_String(" ;
        if(flag == 0) out << id;
        else out << *x;
        
       out << ")";
  }
  