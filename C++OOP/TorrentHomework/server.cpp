#include "server.hh"
#include<iostream>
#include<string.h>

void Server::add_torrent(Torrent* torrent)
{
    torrents.push_back(torrent);
}
void Server::add_torrent(GameTorrent* torrent)
{
    torrents.push_back(torrent);
    gametorrents.push_back(torrent);
}
void Server::add_torrent(FilmTorrent* torrent)
{
    torrents.push_back(torrent);
    filmtorrents.push_back(torrent);
        //cout<<torrent.toString();
}
void Server::add_torrent(SoftwareTorrent* torrent)
{
    torrents.push_back(torrent);
    softwaretorrents.push_back(torrent);
}
void Server::print_torrents()
{
    for (int i = 0; i < torrents.size(); i++)
    {
        std::cout<<torrents[i]->toString()<<std::endl;
        std::cout<<std::endl;
    }
}
std::vector<Torrent*> Server::search_by_heading(std::string text)///not sure
{
    std::vector<Torrent*> searchedTor;
    for (int i = 0; i < torrents.size(); i++)
    {
        if(strstr(torrents[i]->get_heading().c_str(), text.c_str()))
        {
            searchedTor.push_back(torrents[i]);
         }
            /*if(torrents[i]->get_heading() == text)
            {
                searchedTor.push_back(torrents[i]);
                //return torrents[i];
            }
            */
        }
    return searchedTor;
    }
std::vector<GameTorrent*> Server::search_by_maturity_rating(char rating)
{
    std::vector<GameTorrent*> searchedTor;
    for (int i = 0; i < gametorrents.size(); i++)
    {
        if(gametorrents[i]->get_maturity_rating() == rating)
        {
                searchedTor.push_back(gametorrents[i]);
                //return gametorrents[i];
        }
    }
    return searchedTor;
}
std::vector<FilmTorrent*> Server::search_by_director_name(std::string name)
{
    std::vector<FilmTorrent*> searchedTor;
    for (int i = 0; i < filmtorrents.size(); i++)
    {
        if(filmtorrents[i]->get_director_name() == name)
        {
            searchedTor.push_back(filmtorrents[i]);
                //return filmtorrents[i];
        }
    }
    return searchedTor;
}
std::vector<SoftwareTorrent*> Server::search_by_majore_software_version(int major_version)
{
    std::vector<SoftwareTorrent*> searchedTor;
    for (int i = 0; i < softwaretorrents.size(); i++)
    {
        if(softwaretorrents[i]->get_major_version() == major_version)
        {
            searchedTor.push_back(softwaretorrents[i]);
                //return softwaretorrents[i];
        }
    }
    return searchedTor;
}