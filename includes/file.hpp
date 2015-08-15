#ifndef UNIFIED_INCLUDES_FILE_HPP
#define UNIFIED_INCLUDES_FILE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <experimental/filesystem>

using std::shared_ptr;
using std::string;
using std::make_shared;
using std::cout;
using std::cerr;
using std::vector;
using std::fstream;
using std::ios;
using std::flush;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::getline;

namespace filesystem = std::experimental::filesystem;

namespace unified_includes {

	extern const string karma_lang_source_file_extension;
	extern const string dharma_vm_source_file_extension;

	class file {
		string path;
		filesystem::path path_representation;
		public:
			file(string p);
			~file();
			string get_parent_path();
			string get_full_name_with_path();
			string get_extension();
			string get_name();
			string get_full_name();
			const bool exists();
			float size_in_KB();
			const bool is_file();
			const bool remove();
			const bool is_directory();
			vector<string> get_source();
			const bool write(vector<string> lines_to_write);
			const bool append(vector<string> lines_to_write);
			const bool create_file();
			const bool create_directory();
			const static string platform_path_separator;
			const static string dot;
	};

	vector<file> search_directory(file f, bool recursive = true);
	string get_current_path();
	vector<file> isolate_by_extension(vector<file> file_list, string file_extension);
	vector<file> isolate_by_file(vector<file> file_list, file file_name);
}

#endif