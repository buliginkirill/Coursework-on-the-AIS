#include "database.h"
#include "../config/config.h"
#include "wall.h"


#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/MySQL/MySQLException.h>
#include <Poco/Data/SessionFactory.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>

#include <sstream>
#include <exception>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

namespace database
{

    long Wall::get_id() const {
        return _id;
    }

    const long &Wall::get_user_id() const {
        return _user_id;
    }

    const std::string &Wall::get_content() const {
        return _content;
    }

    const std::string &Wall::get_created_at() const {
        return _created_at;
    }

    long &Wall::id() {
        return _id;
    }

    long &Wall::user_id() {
        return _user_id;
    }

    std::string &Wall::content() {
        return _content;
    }

    std::string &Wall::created_at() {
        return _created_at;
    }

    void Wall::init() {
        try {
            Poco::Data::Session session = database::Database::get().create_session();
            Statement create_stmt(session);
            create_stmt << "CREATE TABLE IF NOT EXISTS `Message_wall` ("
                        << "`id` INT NOT NULL AUTO_INCREMENT, "
                        << "`user_id` INT NOT NULL, "
                        << "`content` TEXT CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL, "
                        << "`created_at` DATETIME NOT NULL, "
                        << "PRIMARY KEY (`id`), "
                        << "KEY `user_id` (`user_id`), "
                        << "FOREIGN KEY (`user_id`) REFERENCES `Author`(`id`) ON DELETE CASCADE "
                        << ");", now;
            std::cout << "Init OK" << std::endl;
        }

        catch (Poco::Data::MySQL::ConnectionException &e)
        {
            std::cout << "connection:" << e.what() << std::endl;
            throw;
        }
        catch (Poco::Data::MySQL::StatementException &e)
        {

            std::cout << "statement:" << e.what() << std::endl;
            throw;
        }
    }

    std::optional<long> Wall::post(long &user_id, std::string &message) {
        try
        {
            Poco::Data::Session session = database::Database::get().create_session();
            Poco::Data::Statement insert(session);
            //User a;
            insert << "insert into Message_wall(user_id, content, created_at) values(?, ?, now())",
                    use(user_id),
                    use(message);
            Poco::Data::Statement select(session);
            long return_id;
            select <<"SELECT LAST_INSERT_ID();",
                into(return_id),
                range(0, 1);;
            insert.execute();
            select.execute();
            Poco::Data::RecordSet rs(select);
            if (rs.moveFirst()) return return_id;
        }

        catch (Poco::Data::MySQL::ConnectionException &e)
        {
            std::cout << "connection:" << e.what() << std::endl;
        }
        catch (Poco::Data::MySQL::StatementException &e)
        {

            std::cout << "statement:" << e.what() << std::endl;

        }
        return {};
    }

    std::vector<Wall> Wall::get(long &user_id)     {
        try
        {
            Poco::Data::Session session = database::Database::get().create_session();
            Statement select(session);
            std::vector<Wall> result;
            Wall a;
                select << "select id, user_id, content, cast(created_at as varchar(100)) "
                       << "from Message_wall where user_id = ?",
                    into(a._id),
                    into(a._user_id),
                    into(a._content),
                    into(a._created_at),
                    use(user_id),
                    range(0, 1); //  iterate over result set one row at a time
            while (!select.done())
            {
                if (select.execute()){
                    result.push_back(a);
                }
            }
            return result;
        }

        catch (Poco::Data::MySQL::ConnectionException &e)
        {
            std::cout << "connection:" << e.displayText() << std::endl;
            throw;
        }
        catch (Poco::Data::MySQL::StatementException &e)
        {

            std::cout << "statement:" << e.displayText() << std::endl;
            throw;
        }
        catch (Poco::Data::MySQL::MySQLException &e)
        {

            std::cout << "MySqlException:" << e.displayText() << std::endl;
            throw;
        }
    }

    Poco::JSON::Object::Ptr Wall::toJSON() const {
        Poco::JSON::Object::Ptr root = new Poco::JSON::Object();

        root->set("id", _id);
        root->set("user_id", _user_id);
        root->set("content", _content);
        root->set("created_at", _created_at);
        return root;
    }
}