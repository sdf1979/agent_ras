#include <iostream>
#include <string>
#include <boost\locale.hpp>
#include "agent_ras.h"
#include "cluster_objects.h"
#include "cluster.h"

#include <fcntl.h>

int wmain (int argc, wchar_t** argv) {
    
    #ifdef WIN32
        _setmode(_fileno(stdout), _O_U16TEXT);
        _setmode(_fileno(stdin),  _O_U16TEXT);
        _setmode(_fileno(stderr), _O_U16TEXT);
    #endif

    std::string host = "localhost";
    std::uint16_t port = 1545;
    std::string user = "";
    std::string password = "";
    
    if(argc >= 3){
        host = boost::locale::conv::utf_to_utf<char, wchar_t>(std::wstring(argv[1]));
        port = std::stoul(std::wstring(argv[2]));
    }
    if (argc == 5){
        user = boost::locale::conv::utf_to_utf<char, wchar_t>(std::wstring(argv[3]));
        password = boost::locale::conv::utf_to_utf<char, wchar_t>(std::wstring(argv[4]));
    }
    
    YellowManagmentStudio::AgentRas agent_ras(host, port);
    agent_ras.Connect();
    agent_ras.RequestClusterData();
    YellowManagmentStudio::ClusterObjects<YellowManagmentStudio::Cluster> clusters = agent_ras.GetClusters();
    clusters[0].Auth(user, password);
    clusters[0].UpdateInfoBases();
    clusters[0].UpdateWorkingServers();
    clusters[0].UpdateSessions();
    clusters[0].UpdateClusterAdmins();
    clusters[0].UpdateClusterManagers();
    clusters[0].UpdateWorkingProcesses();
    clusters[0].UpdateObjectLock();
    clusters[0].UpdateConnectionsShort();
    agent_ras.Close();

    for(auto it = clusters.begin(); it != clusters.end(); ++it){
        std::wcout << *it;
    }    

    return 0;
}