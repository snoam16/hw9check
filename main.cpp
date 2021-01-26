#include "string.h"
#include "field.h"
#include "ip.h"
#include "port.h"
#include <iostream>
#include <cstring>
#include "input.h"
#define PACKETPARTS 4
 int main(int argc, char** argv)
 {
 	check_args(argc,argv);
 	String rule(argv[0]);
 	 	size_t* size=new size_t;
 	*size=0;
 	String* rule_split;
 	rule.split("=",&rule_split, size);
 	Field rules(rule_split[0]);
 	rules.set_value(rule_split[1]);
  	parse_input(rules);
 	delete size;
 	delete[] rule_split;
 	return 1;	
 	
 }
