#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>


/**
 * Class representing a single message
 */
class Message
{
public:
    /**
     * Empty constructor, creates an empty message
     */
    Message();

    /**
     * Creates a Message object with a given message
     * @param s -- message string
     */
    Message(std::string s);

    /**
     * Sets the message contents
     * @param msg -- value to set the contents to
     */
    void setMessage(std::string msg);

    /**
     * Sets the message id
     * @param id -- what to set the id to
     */
    void setId(int id);

    /**
     * Gets the message contents
     * @return the message
     */
    std::string getMessage();

    /**
     * Gets the message id
     * @return the id
     */
    int getId();

private:
    // Contents
    std::string msg_;
    // Sequential id of each message
    int id_;
};

#endif // MESSAGE_H
