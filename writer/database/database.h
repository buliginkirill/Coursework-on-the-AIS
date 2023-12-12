#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/MySQL/MySQLException.h>
#include <Poco/Data/SessionFactory.h>
#include <Poco/Data/SessionPool.h>

namespace database{
    class Database{
        private:
            std::string _connection_string;
            std::unique_ptr<Poco::Data::SessionPool> _pool;
            Database();
            static inline int shard_count(){
                return 3;
            };
        public:
            static Database& get();
            Poco::Data::Session create_session();
            static std::vector<std::string> get_all_hints(){
                std::vector<std::string> result;
                for (int i=0; i<shard_count(); i++){
                    result.push_back(get_hint_value(i)+" ");
                }
                return result;
            }
            static inline std::string get_hint_value(long id){
                return "-- sharding:" + std::to_string(id % shard_count());
            }
    };
}
#endif