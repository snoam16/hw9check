

#include "field.h"
#include "port.h"
#include "ip.h"
#include <iostream>
#include <cstring>
    
    Field::Field(String pattern, field_type type)
    {
    	
    		this->pattern =pattern.trim();
    		this->type =type;
    } 
   
    Field::Field(String pattern)
    {
    	if(pattern.equals("src-ip") || pattern.equals("dst-ip") )
    	{
   		 	this->type = IP;
   		}
   		else if(pattern.equals("src-port") || pattern.equals("dst-port") )
    	{
   		 	this->type = PORT;
   		}
   		else
   		{
   			this->type =GENERIC;
   		}
   	}
   	
    Field::~Field()
    {
    }

    field_type  Field::get_type() const
    {
    	return type;
    }
    
    bool Field::set_value(String val)
    {
      switch(this->get_type())
      {
      	case IP:  
      		return ((Ip*)this)->Ip::set_value(val);
      	break;
     	case PORT: 
     		return ((Port*)this)->Port::set_value(val);
     	break;
     	default:
     		return false;
      }
     }
     	

    bool Field::match_value(String val) const
     {
      switch(this->get_type())
      {
      	case IP:  
      		return ((Ip*)this)-> Ip::match_value(val);
      	break;
     	case PORT: 
     		return ((Port*)this)->Port::match_value(val);
     	break;
     	default:
     		return false;
      }
     }

    bool Field::match(String packet)
    {
     	String* output;
     	size_t* size = new size_t;
     	*size=0;
     	bool flag=true;
    	packet.split(",", &output, size);
    	for(int i=0; i < (int)(*size);i++)
    	{
    		flag = flag && Field::match_value(output[i]);
    	}
    	delete size;
    	delete[] output;
    	return flag;
    }
