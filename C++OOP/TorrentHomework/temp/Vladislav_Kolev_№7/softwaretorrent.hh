#ifndef SOFTWARETORRENT_HH
#define SOFTWARETORRENT_HH

#include "torr.hh"

class SoftwareTorrent : public Torrent
{
    std::string maker_name;
    std::string os;
    int version[3];/// not sure
public:
    SoftwareTorrent(std::string maker_name, std::string os, int version[3],
     std::string heading, int size, std::string uploader_name, int count_downloads);

    SoftwareTorrent(const SoftwareTorrent &softwareTorrent);

    std::string toString()override;

    int get_major_version()const;

    int get_minor_version()const;

    int get_patch_version()const;

    std::string get_maker_name()const;

    std::string get_os()const;
};

#endif