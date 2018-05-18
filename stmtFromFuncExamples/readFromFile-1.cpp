#include <iostream>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>

bool is_file(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool is_dir(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}


enum ERROR { NO = 0, OPEN_FILE , OPEN_DIR };

ERROR error = ERROR::NO;

void readFromFile(std::string path, std::string name);;
void readFromDir(std::string path);

int main() {
    readFromDir("/home/guzel/1");
    std::cout << error << std::endl;

    //error = ERROR::NO;
    readFromFile("/home/guzel/1", "1.txt");
    std::cout << error << std::endl;
    return 0;
}

void readFromDir(std::string path) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            std::string file = ent->d_name;
            if (file != "." && file != ".."){
                readFromFile(path, file);
            }
        }
        closedir (dir);
    } else {
        error = ERROR::OPEN_DIR;
    }
}

void readFromFile(std::string path, std::string name) {
    //delete
    error = ERROR::NO;
    std::string fullName = path + '/' + name;
    std::string line;
    std::string res = "";
    std::ifstream myfile (fullName);
    if (is_file(fullName.c_str())&& myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            res += line + "\n";
        }
        myfile.close();
    }
    else {
        error = ERROR::OPEN_FILE;
    }
    std::cout << res << std::endl;

};

