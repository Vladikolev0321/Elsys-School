#ifndef FILMTORRENT_HH
#define FILMTORRENT_HH

#include "torr.hh"

class FilmTorrent : public Torrent
{
    std::string director_name;
    int duration;
    std::string language;
public:
    FilmTorrent(std::string director_name, int duration, std::string language,
     std::string heading, int size, std::string uploader_name, int count_downloads);

    FilmTorrent(const FilmTorrent &film_torrent);

    std::string toString()override;

    std::string get_director_name()const;

    int get_duration()const;

    std::string get_language()const;
};

#endif