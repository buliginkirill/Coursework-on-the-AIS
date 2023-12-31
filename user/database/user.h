#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <vector>
#include "Poco/JSON/Object.h"
#include <optional>

namespace database
{
    class User{
        private:
            long _id;
            std::string _first_name;
            std::string _last_name;
            std::string _email;
            std::string _title;
            std::string _login;
            std::string _password;

        public:

            static User fromJSON(const std::string & str);

            [[nodiscard]] long             get_id() const;
            [[nodiscard]] const std::string &get_first_name() const;
            [[nodiscard]] const std::string &get_last_name() const;
            [[nodiscard]] const std::string &get_email() const;
            [[nodiscard]] const std::string &get_title() const;
            [[nodiscard]] const std::string &get_login() const;
            [[nodiscard]] const std::string &get_password() const;

            long&        id();
            std::string &first_name();
            std::string &last_name();
            std::string &email();
            std::string &title();
            std::string &login();
            std::string &password();

            static void init();
            static std::optional<User> read_by_id(long id);
            static std::optional<long> auth(std::string &login, std::string &password);
            static std::vector<User> read_all();
            static std::vector<User> search(std::string first_name,std::string last_name);
            void save_to_mysql();

            void save_to_cache() const;
            static std::optional<User> read_from_cache_by_id(long id);

            [[nodiscard]] Poco::JSON::Object::Ptr toJSON() const;
            void send_to_queue() const;

    };
}

#endif