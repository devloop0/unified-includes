#ifndef UNIFIED_INCLUDES_COMMAND_LINE_PARSER_HPP
#define UNIFIED_INCLUDES_COMMAND_LINE_PARSER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;
using std::cerr;
using std::pair;

namespace unified_includes {
	
	enum argument_kind {
		VALUE_ARGUMENT, SWITCH_ARGUMENT, ANY_ARGUMENT, ANY_ARGUMENT_MULTI
	};

	const extern string long_argument_prefix;
	const extern string short_argument_prefix;

	class command_line_argument {
		argument_kind kind;
		string short_argument;
		string long_argument;
		string reference_name;
		string usage;
		bool mandatory;
		bool once_only;
		public:
			command_line_argument(argument_kind ak, string sa, string la, string rn, string u, bool m, bool oo);
			~command_line_argument();
			string get_short_argument();
			string get_long_argument();
			string get_reference_name();
			string get_usage();
			const bool get_mandatory();
			const bool get_once_only();
			const argument_kind get_argument_kind();
	};

	class command_line_argument_result {
		command_line_argument arg;
		bool true_false;
		string argument;
		vector<string> argument_list;
		bool present;
		public:
			command_line_argument_result(command_line_argument cla, bool tf, bool p = true);
			command_line_argument_result(command_line_argument cla, string a, bool p = true);
			command_line_argument_result(command_line_argument cla, vector<string> al, bool p = true);
			~command_line_argument_result();
			const bool get_true_false();
			string get_argument();
			command_line_argument get_command_line_argument();
			vector<string> get_argument_list();
			const bool get_present();
	};

	class command_line_parser {
		vector<command_line_argument> possible_argument_list;
		vector<command_line_argument_result> argument_result_list;
		string logo;
		string usage;
		public:
			command_line_parser(string l, string u, vector<command_line_argument> pal);
			command_line_parser(string l, string u);
			~command_line_parser();
			command_line_argument add_argument(command_line_argument cla);
			vector<command_line_argument_result> parse(int argc, char* argv[]);
			string get_logo();
			string get_usage();
	};
}

#endif