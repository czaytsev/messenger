#ifndef USER_H
#define USER_H

#include <string>

/**
 * Class representing a single user
 */
class User
{
public:
    /**
     * Empty constructor; creates a user with no name
     */
    User();

    /**
     * Creates a user with a given name
     * @param n -- name of user
     */
    User(std::string n);

    /**
     * Sets the name of the user
     * @param user -- string representing name of user
     */
    void setUser(std::string user);

    /**
     * Gets the name of the user
     * @return the user name
     */
    std::string getUser();

private:
    // Contents
    std::string user_;
};

#endif // USER_H
