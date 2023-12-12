#include "config.h"
#include <iostream>

Config::Config()
{
        if (std::getenv("")== nullptr) { //переменных нет
            setenv("DB_HOST","172.30.0.1",0);
            setenv("DB_PORT","9010",0);
            setenv("DB_LOGIN","user",0);
            setenv("DB_PASSWORD","password",0);
            setenv("DB_DATABASE","db",0);
            setenv("CACHE","172.30.0.1:9100",0);
            setenv("QUEUE_HOST","172.30.0.1:9192",0);
            setenv("QUEUE_TOPIC","event_server",0);
            setenv("QUEUE_GROUP_ID","0",0);
        }

        _host = get_env("DB_HOST");
        _port = get_env("DB_PORT");
        _login = get_env("DB_LOGIN");
        _password = get_env("DB_PASSWORD");
        _database = get_env("DB_DATABASE");
        _cache_servers = get_env("CACHE");
        _queue_host = get_env("QUEUE_HOST");
        _queue_topic = get_env("QUEUE_TOPIC");
        _queue_group_id = get_env("QUEUE_GROUP_ID");

        std::cout<<_host<<std::endl;
        std::cout<<_port<<std::endl;
        std::cout<<_login<<std::endl;
        std::cout<<_password<<std::endl;
        std::cout<<_database<<std::endl;
        std::cout<<_cache_servers<<std::endl;
        std::cout<<_queue_host<<std::endl;
        std::cout<<_queue_topic<<std::endl;
        std::cout<<_queue_group_id<<std::endl;

}


Config &Config::get()
{
    static Config _instance;
    return _instance;
}

const std::string &Config::get_cache_servers() const
{
    return _cache_servers;
}

std::string &Config::cache_servers()
{
    return _cache_servers;
}

const std::string &Config::get_port() const
{
    return _port;
}

const std::string &Config::get_host() const
{
    return _host;
}

const std::string &Config::get_login() const
{
    return _login;
}

const std::string &Config::get_password() const
{
    return _password;
}
const std::string &Config::get_database() const
{
    return _database;
}

std::string &Config::port()
{
    return _port;
}

std::string &Config::host()
{
    return _host;
}

std::string &Config::login()
{
    return _login;
}

std::string &Config::password()
{
    return _password;
}

std::string &Config::database()
{
    return _database;
}

const std::string &Config::get_queue_host() const {
    return _queue_host;
}

const std::string &Config::get_queue_group_id() const {
    return _queue_group_id;
}

const std::string &Config::get_queue_topic() const {
    return _queue_topic;
}

std::string &Config::queue_group_id() {
    return _queue_group_id;
}

std::string &Config::queue_host() {
    return _queue_host;
}

std::string &Config::queue_topic() {
    return _queue_topic;
}
