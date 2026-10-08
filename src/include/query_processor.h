#ifndef QUERY_PROCESSOR
#define QUERY_PROCESSOR
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class QueryProcessor {};

class QueryLexer {};

class QueryParser {};

class QueryOptimizer {};

class QueryExecutor {};

enum class SQLType;

enum class TokenType;

std::unordered_map<std::string, SQLType> type_system_catalog;

class StandardAST;

class StreamAST;

struct QueueNode {
    std::string user;
    std::string query;
};

struct QueryClasses {
    QueryLexer lexical_analyzer;
    QueryParser lexical_parser;
    QueryOptimizer lexical_optimzer;
    QueryExecutor lexical_executor;
    QueryProcessor query_processor;
};

struct SyntaxNode {
    TokenType Token;
    int LeftChild;
    int RightChild;
    int RootChild;
};

struct EvictedSubtree {
    TokenType PreviousToken;
    TokenType RightChild;
    TokenType RootChild;
    TokenType LeftChild;
};

struct ASTCatalog {
    StandardAST standard_ast;
    StreamAST stream_ast;
};


#endif