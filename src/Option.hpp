// The Phi Project
// Copyright 2026 C3PO Authors
// Use of this source code is governed by the GPL-3.0 license, found in the LICENSE file
//
// Date created: 02-05-2026
// Original author: Zevi Berlin (zeviberlin@gmail.com)
// Latest editor: Zevi Berlin (zeviberlin@gmail.com)

#ifndef C3PO_OPTION_HPP
#define C3PO_OPTION_HPP

#include <string>
#include <memory>

#include "OptionBase.hpp"
#include "parse.hpp"



namespace C3PO {

/// Typed template class for Options which
/// will actually be held (via shared_ptr)
/// inside of the parser
template <typename T>
class Option : OptionBase {
	private:
		bool has_default = true;
		std::shared_ptr<T> parsed = std::make_shared<T>();

	public:
		Option(const std::string& flag, const std::string& full, const std::string& desc, bool takes_value) :
			OptionBase(flag, full, desc, takes_value) {}

		~Option() const override = default;

		/**/

		/// Parse the arg into the given
		/// type based on a set of rules
		/// defined in the docs
		void parse(const std::string& arg) override {
			T result{};
			parse_argument(arg, &result);
			this->parsed = std::make_shared<T>(result);

			this->has_default = false;
		}

		// no-op, old model is deprecated
		void parse() const override {}

		bool has_default() const override {
			return this->has_default;
		}

		/**/

		const T& get() const {
			return *(this->parsed);
		}
};
	
}
