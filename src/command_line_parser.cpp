#include "includes/command_line_parser.hpp"

using namespace unified_includes;

namespace unified_includes {

	const string long_argument_prefix = "--";
	const string short_argument_prefix = "-";

	command_line_argument::command_line_argument(argument_kind ak, string sa, string la, string rn, string u, bool m, bool oo) {
		kind = ak;
		short_argument = sa;
		long_argument = la;
		reference_name = rn;
		usage = u;
		mandatory = m;
		once_only = oo;
	}

	command_line_argument::~command_line_argument() {

	}

	string command_line_argument::get_short_argument() {
		return short_argument;
	}

	string command_line_argument::get_long_argument() {
		return long_argument;
	}

	string command_line_argument::get_reference_name() {
		return reference_name;
	}

	string command_line_argument::get_usage() {
		return usage;
	}

	const bool command_line_argument::get_mandatory() {
		return mandatory;
	}

	const bool command_line_argument::get_once_only() {
		return once_only;
	}

	const argument_kind command_line_argument::get_argument_kind() {
		return kind;
	}

	command_line_argument_result::command_line_argument_result(command_line_argument cla, bool tf, bool p) : arg(cla), true_false(tf), present(p) {

	}

	command_line_argument_result::command_line_argument_result(command_line_argument cla, string a, bool p) : arg(cla), argument(a), present(p) {

	}

	command_line_argument_result::command_line_argument_result(command_line_argument cla, vector<string> al, bool p) : arg(cla), argument_list(al), present(p) {

	}

	command_line_argument_result::~command_line_argument_result() {

	}

	const bool command_line_argument_result::get_true_false() {
		return true_false;
	}

	string command_line_argument_result::get_argument() {
		return argument;
	}

	command_line_argument command_line_argument_result::get_command_line_argument() {
		return arg;
	}

	vector<string> command_line_argument_result::get_argument_list() {
		return argument_list;
	}

	const bool command_line_argument_result::get_present() {
		return present;
	}

	command_line_parser::command_line_parser(string l, string u, vector<command_line_argument> pal) : possible_argument_list(pal), logo(l), usage(u) {

	}

	command_line_parser::command_line_parser(string l, string u) : logo(l), possible_argument_list(vector<command_line_argument>()), usage(u) {

	}

	command_line_parser::~command_line_parser() {
	
	}

	command_line_argument command_line_parser::add_argument(command_line_argument cla) {
		possible_argument_list.push_back(cla);
		return cla;
	}
	
	vector<command_line_argument_result> command_line_parser::parse(int argc, char* argv[]) {
		vector<string> string_argument_list;
		for (int i = 1; i < argc; i++)
			string_argument_list.push_back(argv[i]);
		vector<bool> hit_list;
		for (int i = 0; i < possible_argument_list.size(); i++)
			hit_list.push_back(false);
		vector<command_line_argument_result> result_list;
		for (int i = 0; i < string_argument_list.size(); i++) {
			int pos = i;
			string current = string_argument_list[i];
			string argument_name;
			if (current.substr(0, 2) == long_argument_prefix || current.substr(0, 1) == short_argument_prefix) {
				bool long_arg = false;
				if (current.substr(0, 2) == long_argument_prefix) {
					argument_name = current.substr(2);
					long_arg = true;
				}
				else
					argument_name = current.substr(1);
				int j = -1;
				for (int k = 0; k < possible_argument_list.size(); k++)
					if ((long_arg && argument_name == possible_argument_list[k].get_long_argument()) || (!long_arg &&
						argument_name == possible_argument_list[k].get_short_argument())) {
						j = k;
						break;
					}
				if (j != -1) {
					if (possible_argument_list[j].get_argument_kind() == argument_kind::SWITCH_ARGUMENT) {
						if (hit_list[j]) {
							cerr << "Switch already passed: " << current << ".";
							cerr << usage << '\n';
							exit(1);
						}
						hit_list[j] = true;
						result_list.push_back(command_line_argument_result(possible_argument_list[j], true));
					}
					else if (possible_argument_list[j].get_argument_kind() == argument_kind::VALUE_ARGUMENT) {
						if (pos == argc - 2) {
							cerr << "Expected an argument to follow this switch: " << current << ".\n";
							cerr << usage << '\n';
							exit(1);
						}
						else {
							string name = string_argument_list[pos + 1];
							if (!hit_list[j]) {
								hit_list[j] = true;
								result_list.push_back(command_line_argument_result(possible_argument_list[j], name));
							}
							else {
								if (possible_argument_list[j].get_once_only()) {
									cerr << "Only expected this switch once: " << current << ".\n";
									cerr << usage << '\n';
									exit(1);
								}
								else {
									int find = -1;
									for (int k = 0; k < result_list.size(); i++)
										if ((long_arg && argument_name == result_list[k].get_command_line_argument().get_long_argument()) || (!long_arg &&
											argument_name == result_list[k].get_command_line_argument().get_short_argument())) {
											find = k;
											break;
										}
									if (find == -1)
										exit(1);
									vector<string> name_list;
									if (result_list[find].get_argument().length() != 0) {
										name_list.push_back(result_list[find].get_argument());
									}
									else {
										vector<string> vec = result_list[find].get_argument_list();
										name_list = vec;
									}
									name_list.push_back(name);
									result_list.erase(result_list.begin() + find, result_list.begin() + find + 1);
									result_list.insert(result_list.begin() + find, command_line_argument_result(possible_argument_list[j], name_list));
								}
							}
							i++;
						}
					}
				}
				else {
					cerr << "Unrecognized command line option: " << current << ".\n";
					cerr << usage << '\n';
					exit(1);
				}
			}
			else {
				argument_name = current;
				bool done = false;
				for (int j = 0; j < possible_argument_list.size(); j++) {
					if (possible_argument_list[j].get_argument_kind() == argument_kind::ANY_ARGUMENT) {
						if (hit_list[j]) {
							j++;
							continue;
						}
						else {
							hit_list[j] = true;
							result_list.push_back(command_line_argument_result(possible_argument_list[j], argument_name));
							done = true;
							break;
						}
					}
					else if (possible_argument_list[j].get_argument_kind() == argument_kind::ANY_ARGUMENT_MULTI) {
						if (hit_list[j]) {
							j++;
							continue;
						}
						else {
							hit_list[j] = true;
							i++;
							vector<string> args;
							args.push_back(argument_name);
							while (i < string_argument_list.size() && (string_argument_list[i].substr(0, 1) != short_argument_prefix &&
								string_argument_list[i].substr(0, 2) != long_argument_prefix)) {
								args.push_back(string_argument_list[i]);
								i++;
							}
							result_list.push_back(command_line_argument_result(possible_argument_list[j], args));
							done = true;
							i--;
						}
					}
				}
				if (!done) {
					cerr << "No unnamed argument left or expected: " << argument_name << ".\n";
					cerr << usage << '\n';
					exit(1);
				}
			}
		}
		for (int i = 0; i < hit_list.size(); i++) {
			if (!hit_list[i]) {
				if (possible_argument_list[i].get_mandatory()) {
					cerr << "Mandatory argument missing: '" << possible_argument_list[i].get_reference_name() << "'.\n";
					cerr << usage << '\n';
					exit(1);
				}
				else {
					if (possible_argument_list[i].get_argument_kind() == argument_kind::ANY_ARGUMENT ||
						possible_argument_list[i].get_argument_kind() == argument_kind::VALUE_ARGUMENT ||
						possible_argument_list[i].get_argument_kind() == argument_kind::ANY_ARGUMENT_MULTI) {
						result_list.push_back(command_line_argument_result(possible_argument_list[i], "", false));
					}
					else
						result_list.push_back(command_line_argument_result(possible_argument_list[i], false, false));
				}
			}
		}
		argument_result_list = result_list;
		return argument_result_list;
	}

	string command_line_parser::get_logo() {
		return logo;
	}

	string command_line_parser::get_usage() {
		return usage;
	}
}