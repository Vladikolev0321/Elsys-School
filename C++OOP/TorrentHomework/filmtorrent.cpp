#include "filmtorrent.hh"

FilmTorrent::FilmTorrent(std::string director_name, int duration, std::string language,
     std::string heading, int size, std::string uploader_name, int count_downloads)
    : Torrent(heading, size, uploader_name, count_downloads)
{
    if(director_name.empty()){throw "empty director name";};
    if(duration == 0){throw "duration can't be 0";};
    if(language.empty()){throw "empty language";};

    this->director_name = director_name;
    this->duration = duration;
    this->language = language;
}
FilmTorrent::FilmTorrent(const FilmTorrent &film_torrent)
{
    this->director_name = film_torrent.get_director_name();
    this->duration = film_torrent.get_duration();
    this->language = film_torrent.get_language();
    this->heading = film_torrent.get_heading();
    this->size = film_torrent.get_size();
    this->uploader_name = film_torrent.get_uploader_name();
    this->count_downloads = film_torrent.get_count_downloads();
}
std::string FilmTorrent::toString()
{
    return Torrent::toString() + "\n" + "Director:" + director_name + "\n"
     + "Duration:" + std::to_string(duration) + "\n"
      + "Language:" + language;
}
std::string FilmTorrent::get_director_name() const
{
    return this->director_name;
}
int FilmTorrent::get_duration() const
{
    return this->duration;
}
std::string FilmTorrent::get_language() const
{
    return this->language;
}