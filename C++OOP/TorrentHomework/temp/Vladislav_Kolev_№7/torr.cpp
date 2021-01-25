#include "torr.hh"

#include <iostream>
#include <string>

Torrent::Torrent(std::string heading, int size, std::string uploader_name, int count_downloads)
{
    if(heading.empty()){throw "Empty heading";}
    if(size < 0){throw "Invalid heading size";}
    if(uploader_name.empty()){throw "Empty uploader's name";}
    if(count_downloads < 0){throw "Invalid count_downloads";}

    this->heading = heading;
    this->size = size;
    this->uploader_name = uploader_name;
    this->count_downloads = count_downloads;
}
Torrent::Torrent(const Torrent &torrent)
{
    this->heading = torrent.get_heading();
    this->size = torrent.get_size();
    this->uploader_name = torrent.get_uploader_name();
    this->count_downloads = torrent.get_count_downloads();
}
std::string Torrent::toString()
{
    std::string text = "Heading:" + heading + "|Size:" + std::to_string(size) + "\n"
     + "Uploaded by:" + uploader_name + "|with count downloads:" + std::to_string(count_downloads);
    return text;
}
std::string Torrent::get_heading() const
{
    return this->heading;
}
int Torrent::get_size() const
{
    return this->size;
}
std::string Torrent::get_uploader_name() const
{
    return this->uploader_name;
}
int Torrent::get_count_downloads() const
{
    return this->count_downloads;
}