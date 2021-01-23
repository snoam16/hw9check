#include "string.h"
#include <iostream>
#include <cstring>
#define IPSIZE 4


    /**
     * @brief Initiates an empty string
     */
    String::String()
    {
    	 data = NULL;
    	 length=0;
    }

    /**
     * @brief Initiates string from other string
     */
    String::String(const String &str)
    {
    	if(str.data != NULL)
    	{
        	this-> length = str.length;
        
       		this->data = new char[this->length +1];
       		
       		strncpy(this->data, str.data, length +1);
     	}
     	else
     	{
     		String();
     	}
	}

    /**
     * @brief Initiates a string from char array
     */
    String::String(const char *str)
    {
    	if(str != NULL)
    	{
    		this-> length = strlen(str);
    		this-> data = new char[this->length +1];
    		strncpy(this->data, str, length + 1);
     	}
     	else
     	{
     		String();
     	}
     }
    		


    String::~String()
    {
    	if(this->data != NULL)
    	{
    		delete [] this->data;
    	}
    }

    /**
     * @brief Changes this from String
     */
    String& String::operator=(const String &rhs)
    {
    	this -> ~String();
    	if(rhs.data != NULL)
    	{
    		 String(rhs);
    	}
    	return *this;
    }
    
    		
    /**
     * @brief Changes this from char array
     */
    String& String::operator=(const char *str)
    {
       	this -> ~String();
    	if(str != NULL)
    	{
    		String(str);
    	}
    	return *this;
    }

    /**
     * @brief Returns true iff the contents of this equals to the
     * contents of rhs
     */
    bool String::equals(const String &rhs) const
    {
    	if(strncmp(this->data, rhs.data,length) == 0)
    	{
    	    	return true;
    	}
    	return false;
    }

    /**
     * @brief Returns true iff the contents of this equals to rhs
     */
    bool String::equals(const char *rhs) const
    {

    	if(std::strncmp(data, rhs,length) == 0)
    	{
    	    	return true;
    	}
    	return false;
    }

    /**
     * @brief Splits this to several sub-strings according to delimiters.
     * Allocates memory for output that the user must delete (using delete[]).
     * @note Does not affect this.
     * @note If "output" is set to NULL, do not allocated memory, only
     * compute "size".
     */
    void String::split(const char *delimiters, String **output, size_t *size) const
    {

    	if(size == NULL || delimiters==NULL || data==NULL)
    	{
    		return;
    	}
    	int delimitersSize =strlen(delimiters),lastDelim=0;
    	*size =0;
    	if(output==NULL)
    	{
    		*size =2;
    	}
    	for(int i=0; i<this->length; i++)
    	{
    		for(int j=0; j<delimitersSize;j++)
    		{
    			if(this-> data[i]== delimiters[j])
    			{
    				if(i>0)
    				{
    					output[*size]->data = strtok(((this->data) + lastDelim),(delimiters +j));
    					(*size)++;
    				}
    				lastDelim = i +1;
    			}
    		}
    	}
    }
    			
    				
    				
    		

    /**
     * @brief Try to convert this to an integer. Returns 0 on error.
     */
    int String::to_integer() const
    {
    	int ipPart=0, returnVal=0;
    	size_t* size =0;
    	String* output;
    	
    	split(".", &output, size);
    	if(*size == IPSIZE)
    	{
    		for(int i=0; i<IPSIZE; i++)
    		{
    			ipPart=output[i].to_integer();
    			if(ipPart<256 && ipPart>0)
    			{
    				returnVal+= ipPart<<(24-8*i );
    			}
    		}
        	delete[] output;
         	return returnVal;
    	}
    	else if(size == 0)
    	{
    		returnVal = std::stoi(data, NULL, 10);
    		delete[] output;
    		return returnVal;
    	}
    	else
    	{
    		delete[] output;
    		return 0;
    	}
    }
    				    /**
     * @brief Remove any leading or trailing white-spaces.
     * Does not change this.
     */
    String String::trim() const
    {
    	int head=0,tail=length;
    	String strTrimed;
    	while((data[head] == ' ') && (head< (length)+1))
    	{ 
    		head++;;
    	}
    	while((data[tail] == ' ') && (tail>head))
    	{ 
    		tail--;
    	}
    	strncpy(strTrimed.data, (data+head) ,tail-head);
    	return strTrimed;
    }
    	
    	
    		
    		
    	

