//  Include Guard
#ifndef INTERPRETER_H_
#define INTERPRETER_H_


#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define NUM_OF_API_FUNCS  8
#define MAX_RESP_LEN      100
#define CMD_BUFF_LEN      30

//  structure for instruction data
typedef struct API_t{

  uint16_t place;
  struct API_t *left;       //  Left element on a binatry tree branch
  struct API_t *right;      //  Right element on a binary tree branch
  const char **name;        //  Name of the instruction
  const char **desc;        //  Description of the command
  void(*func)(char*,char*); //  Function pointer to the command function
  //void(*resp_fn)(char*, ...)

}API_t;


void add_interpreter_instruction(const char **name, const char **desc, void(*func)(char*,char*));

void init_interpreter(void);

void print_apis_in_order(API_t *head);

void recursive_indexer(API_t *head);

void index_apis_in_order(API_t *head);

uint16_t find_api_index_by_place( uint16_t place );

void optimise_api_tree(API_t *head);

void swap_api_elements( uint16_t index, uint16_t place );

void recursive_optimiser( int32_t start_index, int32_t stop_index );

void execute( char *cmd, char *response );

void teszt(void);

#endif