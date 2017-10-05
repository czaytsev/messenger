#include "user.h"

User::User() {

}

/***
 * setters and getters
 */


void User::setUser(std::string user) {
    user_ = user;
}

std::string User::getUser() {
    return user_;
}

