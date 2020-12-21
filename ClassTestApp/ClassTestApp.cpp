#include <iostream>
#include <string>

//---Человечек--------------------------------------------------------
class Walker
{
private:
    int coin;
    std::string name;
    Walker(std::string name) {
        coin = 0;
        this->name = name;
    }
    ~Walker() {}
    Walker(Walker const&); // в С++ последних версий +( = delete)
    Walker& operator= (Walker const&);  // в С++ последних версий +( = delete)
public:
    static Walker& Instance(std::string name)
    {
        // согласно стандарту, этот код ленивый и потокобезопасный
        static Walker s(name);
        return s;
    }

    void getWallet() {
        std::cout << std::to_string(coin) << std::endl;
    }
    void getName() {
        std::cout << name << std::endl;
    }
};
//--------------------------------------------------------------------

int main()
{
    std::cout << "1st pos\n";
    Walker& Humn = Walker::Instance("bob");
    Humn.getName();
    Humn.getWallet();

    std::cout << "End pos\n";
    system("pause");
    return 0;
}

//---Фабрика-комнат---------------------------------------------------

//---Комнаты----------------------------------------------------------
__interface IRoom	//Интерфейс комнат
{

};
//--------------------------------------------------------------------