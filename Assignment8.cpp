#include <iostream>
#include <vector>
#include "Graph.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

int main(){
    Graph g;
    std::vector<string> cities;
    int a=0;
    int x=0;
    string city;
    int distance;
    int selection;
    std::string token;
    ifstream inFile;
    inFile.open("zombieCities.txt");
    string strLine;
    string check;
    string cit1;
    string cit2;
    if(inFile.fail()){
        cout<<"Failed to open file"<<endl;
    }
    else{
        /*Read line by line.*/
        while(!inFile.eof()){
            getline(inFile, strLine);
            std::istringstream ss(strLine);
            while(std::getline(ss, token, ',')){
                if(x>0){
                    while(a<x){
                        if(a==0){
                            city = token.c_str();
                            cities.push_back(city);
                            g.addVertex(city);
                        }
                        else{
                            distance = atoi(token.c_str());
                            if(distance!=-1){
                                g.addEdge(cities[x],cities[a],distance);
                            }
                        }
                        a++;
                    }
                    a = 0;
                }
                x++;
            }
        }
        inFile.close();
    }
    while(a==0){
        cout<<"======Main Menu====="<<endl
        <<"1. Print vertices"<<endl
        <<"2. Find districts"<<endl
        <<"3. Find shortest path"<<endl
        <<"4. Find shortest distance"<<endl
        <<"5. Quit"<<endl;
        cin>>selection;
        cin.ignore();
        if(selection==1){
            g.printVertices();
        }
        if(selection==2){
            g.findDistricts();
        }
        if(selection==3){
            cout<<"Enter title a starting city:"<<endl;
            std::getline(std::cin,cit1);
            cout<<"Enter title an ending city:"<<endl;
            std::getline(std::cin,cit2);
            g.findShortestPath(cit1, cit2);
        }
        if(selection==4){
            cout<<"Enter title a starting city:"<<endl;
            std::getline(std::cin,cit1);
            cout<<"Enter title an ending city:"<<endl;
            std::getline(std::cin,cit2);
            g.findShortestDistance(cit1, cit2);
        }
        if(selection==5){
            cout<<"Goodbye!"<<endl;
            a=1;
        }
    }
}

