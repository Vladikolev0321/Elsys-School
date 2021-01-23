#include "softwaretorrent.hh"

SoftwareTorrent::SoftwareTorrent(std::string maker_name, std::string os, int version[3],
     std::string heading, int size, std::string uploader_name, int count_downloads)
    : Torrent(heading, size, uploader_name, count_downloads)
    {
        if(maker_name.empty()){throw "empty maker name";};
        if(os.empty()){throw "empty os name";};
        ///v

        this->maker_name = maker_name;
        this->os = os;
        for (int i = 0; i < 3; i++)
        {
            this->version[i] = version[i]; 
        }
    }
SoftwareTorrent::SoftwareTorrent(const SoftwareTorrent &softwareTorrent)
{
    this->maker_name = softwareTorrent.get_maker_name();
    this->os = softwareTorrent.get_os();
    this->version[0] = softwareTorrent.get_major_version();
    this->version[1] = softwareTorrent.get_minor_version();
    this->version[2] = softwareTorrent.get_patch_version();

        /*for (int i = 0; i < 3; i++)
        {
            this->version[i] = softwareTorrent.version[i]; 
        }
        */
    this->heading = softwareTorrent.get_heading();
    this->size = softwareTorrent.get_size();
    this->uploader_name = softwareTorrent.get_uploader_name();
    this->count_downloads = softwareTorrent.get_count_downloads();

}
std::string SoftwareTorrent::toString()
{
    return Torrent::toString() + "\n"
    + "Maker name:" + maker_name + "\n"
    + "OS:" + os + "\n"
    + "Version:" + std::to_string(version[0]) + "."
    + std::to_string(version[1]) + "." + std::to_string(version[2]);
}
int SoftwareTorrent::get_major_version()const
{
    return this->version[0];
}
int SoftwareTorrent::get_minor_version()const
{
    return this->version[1];
}
int SoftwareTorrent::get_patch_version()const
{
    return this->version[2];
}
std::string SoftwareTorrent::get_maker_name()const
{
    return this->maker_name;
}
std::string SoftwareTorrent::get_os()const
{
    return this->os;
}