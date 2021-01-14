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
    Torrent(string heading, int size, string uploader_name, int count_downloads)
    {
        this->heading = heading;
        this->size = size;
        this->uploader_name = uploader_name;
        this->count_downloads = count_downloads;
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
};
