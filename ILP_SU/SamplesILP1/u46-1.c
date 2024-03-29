#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object print;


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp238; 
{ 
  ILP_Object ilptmp239; 
ilptmp239 =  ILP_String2ILP("Un, "); 
ilptmp238 = ILP_print(ilptmp239);
}
{ 
  ILP_Object ilptmp240; 
ilptmp240 =  ILP_String2ILP("deux et "); 
ilptmp238 = ILP_print(ilptmp240);
}
{ 
  ILP_Object ilptmp241; 
ilptmp241 =  ILP_String2ILP("trois."); 
ilptmp238 = ILP_print(ilptmp241);
}
return ilptmp238; 
} 

} 

static ILP_Object ilp_caught_program () {
  struct ILP_catcher* current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if ( 0 == setjmp(new_catcher._jmp_buf) ) {
    ILP_establish_catcher(&new_catcher);
    return ilp_program();
  };
  return ILP_current_exception;
}

int main (int argc, char *argv[]) 
{ 
  ILP_START_GC; 
  ILP_print(ilp_caught_program()); 
  ILP_newline(); 
  return EXIT_SUCCESS; 
} 
