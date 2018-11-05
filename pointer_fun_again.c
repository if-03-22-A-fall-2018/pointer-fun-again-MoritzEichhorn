/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <2 AHIF>
 * ---------------------------------------------------------
 * Exercise Number: 6
 * Title:			Pointer_Fun_Again
 * Author:			Eichhorn Moritz
 * ----------------------------------------------------------
 * Description:
 * Some exercises to pointers, structs, arrays.
 * ----------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

#define STRING_LENGHT 64

struct PlayStruct{
  int int_value;
  double double_value;
  char a_string[STRING_LENGHT];
};

void print_struct(struct PlayStruct ps,struct PlayStruct* pps);

void change_struct(struct PlayStruct ps,struct PlayStruct* pps);

void print_string(char* string_to_print);

void change_string(char* string1, char** p_string);

int main(int argc, char const *argv[]) {
  struct PlayStruct play_struct = {1, 1.1, "Start String"};
  struct PlayStruct* play_struct_pointer = &play_struct;

  print_struct(play_struct, play_struct_pointer);
  change_struct(play_struct, play_struct_pointer);
  // everything will change to the new values of the pointer, becasue it points to the values of play_struct and changes these values.
  print_struct(play_struct, play_struct_pointer);

  print_string(play_struct.a_string);


  char another_string[16] = "another_string";
  char* p = another_string;
  char** p_another_string = &p;
  change_string(play_struct.a_string, p_another_string);
  print_string(play_struct.a_string);
  print_string(another_string);
  /* every charakter after '\0' isn't shown, it "cuts" the string there. Both values are affected by this,
   because a string(char array) is a pointer. */
  return 0;
}

void print_struct(struct PlayStruct ps,struct PlayStruct* pps){
  printf("Values of struct ps: %d, %lf, %s\n",ps.int_value, ps.double_value, ps.a_string);
  printf("Values of struct pps: %d, %lf, %s\n",pps->int_value, pps->double_value, pps->a_string);
}

void change_struct(struct PlayStruct ps,struct PlayStruct* pps){
  ps.int_value = 2;
  ps.double_value = 2.2;
  strcpy(ps.a_string, "Changed Struct");

  pps->int_value = 3;
  pps->double_value = 3.3;
  strcpy(pps->a_string, "Changed Pointer");
}

void print_string(char* string_to_print){
  printf("%s\n",string_to_print);
}

void change_string(char* string1, char** p_string){
  string1[2] = '\0';
  *(*p_string+1) = '\0';
}
