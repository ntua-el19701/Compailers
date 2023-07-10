.PHONY: clean distclean default

CXX = c++ -std=c++11
CXXFLAGS = -Wall

default: grace

lexer/lexer.cpp: lexer/lexer.l
	flex -s -olexer/lexer.cpp lexer/lexer.l

lexer/lexer.o: lexer/lexer.cpp lexer/lexer.hpp parser/parser.hpp ast/ast.hpp symbol.hpp

parser/parser.hpp parser/parser.cpp: parser/parser.y
	bison -dv -oparser/parser.cpp parser/parser.y		

parser/parser.o: parser/parser.cpp lexer/lexer.hpp ast/ast.hpp symbol.hpp

ast/printAST.o: ast/printAST.cpp ast/ast.hpp
	$(CXX) $(CXXFLAGS) -c -o ast/printAST.o ast/printAST.cpp

sem/sem.o: ast/sem.cpp ast/ast.hpp
	$(CXX) $(CXXFLAGS) -c -o ast/sem.o ast/sem.cpp

grace: lexer/lexer.o parser/parser.o ast/printAST.o ast/sem.o
	$(CXX) $(CXXFLAGS) -o grace lexer/lexer.o parser/parser.o ast/printAST.o ast/sem.o

clean:
	$(RM) lexer/lexer.cpp parser/parser.cpp parser/parser.hpp parser/parser.output *.o

distclean: clean
	$(RM) grace
