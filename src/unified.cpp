#include "../includes/unified.hpp"

using namespace unified_includes;

namespace unified_includes {

	const string vm_instruction_list::mov = "mov";
	const string vm_instruction_list::princ = "princ";
	const string vm_instruction_list::poinc = "poinc";
	const string vm_instruction_list::prdec = "prdec";
	const string vm_instruction_list::podec = "podec";
	const string vm_instruction_list::cmpl = "cmpl";
	const string vm_instruction_list::neg = "neg";
	const string vm_instruction_list::pos = "pos";
	const string vm_instruction_list::bneg = "bneg";
	const string vm_instruction_list::tyof = "tyof";
	const string vm_instruction_list::add = "add";
	const string vm_instruction_list::mul = "mul";
	const string vm_instruction_list::div = "div";
	const string vm_instruction_list::mod = "mod";
	const string vm_instruction_list::exp = "exp";
	const string vm_instruction_list::sub = "sub";
	const string vm_instruction_list::shl = "shl";
	const string vm_instruction_list::shr = "shr";
	const string vm_instruction_list::equ = "equ";
	const string vm_instruction_list::nequ = "nequ";
	const string vm_instruction_list::lt = "lt";
	const string vm_instruction_list::lte = "lte";
	const string vm_instruction_list::gt = "gt";
	const string vm_instruction_list::gte = "gte";
	const string vm_instruction_list::bor = "bor";
	const string vm_instruction_list::band = "band";
	const string vm_instruction_list::exor = "exor";
	const string vm_instruction_list::land = "land";
	const string vm_instruction_list::lor = "lor";
	const string vm_instruction_list::cast = "cast";
	const string vm_instruction_list::exit = "exit";
	const string vm_instruction_list::jmp = "jmp";
	const string vm_instruction_list::list = "list";
	const string vm_instruction_list::tupl = "tupl";
	const string vm_instruction_list::dict = "dict";
	const string vm_instruction_list::func = "func";
	const string vm_instruction_list::efunc = "efunc";
	const string vm_instruction_list::struc = "struc";
	const string vm_instruction_list::estruc = "estruc";
	const string vm_instruction_list::istruc = "istruc";
	const string vm_instruction_list::module = "module";
	const string vm_instruction_list::imodule = "imodule";
	const string vm_instruction_list::emodule = "emodule";
	const string vm_instruction_list::imov = "imov";
	const string vm_instruction_list::ret = "ret";
	const string vm_instruction_list::_enum = "enum";
	const string vm_instruction_list::ifunc = "ifunc";
	const string vm_instruction_list::scope = "scope";
	const string vm_instruction_list::escope = "escope";
	const string vm_instruction_list::dmov = "dmov";
	const string vm_instruction_list::lambda = "lambda";
	const string vm_instruction_list::ilambda = "ilambda";
	const string vm_instruction_list::elambda = "elambda";
	const string vm_instruction_list::brk = "brk";
	const string vm_instruction_list::cont = "cont";

	const string vm_instruction_list::adde = "adde";
	const string vm_instruction_list::sube = "sube";
	const string vm_instruction_list::mule = "mule";
	const string vm_instruction_list::dive = "dive";
	const string vm_instruction_list::expe = "expe";
	const string vm_instruction_list::mode = "mode";
	const string vm_instruction_list::shle = "shle";
	const string vm_instruction_list::shre = "shre";
	const string vm_instruction_list::bande = "bande";
	const string vm_instruction_list::bore = "bore";
	const string vm_instruction_list::exore = "exore";
	const string vm_instruction_list::imprt = "imprt";

	const string builtins::builtin__va_args__ = "__va_args__";
	const string builtins::va_args_function_parameter = "_";
	const string builtins::builtin_print = "print";
	const string builtins::builtin_exit = "exit";
	const string builtins::builtin_add = "add";
	const string builtins::builtin_runtime_file_module_prefix = "@@__runtime_file_module__";
	const string builtins::builtin__self__ = "__self__";

	const string builtins::builtin__add__ = "__add__";
	const string builtins::builtin__subtract__ = "__subtract__";
	const string builtins::builtin__multiply__ = "__multiply__";
	const string builtins::builtin__divide__ = "__divide__";
	const string builtins::builtin__exponent__ = "__exponent__";
	const string builtins::builtin__modulus__ = "__modulus__";
	const string builtins::builtin__binary_and__ = "__binary_and__";
	const string builtins::builtin__binary_or__ = "__binary_or__";
	const string builtins::builtin__exclusive_or__ = "__exclusive_or__";

	const string builtins::builtin__add_equals__ = "__add_equals__";
	const string builtins::builtin__subtract_equals__ = "__subtract_equals__";
	const string builtins::builtin__multiply_equals__ = "__multiply_equals__";
	const string builtins::builtin__divide_equals__ = "__divide_equals__";
	const string builtins::builtin__exponent_equals__ = "__exponent_equals__";
	const string builtins::builtin__modulus_equals__ = "__modulus_equals__";
	const string builtins::builtin__binary_and_equals__ = "__binary_and_equals__";
	const string builtins::builtin__binary_or_equals__ = "__binary_or_equals__";
	const string builtins::builtin__exclusive_or_equals__ = "__exclusive_or_equals__";

	const string builtins::builtin__greater_than__ = "__greater_than__";
	const string builtins::builtin__less_than__ = "__less_than__";
	const string builtins::builtin__greater_than_or_equal_to__ = "__greater_than_or_equal_to__";
	const string builtins::builtin__less_than_or_equal_to__ = "__less_than_or_equal_to__";
	const string builtins::builtin__logical_and__ = "__logical_and__";
	const string builtins::builtin__logical_or__ = "__logical_or__";
	const string builtins::builtin__equals_equals__ = "__equals_equals__";
	const string builtins::builtin__not_equals__ = "__not_equals__";
	const string builtins::builtin__cast__ = "__cast__";
	const string builtins::builtin__assign__ = "__assign__";

	const string builtins::builtin__post_increment__ = "__post_increment__";
	const string builtins::builtin__pre_increment__ = "__pre_increment__";
	const string builtins::builtin__post_decrement__ = "__post_decrement__";
	const string builtins::builtin__pre_decrement__ = "__pre_decrement__";
	const string builtins::builtin__numeric_negate__ = "__numeric_negate__";
	const string builtins::builtin__numeric_positive__ = "__numeric_positive__";
	const string builtins::builtin__boolean_negate__ = "__boolean_negate__";
	const string builtins::builtin__complement__ = "__complement__";

	const string builtins::builtin__print__ = "__print__";
	const string builtins::builtin__slice__ = "__slice__";
	const string builtins::builtin__subscript__ = "__subscript__";

	const vector<string> default_include_search_path_list = {
#ifdef _WIN32
		"C:\\libkarma"
#else
		"/usr/include/libkarma"
#endif
	};
}