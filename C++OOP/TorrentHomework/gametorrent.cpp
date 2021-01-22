#include <iostream>

#include "gametorrent.hh"

GameTorrent::GameTorrent(std::string platform, char maturity_rating,
     std::string heading, int size, std::string uploader_name, int count_downloads)
      : Torrent(heading, size, uploader_name, count_downloads)
{
        if(platform.empty()){throw "empty platform name";};
        if(maturity_rating == ' '){throw "empty maturity rating";};

        this->platform = platform;
        this->maturity_rating = maturity_rating;
}

GameTorrent::GameTorrent(const GameTorrent &game_torrent)
    {
        this->platform = game_torrent.get_platform();
        this->maturity_rating = game_torrent.get_maturity_rating();
        this->heading = game_torrent.get_heading();
        this->size = game_torrent.get_size();
        this->uploader_name = game_torrent.get_uploader_name();
        this->count_downloads = game_torrent.get_count_downloads();
    }
    std::string GameTorrent::toString()
    {
        return Torrent::toString() + "\n"
        + "Platform:" + platform + "\n"
        + "Maturity rating:" + maturity_rating;
    }
    char GameTorrent::get_maturity_rating()const
    {
        return this->maturity_rating;
    }
    std::string GameTorrent::get_platform()const
    {
        return this->platform;
    }