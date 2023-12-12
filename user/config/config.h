#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class  Config{
    private:
        Config();
        std::string _host;
        std::string _port;
        std::string _login;
        std::string _password;
        std::string _database;
        std::string _cache_servers;
        std::string _queue_host;
        std::string _queue_topic;
        std::string _queue_group_id;

    public:
        static Config& get();

        std::string& port();
        std::string& host();
        std::string& login();
        std::string& password();
        std::string& database();
        std::string& cache_servers();
        std::string& queue_group_id();
        std::string& queue_host();
        std::string& queue_topic();

        [[nodiscard]] const std::string& get_port() const ;
        [[nodiscard]] const std::string& get_host() const ;
        [[nodiscard]] const std::string& get_login() const ;
        [[nodiscard]] const std::string& get_password() const ;
        [[nodiscard]] const std::string& get_database() const ;
        [[nodiscard]] const std::string& get_cache_servers() const;

        [[nodiscard]] const std::string& get_queue_group_id() const;
        [[nodiscard]] const std::string& get_queue_host() const ;
        [[nodiscard]] const std::string& get_queue_topic() const ;


        static std::string get_env(const std::string &key) {
            char *res = std::getenv(key.c_str());
            if (res == nullptr)
                return "";
            else {
                return {res};
            }
        }

};

#endif