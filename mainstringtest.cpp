#include "string.h"
#include "field.h"
#include "ip.h"
#include "port.h"
#include <iostream>
#include <cstring>

int main(){


	//Test construcctors
	String s1;
	String s2("test2");
	String s3(s2);

	//Test operator=
	String s4 = s3;
	String s5 = "test2";

	//Test operator ==
	if(s1.equals(s2))
		std::cout << "s1 == s2" << std::endl;
	if(s2.equals(s3))
		std::cout << "s2 == s3" << std::endl;
	if(s3.equals(s4))
		std::cout << "s3 == s4" << std::endl;
	if(s4.equals(s5))
		std::cout << "s4 == s5" << std::endl;
	if(s1.equals(s5))
		std::cout << "s4 == s5" << std::endl;



	//Test split and trim
	String str("  aaa.  bbb = 12345 . ccc /  ddd");
	String ss0("  aaa");
	String ss1("  bbb ");
	String ss2(" 12345 ");
	String ss3(" ccc ");
	String ss4("  ddd");
	
	String t0("aaa");
	String t1("bbb");
	String t2("12345");
	String t3("ccc");
	String t4("ddd");

	String* substrs;
	size_t size = 0;

	str.split("./=", &substrs, &size);
	
	if(ss0.equals(substrs[0]))
		std::cout << "ss0 == substrs0" << std::endl; //does not appear
	if(ss1.equals(substrs[1]))
		std::cout << "ss1 == substrs1" << std::endl;
	if(ss2.equals(substrs[2]))
		std::cout << "ss2 == substrs2" << std::endl;
	if(ss3.equals(substrs[3]))
		std::cout << "ss3 == substrs3" << std::endl;
	if(ss4.equals(substrs[4]))
		std::cout << "ss4 == substrs4" << std::endl; //does not appear


	if(t0.equals(substrs[0].trim()))
		std::cout << "t0 == substrs0.trim" << std::endl;
	if(t1.equals(substrs[1].trim()))
		std::cout << "t1 == substrs1.trim" << std::endl;
	if(t2.equals(substrs[2].trim()))
		std::cout << "t2 == substrs2.trim" << std::endl;
	if(t3.equals(substrs[3].trim()))
		std::cout << "t3 == substrs3.trim" << std::endl;
	if(t4.equals(substrs[4].trim()))
		std::cout << "t4 == substrs4.trim" << std::endl;


	delete[] substrs;


	//Test to_integer()
	String port("123");
	String ip("4.52.133.12");

	std::cout << port.to_integer() << std::endl;
	std::cout << ip.to_integer() << std::endl;


	std::cout << "done" << std::endl;
	

//Test Port
	Port port1("src-port");
	port1.set_value("src-port = 1-9");

	std::cout<< "5 " << (port1.match_value("dst-port=5") ? "match" : "no match") << std::endl;
	std::cout<< "1 " << (port1.match_value("src-port= 1") ? "match" : "no match") << std::endl;
	std::cout<< "9 " << (port1.match_value("src-port=9") ? "match" : "no match") << std::endl;
	std::cout<< "0 " << (port1.match_value("src-port=0") ? "match" : "no match") << std::endl;
	std::cout<< "10 " << (port1.match_value("src-port=10") ? "match" : "no match") << std::endl;

	//Test Ip
	Ip ip1("src-ip");
	ip1.set_value("src-ip=111.222.33.44/8");

	std::cout<< "111.222.33.44 " << (ip1.match_value(String("dst-ip=111.222.33.44")) ? "match" : "no match") << std::endl;
	std::cout<< "111.21.33.44 " << (ip1.match_value(String("src-ip=111.21.33.44")) ? "match" : "no match") << std::endl;
	std::cout<< "111.0.0.0 " << (ip1.match_value(String("src-ip=111.0.0.0")) ? "match" : "no match") << std::endl;
	std::cout<< "111.255.255.255 " << (ip1.match_value(String("src-ip=111.255.255.255")) ? "match" : "no match") << std::endl;
	std::cout<< "112.0.0.0 " << (ip1.match_value(String("src-ip=112.0.0.0")) ? "match" : "no match") << std::endl;
	std::cout<< "255.255.255.255 " << (ip1.match_value(String("src-ip=255.255.255.255")) ? "match" : "no match") << std::endl;
	std::cout<< "0.0.0.1 " << (ip1.match_value(String("src-ip=0.0.0.1")) ? "match" : "no match") << std::endl;
	std::cout<< "0.0.0.0 " << (ip1.match_value(String("src-ip=0.0.0.0")) ? "match" : "no match") << std::endl;

	//Test field - implementation issues
/*	std::cout<< "ip1 "<< (ip1.match(String("src-ip=111.222.33.44,dst-ip=111.222.33.44,src-port=5,dst-port=5")) ? "match" : "no match") << std::endl;
	std::cout<< "port1 "<< (port1.match(String("src-ip=111.222.33.44,dst-ip=111.222.33.44,src-port=5,dst-port=5")) ? "match" : "no match") << std::endl;

	std::cout<< "ip1 "<< (ip1.match(String("src-ip=112.222.33.44,dst-ip=111.222.33.44,src-port=5,dst-port=5")) ? "match" : "no match") << std::endl;
	std::cout<< "port1 "<< (port1.match(String("src-ip=111.222.33.44,dst-ip=111.222.33.44,src-port=55,dst-port=5")) ? "match" : "no match") << std::endl;
*/



	Ip ip2("dst-ip");
	ip2.set_value("dst-ip = 4.4.4.4/32");
	std::cout<< "ip2 "<< (ip2.match(String("dst-ip=4.255.255.4")) ? "match" : "no match") << std::endl;

	printf("chen");

	Ip t("src-ip");
	t.set_value("src-ip=3.3.3.3/32");
	printf("chen2");
	String s = String(",, , ,,src-ip=3.3.3.3 ,,,,  ,");
	//std::cout<< "t "
	int i= t.match(s);
	printf("noam");
	//"match" : "no match") << std::endl;
	
}

