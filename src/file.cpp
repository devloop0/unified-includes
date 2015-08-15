#include "includes/file.hpp"

using namespace unified_includes;

namespace unified_includes {

	const string karma_lang_source_file_extension = "ka";
	const string dharma_vm_source_file_extension = "kac";

	file::file(string p) {
		path = p;
		path_representation = filesystem::path(path);
	}

	file::~file() {

	}

	string file::get_parent_path() {
		return path_representation.parent_path().string();
	}

	string file::get_extension() {
		return (path_representation.has_extension() ? path_representation.extension().string().substr(1) : "");
	}

	const bool file::exists() {
		return filesystem::exists(path_representation);
	}

	float file::size_in_KB() {
		return filesystem::file_size(path_representation) / 1000;
	}

	const bool file::remove() {
		return filesystem::remove(path_representation);
	}

	const bool file::is_file() {
		return filesystem::is_regular_file(path_representation);
	}

	const bool file::is_directory() {
		return filesystem::is_directory(path_representation);
	}

	const bool file::create_file() {
		fstream f;
		f.open(path, ios::out);
		f << flush;
		f.close();
		return true;
	}

	const bool file::create_directory() {
		filesystem::create_directories(path_representation);
		return true;
	}

	const bool file::write(vector<string> lines_to_write) {
		ofstream of;
		of.open(path);
		for (string s : lines_to_write)
			of << s << endl;
		of.close();
		return true;
	}

	vector<string> file::get_source() {
		vector<string> line_list;
		string line;
		ifstream i(path);
		while (getline(i, line))
			line_list.push_back(line);
		i.close();
		return line_list;
	}

	const bool file::append(vector<string> lines_to_write) {
		ofstream of;
		of.open(path, ios::app);
		for (string s : lines_to_write)
			of << s << endl;
		return true;
	}

	string file::get_full_name() {
		return path_representation.filename().string();
	}

	string file::get_name() {
		return get_full_name().substr(0, get_full_name().find('.'));
	}

	string file::get_full_name_with_path() {
		return path_representation.string();
	}

#ifdef _WIN32
	const string file::platform_path_separator = "\\";
#else
	const string file::platform_path_separator = "/";
#endif

	const string file::dot = ".";

	vector<file> search_directory(file f, bool recursive) {
		vector<file> ret;
		if (f.is_directory()) {
			if (recursive)
				for (filesystem::directory_entry de : filesystem::recursive_directory_iterator(f.get_full_name_with_path() + file::platform_path_separator))
					ret.push_back(file(de.path().string()));
			else
				for (filesystem::directory_entry de : filesystem::directory_iterator(f.get_full_name_with_path() + file::platform_path_separator))
					ret.push_back(file(de.path().string()));
		}
		return ret;
	}

	string get_current_path() {
		return filesystem::current_path().string();
	}

	vector<file> isolate_by_extension(vector<file> file_list, string file_extension) {
		vector<file> ret;
		for (int i = 0; i < file_list.size(); i++)
			if (file_list[i].get_extension() == file_extension)
				ret.push_back(file_list[i]);
		return ret;
	}

	vector<file> isolate_by_file(vector<file> file_list, file file_name) {
		vector<file> ret;
		for (int i = 0; i < file_list.size(); i++)
			if (file_list[i].get_full_name() == file_name.get_full_name())
				ret.push_back(file_list[i]);
		return ret;
	}
}