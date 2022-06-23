//20541번
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Album
{
private:
    Album* parentAlbum;
    string albumName;
    int photoCnt;
    int albumCnt;
    set <string> photoSet;  //사진이름
    map <string, Album*> albumMap;   //앨범이름 , 앨범 클래스
 


public:
    Album(Album* inputparentAlbum, string inputAlbumName){parentAlbum=inputparentAlbum; albumName = inputAlbumName;}
    void deleteAlbum();
    Album* getParentAlbum(){return parentAlbum;}
    string getAlbumName(){return albumName;}
    void setAlbumCnt();
    int getAlbumCnt(){return albumCnt;}
    void setPhotoCnt();
    int getPhotoCnt(){return photoCnt;}
    void mkalbFunc(string inputAlbumName);
    void rmalbFunc(string inputAlbumName);
    void insertFunc(string inputPhotoName);
    void deleteFunc(string inputPhotoName);
    void caFunc(string inputalbumNmae);
};

Album* curAlbum;
Album* topAlbum;

void Album::setAlbumCnt()
{
    albumCnt = 0;
    if(albumMap.size() == 0)
    {
        return;
    }
    else
    {
        for(auto it = albumMap.begin(); it != albumMap.end(); it++)
        {
            albumCnt++;
            (*it->second).setAlbumCnt();
            albumCnt = albumCnt + (*it->second).getAlbumCnt();
        }
    }
}

void Album::setPhotoCnt()
{
    photoCnt = 0;
    if(albumMap.empty())
    {
        photoCnt = photoCnt + photoSet.size();
        return;
    }
    else
    {
        photoCnt = photoCnt + photoSet.size();
        for(auto it = albumMap.begin(); it != albumMap.end(); it++)
        {
            (*it->second).setPhotoCnt();
            photoCnt = photoCnt + (*it->second).getPhotoCnt();
        }
    }
}

void Album::mkalbFunc(string inputAlbumName)
{
    if(albumMap.count(inputAlbumName) == 0) //중복 아님
    {
        Album *album = new Album(curAlbum, inputAlbumName);
        curAlbum->albumMap.insert({inputAlbumName, album});
    }
    else
    {
        cout<<"duplicated album name\n";
    }
}

void Album::deleteAlbum()
{
    delete this;
}

void Album::rmalbFunc(string inputAlbumName)
{
    int deletePhotoCnt = 0;
    int deleteAlbumCnt = 0;
    if(inputAlbumName == "-1")
    {
        if(albumMap.size() != 0)
        {
            auto it = curAlbum->albumMap.begin();

            (*it->second).setPhotoCnt();
            (*it->second).setAlbumCnt();

            deletePhotoCnt = deletePhotoCnt + (*it->second).getPhotoCnt();
            deleteAlbumCnt = deleteAlbumCnt + (*it->second).getAlbumCnt();
            
            (*it->second).photoSet.clear();
            (*it->second).deleteAlbum();

            deleteAlbumCnt++;
            albumMap.erase(it);
        }
    }
    else if(inputAlbumName == "0")
    {
        for(auto it = curAlbum->albumMap.begin(); it != curAlbum->albumMap.end(); it++)
        {
            (*it->second).setPhotoCnt();
            (*it->second).setAlbumCnt();

            deletePhotoCnt = deletePhotoCnt + (*it->second).getPhotoCnt();
            deleteAlbumCnt = deleteAlbumCnt + (*it->second).getAlbumCnt();

            (*it->second).photoSet.clear();
            (*it->second).deleteAlbum();

            deleteAlbumCnt++;

            //albumMap.erase(it);
        }
        albumMap.clear();
    }
    else if(inputAlbumName == "1")
    {
        if(albumMap.size() != 0)
        {
            auto it = curAlbum->albumMap.end();
            it--;

            (*it->second).setPhotoCnt();
            (*it->second).setAlbumCnt();

            deletePhotoCnt = deletePhotoCnt + (*it->second).getPhotoCnt();
            deleteAlbumCnt = deleteAlbumCnt + (*it->second).getAlbumCnt();

            (*it->second).photoSet.clear();
            (*it->second).deleteAlbum();

            deleteAlbumCnt++;
            albumMap.erase(it);
        }
    }
    else
    {
        if(curAlbum->albumMap.count(inputAlbumName) != 0)
        {
            auto it = curAlbum->albumMap.find(inputAlbumName);

            (*it->second).setPhotoCnt();
            (*it->second).setAlbumCnt();

            deletePhotoCnt = deletePhotoCnt + (*it->second).getPhotoCnt();
            deleteAlbumCnt = deleteAlbumCnt + (*it->second).getAlbumCnt();

            (*it->second).photoSet.clear();
            (*it->second).deleteAlbum();

            deleteAlbumCnt++;
            albumMap.erase(it);
        }
    }
    cout<<deleteAlbumCnt<<" "<<deletePhotoCnt<<"\n";
}

void Album::insertFunc(string inputPhotoName)
{
    if(photoSet.count(inputPhotoName) == 0) //중복 아님
    {
        curAlbum->photoSet.insert(inputPhotoName);
    }
    else
    {
        cout<<"duplicated photo name\n";
    }
}

void Album::deleteFunc(string inputPhotoName)
{
    int deletePhotoCnt = 0;
    if(inputPhotoName == "-1")
    {
        if(photoSet.size()!=0)
        {
            auto it = photoSet.begin();

            deletePhotoCnt = 1;

            curAlbum->photoSet.erase(it);
        }
    }
    else if(inputPhotoName == "0")
    {
        deletePhotoCnt = deletePhotoCnt + curAlbum->photoSet.size();

        curAlbum->photoSet.clear();
    }
    else if(inputPhotoName == "1")
    {
        if(photoSet.size()!=0)
        {
            auto it = photoSet.end();
            it--;

            deletePhotoCnt = 1;

            curAlbum->photoSet.erase(it);
        }
    }
    else
    {
        auto it = photoSet.find(inputPhotoName);
        if(it != photoSet.end())
        {
            deletePhotoCnt = 1;
            curAlbum->photoSet.erase(it);
        }
    }
    cout<<deletePhotoCnt<<"\n";
}

void Album::caFunc(string inputAlbumName)
{
    if(inputAlbumName == "..")
    {
        if(curAlbum->getAlbumName() != "album")
        {
            curAlbum = curAlbum->getParentAlbum();
        }
    }
    else if(inputAlbumName == "/")
    {
        curAlbum = topAlbum;
    }
    else
    {
        if(curAlbum->albumMap.count(inputAlbumName) != 0)
        {
            curAlbum = curAlbum->albumMap[inputAlbumName];
        }
    }
    
    cout<<curAlbum->getAlbumName()<<"\n";
}


void doTask(string command)
{
    if(command == "mkalb")
    {
        string albumName; cin>>albumName;
        curAlbum->mkalbFunc(albumName);
    }
    else if(command == "rmalb")
    {
        string albumName; cin>>albumName;
        curAlbum->rmalbFunc(albumName);
    }
    else if(command == "insert")
    {
        string photoName; cin>>photoName;
        curAlbum->insertFunc(photoName);
    }
    else if(command == "delete")
    {
        string photoName; cin>>photoName;
        curAlbum->deleteFunc(photoName);
    }
    else if(command == "ca")
    {
        string albumName; cin>>albumName;
        curAlbum->caFunc(albumName);
    }
}

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    curAlbum = new Album(NULL, "album");
    topAlbum = curAlbum;

    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        string command; cin>>command;
        doTask(command);
    }
}