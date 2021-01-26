#include "ip.h"
#include <iostream>
#include <cstring>
#include <cmath>


    Ip::Ip(String pattern):Field::Field(pattern,IP)
    {
    }

    bool  Ip::set_value(String val)
    {
    	unsigned int ipValue=0,bitValue=0,lowb=0,highb=0;
    	String* output;
     	size_t* size = new size_t;
     	*size=0;
    	val.split("/", &output, size);
    	if(*size == 2)
    	{
    		
    		ipValue=(output[0]).trim().to_integer();
    		bitValue=(output[1]).trim().to_integer();
    		for(int i=0;i<32;i++)
    		{
    			if((32-i)<= (int)bitValue)
    			{
    				lowb+=pow(2,i);
    			}
    			else
    			{
    				highb+=pow(2,i);
    			}
    		}
    		low = ipValue & lowb;
    		high = ipValue | highb;
    
    		delete size;
    		delete[] output;
    		return true;
    	}
    	delete size;
    	delete[] output;
    	return false;
    }
    bool  Ip::match_value(String val) const
    {
    	int value=0;
    	String* outputs;
     	size_t* size = new size_t;
     	*size=0;
    	val.split("=", &outputs, size);
    	if(*size==2)
    	{
    		value =(outputs[1]).trim().to_integer();
    		if(value>=(int)low && value<= (int)high)
    		{
    		    delete size;
    			delete[] outputs;
    			return true;
    		}
    	}
    	delete size;
    	delete[] outputs;
    	return false;
    }
    			
    	
    

