#ifndef GAMETORRENT_HH
#define GAMETORRENT_HH

#include "torr.hh"

class GameTorrent : public Torrent
{
    std::string platform;
    char maturity_rating;
public:
    GameTorrent(std::string platform, char maturity_rating,
     std::string heading, int size, std::string uploader_name, int count_downloads);

    GameTorrent(const GameTorrent &game_torrent);

    std::string toString()override;

    char get_maturity_rating()const;

    std::string get_platform()const;
    
};

#endif