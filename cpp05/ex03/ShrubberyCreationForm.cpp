#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137),
target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
AForm("shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()),
target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    (void) other;
    return *this;
}


void ShrubberyCreationForm::action() const {
    std::string file(this->target + "_shrubbery");
    std::ofstream out(file.c_str());
    if (!out) 
	{
        std::cerr << "can't open/create" << this->target + "_shrubbery" << std::endl;
        return ;
    }
    out << 
    "            # #### ####\n"
    "        ### \\/#|### |/####\n"
    "        ##\\/#/ \\||/##/_/##/_#\n"
    "       ###  \\/###|/ \\/ # ###\n"
    "    ##_\\_#\\_\\## | #/###_/_####\n"
    "    ## #### # \\ #| /  #### ##/##\n"
    "    __#_--###`  |{,###---###-~\n"
    "                \\ }{\n"
    "                }}{\n"
    "                }}{\n"
    "        akarafi {{}\n"
    "        , -=-~{ .-^- _\n"
    "                `}\n"
    "                 {"
    << std::endl;
}

const std::string& ShrubberyCreationForm::getTarget() const { return this->target; }