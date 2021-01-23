#include "server.hh"
#include <iostream>

int main()
{
    //Inicialising torrents

    try
    {
        Torrent t1 = Torrent("Star Wars", 10, "Vladi", 20);
    GameTorrent *t2 = new GameTorrent("MacOS", 'P',
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
    server.add_torrent(t2);
    server.add_torrent(t3);
    server.add_torrent(t4);
    server.add_torrent(t5);
    server.add_torrent(t6);
    //server.print_torrents();

    std::cout<<"Result by text 3  search:"<<std::endl;
    std::vector<Torrent*> torrents_with_title_Gosho = server.search_by_heading("3");
    for (int i = 0; i < torrents_with_title_Gosho.size(); i++)
    {
        std::cout<<torrents_with_title_Gosho[i]->toString()<<std::endl;
       std::cout<<std::endl;
    }

    std::cout<<"Result by director name Misho search:"<<std::endl;
    std::vector<FilmTorrent*> films_with_director_Misho = server.search_by_director_name("Misho");
    for (int i = 0; i < films_with_director_Misho.size(); i++)
    {
        std::cout<<films_with_director_Misho[i]->toString()<<std::endl;
        std::cout<<std::endl;
    }

    std::cout<<"Result by version P maturity rating search:"<<std::endl;
    std::vector<GameTorrent*> games_with_mat_rat_P = server.search_by_maturity_rating('P');
    for (int i = 0; i < games_with_mat_rat_P.size(); i++)
    {
        std::cout<<games_with_mat_rat_P[i]->toString()<<std::endl;
        std::cout<<std::endl;
    }

    std::cout<<"Result by version 1 search:"<<std::endl;
    std::vector<SoftwareTorrent*> softtor_with_vers1;
    softtor_with_vers1 = server.search_by_majore_software_version(1);
    for (int i = 0; i < softtor_with_vers1.size(); i++)
    {
        std::cout<<softtor_with_vers1[i]->toString()<<std::endl;
        std::cout<<std::endl;
    }

    
    }
    catch(const char* ex)
    {
        std::cout<<ex<<std::endl;
    }
    return 0;
}
