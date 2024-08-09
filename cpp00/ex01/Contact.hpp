
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    void setFirstName(const std::string &name);
    void setLastName(const std::string &lasName);
    void setNickName(const std::string &nickName);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darrkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif