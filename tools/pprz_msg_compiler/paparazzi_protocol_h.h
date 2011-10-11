/* 
	AUTOGENERATED: Do not change this file here! Generated by:
	$Id: templater.cpp 6153 2011-08-01 14:39:19Z coendewagter $
 */

#include <time.h>
#include <string>
#include <fstream>


class paparazzi_protocol_h_tpl_class
{
public:
	paparazzi_protocol_h_tpl_class()
	{
		ini = "";
		struct_ = "";
		sen = "";
		to_iv = "";
		prin = "";
		iv = "";
		switche = "";
		cbfun = "";
		privda = "";
		rest = "";
	}
	void open(const char* filename){file.open(filename);}
private:
	std::ofstream file;

	std::string ini; // block 0: ini
	std::string struct_; // block 1: struct
	std::string sen; // block 2: sen
	std::string to_iv; // block 3: to_iv
	std::string prin; // block 4: prin
	std::string iv; // block 5: iv
	std::string switche; // block 6: switche
	std::string cbfun; // block 7: cbfun
	std::string privda; // block 8: privda
	std::string rest; // block 9: rest

public:
	void add_init(const char* _txt1, const char* _txt2)
	{
		ini.append("		memset(&this->");
		ini.append(_txt1);
		ini.append(", 0, sizeof(");
		ini.append(_txt2);
		ini.append("_pprz_struct));\n");
	};
	void add_structs(const char* _txt1, const char* _txt2, const char* _txt3)
	{
		struct_.append("	struct ");
		struct_.append(_txt1);
		struct_.append("_pprz_struct\n	{\n");
		struct_.append(_txt2);
		struct_.append("	} ");
		struct_.append(_txt3);
		struct_.append("\n#if defined(__GNUC__)\n__attribute__((packed))\n#endif\n;\n\n");
	};
	void add_send(const char* _txt1, const char* _txt2, const int _nr3, const int _nr4)
	{
		sen.append("	void send_");
		sen.append(_txt1);
		sen.append("() { send( (void*) &this->");
		sen.append(_txt2);
		sen.append(", ");
		char tijdelijk[32];
		sprintf(tijdelijk,"%d",_nr3);
		sen.append(tijdelijk);
		sen.append(", ");
		sprintf(tijdelijk,"%d",_nr4);
		sen.append(tijdelijk);
		sen.append(" ); }\n");
	};
	void add_to_ivy(const char* _txt1, const char* _txt2, const char* _txt3)
	{
		to_iv.append("	std::string ");
		to_iv.append(_txt1);
		to_iv.append("_to_ivy()\n	{\n		std::stringstream ivy;\n\n		ivy << this->ac_id <<  \" ");
		to_iv.append(_txt2);
		to_iv.append("\";\n");
		to_iv.append(_txt3);
		to_iv.append("\n\n		return ivy.str();\n	}\n");
	};
	void add_print(const char* _txt1, const char* _txt2, const int _nr3, const char* _txt4)
	{
		prin.append("	void print_");
		prin.append(_txt1);
		prin.append("()\n	{\n		printf(\"Received msg '%s' (%d)\\n\",\"");
		prin.append(_txt2);
		prin.append("\",");
		char tijdelijk[32];
		sprintf(tijdelijk,"%d",_nr3);
		prin.append(tijdelijk);
		prin.append(");\n");
		prin.append(_txt4);
		prin.append("	}\n");
	};
	void add_ivy(const char* _txt1, const char* _txt2, const char* _txt3, const int _nr4)
	{
		iv.append("		if (msg_name.compare(\"");
		iv.append(_txt1);
		iv.append("\") == 0)\n		{\n");
		iv.append(_txt2);
		iv.append("			print_");
		iv.append(_txt3);
		iv.append("();\n			return ");
		char tijdelijk[32];
		sprintf(tijdelijk,"%d",_nr4);
		iv.append(tijdelijk);
		iv.append(";\n		}\n");
	};
	void add_switcher(const int _nr1, const char* _txt2, const char* _txt3, const int _nr4, const char* _txt5)
	{
		switche.append("		case ");
		char tijdelijk[32];
		sprintf(tijdelijk,"%d",_nr1);
		switche.append(tijdelijk);
		switche.append(":	// ");
		switche.append(_txt2);
		switche.append("\n			memcpy(&this->");
		switche.append(_txt3);
		switche.append(",&(port->buffer[4]),");
		sprintf(tijdelijk,"%d",_nr4);
		switche.append(tijdelijk);
		switche.append(");\n			print_");
		switche.append(_txt5);
		switche.append("();\n			break;\n");
	};
	void add_cbfunc(const char* _txt1, const char* _txt2, const char* _txt3)
	{
		cbfun.append("	inline void ");
		cbfun.append(_txt1);
		cbfun.append("_set_interrupt(Cb_Class *_inst, void (Cb_Class::*f) (void*))\n	{\n		");
		cbfun.append(_txt2);
		cbfun.append("_Instance = _inst; ");
		cbfun.append(_txt3);
		cbfun.append("_func_p = f;\n	}\n");
	};
	void add_privdat(const char* _txt1, const char* _txt2)
	{
		privda.append("	void (Cb_Class::*");
		privda.append(_txt1);
		privda.append("_func_p) (void*);\n	Cb_Class *");
		privda.append(_txt2);
		privda.append("_Instance;\n");
	};
public:
	void commit()
	{
		time_t aclock;
		time( &aclock );
		file << "/*\n"
				"\tAUTOGENERATED: Do not change this file here! Generated by:\n"
				"\t" __FILE__ "\n"
				"\tCompiled on: ";
		file << asctime( localtime( &aclock ) );
		file << "\n*/\n\n";
		file <<	"/****************************************************************\n"
				"*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
				"*\t\t\t\t------ SmartUAV Project ------\t\t\t\t\t*\n"
				"*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
				"*\tAerospace Software and Technologies Institue\tASTI\t\t*\n"
				"*\tDelft Cooperation for Intelligent Systems\t\tDECIS\t\t*\n"
				"*\tDelft University of Technology\t\t\t\t\tTU Delft\t*\n"
				"*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
				"*\tM. Amelink - C. De Wagter\t\t\t\t\t\t\t\t\t*\n"
				"*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
				"*\t$Id: paparazzi_protocol_h.tpl $\n"
				"*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
				"****************************************************************/\n"
				"\n"
				"// Includes\n"
				"#ifndef __MY_PAPARAZZI_PROTOCOL_HEADER__\n"
				"#define __MY_PAPARAZZI_PROTOCOL_HEADER__\n"
				"\n"
				"#include \"Fdc.h\"\n"
				"#include \"MyStdLib.h\"\n"
				"\n"
				"#include <string>\n"
				"#include <sstream>\n"
				"#include <iterator>\n"
				"#include <vector>\n"
				"// included for itoa\n"
				"#include <stdio.h>\n"
				"#include <stdlib.h>\n"
				"\n"
				"#if defined(WIN32)\n"
				"#pragma pack(push)\n"
				"#pragma pack(1)\n"
				"#endif\n"
				"\n"
				"#ifdef DEBUG\n"
				"#undef DEBUG\n"
				"#define DEBUG DEBUK\n"
				"#endif\n"
				"\n"
				"template <class Cb_Class>\n"
				"class paparazzi_protocol\n"
				"{\n"
				"public:\n"
				"\n"
				"\tpaparazzi_protocol(struct Fdc* s)\n"
				"\t{\n"
				"";
		file <<	ini;
		file <<	"\t\tport = s;\n"
				"\t}\n"
				"\n"
				"";
		file <<	struct_;
		file <<	"\n"
				"public:\n"
				"";
		file <<	sen;
		file <<	"\n"
				"\n"
				"";
		file <<	to_iv;
		file <<	"\n"
				"\tvoid split(const std::string input, std::vector<std::string> &results)\n"
				"\t{\n"
				"\t\tconst string& delimiter = \" \";\n"
				"\t\tconst bool includeEmpties = true;\n"
				"\n"
				"\t\tint iPos = 0;\n"
				"\t\tint newPos = -1;\n"
				"\t\tint sizeS2 = (int)delimiter.size();\n"
				"\t\tint isize = (int)input.size();\n"
				"\n"
				"\t\tif( \n"
				"\t\t\t( isize == 0 )\n"
				"\t\t\t||\n"
				"\t\t\t( sizeS2 == 0 )\n"
				"\t\t)\n"
				"\t\t{\n"
				"\t\t\treturn;\n"
				"\t\t}\n"
				"\n"
				"\t\tvector<int> positions;\n"
				"\n"
				"\t\tnewPos = input.find (delimiter, 0);\n"
				"\n"
				"\t\tif( newPos < 0 )\n"
				"\t\t{ \n"
				"\t\t\treturn; \n"
				"\t\t}\n"
				"\n"
				"\t\tint numFound = 0;\n"
				"\n"
				"\t\twhile( newPos >= iPos )\n"
				"\t\t{\n"
				"\t\t\tnumFound++;\n"
				"\t\t\tpositions.push_back(newPos);\n"
				"\t\t\tiPos = newPos;\n"
				"\t\t\tnewPos = input.find (delimiter, iPos+sizeS2);\n"
				"\t\t}\n"
				"\n"
				"\t\tif( numFound == 0 )\n"
				"\t\t{\n"
				"\t\t\treturn;\n"
				"\t\t}\n"
				"\n"
				"\t\tfor( int i=0; i <= (int)positions.size(); ++i )\n"
				"\t\t{\n"
				"\t\t\tstring s(\"\");\n"
				"\t\t\tif( i == 0 ) \n"
				"\t\t\t{ \n"
				"\t\t\t\ts = input.substr( i, positions[i] ); \n"
				"\t\t\t}\n"
				"\t\t\tint offset = positions[i-1] + sizeS2;\n"
				"\t\t\tif( offset < isize )\n"
				"\t\t\t{\n"
				"\t\t\t\tif( i == positions.size() )\n"
				"\t\t\t\t{\n"
				"\t\t\t\t\ts = input.substr(offset);\n"
				"\t\t\t\t}\n"
				"\t\t\t\telse if( i > 0 )\n"
				"\t\t\t\t{\n"
				"\t\t\t\t\ts = input.substr( positions[i-1] + sizeS2, \n"
				"\t\t\t\t\t\t  positions[i] - positions[i-1] - sizeS2 );\n"
				"\t\t\t\t}\n"
				"\t\t\t}\n"
				"\t\t\tif( includeEmpties || ( s.size() > 0 ) )\n"
				"\t\t\t{\n"
				"\t\t\t\tresults.push_back(s);\n"
				"\t\t\t}\n"
				"\t\t}\n"
				"\t\treturn;\n"
				"\t}\n"
				"\n"
				"";
		file <<	prin;
		file <<	"\n"
				"\n"
				"\n"
				"\tint ivy_decode(const char* _msg)\n"
				"\t{\n"
				"\t\tstd::stringstream vals;\n"
				"\t\tvals.str(_msg);\n"
				"\t\tstd::string msg_name;\n"
				"\t\tstd::vector<std::string> msg;\n"
				"\t\tsplit(_msg, msg);\n"
				"\n"
				"\t\tif (msg.size() < 2)\n"
				"\t\t{\t\n"
				"\t\t\tE_printf(\"Msg Error: too short\\n\");\n"
				"\t\t\treturn -1;\n"
				"\t\t}\n"
				"\n"
				"\t\tvals >> this->ac_id;\n"
				"\t\tvals >> msg_name;\n"
				"\n"
				"";
		file <<	iv;
		file <<	"\t\treturn -2;\n"
				"\t}\n"
				"\n"
				"\tint receive()\n"
				"\t{\n"
				"\t\t// Read\n"
				"\t\tfdcRead(port);\n"
				"\n"
				"\t\t// Search for start-byte\n"
				"\t\twhile ( (port->bytesread > 0) &&\n"
				"\t\t\t\t(port->buffer[0] != 0x99) )\n"
				"\t\t{\n"
				"\t\t\tfdcBufCrop(port,1);\n"
				"\t\t}\n"
				"\n"
				"\t\t// Check Length\n"
				"\t\tint l = (unsigned char) port->buffer[1]-4;\n"
				"\t\tif ((int)port->bytesread < (l+4))\n"
				"\t\t\treturn 0;\n"
				"\n"
				"\t\t// Verify Checksum\n"
				"\t\tunsigned char ck_a;\n"
				"\t\tunsigned char ck_b;\n"
				"\t\tck_a = port->buffer[1];\n"
				"\t\tck_b = port->buffer[1];\n"
				"\t\tfor (int i=0;i<l;i++)\n"
				"\t\t{\n"
				"\t\t\tck_a += port->buffer[2+i];\n"
				"\t\t\tck_b += ck_a;\n"
				"\t\t}\n"
				"\t\tif ((port->buffer[2+l] != ck_a) ||\n"
				"\t\t\t(port->buffer[3+l] != ck_b))\n"
				"\t\t{\t\n"
				"\t\t\tE_printf(\"Decoding Checksum Error\\n\");\n"
				"\t\t\tE_printf(\"CK: %X %X %X %X \\n\",ck_a,ck_b,port->buffer[2+l],port->buffer[3+l]);\n"
				"\t\t\t//fdcBufCrop(port,l+4);\n"
				"\t\t\t//return -1;\n"
				"\t\t}\n"
				"\n"
				"\t\tac_id = port->buffer[2];\n"
				"\t\tint msgid = port->buffer[3];\n"
				"\t\tswitch (msgid)\n"
				"\t\t{\n"
				"";
		file <<	switche;
		file <<	"\t\t}\n"
				"\t\tfdcBufCrop(port,l+4);\n"
				"\t\treturn msgid;\n"
				"\t}\n"
				"\n"
				"private:\n"
				"\tvoid send(void *p, unsigned char t, int len)\n"
				"\t{\n"
				"\t\tunsigned char cs_a, cs_b;\n"
				"\n"
				"\t\tcs_a = (unsigned char) (len+2);\n"
				"\t\tcs_b = cs_a;\n"
				"\n"
				"\t\tbuff[0] = 0x99;\n"
				"\t\tbuff[1] = cs_a;\n"
				"\t\tbuff[2] = ac_id;\n"
				"\t\tbuff[3] = t;\n"
				"\n"
				"\t\tmemcpy(&(buff[4]),p, len);\n"
				"\n"
				"\t\tfor (int i=0;i<(len+2);i++)\n"
				"\t\t{\n"
				"\t\t\tcs_a += buff[2+len];\n"
				"\t\t\tcs_b += cs_a;\n"
				"\t\t}\n"
				"\n"
				"\t\tbuff[4+len] = cs_a;\n"
				"\t\tbuff[5+len] = cs_b;\n"
				"\n"
				"\t\tfdcWrite(port,(char*)buff,len+6);\n"
				"\t}\n"
				"\n"
				"public:\n"
				"\tint ac_id;\n"
				"\n"
				"";
		file <<	cbfun;
		file <<	"\n"
				"private:\n"
				"\tstruct Fdc* port;\n"
				"\tunsigned char buff[264];\n"
				"\n"
				"";
		file <<	privda;
		file <<	"\n"
				"\n"
				"\n"
				"};\n"
				"\n"
				"#if defined(WIN32)\n"
				"#pragma pack(pop)\n"
				"#endif\n"
				"\n"
				"\n"
				"#endif\n"
				"";
		file <<	rest;
	}
} paparazzi_protocol_h ;

