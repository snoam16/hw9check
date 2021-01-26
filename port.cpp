#include "port.h"
#include <iostream>
#include <cstring>


    Port::Port(String pattern):	Field::Field(pattern,PORT)
    {
    }
    bool Port::set_value(String val)
    {
    	String* output;
     	size_t* size = new size_t;
     	*size=0;
    	val.split("-", &output, size);
    	if(*size == 2)
    	{
    		range[0]=(output[0]).trim().to_integer();
    		range[1]=(output[1]).trim().to_integer();
    		delete size;
    		delete[] output;
    		return true;
    	}
    	delete size;
    	delete[] output;
    	return false;
    }
    bool Port::match_value(String val) const
    {
    	int value=0;
    	String* output;
     	size_t* size = new size_t;
     	*size=0;
    	val.split("=", &output, size);
    	if(*size==2)
    	{
    		value =(output[1]).trim().to_integer();
    		if(value>=range[0] && value<= range[1])
    		{
    		    delete size;
    			delete[] output;
    			return true;
    		}
    	}
    	delete size;
    	delete[] output;
    	return false;
    }
    			
    	
   

