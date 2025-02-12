//
// Created by shachafk@wincs.cs.bgu.ac.il on 18/11/2019.
//

#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include "Action.h"

class User;
class Watchable;

class Session{
    enum StringValue {defaultcase,
        changeActiveUser,
        createUser,
        deleteUser,
        duplicateUser,
        exit,
        printActionsLog,
        printContentList,
        printWatchHistory,
        watch};

public:
    Session(const std::string &configFilePath);
    Session(const Session &other); //copy constructor
    Session &operator=(const Session& s); //copy assignment
    Session(Session &&other);//move
    Session& operator=(Session &&other);//move assignment
    void cleanOther(Session &other);
    void copy(const Session& s) ;
    ~Session();
    void start();
    void loadContents (const std::string &configFilePath);
    //getters
    std::vector<Watchable*> getContent() const ;
    std::unordered_map<std::string,User*>* getUsersMap()  ;
    std::vector<BaseAction*> getActionsLog() const ;
    User* getActiveUser() const ;
    std::vector <std::string>* getInputVector()  ;
    std::vector<Watchable *> myHistory() const;
    //setters
    void setActionInLog(BaseAction* act);
    void setActiveUser(User* user);
    //
    void runAction(BaseAction* action);
    void loadMapStringValues();
    void watchAgain(BaseAction *action);

private:
    std::vector<Watchable*> content;
    std::vector<BaseAction*> actionsLog;
    std::unordered_map<std::string,User*> userMap;
    User* activeUser;
    std::vector<std::string> inputVector;
    std::map<std::string, StringValue> s_mapStringValues;
    void route();
    void clean();
    void mainLoop();
    void changeToNewPointer(User *u) const;

};
#endif