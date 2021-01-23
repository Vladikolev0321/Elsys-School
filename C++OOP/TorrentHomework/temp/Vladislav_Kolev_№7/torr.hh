#ifndef TORR_HH
#define TORR_HH

#include <stdio.h>
#include<string>

class Torrent
{
protected:
    std::string heading;
    int size;
    std::string uploader_name;
    int count_downloads;
public:
    Torrent(){};
    Torrent(std::string heading, int size, std::string uploader_name, int count_downloads);

    Torrent(const Torrent &torrent);

    virtual std::string toString();

    std::string get_heading()const;

    int get_size()const;

    std::string get_uploader_name()const;

    int get_count_downloads()const;
};

#endif