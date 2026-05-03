// The Phi Project
// Copyright 2026 C3PO Authors
// Use of this source code is governed by the GPL-3.0 license, found in the LICENSE file
//
// Date created: 02-05-2026
// Original author: Zevi Berlin (zeviberlin@gmail.com)
// Latest editor: Zevi Berlin (zeviberlin@gmail.com)

#ifndef C3PO_OPTIONBASE_HPP
#define C3PO_OPTIONBASE_HPP

#include <string>
#include <memory>



namespace C3PO {

/// Typeless base-class so that I can use Type-Erasure
class OptionBase {
	private:
		std::string flag; // e.g. "-s", "-if"
		std::string full; // e.g. "--string", "--in-file"

		std::string desc;

		bool takes_value;
		bool filled;

	public:
		OptionBase(const std::string& flag_, const std::string& full_, const std::string& desc_, bool takes_value_) :
				flag(flag_), full(full_), desc(desc_), takes_value(takes_value_), filled(false) {}

		virtual ~OptionBase() const = default;

		/**/

		virtual void parse(const std::string& arg) = 0;
		virtual void parse() = 0; // default parser

		virtual bool has_default() const = 0;
};
	
}

#endif /* C3PO_OPTIONBASE_HPP */
