#ifndef UNIFIED_INCLUDES_UNIFIED_HPP
#define UNIFIED_INCLUDES_UNIFIED_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;

namespace unified_includes {

	class vm_instruction_list {
	public:
		const static string mov;
		const static string princ;
		const static string poinc;
		const static string prdec;
		const static string podec;
		const static string cmpl;
		const static string neg;
		const static string pos;
		const static string bneg;
		const static string tyof;
		const static string add;
		const static string mul;
		const static string div;
		const static string mod;
		const static string exp;
		const static string sub;
		const static string shl;
		const static string shr;
		const static string equ;
		const static string nequ;
		const static string gt;
		const static string lt;
		const static string gte;
		const static string lte;
		const static string band;
		const static string bor;
		const static string exor;
		const static string lor;
		const static string land;
		const static string cast;
		const static string exit;
		const static string jmp;
		const static string list;
		const static string tupl;
		const static string dict;
		const static string func;
		const static string efunc;
		const static string struc;
		const static string estruc;
		const static string istruc;
		const static string module;
		const static string imodule;
		const static string emodule;
		const static string imov;
		const static string ret;
		const static string _enum;
		const static string ifunc;
		const static string scope;
		const static string escope;
		const static string dmov;
		const static string lambda;
		const static string ilambda;
		const static string elambda;
		const static string brk;
		const static string cont;

		const static string adde;
		const static string sube;
		const static string mule;
		const static string dive;
		const static string expe;
		const static string mode;
		const static string shle;
		const static string shre;
		const static string bande;
		const static string bore;
		const static string exore;
		const static string imprt;
	};

	class builtins {
		public:
			const static string builtin__va_args__;
			const static string va_args_function_parameter;
			const static string builtin_print;
			const static string builtin_exit;
			const static string builtin_add;
			const static string builtin_runtime_file_module_prefix;
			const static string builtin__self__;
	
			const static string builtin__add__;
			const static string builtin__subtract__;
			const static string builtin__multiply__;
			const static string builtin__divide__;
			const static string builtin__exponent__;
			const static string builtin__modulus__;
			const static string builtin__binary_and__;
			const static string builtin__binary_or__;
			const static string builtin__exclusive_or__;

			const static string builtin__add_equals__;
			const static string builtin__subtract_equals__;
			const static string builtin__multiply_equals__;
			const static string builtin__divide_equals__;
			const static string builtin__exponent_equals__;
			const static string builtin__modulus_equals__;
			const static string builtin__binary_and_equals__;
			const static string builtin__binary_or_equals__;
			const static string builtin__exclusive_or_equals__;

			const static string builtin__greater_than__;
			const static string builtin__less_than__;
			const static string builtin__greater_than_or_equal_to__;
			const static string builtin__less_than_or_equal_to__;
			const static string builtin__logical_and__;
			const static string builtin__logical_or__;
			const static string builtin__equals_equals__;
			const static string builtin__not_equals__;
			const static string builtin__cast__;
			const static string builtin__assign__;

			const static string builtin__post_increment__;
			const static string builtin__pre_increment__;
			const static string builtin__post_decrement__;
			const static string builtin__pre_decrement__;
			const static string builtin__numeric_negate__;
			const static string builtin__boolean_negate__;
			const static string builtin__complement__;
			const static string builtin__numeric_positive__;

			const static string builtin__print__;
			const static string builtin__slice__;
			const static string builtin__subscript__;
	};

	enum type_pure_kind {
		TYPE_PURE_YES, TYPE_PURE_NO, TYPE_PURE_NONE
	};

	enum type_class_kind {
		TYPE_CLASS_YES, TYPE_CLASS_NO, TYPE_CLASS_NONE
	};

	const extern vector<string> default_include_search_path_list;
}

#endif