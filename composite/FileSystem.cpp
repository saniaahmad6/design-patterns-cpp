#include <iostream>
#include <vector>
#include <string>


class FileSystem {
    public:
    virtual void ls () = 0;
};

class File : public FileSystem{
    std::string name;
    public:
    File(std::string name) {
        this->name=name;
    }
    void ls(){
        std::cout<<"File "<<name<<std::endl;
    }

};
class Directory : public FileSystem{
    std::vector <FileSystem * > list;
    std::string name;
    public:
    Directory(std::string name) {
        this->name=name;
    }
    void add(FileSystem * filesystem) { //unique to directory 
        list.push_back(filesystem);
    }
    void ls(){
        std::cout<<"Directory "<<name<<std::endl;
        for (auto itr : list) {
            itr->ls();
        }
    }

};

int main() {
    Directory *desktop = new Directory("Tech");
    FileSystem *song1 = new File("S1");
    FileSystem *song2 = new File("S1");
    Directory *subdir = new Directory("subdir");
    desktop->add(song1);
    desktop->add(song2);
    desktop->add(subdir);
    desktop->ls();

    return 0;
}