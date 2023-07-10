#include "ast.hpp"

/*
    COMPARE
*/
void Compare::sem() {
    if(expr1->type != expr2->type)
        yyerror("Type Mismatch"); 
} 

/*
    EXPR
*/

/*
    HEADER
*/
void Header::sem(){
    st.openScope();
    st.insert(nam.getName(),ret_type->getTypos(),ENTRY_FUNCTION );
    st.printST();
}

/*
    FUNC DEF
*/
void Func_def::sem(){
    
}
/*
    BLOCK
*/
void Block::sem(){
    std::cout<<"block sem";
    for (Stmt *s : stmt_list) s->sem();
}

/*
    ID
*/
void Id::sem(){
   ;
}

void Ret_type::sem(){
    type = typos;
   
}

void IntConst::sem() {
    type = TYPE_int;
}

void Const_char::sem() {
    type = TYPE_const_char;
}

void StringConst::sem() {
    type = TYPE_const_string;
}
