#ifndef SERVER_HH
#define SERVER_HH

#include <iostream>
#include<vector>
#include "torr.hh"
#include "gametorrent.hh"
#include "filmtorrent.hh"
#include "softwaretorrent.hh"


class Server
{
    std::vector<Torrent*> torrents;
    std::vector<GameTorrent*> gametorrents;
    std::vector<FilmTorrent*> filmtorrents;
    std::vector<SoftwareTorrent*> softwaretorrents;
    std::vector<std::string> users_names;
public:
    Server(){};
    void add_torrent(Torrent* torrent);

    void add_torrent(GameTorrent* torrent);

    void add_torrent(FilmTorrent* torrent);

    void add_torrent(SoftwareTorrent* torrent);

    void print_torrents();
    
    std::vector<Torrent*> search_by_heading(std::string text);///not sure

    std::vector<GameTorrent*> search_by_maturity_rating(char rating);

    std::vector<FilmTorrent*> search_by_director_name(std::string name);

    std::vector<SoftwareTorrent*> search_by_majore_software_version(int major_version);
};



#endif