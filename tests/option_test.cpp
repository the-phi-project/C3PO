#include "Option.hpp"

#include <string>
#include <memory>
#include <iostream>

template <typename T>
void printOpt(const std::shared_ptr<C3PO::OptionBase>& option) {
	auto* opt = dynamic_cast<C3PO::Option<T>*>(option.get());

	std::cout << std::boolalpha;
	std::cout << "opt->getFlag(): " << opt->getFlag();
	std::cout << "\nopt->getFull(): " << opt->getFull();
	std::cout << "\nopt->getDesc(): " << opt->getDesc();
	std::cout << "\nopt->get(): " << opt->get();
	std::cout << "\nopt->getT(): " << opt->getT();
	std::cout << "\nopt->isFilled(): " << opt->isFilled();
	std::cout << "\nopt->hasDefault(): " << opt->hasDefault();
	std::cout << "\nopt->isRequired(): " << opt->isRequired();
	std::cout << "\nTYPE_INFO: " << C3PO::TYPE_INFO<decltype(opt->getT())>() << std::endl;
}

int main() {
	std::shared_ptr<C3PO::OptionBase> bool_opt = std::make_shared<C3PO::Option<bool>>("-b", "--bool", "A boolean argument", false, false);

	std::cout << "BOOLEAN OPTION: \n";
	printOpt<bool>(bool_opt);

	//

	std::shared_ptr<C3PO::OptionBase> char_opt = std::make_shared<C3PO::Option<char>>("-c", "--char", "A character argument", true, true);

	std::cout << "\nCHARACTER OPTION: \n";
	printOpt<char>(char_opt);

	//

	std::shared_ptr<C3PO::OptionBase> short_opt = std::make_shared<C3PO::Option<short>>("-sh", "--short", "A short argument", true, false);
	
	std::cout << "\nSHORT OPTION: \n";
	printOpt<short>(short_opt);

	//

	std::shared_ptr<C3PO::OptionBase> int_opt = std::make_shared<C3PO::Option<int>>("-i", "--int", "An integer argument", false, true);
	
	std::cout << "\nINT OPTION: \n";
	printOpt<int>(int_opt);

	//

	std::shared_ptr<C3PO::OptionBase> long_opt = std::make_shared<C3PO::Option<long>>("-l", "--long", "A long argument", true, true);
	
	std::cout << "\nLONG OPTION: \n";
	printOpt<long>(long_opt);

	//

	std::shared_ptr<C3PO::OptionBase> long_long_opt = std::make_shared<C3PO::Option<long long>>("-ll", "--long-long", "A character argument", true, false);
	
	std::cout << "\nLONG LONG OPTION: \n";
	printOpt<long long>(long_long_opt);

	//

	std::shared_ptr<C3PO::OptionBase> size_t_opt = std::make_shared<C3PO::Option<size_t>>("-st", "--st", "A size_t argument", false, false);
	
	std::cout << "\nSIZE_T OPTION: \n";
	printOpt<size_t>(size_t_opt);

	//

	std::shared_ptr<C3PO::OptionBase> float_opt = std::make_shared<C3PO::Option<float>>("-f", "--float", "A floating point argument", true, false);
	
	std::cout << "\nFLOAT OPTION: \n";
	printOpt<float>(float_opt);

	//

	std::shared_ptr<C3PO::OptionBase> double_opt = std::make_shared<C3PO::Option<double>>("-d", "--double", "A double floating point argument", false, true);
	
	std::cout << "\nDOUBLE OPTION: \n";
	printOpt<double>(double_opt);

	//

	std::shared_ptr<C3PO::OptionBase> string_opt = std::make_shared<C3PO::Option<std::string>>("-s", "--string", "A string argument", true, true);
	
	std::cout << "\nSTRING OPTION: \n";
	printOpt<std::string>(string_opt);

	return 0;
}
