#include<iostream>
#include<thread>
#include<client.h>
#include<memory>
#include<deque>
using namespace std;

deque<string> ECC2TM;
deque<string> TM2ECC;

class EdgeCloudColla{
public:
    EdgeCloudColla(string serviceName, string myName, string group):serviceName(serviceName){
        isReceive=true;
        isSend=false;
        cli->connect(myName);
    }

    void run(){
        while(isReceive && !isSend){
            int num;
            while(!cli->mail_size(num)){};
            while(num){
                num--;
                ECC2TM.push_back(cli->receive());
            }
        }
        while(isSend){
            isSend=false;
            while(TM2ECC.size()){
                cli->unicast(serviceName, TM2ECC.front());
                TM2ECC.pop_front();
            }
        }
    }
private:
    bool isReceive;
    bool isSend;
    string serviceName;
    inline static client* cli = client::get_instance("10.112.212.188", 9000);
};

class TaskManager{
    void run(){
        
    }
    int getTaskKind(){

    }
};

class test{
public:
    void pr(){
        int i=0;
        while(i<1000){
            cout<<i<<endl;
            i++;
        }
    }
};

int main()
{
    test a;
    std::thread t1(&test::pr, a);
    t1.join();   //等待threadfunc运行结束
 
    return 0;
}