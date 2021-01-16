#include <iostream>
#include <string>
using namespace std;

class Torrent
{
protected:
    string heading;
    int size;
    string uploader_name;
    int count_downloads;
public:
    Torrent(){};
    Torrent(string heading, int size, string uploader_name, int count_downloads)
    {
        this->heading = heading;
        this->size = size;
        this->uploader_name = uploader_name;
        this->count_downloads = count_downloads;
    }
    Torrent(const Torrent &torrent)
    {
        this->heading = torrent.heading;
        this->size = torrent.size;
        this->uploader_name = torrent.uploader_name;
        this->count_downloads = torrent.count_downloads;
    }
};
class GameTorrent : public Torrent
{
    string platform;
    char maturity_rating;
public:
    GameTorrent(string platform, char maturity_rating,
     string heading, int size, string uploader_name, int count_downloads)
      : Torrent(heading, size, uploader_name, count_downloads)
    {
        this->platform = platform;
        this->maturity_rating = maturity_rating;
    }
    GameTorrent(const GameTorrent &game_torrent)
    {
        this->platform = game_torrent.platform;
        this->maturity_rating = game_torrent.maturity_rating;
        this->heading = game_torrent.heading;
        this->size = game_torrent.size;
        this->uploader_name = game_torrent.uploader_name;
        this->count_downloads = game_torrent.count_downloads;
    }
    /*string toString()
    {
        
    }
    */
};
class FilmTorrent : public Torrent
{
    string director_name;
    int duration;
    string language;
public:
    FilmTorrent(string director_name, int duration, string language,
     string heading, int size, string uploader_name, int count_downloads)
    : Torrent(heading, size, uploader_name, count_downloads)
    {
        this->director_name = director_name;
        this->duration = duration;
        this->language = language;
    }
    FilmTorrent(const FilmTorrent &film_torrent)
    {
        this->director_name = film_torrent.director_name;
        this->duration = film_torrent.duration;
        this->language = film_torrent.language;
        this->heading = film_torrent.heading;
        this->size = film_torrent.size;
        this->uploader_name = film_torrent.uploader_name;
        this->count_downloads = film_torrent.count_downloads;

    }
};
class SoftwareTorrent : public Torrent
{
    string maker_name;
    string os;
    int version[3];/// not sure
public:
    SoftwareTorrent(string maker_name, string os, int version[3],
     string heading, int size, string uploader_name, int count_downloads)
    : Torrent(heading, size, uploader_name, count_downloads)
    {
        this->maker_name = maker_name;
        this->os = os;
        for (int i = 0; i < 3; i++)
        {
            this->version[i] = version[i]; 
        }
    }
    SoftwareTorrent(const SoftwareTorrent &softwareTorrent)
    {
        this->maker_name = softwareTorrent.maker_name;
        this->os = softwareTorrent.os;
        for (int i = 0; i < 3; i++)
        {
            this->version[i] = softwareTorrent.version[i]; 
        }
        this->heading = softwareTorrent.heading;
        this->size = softwareTorrent.size;
        this->uploader_name = softwareTorrent.uploader_name;
        this->count_downloads = softwareTorrent.count_downloads;

    }


};
int main()
{
    return 0;
}