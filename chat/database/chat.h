#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <vector>
#include "Poco/JSON/Object.h"
#include <optional>

namespace database
{
    class Chat{
        private:
            long _id;
            long _user_id;
            std::string _message;
            std::string _created_at;

        public:

            //static Wall fromJSON(const std::string & str);

            [[nodiscard]] long  get_id() const;
            [[nodiscard]] const long &get_user_id() const;
            [[nodiscard]] const std::string &get_message() const;
            [[nodiscard]] const std::string &get_created_at() const;

            long&        id();
            long &user_id();
            std::string &message();
            std::string &created_at();

            static void init();
            static std::optional<long> post(long &user_id, std::string &message);
            static std::vector<Chat> get(long & user_id);

            Poco::JSON::Object::Ptr toJSON() const;

    };
}

#endif