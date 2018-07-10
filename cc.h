#ifndef _CC_H_
#define _CC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct string {
  int size, length;
  char *buffer;
};
typedef struct string String;

extern String *string_new();
extern void string_push(String *string, char c);

struct map {
  int count;
  char *keys[1024];
  void *values[1024];
};
typedef struct map Map;

extern Map *map_new();
extern int map_count(Map *map);
extern bool map_put(Map *map, char *key, void *value);
extern void *map_lookup(Map *map, char *key);

extern void error(char *message);

extern char peek_char();
extern char get_char();

typedef enum token_type {
  tINT,
  tIDENTIFIER,
  tNOT,
  tLNOT,
  tADD,
  tSUB,
  tMUL,
  tDIV,
  tMOD,
  tLSHIFT,
  tRSHIFT,
  tLT,
  tGT,
  tLTE,
  tGTE,
  tEQ,
  tNEQ,
  tAND,
  tOR,
  tXOR,
  tLAND,
  tLOR,
  tQUESTION,
  tCOLON,
  tASSIGN,
  tSEMICOLON,
  tLPAREN,
  tRPAREN,
  tEND
} TokenType;

typedef struct token {
  TokenType type;
  int int_value;
  char *identifier;
} Token;

extern Token *peek_token();
extern Token *get_token();
extern void lex_init();

typedef struct symbol {
  int position;
} Symbol;

typedef enum node_type {
  CONST,
  IDENTIFIER,
  UPLUS,
  UMINUS,
  NOT,
  LNOT,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  LSHIFT,
  RSHIFT,
  LT,
  GT,
  LTE,
  GTE,
  EQ,
  NEQ,
  AND,
  OR,
  XOR,
  LAND,
  LOR,
  CONDITION,
  ASSIGN,
  BLOCK_ITEM
} NodeType;

typedef struct node {
  enum node_type type;
  int int_value;
  char *identifier;
  struct node *condition;
  struct node *left;
  struct node *right;
} Node;

extern int symbols_count();
extern Symbol *symbols_lookup(char *key);
extern Node *parse();
extern void parse_init();

extern void generate(Node *node);

#endif