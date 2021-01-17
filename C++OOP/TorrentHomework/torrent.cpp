#include <iostream>
#include <string>
#include <vector>
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
        if(heading.empty()){throw "Empty heading";}
        if(uploader_name.empty()){throw "Empty uploader's name";}

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
    virtual string toString()
    {
        string text = "Heading:" + heading + "|Size:" + to_string(size) + "\n"
        + "Uploaded by:" + uploader_name + "|with count downloads:" + to_string(count_downloads); 
        return text;
    }
    string get_heading()
    {
        return this->heading;
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
        if(platform.empty()){throw "empty platform name";};
        if(maturity_rating == ' '){throw "empty maturity rating";};

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
    string toString()override
    {
        return Torrent::toString() + "\n"
        + "Platform:" + platform + "\n"
        + "Maturity rating:" + maturity_rating;
    }
    char get_maturity_rating()
    {
        return this->maturity_rating;
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
        if(director_name.empty()){throw "empty director name";};
        if(duration == 0){throw "duration can't be 0";};
        if(language.empty()){throw "empty language";};

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
    string toString()override
    {
        return Torrent::toString() + "\n"
        + "Director:" + director_name + "\n"
        + "Duration:" + to_string(duration) + "\n"
        + "Language:" + language;
    }
    string get_director_name()
    {
        return this->director_name;
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
    string toString()override
    {
        return Torrent::toString() + "\n"
        + "Maker name:" + maker_name + "\n"
        + "OS:" + os + "\n"
        + "Version:" + to_string(version[0]) + "."
        + to_string(version[1]) + "." + to_string(version[2]);
    }
    int get_major_version()
    {
        return this->version[0];
    }
};
class Server
{
    vector<Torrent*> torrents;
    vector<GameTorrent*> gametorrents;
    vector<FilmTorrent*> filmtorrents;
    vector<SoftwareTorrent*> softwaretorrents;
    vector<string> users_names;
public:
    Server(){};
    void add_torrent(Torrent* torrent)
    {
        torrents.push_back(torrent);
    }
    void add_torrent(GameTorrent* torrent)
    {
        torrents.push_back(torrent);
        gametorrents.push_back(torrent);
    }
    void add_torrent(FilmTorrent* torrent)
    {
        torrents.push_back(torrent);
        filmtorrents.push_back(torrent);
        //cout<<torrent.toString();
    }
    void add_torrent(SoftwareTorrent* torrent)
    {
        torrents.push_back(torrent);
        softwaretorrents.push_back(torrent);
    }
    void print_torrents()
    {
        for (int i = 0; i < torrents.size(); i++)
        {
            cout<<torrents[i]->toString()<<endl;
            cout<<endl;
        }
    }
    vector<Torrent*> search_by_heading(string text)///not sure
    {
        vector<Torrent*> searchedTor;
        for (int i = 0; i < torrents.size(); i++)
        {
            if(torrents[i]->get_heading() == text)
            {
                searchedTor.push_back(torrents[i]);
                //return torrents[i];
            }
        }
        return searchedTor;
    }
    vector<GameTorrent*> search_by_maturity_rating(char rating)
    {
        vector<GameTorrent*> searchedTor;
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
    vector<FilmTorrent*> search_by_director_name(string name)
    {
        vector<FilmTorrent*> searchedTor;
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
    vector<SoftwareTorrent*> search_by_majore_software_version(int major_version)
    {
        vector<SoftwareTorrent*> searchedTor;
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
};
int main()
{
    //Inicialising torrents
    Torrent t1 = Torrent("Star Wars", 10, "Vladi", 20);
    GameTorrent t2 = GameTorrent("MacOS", 'P',
    "Star Wars2", 10, "Vladi", 20);
    FilmTorrent *t3 = new FilmTorrent("Misho", 20, "Bulgarian", "Star Wars3", 10, "Vladi", 20);
    int version[3] = {1, 22, 33};
    int version2[3] = {0, 22, 33};

    SoftwareTorrent *t4 = new SoftwareTorrent("Gosho", "Linux", version, "Star Wars4", 10, "Vladi", 20);
    SoftwareTorrent *t5 = new SoftwareTorrent("Gosho", "Linux", version2, "Star Wars5", 10, "Vladi", 20);
    SoftwareTorrent *t6 = new SoftwareTorrent("Gosho", "Linux", version, "Star Wars6", 10, "Vladi", 20);


    /*
    cout<<t1.toString()<<endl;
    cout<<endl;
    cout<<t2.toString()<<endl;
    cout<<endl;
    cout<<t3.toString()<<endl;
    cout<<endl;
    cout<<t4.toString()<<endl;
    */

    //Inicialising server
    Server server;
    server.add_torrent(t3);
    server.add_torrent(t4);
    server.add_torrent(t5);
    server.add_torrent(t6);
    //server.print_torrents();

    cout<<"Result by search:"<<endl;
    vector<SoftwareTorrent*> softtor_with_vers1;
    softtor_with_vers1 = server.search_by_majore_software_version(1);
    for (int i = 0; i < softtor_with_vers1.size(); i++)
    {
        cout<<softtor_with_vers1[i]->toString()<<endl;
        cout<<endl;
    }
    




    return 0;
}
