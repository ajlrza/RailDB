#ifndef QUERY_PROCESSOR
#define QUERY_PROCESSOR
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

template<typename T>
concept Lexer = requires(T LexerType) {
    { LexerType.Regex() } -> std::same_as<std::string>;
    { LexerType.Query() } -> std::same_as<std::string>;
    { LexerType.Math() } -> std::same_as<int>;
};

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

enum class SQLType {
    INTEGER,
    BOOLEAN,
    VARCHAR,
};

enum class TokenType {
    ADD,
    INTO,
    GET,
    FROM,
    REMOVE,
    TABLE,
    COLUMN,
    NONE = true
};

class QueryProcessor {};

class QueryLexer {};

class QueryParser {};

class QueryOptimizer {};

class QueryExecutor {};

std::unordered_map<std::string, SQLType> type_system_catalog;


#endif