// The Phi Project
// Copyright 2026 C3PO Authors
// Use of this source code is governed by the GPL-3.0 license, found in the LICENSE file
//
// Date created: 02-05-2026
// Original author: Zevi Berlin (zeviberlin@gmail.com)
// Latest editor: Zevi Berlin (zeviberlin@gmail.com)

#ifndef C3PO_OPTION_HPP
#define C3PO_OPTION_HPP

#include <cxxabi.h>
#include <typeinfo>
#include <type_traits>
#include <string>
#include <memory>

#include "OptionBase.hpp"
#include "parse.hpp"



namespace C3PO {

/// Typed template class for Options which
/// will actually be held (via shared_ptr)
/// inside of the parser
template <typename T>
class Option : public OptionBase {
	private:
		bool has_default = true;
		std::shared_ptr<T> parsed = std::make_shared<T>();

	public:
		Option(const std::string& flag, const std::string& full, const std::string& desc, bool takes_value, bool required) :
			OptionBase(flag, full, desc, takes_value, required) {}

		~Option() override = default;

		/**/

		/// Parse the arg into the given
		/// type based on a set of rules
		/// defined in the docs
		bool parse(const std::string& arg) override {
			T result{};
			if (!parse_argument(arg, &result)) return false;
			this->parsed = std::make_shared<T>(result);

			this->has_default = false;
			this->fill();
			
			return true;
		}
		
		bool hasDefault() const override {
			return this->has_default;
		}

		/**/

		const T& get() const {
			return *(this->parsed);
		}

		constexpr T getT() const { return T{}; }
};



// helper to detect if a type is a specialization of a template
template <typename T, template <typename...> class Template>
struct is_specialization_of : std::false_type {};

template <template <typename...> class Template, typename... Args>
struct is_specialization_of<Template<Args...>, Template> : std::true_type {};

/**/

template <typename T>
std::string TYPE_INFO() {
	if constexpr (std::is_same<T, std::string>::value) {
		return "string";
	} else if constexpr (is_specialization_of<T, std::vector>::value) {
		using Inner = typename T::value_type;
    return "list<" + TYPE_INFO<Inner>() + ">";
	} else {
		int status;
  	char* demangled = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, &status);
  	std::string result = (status == 0) ? demangled : typeid(T).name();
  	free(demangled);
  	return result;
  }
}
	
}

#endif /* C3PO_OPTION_HPP */
